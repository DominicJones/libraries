// -*- C++ -*-

#ifndef _Unary_h_
#define _Unary_h_


#include "expr/MathFn.h"

#include "util/AlwaysInline.h"
#include "util/mp_functions.h"


template<typename Fn, typename L>
struct Unary
  : std::integral_constant<int, (L::value + 1)>
{
  static std::string name()
  {
    return "(" + std::string(Fn::name()) + "" + std::string(L::name()) + ")";
  }

  using List_m = typename L::List_m;
  using List_fn = mp_append<typename L::List_fn, mp_list<mp_list<Unary> > >;
  using List_pv = typename L::List_pv;
  using L_type = typename L::type;
  using type = decltype(Fn::primal(L_type{}));

  AlwaysInlineCtor inline constexpr Unary(L const &l)
    : list_m(l.list_m)
    , list_pv(l.list_pv)
  {}

  template<class Pri, class PV, class I, class IL, class IM, class IR, class IP>
  AlwaysInline inline static void primal_fn(Pri &pri, PV const &pv, I, IL, IM, IR, IP)
  {
    auto constexpr i = I::value;
    auto constexpr il = IL::value;
    mp_get_r<i>(pri) = Fn::primal(mp_get_v<il>(pri));
  }

  template<class Pri, class Adj, class PV, class I, class IL, class IM, class IR, class IP>
  AlwaysInline inline static void adjoint_fn(Pri &pri, Adj &adj, PV const &pv, I, IL, IM, IR, IP)
  {
    auto constexpr i = I::value;
    auto constexpr il = IL::value;
    L_type nul_l; auto pri_l = mp_get_if<!Fn::is_trivial, il>::apply(pri, nul_l);
    Fn::adjoint(pri_l, mp_get_r<il>(adj), mp_get_v<i>(adj));
  }

  List_m const list_m;
  List_pv const list_pv;
};


#endif // _Unary_h_
