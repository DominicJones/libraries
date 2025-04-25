// -*- C++ -*-
#pragma once

#include "util/mp_functions.h"


template<typename T>
struct Terminal
  : std::integral_constant<int, 0>
{
  static std::string name()
  {
    return "(" + std::string(T::name()) + ")";
  }

  using type = mp_type_of_t<T>;
  using List_m = mp_tuple<Terminal*>;
  using List_fn = mp_list<mp_list<> >;
  using List_pv = mp_tuple<>;

  inline constexpr Terminal(type const &pri, type &adj)
    : pri(pri)
    , adj(0)
    , list_m(this)
    , list_pv()
  {}

  inline constexpr Terminal(type const &pri)
    : pri(pri)
    , adj(0)
    , list_m(this)
    , list_pv()
  {}

  inline constexpr Terminal()
    : pri(0)
    , adj(0)
    , list_m(this)
    , list_pv()
  {}

  template<class Pri, class I>
  inline void primal_m(Pri &pri, I) const
  {
    auto constexpr i = I::value;
    mp_get_r<i>(pri) = this->pri;
  }

  template<class Adj, class I>
  inline void adjoint_m(Adj &adj, I) const
  {
    auto constexpr i = I::value;
    this->adj = mp_get_v<i>(adj);
  }

  template<class Pri, class PV, class I, class IL, class IM, class IR, class IP>
  inline static void primal_fn(Pri &pri, PV const &pv, I, IL, IM, IR, IP) {}

  template<class Pri, class Adj, class PV, class I, class IL, class IM, class IR, class IP>
  inline static void adjoint_fn(Pri &pri, Adj &adj, PV const &pv, I, IL, IM, IR, IP) {}

  type mutable pri;
  type mutable adj;
  List_m const list_m;
  List_pv const list_pv;
};
