// -*- C++ -*-

#ifndef _test_harmonic_h_
#define _test_harmonic_h_


#include "harmonic.h"


namespace harmonic_data
{
  const double alpha_0{1.2};
  const double beta_0{2.5};
  const double gamma_0{3.1};
  const double beta2_0{2.2};
  const double beta3_0{2.1};

  volatile double alpha{alpha_0};
  volatile double beta{beta_0};
  volatile double gamma{gamma_0};
  volatile double beta2{beta2_0};
  volatile double beta3{beta3_0};
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

  void reset_primal()
  {
    alpha = alpha_0;
    beta = beta_0;
    gamma = gamma_0;
    beta2 = beta2_0;
    beta3 = beta3_0;
    f = 0;
  }

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

  void update_primal(int it)
  {
    double fac = 0.0000001;
    double delta = (1 + fac * it);
    alpha = alpha_0 * delta;
    beta = beta_0 * delta;
    gamma = gamma_0 * delta;
    beta2 = beta2_0 * delta;
    beta3 = beta3_0 * delta;
    f = 0;
  }
}


void harmonic_primal_reference(int n = 1)
{
  name = "harmonic-pri-ref";

  namespace data = harmonic_data;
  data::reset_primal();

  Timer timer;
  timer.start();

  {
    double f_sum = 0;
    for (int it = 0; it != n; ++it)
    {
      data::update_primal(it);
      harmonic(double(data::alpha),
               double(data::beta),
               double(data::gamma),
               double(data::beta2),
               double(data::beta3),
               &data::f);
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


void harmonic_adjoint(int n = 1)
{
  name = "harmonic-adj";

  namespace data = harmonic_data;
  data::reset_primal();
  data::reset_adjoint();

  Timer timer;
  timer.start();

  {
    for (int it = 0; it != n; ++it)
    {
      data::update_primal(it);

      Terminal<A> a{double(data::alpha), data::alpha_adj};
      Terminal<B> b{double(data::beta), data::beta_adj};
      Terminal<C> c{double(data::gamma), data::gamma_adj};
      Terminal<D> d{double(data::beta2), data::beta2_adj};
      Terminal<E> e{double(data::beta3), data::beta3_adj};
      Result<R> r{double(0), data::f_adj};

      harmonic_uniq(a, b, c, d, e, r);

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


void harmonic_adjoint_tapenade(int n = 1)
{
  name = "harmonic-adj-tapenade";

  namespace data = harmonic_data;
  data::reset_primal();
  data::reset_adjoint();

  Timer timer;
  timer.start();

  {
    for (int it = 0; it != n; ++it)
    {
      data::update_primal(it);
      data::f_adj = 1;
      harmonic_adjoint_tapenade(double(data::alpha), &data::alpha_adj,
                                double(data::beta), &data::beta_adj,
                                double(data::gamma), &data::gamma_adj,
                                double(data::beta2), &data::beta2_adj,
                                double(data::beta3), &data::beta3_adj,
                                data::f, &data::f_adj);
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


void test_harmonic(int r_size, int t_size)
{
  timers.clear();

  print_results = true;

  for (int it = 0; it != t_size; ++it)
  {
    harmonic_primal_reference(r_size);
    harmonic_adjoint(r_size);
    harmonic_adjoint_tapenade(r_size);

    print_results = false;
  }

  for (auto &timer: timers)
  {
    std::sort(timer.second.begin(), timer.second.end());
  }

  double t_ref = 1;
  {
    auto timer = timers.find("harmonic-pri-ref");

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


#endif // _test_harmonic_h_
