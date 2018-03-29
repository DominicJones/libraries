// -*- C++ -*-

#ifndef _Result_h_
#define _Result_h_


#include "util/AlwaysInline.h"
#include "util/mp_functions.h"


// primal_m
template<std::size_t I = 0, class N, class D, class L>
AlwaysInline inline typename std::enable_if<(I == N::value)>::type
evaluate_primal_m(N n, D &pri, L const &l) {}

template<std::size_t I = 0, class N, class D, class L>
AlwaysInline inline typename std::enable_if<(I < N::value)>::type
evaluate_primal_m(N n, D &pri, L const &l)
{
  using J = std::integral_constant<std::size_t, I>;
  mp_get_r<I>(l)->primal_m(pri, J{});
  evaluate_primal_m<I + 1>(n, pri, l);
}


// adjoint_m
template<std::size_t I = 0, class N, class D, class L>
AlwaysInline inline typename std::enable_if<(I == N::value)>::type
evaluate_adjoint_m(N n, D &adj, L const &l) {}

template<std::size_t I = 0, class N, class D, class L>
AlwaysInline inline typename std::enable_if<(I < N::value)>::type
evaluate_adjoint_m(N n, D &adj, L const &l)
{
  using J = std::integral_constant<std::size_t, I>;
  mp_get_r<I>(l)->adjoint_m(adj, J{});
  evaluate_adjoint_m<I + 1>(n, adj, l);
}




// primal_fn
template<std::size_t I = 0, class N, class D, class PV, class L, class IL, class IM, class IR, class IP>
AlwaysInline inline typename std::enable_if<(I == N::value)>::type
evaluate_primal_fn(N n, D &pri, PV const &pv, L l, IL il, IM im, IR ir, IP ip) {}

template<std::size_t I = 0, class N, class D, class PV, class L, class IL, class IM, class IR, class IP>
AlwaysInline inline typename std::enable_if<(I < N::value)>::type
evaluate_primal_fn(N n, D &pri, PV const &pv, L l, IL il, IM im, IR ir, IP ip)
{
  using J = std::integral_constant<std::size_t, I>;
  using T = mp_front<L>;
  using LN = mp_pop_front<L>;
  using JL = mp_front<IL>;
  using ILN = mp_pop_front<IL>;
  using JM = mp_front<IM>;
  using IMN = mp_pop_front<IM>;
  using JR = mp_front<IR>;
  using IRN = mp_pop_front<IR>;
  using JP = mp_front<IP>;
  using IPN = mp_pop_front<IP>;
  T::primal_fn(pri, pv, J{}, JL{}, JM{}, JR{}, JP{});
  evaluate_primal_fn<I + 1>(n, pri, pv, LN{}, ILN{}, IMN{}, IRN{}, IPN{});
}


// adjoint_fn
template<std::size_t I = 0, class N, class D, class PV, class L, class IL, class IM, class IR, class IP>
AlwaysInline inline typename std::enable_if<(I == N::value)>::type
evaluate_adjoint_fn(N n, D &pri, D &adj, PV const &pv, L l, IL il, IM im, IR ir, IP ip) {}

template<std::size_t I = 0, class N, class D, class PV, class L, class IL, class IM, class IR, class IP>
AlwaysInline inline typename std::enable_if<(I < N::value)>::type
evaluate_adjoint_fn(N n, D &pri, D &adj, PV const &pv, L l, IL il, IM im, IR ir, IP ip)
{
  using J = std::integral_constant<std::size_t, I>;
  using T = mp_front<L>;
  using LN = mp_pop_front<L>;
  using JL = mp_front<IL>;
  using ILN = mp_pop_front<IL>;
  using JM = mp_front<IM>;
  using IMN = mp_pop_front<IM>;
  using JR = mp_front<IR>;
  using IRN = mp_pop_front<IR>;
  using JP = mp_front<IP>;
  using IPN = mp_pop_front<IP>;
  evaluate_adjoint_fn<I + 1>(n, pri, adj, pv, LN{}, ILN{}, IMN{}, IRN{}, IPN{});
  T::adjoint_fn(pri, adj, pv, J{}, JL{}, JM{}, JR{}, JP{});
}


template<typename T>
struct Result
{
  using type = mp_type_of_t<T>;

  AlwaysInline inline Result(type const &pri, type const &adj)
    : pri(pri)
    , adj(adj)
  {}

  template<typename E>
  AlwaysInline inline void operator=(E const &e) const
  {
    using List_m = typename E::List_m;
    using List_fn_0 = mp_transform<std::remove_pointer_t, mp_rename<List_m, mp_list> >;
    using List_fn_1N = mp_drop_c<typename E::List_fn, 1>;
    using List_fn_0N = mp_append<mp_list<List_fn_0>, List_fn_1N>;
    using List_fn = mp_flatten<List_fn_0N>;
    using List_pv = typename E::List_pv;
    using List_pt = mp_rename<mp_transform<mp_type_of_t, List_pv>, mp_list>;
    constexpr int size_fn = mp_size<List_fn>::value;
    constexpr int size_m = mp_size<List_m>::value;

    // std::cout << "# inputs  " << mp_size<List_m>::value << std::endl;
    // std::cout << "# levels  " << mp_size<List_fn_1N>::value << std::endl;
    // std::cout << "# nodes   " << mp_size<List_fn>::value << std::endl;
    // std::cout << "# scalars " << mp_size<List_pv>::value << std::endl;

    using L = List_fn;
    using LL = mp_transform<mp_left, L>;
    using LM = mp_transform<mp_middle, L>;
    using LR = mp_transform<mp_right, L>;

    using _IP = mp_subgroup_find<List_pt, List_fn_0N>;
    using IP = mp_dual<_IP, size_fn>;

    using IL = mp_subgroup_find<LL, List_fn_0N>;
    using IM = mp_subgroup_find<LM, List_fn_0N>;
    using IR = mp_subgroup_find<LR, List_fn_0N>;

    using N = mp_size_t<size_fn>;
    using M = mp_size_t<size_m>;

    using Data_t = mp_transform<mp_type_of_t, mp_rename<List_fn, mp_tuple> >;
    Data_t pri;
    Data_t adj;

    {
      evaluate_primal_m(M{}, pri, e.list_m);
      evaluate_primal_fn(N{}, pri, e.list_pv, L{}, IL{}, IM{}, IR{}, IP{});
      this->pri = mp_get_v<(N::value - 1)>(pri);
    }

    {
      std::memset(&adj, 0, sizeof(adj));
      mp_get_r<(N::value - 1)>(adj) = this->adj;
      evaluate_adjoint_fn(N{}, pri, adj, e.list_pv, L{}, IL{}, IM{}, IR{}, IP{});
      evaluate_adjoint_m(M{}, adj, e.list_m);
    }
  }

  mutable type pri;
  mutable type adj;
};


#endif // _Result_h_
