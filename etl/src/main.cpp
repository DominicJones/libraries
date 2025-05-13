#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <functional>
#include <utility>
#include <tuple>
#include <map>
#include <cmath>

#include "expr/mathop.h"
#include "expr/MathFn.h"
#include "expr/Terminal.h"
#include "expr/Unary.h"
#include "expr/Binary.h"
#include "expr/Result.h"
#include "expr/Unique.h"


// Identifiers
struct A { static char const * name() { return "A"; }; using type = double; };
struct B { static char const * name() { return "B"; }; using type = double; };
struct C { static char const * name() { return "C"; }; using type = double; };
struct D { static char const * name() { return "D"; }; using type = double; };
struct E { static char const * name() { return "E"; }; using type = double; };
struct R { static char const * name() { return "R"; }; using type = double; };


void eval(Terminal<A> const &arg0,
          Terminal<B> const &arg1,
          Result<R> &result)
{
  auto const c0 = UQ(double(5));
  auto const c1 = UQ(double(6));
  auto const tmp0=(c0 * arg0 * c1);
  auto const tmp1=(arg1 / (c0 + c1));
  auto const tmp2=(-tmp0 + tmp1);
  result = tmp2;
}


// testing
template<auto value> using UC = std::integral_constant<std::size_t, value>;
template<auto value> using IC = std::integral_constant<int, value>;
template<typename T> struct debug_type;


int main()
{
  // testing
  {
    using I = mp_list<UC<3>,UC<4>>;
    using O = mp_dual<I,6>;
    using E = mp_list<UC<2>,UC<2>,UC<2>,UC<0>,UC<1>,UC<2>>;
    static_assert(std::is_same_v<O, E>);
  }

  {
    Terminal<A> const a(3);
    Terminal<B> const b(4);
    Result<R> r(0, 1);

    eval(a, b, r);

    std::cout << "r.pri: " << r.pri << std::endl;
    std::cout << "a.adj: " << a.adj << std::endl;
    std::cout << "b.adj: " << b.adj << std::endl;
  }
}
