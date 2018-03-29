// -*- C++ -*-

#ifndef _test_smallfunc_h_
#define _test_smallfunc_h_


#include "smallfunc.h"


namespace smallfunc_data
{
  double alpha{1.2};
  double beta{2.5};
  double gamma{3.1};
  double beta2{2.2};
  double beta3{2.1};
  double f{0};

  double alpha_tng{0};
  double beta_tng{0};
  double gamma_tng{0};
  double beta2_tng{0};
  double beta3_tng{0};
  double f_tng{0};

  double alpha_adj{0};
  double beta_adj{0};
  double gamma_adj{0};
  double beta2_adj{0};
  double beta3_adj{0};
  double f_adj{1};

  void reset_tangent()
  {
    alpha_tng = 0;
    beta_tng = 0;
    gamma_tng = 0;
    beta2_tng = 0;
    beta3_tng = 0;
    f_tng = 0;
  }

  void reset_adjoint()
  {
    alpha_adj = 0;
    beta_adj = 0;
    gamma_adj = 0;
    beta2_adj = 0;
    beta3_adj = 0;
    f_adj = 1;
  }
}


void smallfunc_primal_reference(int n = 1)
{
  name = "smallfunc-pri-ref";

  namespace data = smallfunc_data;

  Timer timer;
  timer.start();

  {
    double f_sum = 0;
    for (int it = 0; it != n; ++it)
    {
      smallfunc(data::alpha, data::beta, data::gamma, data::beta2, data::beta3, &data::f);
      f_sum += data::f;
    }
    data::f = f_sum;
  }

  timer.stop();
  timers[name].push_back(timer.duration());

  if (print_results)
  {
    std::cout << name << " | " << data::f << std::endl;
  }
}


void smallfunc_adjoint(int n = 1)
{
  name = "smallfunc-adj";

  namespace data = smallfunc_data;

  data::reset_adjoint();

  Timer timer;
  timer.start();

  {
    for (int it = 0; it != n; ++it)
    {
      Terminal<A> a{data::alpha, data::alpha_adj};
      Terminal<B> b{data::beta, data::beta_adj};
      Terminal<C> c{data::gamma, data::gamma_adj};
      Terminal<D> d{data::beta2, data::beta2_adj};
      Terminal<E> e{data::beta3, data::beta3_adj};
      Result<R> r{double(0), data::f_adj};

      smallfunc_uniq(a, b, c, d, e, r);

      data::alpha_adj += a.adj;
      data::beta_adj += b.adj;
      data::gamma_adj += c.adj;
      data::beta2_adj += d.adj;
      data::beta3_adj += e.adj;
    }
  }

  timer.stop();
  timers[name].push_back(timer.duration());

  if (print_results)
  {
    std::cout << name << " | " << data::alpha_adj << std::endl;
    std::cout << name << " | " << data::beta_adj << std::endl;
    std::cout << name << " | " << data::gamma_adj << std::endl;
    std::cout << name << " | " << data::beta2_adj << std::endl;
    std::cout << name << " | " << data::beta3_adj << std::endl;
  }
}


void smallfunc_adjoint_tapenade(int n = 1)
{
  name = "smallfunc-adj-tapenade";

  namespace data = smallfunc_data;

  data::reset_adjoint();

  Timer timer;
  timer.start();

  {
    for (int it = 0; it != n; ++it)
    {
      data::f_adj = 1;

      // smallfunc_b(data::alpha, &data::alpha_adj,
      //             data::beta, &data::beta_adj,
      //             data::gamma, &data::gamma_adj,
      //             data::beta2, &data::beta2_adj,
      //             data::beta3, &data::beta3_adj,
      //             &data::f, &data::f_adj);

      smallfunc_b(data::alpha, &data::alpha_adj,
                  data::beta, &data::beta_adj,
                  data::gamma,
                  data::beta2,
                  data::beta3,
                  &data::f, &data::f_adj);
    }
  }

  timer.stop();
  timers[name].push_back(timer.duration());

  if (print_results)
  {
    std::cout << name << " | " << data::alpha_adj << std::endl;
    std::cout << name << " | " << data::beta_adj << std::endl;
    std::cout << name << " | " << data::gamma_adj << std::endl;
    std::cout << name << " | " << data::beta2_adj << std::endl;
    std::cout << name << " | " << data::beta3_adj << std::endl;
  }
}


void test_smallfunc(int r_size, int t_size)
{
  timers.clear();

  print_results = true;

  for (int it = 0; it != t_size; ++it)
  {
    smallfunc_primal_reference(r_size);
    smallfunc_adjoint(r_size);
    smallfunc_adjoint_tapenade(r_size);

    print_results = false;
  }

  for (auto &timer: timers)
  {
    std::sort(timer.second.begin(), timer.second.end());
  }

  double t_ref = 1;
  {
    auto timer = timers.find("smallfunc-pri-ref");

    if (timer != timers.end())
      t_ref = timer->second[timer->second.size()*0.50];
  }

  std::cout << "timings:" << std::endl;
  for (auto const &timer: timers)
  {
    std::cout << std::setprecision(3);
    std::cout << std::scientific;
    std::cout << std::setw(30);

    std::cout << timer.first
              << " | " << timer.second[timer.second.size()*0.50] / t_ref
              << std::endl;
  }
}


#endif // _test_smallfunc_h_
