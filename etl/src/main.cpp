#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <functional>
#include <utility>
#include <tuple>
#include <map>
#include <cmath>

#include "Identifiers.h"
#include "Timer.h"
#include "demangle.h"

#include "expr/mathop.h"
#include "expr/MathFn.h"
#include "expr/Terminal.h"
#include "expr/Unary.h"
#include "expr/Binary.h"
#include "expr/Ternary.h"
#include "expr/Result.h"
#include "expr/Unique.h"


// #define LOCAL_TEST


#ifdef LOCAL_TEST
void eval_ref(double arg0, double * arg0b,
              double arg1, double * arg1b,
              double * result, double * resultb)
{
#define LTYPE double const
#define CTYPE double const

    double c1 = 1;
    double c2 = 2;
    double c3 = 3;
    double c4 = 4;
    double c5 = 5;
    double c6 = 6;
    double c7 = 7;
    double c8 = 8;
    double c9 = 9;
    double c10 = 10;
    double c11 = 11;
    double c12 = 12;
    double tmp0 = c1*arg0*sin(arg0)/cos(arg1)*c2;
    double tmp0b;
    double tmp1 = arg1*c3*sin(arg1)/cos(arg0);
    double tmp1b;
    double tmp2 = sin(tmp0)*tmp1 + sin(tmp1)*tmp0;
    double tmp2b;
    double tmp3 = sin(tmp2)/cos(tmp2) + cos(tmp0)*c4/sin(tmp0);
    double tmp3b;
    double tmp4 = sin(tmp2)/c5*cos(tmp2) + cos(tmp1)/sin(tmp3);
    double tmp4b;
    double tmp5 = sin(tmp2)*cos(tmp4) + cos(tmp0)*sin(tmp1);
    double tmp5b;
    double tmp6 = c6*sin(tmp2)/cos(tmp5) + cos(tmp0)/sin(tmp3);
    double tmp6b;
    double tmp7 = sin(tmp4) + cos(tmp6) + cos(tmp0)*c7/sin(tmp5);
    double tmp7b;
    double tmp8 = sin(tmp1)/cos(tmp5)*cos(tmp0)*sin(tmp6);
    double tmp8b;
    double tmp9 = sin(tmp6) + c8*cos(tmp4) + cos(tmp0)/sin(tmp1);
    double tmp9b;
    double tmp10 = sin(tmp5)/cos(tmp3) + cos(tmp7) + sin(tmp2);
    double tmp10b;
    double tmp11 = sin(tmp8)*c9*cos(tmp2) + cos(tmp0)/sin(tmp3);
    double tmp11b;
    double tmp12 = c10*sin(tmp10)/cos(tmp1) + cos(tmp0)/sin(tmp4);
    double tmp12b;
    double tmp13 = sin(tmp12) + cos(tmp0)*c11 + cos(tmp0)/sin(tmp3);
    double tmp13b;
    double tmp14;
    double tmp14b;
    double temp;
    double temp0;
    double temp1;
    double temp2;
    double temp3;
    double temp4;
    double temp5;
    double temp6;
    double temp7;
    double temp8;
    double temp9;
    double temp10;
    double temp11;
    double temp12;
    double temp13;
    double temp14;
    double temp15;
    double temp16;
    double temp17;
    double temp18;
    double temp19;
    double temp20;
    double temp21;
    double temp22;
    double temp23;
    double temp24;
    double tempb;
    double tempb0;
    double tempb1;
    double tempb2;
    double tempb3;
    double tempb4;
    double tempb5;
    double tempb6;
    double tempb7;
    double tempb8;
    temp4 = cos(tmp2);
    temp5 = sin(tmp3);
    temp6 = sin(tmp3);
    tmp14b = *resultb;
    *resultb = 0.0;
    temp24 = sin(tmp11);
    temp21 = tmp11*tmp9;
    temp23 = tmp6*tmp13*temp21;
    temp20 = temp23/temp24;
    temp22 = sin(tmp0);
    tempb = -(sin(tmp13/temp22+c12*temp20)*tmp14b);
    tempb0 = c12*tempb/temp24;
    tempb1 = tmp6*tmp13*tempb0;
    tmp13b = temp21*tmp6*tempb0 + tempb/temp22;
    tmp11b = tmp9*tempb1 - temp20*cos(tmp11)*tempb0;
    tmp9b = tmp11*tempb1;
    temp19 = sin(tmp3);
    tmp12b = cos(tmp12)*tmp13b;
    temp18 = cos(tmp1);
    tempb5 = c10*tmp12b/temp18;
    temp17 = sin(tmp4);
    tmp10b = cos(tmp10)*tempb5;
    temp16 = sin(tmp3);
    tmp8b = cos(tmp2)*c9*cos(tmp8)*tmp11b;
    temp15 = cos(tmp3);
    tmp7b = -(sin(tmp7)*tmp10b);
    temp14 = sin(tmp1);
    temp13 = cos(tmp5);
    temp12 = sin(tmp6);
    temp9 = temp12/temp13;
    temp11 = cos(tmp0);
    temp10 = sin(tmp1);
    tempb4 = temp10*temp11*tmp8b/temp13;
    tmp6b = cos(tmp6)*tmp9b - sin(tmp6)*tmp7b + cos(tmp6)*tempb4 + temp21*
        tmp13*tempb0;
    temp8 = sin(tmp5);
    tempb3 = c7*tmp7b/temp8;
    temp7 = cos(tmp5);
    tempb6 = c6*tmp6b/temp7;
    tmp5b = temp9*sin(tmp5)*tempb4 + sin(tmp2)*sin(tmp5)*tempb6/temp7 - cos(
        tmp0)*cos(tmp5)*tempb3/temp8 + cos(tmp5)*tmp10b/temp15;
    tmp4b = cos(tmp4)*tmp7b - sin(tmp2)*sin(tmp4)*tmp5b - c8*sin(tmp4)*tmp9b -
        cos(tmp0)*cos(tmp4)*tmp12b/(temp17*temp17);
    tmp3b = sin(tmp5)*sin(tmp3)*tmp10b/(temp15*temp15) - cos(tmp0)*cos(tmp3)*
        tmp6b/(temp6*temp6) - cos(tmp1)*cos(tmp3)*tmp4b/(temp5*temp5) - cos(
        tmp0)*cos(tmp3)*tmp11b/(temp16*temp16) - cos(tmp0)*cos(tmp3)*tmp13b/(
        temp19*temp19);
    tmp2b = cos(tmp2)*tmp10b + cos(tmp4)*cos(tmp2)*tmp5b + (sin(tmp2)*sin(tmp2
        )/(temp4*temp4)+cos(tmp2)/temp4)*tmp3b + (cos(tmp2)*cos(tmp2)/c5-sin(
        tmp2)*sin(tmp2)/c5)*tmp4b + cos(tmp2)*tempb6 - sin(tmp8)*c9*sin(tmp2)*
        tmp11b;
    tmp1b = cos(tmp0)*cos(tmp1)*tmp5b - cos(tmp0)*cos(tmp1)*tmp9b/(temp14*
        temp14) + (tmp0*cos(tmp1)+sin(tmp0))*tmp2b - sin(tmp1)*tmp4b/temp5 +
        temp11*temp9*cos(tmp1)*tmp8b + sin(tmp10)*sin(tmp1)*tempb5/temp18;
    temp3 = sin(tmp0);
    tempb2 = c4*tmp3b/temp3;
    tmp0b = (-(sin(tmp0)/temp19)-c11*sin(tmp0))*tmp13b - sin(tmp0)*tmp11b/
        temp16 - temp10*temp9*sin(tmp0)*tmp8b - sin(tmp0)*tmp6b/temp6 + (-(cos
        (tmp0)*cos(tmp0)/temp3)-sin(tmp0))*tempb2 + (sin(tmp1)+tmp1*cos(tmp0))
        *tmp2b - sin(tmp1)*sin(tmp0)*tmp5b - sin(tmp0)*tempb3 - sin(tmp0)*
        tmp9b/temp14 - sin(tmp0)*tmp12b/temp17 - tmp13*cos(tmp0)*tempb/(temp22
        *temp22);
    temp2 = cos(arg0);
    temp1 = sin(arg1);
    tempb7 = c3*tmp1b/temp2;
    temp0 = cos(arg1);
    temp = sin(arg0);
    tempb8 = c1*c2*tmp0b/temp0;
    *arg1b = *arg1b + arg0*temp*sin(arg1)*tempb8/temp0 + (arg1*cos(arg1)+temp1
        )*tempb7;
    *arg0b = *arg0b + (arg0*cos(arg0)+temp)*tempb8 + arg1*temp1*sin(arg0)*
        tempb7/temp2;


#undef LTYPE
#undef CTYPE
}


void eval(Terminal<A> const &arg0,
          Terminal<B> const &arg1,
          Result<R> &result)
{
#define LTYPE auto const
#define CTYPE auto const

  // test 1
  // auto const tmp0=2.0*arg0;
  // auto const tmp1=4.0*arg0;
  // auto const tmp2=tmp0+tmp1;
  // result = tmp2;

  // test 2
  // LTYPE tmp0=(arg0 * arg1);
  // LTYPE tmp1=(tmp0 + 6);
  // LTYPE tmp2=(tmp0 - 6);
  // result = tmp1 / tmp2;

  // test 3
  // auto t = cos(a)
  // z = (t + cos(b)) / t

  // test 4
  // LTYPE tmp0=(arg0 + arg1);
  // LTYPE tmp1=(tmp0 * tmp0);
  // LTYPE tmp2=(tmp1 + tmp0);
  // result = tmp2;

  // test 5
  // LTYPE tmp0=(-sin(arg0));
  // LTYPE tmp1=(-cos(tmp0));
  // LTYPE tmp2=(-sin(tmp1));
  // result = tmp2;

  // test 6
  // LTYPE tmp0 = (arg0 * double{5});
  // LTYPE tmp1 = (arg1 * double{6});
  // result = tmp0 + tmp1;

  // test 7
  // LTYPE tmp0 = (double{5} * arg0);
  // LTYPE tmp1 = (double{6} * arg1);
  // result = tmp0 + tmp1;

  // test 8
  // CTYPE c0 = UQ(double(1));
  // CTYPE c1 = UQ(double(2));
  // LTYPE tmp0=(c0 * arg0 * c1);
  // LTYPE tmp1=(arg1 + c0);
  // LTYPE tmp2=(-tmp0 + tmp1);
  // result = tmp2;

  // test 9
  // CTYPE c0 = UQ(double(5));
  // CTYPE c1 = UQ(double(6));
  // LTYPE tmp0=(c0 * arg0 * sin(arg0) / cos(arg1) * c1);
  // LTYPE tmp1=(arg1 * sin(arg1) / c0 * cos(arg0));
  // LTYPE tmp2=(sin(tmp0) * tmp1 + sin(tmp1) * tmp0);
  // LTYPE tmp3=(sin(tmp2) / cos(tmp2) * c1  + cos(tmp0) / sin(tmp0));
  // result = tmp3;

  // test 10
  // CTYPE c0 = UQ(bool(false));
  // LTYPE tmp0 = cond(c0, arg0 * arg0, arg1 * arg1);
  // result = tmp0;

  // test 11
  // CTYPE c0 = UQ(bool(true));
  // LTYPE tmp0 = cond(c0, arg0 * arg0, UQ(double(4)));
  // result = tmp0;

  // test 12
  // CTYPE c0 = UQ(bool(false));
  // LTYPE tmp0 = cond(c0, UQ(double(3)), arg1 * arg1);
  // result = tmp0;

  // largefunc
  CTYPE c1 = UQ(double(1));
  CTYPE c2 = UQ(double(2));
  CTYPE c3 = UQ(double(3));
  CTYPE c4 = UQ(double(4));
  CTYPE c5 = UQ(double(5));
  CTYPE c6 = UQ(double(6));
  CTYPE c7 = UQ(double(7));
  CTYPE c8 = UQ(double(8));
  CTYPE c9 = UQ(double(9));
  CTYPE c10 = UQ(double(10));
  CTYPE c11 = UQ(double(11));
  CTYPE c12 = UQ(double(12));
  LTYPE tmp0=(c1 * arg0 * sin(arg0) / cos(arg1) * c2);
  LTYPE tmp1=(arg1 * c3 * sin(arg1) / cos(arg0));
  LTYPE tmp2=(sin(tmp0) * tmp1 + sin(tmp1) * tmp0);
  LTYPE tmp3=(sin(tmp2) / cos(tmp2) + cos(tmp0) * c4 / sin(tmp0));
  LTYPE tmp4=(sin(tmp2) / c5 * cos(tmp2) + cos(tmp1) / sin(tmp3));
  LTYPE tmp5=(sin(tmp2) * cos(tmp4) + cos(tmp0) * sin(tmp1));
  LTYPE tmp6=(c6 * sin(tmp2) / cos(tmp5) + cos(tmp0) / sin(tmp3));
  LTYPE tmp7=(sin(tmp4) + cos(tmp6) + cos(tmp0) * c7 / sin(tmp5));
  LTYPE tmp8=(sin(tmp1) / cos(tmp5) * cos(tmp0) * sin(tmp6));
  LTYPE tmp9=(sin(tmp6) + c8 * cos(tmp4) + cos(tmp0) / sin(tmp1));
  LTYPE tmp10=(sin(tmp5) / cos(tmp3) + cos(tmp7) + sin(tmp2));
  LTYPE tmp11=(sin(tmp8) * c9 * cos(tmp2) + cos(tmp0) / sin(tmp3));
  LTYPE tmp12=(c10 * sin(tmp10) / cos(tmp1) + cos(tmp0) / sin(tmp4));
  LTYPE tmp13=(sin(tmp12) + cos(tmp0) * c11 + cos(tmp0) / sin(tmp3));
  LTYPE tmp14=(cos(tmp13 / sin(tmp0) + tmp6 / sin(tmp11) * c12 * tmp13 * tmp11 * tmp9));
  result = tmp14;

#undef LTYPE
#undef CTYPE
}


int main()
{
  {
    Terminal<A> const a(3);
    Terminal<B> const b(4);
    Result<R> r(0, 1);

    eval(a, b, r);
    std::cout << "r.pri: " << r.pri << std::endl;
    std::cout << "a.adj: " << a.adj << std::endl;
    std::cout << "b.adj: " << b.adj << std::endl;

    r.pri = 0; r.adj = 1; a.adj = 0; b.adj = 0;
    eval_ref(a.pri, &a.adj, b.pri, &b.adj, &r.pri, &r.adj);
    std::cout << "ref r.pri: " << r.pri << std::endl;
    std::cout << "ref a.adj: " << a.adj << std::endl;
    std::cout << "ref b.adj: " << b.adj << std::endl;
  }
  /*
  {
    using L = mp_list<mp_list<bool, char>, mp_list<int> >;
    using C = mp_cumulative<L>;
    std::cout << demangle<L>() << std::endl;
    std::cout << demangle<C>() << std::endl;
  }

  {
    using LS = mp_iota_v<3>;
    using S = std::make_index_sequence<3>;
    using C = mp_cumulative_impl<LS, S>::type;
    std::cout << demangle<C>() << std::endl;
  }

  {
    using T0 = std::integral_constant<std::size_t, 3>;
    using T1 = std::integral_constant<std::size_t, 2>;
    using T2 = std::integral_constant<std::size_t, 4>;
    using T3 = std::integral_constant<std::size_t, 1>;

    using L = mp_tuple<T0, T1, T2, T3>;
    using LR = mp_reverse<L>;

    std::cout << mp_tuple_get_t<0, LR>::value << std::endl;
    std::cout << mp_tuple_get_t<1, LR>::value << std::endl;
    // std::cout << mp_tuple_get_t<2, LR>::value << std::endl;
    // std::cout << mp_tuple_get_t<3, LR>::value << std::endl;

    std::cout << mp_tuple_get<0>(LR{}) << std::endl;
    std::cout << mp_tuple_get<1>(LR{}) << std::endl;
    std::cout << mp_tuple_get<2>(LR{}) << std::endl;
    std::cout << mp_tuple_get<3>(LR{}) << std::endl;
  }
  */
}
#endif


#ifndef LOCAL_TEST

// comment / uncomment
#define RT_TEST

#ifdef RT_TEST
static int const r_size = 10000;
static int const t_size = 250;
#else
static int const r_size = 1;
static int const t_size = 1;
#endif

static std::string name;
static std::map<std::string, std::vector<double> > timers;
static bool print_results = true;


#ifdef SMALLFUNC_UNIQ
#include "test/test_smallfunc.h"
int main()
{
  test_smallfunc(r_size, t_size);
}
#endif

#ifdef LARGEFUNC_UNIQ
#include "test/test_largefunc.h"
int main()
{
  test_largefunc(r_size, t_size);
}
#endif

#ifdef HARMONIC_UNIQ
#include "test/test_harmonic.h"
int main()
{
  test_harmonic(r_size, t_size);
}
#endif
#endif
