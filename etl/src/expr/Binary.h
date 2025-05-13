// -*- C++ -*-
#pragma once

#include "expr/MathFn.h"
#include "expr/Passive.h"
#include "expr/Unique.h"

#include "util/mp_functions.h"


template<typename Fn, typename L, typename R>
struct Binary
  : std::integral_constant<int, ((L::value > R::value? L::value: R::value) + 1)>
{
  static std::string name()
  {
    return "(" + std::string(Fn::name()) + "" + std::string(L::name()) + "" + std::string(R::name()) + ")";
  }

  using _L_m = typename L::List_m;
  using _R_m = typename R::List_m;
  using _swap_m = mp_swap<_L_m, _R_m>;
  using _LS_m = typename _swap_m::Left;
  using _RS_m = typename _swap_m::Right;
  using _List_m_l = mp_as_set<_LS_m>;
  using _List_m_r = mp_as_set<_RS_m>;
  using List_m = mp_rename<mp_insert_all<_List_m_l, _List_m_r>, mp_tuple>;
  using _List_m_u = mp_drop_c<List_m, mp_size<_LS_m>::value>;

  using _List_fn_l = mp_resize<Binary::value, typename L::List_fn, mp_list<> >;
  using _List_fn_r = mp_resize<Binary::value, typename R::List_fn, mp_list<> >;
  using _List_fn_lr = mp_uniq_merge<_List_fn_l, _List_fn_r>;
  using List_fn = mp_append<_List_fn_lr, mp_list<mp_list<Binary> > >;

  using _L_pv = typename L::List_pv;
  using _R_pv = typename R::List_pv;
  using _swap_pv = mp_swap<_L_pv, _R_pv>;
  using _LS_pv = typename _swap_pv::Left;
  using _RS_pv = typename _swap_pv::Right;
  using _List_pv_l = mp_as_set<_LS_pv>;
  using _List_pv_r = mp_as_set<_RS_pv>;
  using List_pv = mp_rename<mp_insert_all<_List_pv_l, _List_pv_r>, mp_tuple>;
  using _List_pv_u = mp_drop_c<List_pv, mp_size<_LS_pv>::value>;

  using L_type = typename L::type;
  using R_type = typename R::type;
  using type = decltype(Fn::primal(L_type{}, R_type{}));

  inline constexpr Binary(L const &l, R const &r)
    : list_m(mp_tuple_cat(_LS_m{_swap_m::left(l.list_m, r.list_m)}, mp_select_fn(_List_m_u{}, _swap_m::right(l.list_m, r.list_m))))
    , list_pv(mp_tuple_cat(_LS_pv{_swap_pv::left(l.list_pv, r.list_pv)}, mp_select_fn(_List_pv_u{}, _swap_pv::right(l.list_pv, r.list_pv))))
  {}

  template<class Pri, class PV, class I, class IL, class IM, class IR, class IP>
  inline static void primal_fn(Pri &pri, PV const &pv, I, IL, IM, IR, IP)
  {
    auto constexpr i = I::value;
    auto constexpr il = IL::value;
    auto constexpr im = IM::value;
    mp_get_r<i>(pri) = Fn::primal(mp_get_v<il>(pri), mp_get_v<im>(pri));
  }

  template<class Pri, class Adj, class PV, class I, class IL, class IM, class IR, class IP>
  inline static void adjoint_fn(Pri &pri, Adj &adj, PV const &pv, I, IL, IM, IR, IP)
  {
    auto constexpr i = I::value;
    auto constexpr il = IL::value;
    auto constexpr im = IM::value;
    L_type nul_l; auto pri_l = mp_get_if<!Fn::is_trivial, il>::apply(pri, nul_l);
    R_type nul_r; auto pri_r = mp_get_if<!Fn::is_trivial, im>::apply(pri, nul_r);
    Fn::adjoint(pri_l, mp_get_r<il>(adj), pri_r, mp_get_r<im>(adj), mp_get_v<i>(adj));
  }

  List_m const list_m;
  List_pv const list_pv;
};


template<typename Fn, typename L, std::size_t IPR, typename PR>
struct Binary<Fn, L, Unique<IPR, PR> >
  : std::integral_constant<int, (L::value + 1)>
{
  static std::string name()
  {
    return "(" + std::string(Fn::name()) + "" + std::string(L::name()) + "" + "{p}" + ")";
  }

  using List_m = typename L::List_m;
  using List_fn = mp_append<typename L::List_fn, mp_list<mp_list<Binary> > >;
  using List_pv = mp_append<typename L::List_pv, mp_tuple<Passive<Binary, PR> > >;
  using L_type = typename L::type;
  using R_type = PR;
  using type = decltype(Fn::primal(L_type{}, R_type{}));

  inline constexpr Binary(L const &l, Unique<IPR, R_type> const &r)
    : list_m(l.list_m)
    , list_pv(mp_tuple_cat(l.list_pv, mp_tuple<Passive<Binary, PR> >{Passive<Binary, R_type>{r.value}}))
  {}

  template<class Pri, class PV, class I, class IL, class IM, class IR, class IP>
  inline static void primal_fn(Pri &pri, PV const &pv, I, IL, IM, IR, IP)
  {
    auto constexpr i = I::value;
    auto constexpr il = IL::value;
    auto constexpr ip = IP::value;
    auto const pvr = mp_get_v<ip>(pv).value;
    mp_get_r<i>(pri) = Fn::primal(mp_get_v<il>(pri), pvr);
  }

  template<class Pri, class Adj, class PV, class I, class IL, class IM, class IR, class IP>
  inline static void adjoint_fn(Pri &pri, Adj &adj, PV const &pv, I, IL, IM, IR, IP)
  {
    auto constexpr i = I::value;
    auto constexpr il = IL::value;
    auto constexpr ip = IP::value;
    L_type nul_l; auto pri_l = mp_get_if<!Fn::is_trivial, il>::apply(pri, nul_l);
    auto const pvr = mp_get_v<ip>(pv).value;
    R_type nul;
    Fn::adjoint(pri_l, mp_get_r<il>(adj), pvr, nul, mp_get_v<i>(adj));
  }

  List_m const list_m;
  List_pv const list_pv;
};


template<typename Fn, std::size_t IPL, typename PL, typename R>
struct Binary<Fn, Unique<IPL, PL>, R>
  : std::integral_constant<int, (R::value + 1)>
{
  static std::string name()
  {
    return "(" + std::string(Fn::name()) + "" + "{p}" + "" + std::string(R::name()) + ")";
  }

  using List_m = typename R::List_m;
  using List_fn = mp_append<typename R::List_fn, mp_list<mp_list<Binary> > >;
  using List_pv = mp_append<typename R::List_pv, mp_tuple<Passive<Binary, PL> > >;
  using L_type = PL;
  using R_type = typename R::type;
  using type = decltype(Fn::primal(L_type{}, R_type{}));

  inline constexpr Binary(Unique<IPL, L_type> const &l, R const &r)
    : list_m(r.list_m)
    , list_pv(mp_tuple_cat(r.list_pv, mp_tuple<Passive<Binary, PL> >{Passive<Binary, L_type>{l.value}}))
  {}

  template<class Pri, class PV, class I, class IL, class IM, class IR, class IP>
  inline static void primal_fn(Pri &pri, PV const &pv, I, IL, IM, IR, IP)
  {
    auto constexpr i = I::value;
    auto constexpr im = IM::value;
    auto constexpr ip = IP::value;
    auto const pvl = mp_get_v<ip>(pv).value;
    mp_get_r<i>(pri) = Fn::primal(pvl, mp_get_v<im>(pri));
  }

  template<class Pri, class Adj, class PV, class I, class IL, class IM, class IR, class IP>
  inline static void adjoint_fn(Pri &pri, Adj &adj, PV const &pv, I, IL, IM, IR, IP)
  {
    auto constexpr i = I::value;
    auto constexpr im = IM::value;
    auto constexpr ip = IP::value;
    auto const pvl = mp_get_v<ip>(pv).value;
    L_type nul;
    R_type nul_r; auto pri_r = mp_get_if<!Fn::is_trivial, im>::apply(pri, nul_r);
    Fn::adjoint(pvl, nul, pri_r, mp_get_r<im>(adj), mp_get_v<i>(adj));
  }

  List_m const list_m;
  List_pv const list_pv;
};
