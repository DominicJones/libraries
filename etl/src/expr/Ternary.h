// -*- C++ -*-

#ifndef _Ternary_h_
#define _Ternary_h_


#include "expr/MathFn.h"
#include "expr/Passive.h"
#include "expr/Unique.h"

#include "util/AlwaysInline.h"
#include "util/mp_functions.h"


template<typename Fn, typename L, typename M, typename R>
struct Ternary;


/*
 * Note: First operand treated as passive for all specialisations
 */


template<typename Fn, std::size_t IPC, typename PC, typename L, typename R>
struct Ternary<Fn, Unique<IPC, PC>, L, R>
  : std::integral_constant<int, ((L::value > R::value? L::value: R::value) + 1)>
{
  static std::string name()
  {
    return "(" + std::string(Fn::name()) + "{p}" + std::string(L::name()) + std::string(R::name()) + ")";
  }

  using C_type = PC;
  using L_type = typename L::type;
  using R_type = typename R::type;
  using type = decltype(Fn::primal(C_type{}, L_type{}, R_type{}));

  using _L_m = typename L::List_m;
  using _R_m = typename R::List_m;
  using _swap_m = mp_swap<_L_m, _R_m>;
  using _LS_m = typename _swap_m::Left;
  using _RS_m = typename _swap_m::Right;
  using _List_m_l = brigand::as_set<_LS_m>;
  using _List_m_r = brigand::as_set<_RS_m>;
  using List_m = mp_rename<mp_insert_all<_List_m_l, _List_m_r>, std::tuple>;
  using _List_m_u = mp_drop_c<List_m, mp_size<_LS_m>::value>;

  using _List_fn_l = mp_resize<Ternary::value, typename L::List_fn, mp_list<> >;
  using _List_fn_r = mp_resize<Ternary::value, typename R::List_fn, mp_list<> >;
  using _List_fn_lr = mp_uniq_merge<_List_fn_l, _List_fn_r>;
  using List_fn = mp_append<_List_fn_lr, mp_list<mp_list<Ternary> > >;

  using _L_pv = typename L::List_pv;
  using _R_pv = typename R::List_pv;
  using _swap_pv = mp_swap<_L_pv, _R_pv>;
  using _LS_pv = typename _swap_pv::Left;
  using _RS_pv = typename _swap_pv::Right;
  using _List_pv_l = brigand::as_set<_LS_pv>;
  using _List_pv_r = brigand::as_set<_RS_pv>;
  using _List_pv = mp_rename<mp_insert_all<_List_pv_l, _List_pv_r>, std::tuple>;
  using _List_pv_u = mp_drop_c<_List_pv, mp_size<_LS_pv>::value>;
  using List_pv = mp_append<_List_pv, std::tuple<Passive<Ternary, C_type> > >;

  AlwaysInline inline constexpr Ternary(Unique<IPC, C_type> const &c, L const &l, R const &r)
    : list_m(std::tuple_cat(_LS_m{_swap_m::left(l.list_m, r.list_m)}, mp_select_fn(_List_m_u{}, _swap_m::right(l.list_m, r.list_m))))
    , list_pv(std::tuple_cat(_LS_pv{_swap_pv::left(l.list_pv, r.list_pv)}, mp_select_fn(_List_pv_u{}, _swap_pv::right(l.list_pv, r.list_pv)),
                             std::make_tuple(Passive<Ternary, C_type>{c.value})))
  {}

  template<class Pri, class PV, class I, class IL, class IM, class IR, class IP>
  AlwaysInline inline static void primal_fn(Pri &pri, PV const &pv, I, IL, IM, IR, IP)
  {
    auto constexpr i = I::value;
    auto constexpr ip = IP::value;
    auto constexpr im = IM::value;
    auto constexpr ir = IR::value;
    auto const pvl = std::get<ip>(pv).value;
    std::get<i>(pri) = Fn::primal(pvl, std::get<im>(pri), std::get<ir>(pri));
  }

  template<class Pri, class Adj, class PV, class I, class IL, class IM, class IR, class IP>
  AlwaysInline inline static void adjoint_fn(Pri &pri, Adj &adj, PV const &pv, I, IL, IM, IR, IP)
  {
    auto constexpr i = I::value;
    auto constexpr ip = IP::value;
    auto constexpr im = IM::value;
    auto constexpr ir = IR::value;
    auto const pvl = std::get<ip>(pv).value;
    C_type nul_l;
    L_type nul_m; auto pri_m = mp_get_if<!Fn::is_trivial, im>::apply(pri, nul_m);
    R_type nul_r; auto pri_r = mp_get_if<!Fn::is_trivial, ir>::apply(pri, nul_r);
    Fn::adjoint(pvl, nul_l, pri_m, std::get<im>(adj), pri_r, std::get<ir>(adj), std::get<i>(adj));
  }

  List_m const list_m;
  List_pv const list_pv;
};


template<typename Fn, std::size_t IPC, typename PC, typename L, std::size_t IPR, typename PR>
struct Ternary<Fn, Unique<IPC, PC>, L, Unique<IPR, PR> >
  : std::integral_constant<int, (L::value + 1)>
{
  static std::string name()
  {
    return "(" + std::string(Fn::name()) + "{p}" + std::string(L::name()) + "{p}" + ")";
  }

  using C_type = PC;
  using L_type = typename L::type;
  using R_type = PR;
  using type = decltype(Fn::primal(C_type{}, L_type{}, R_type{}));

  using List_m = typename L::List_m;
  using List_fn = mp_append<typename L::List_fn, mp_list<mp_list<Ternary> > >;
  using List_pv = mp_append<typename L::List_pv, std::tuple<Passive<Ternary, std::tuple<C_type, R_type> > > >;

  AlwaysInline inline constexpr Ternary(Unique<IPC, C_type> const &c, L const &l, Unique<IPR, R_type> const &r)
    : list_m(l.list_m)
    , list_pv(std::tuple_cat(l.list_pv, std::make_tuple(Passive<Ternary, std::tuple<C_type, R_type> >{std::tuple<C_type, R_type>{c.value, r.value}})))
  {}

  template<class Pri, class PV, class I, class IL, class IM, class IR, class IP>
  AlwaysInline inline static void primal_fn(Pri &pri, PV const &pv, I, IL, IM, IR, IP)
  {
    auto constexpr i = I::value;
    auto constexpr im = IM::value;
    auto constexpr ip = IP::value;
    auto const pvi = std::get<ip>(pv);
    auto const pvl = std::get<0>(pvi.value);
    auto const pvr = std::get<1>(pvi.value);
    std::get<i>(pri) = Fn::primal(pvl, std::get<im>(pri), pvr);
  }

  template<class Pri, class Adj, class PV, class I, class IL, class IM, class IR, class IP>
  AlwaysInline inline static void adjoint_fn(Pri &pri, Adj &adj, PV const &pv, I, IL, IM, IR, IP)
  {
    auto constexpr i = I::value;
    auto constexpr im = IM::value;
    auto constexpr ip = IP::value;
    auto const pvi = std::get<ip>(pv);
    auto const pvl = std::get<0>(pvi.value);
    auto const pvr = std::get<1>(pvi.value);
    C_type nul_l;
    L_type nul_m; auto pri_m = mp_get_if<!Fn::is_trivial, im>::apply(pri, nul_m);
    R_type nul_r;
    Fn::adjoint(pvl, nul_l, pri_m, std::get<im>(adj), pvr, nul_r, std::get<i>(adj));
  }

  List_m const list_m;
  List_pv const list_pv;
};


template<typename Fn, std::size_t IPC, typename PC, std::size_t IPL, typename PL, typename R>
struct Ternary<Fn, Unique<IPC, PC>, Unique<IPL, PL>, R>
  : std::integral_constant<int, (R::value + 1)>
{
  static std::string name()
  {
    return "(" + std::string(Fn::name()) + "{p}" + "{p}" + "" + std::string(R::name()) + ")";
  }

  using C_type = PC;
  using L_type = PL;
  using R_type = typename R::type;
  using type = decltype(Fn::primal(C_type{}, L_type{}, R_type{}));

  using List_m = typename R::List_m;
  using List_fn = mp_append<typename R::List_fn, mp_list<mp_list<Ternary> > >;
  using List_pv = mp_append<typename R::List_pv, std::tuple<Passive<Ternary, std::tuple<C_type, L_type> > > >;

  AlwaysInline inline constexpr Ternary(Unique<IPC, C_type> const &c, Unique<IPL, L_type> const &l, R const &r)
    : list_m(r.list_m)
    , list_pv(std::tuple_cat(r.list_pv, std::make_tuple(Passive<Ternary, std::tuple<C_type, R_type> >{std::tuple<C_type, L_type>{c.value, l.value}})))
  {}

  template<class Pri, class PV, class I, class IL, class IM, class IR, class IP>
  AlwaysInline inline static void primal_fn(Pri &pri, PV const &pv, I, IL, IM, IR, IP)
  {
    auto constexpr i = I::value;
    auto constexpr ir = IR::value;
    auto constexpr ip = IP::value;
    auto const pvi = std::get<ip>(pv);
    auto const pvl = std::get<0>(pvi.value);
    auto const pvm = std::get<1>(pvi.value);
    std::get<i>(pri) = Fn::primal(pvl, pvm, std::get<ir>(pri));
  }

  template<class Pri, class Adj, class PV, class I, class IL, class IM, class IR, class IP>
  AlwaysInline inline static void adjoint_fn(Pri &pri, Adj &adj, PV const &pv, I, IL, IM, IR, IP)
  {
    auto constexpr i = I::value;
    auto constexpr ir = IR::value;
    auto constexpr ip = IP::value;
    auto const pvi = std::get<ip>(pv);
    auto const pvl = std::get<0>(pvi.value);
    auto const pvm = std::get<1>(pvi.value);
    C_type nul_l;
    L_type nul_m;
    R_type nul_r; auto pri_r = mp_get_if<!Fn::is_trivial, ir>::apply(pri, nul_r);
    Fn::adjoint(pvl, nul_l, pvm, nul_m, pri_r, std::get<ir>(adj), std::get<i>(adj));
  }

  List_m const list_m;
  List_pv const list_pv;
};


#endif // _Ternary_h_
