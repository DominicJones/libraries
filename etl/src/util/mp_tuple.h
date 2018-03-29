// -*- C++ -*-

#ifndef _mp_tuple_h_
#define _mp_tuple_h_


// #define USE_STD_TUPLE

#ifdef USE_STD_TUPLE

#include <tuple>
template<typename... Ts> using mp_tuple = std::tuple<Ts...>;

template<std::size_t idx, typename... Ts> AlwaysInline inline constexpr decltype(auto) mp_get_v(mp_tuple<Ts...> const &t) { return std::get<idx>(t); }
template<std::size_t idx, typename... Ts> AlwaysInline inline constexpr decltype(auto) mp_get_r(mp_tuple<Ts...> const &t) { return(std::get<idx>(t)); }
template<std::size_t idx, typename... Ts> AlwaysInline inline constexpr decltype(auto) mp_get_r(mp_tuple<Ts...> &t) { return(std::get<idx>(t)); }

#else

#include "AlwaysInline.h"


// mp_tuple
template<std::size_t idx, typename... Ts>
struct mp_tuple_impl;

template<std::size_t idx>
struct mp_tuple_impl<idx>
{};

template<std::size_t idx, typename T1, typename... Ts>
struct mp_tuple_impl<idx, T1, Ts...>
  : mp_tuple_impl<idx + 1, Ts...>
{
  using base_t = mp_tuple_impl<idx + 1, Ts...>;

  AlwaysInline inline constexpr mp_tuple_impl() : base_t() {}

  AlwaysInline inline constexpr mp_tuple_impl(T1 value, Ts... values)
    : value(value)
    , base_t(values...)
  {}

  T1 value;
};

template<typename... Ts>
struct mp_tuple
  : mp_tuple_impl<0, Ts...>
{
  using base_t = mp_tuple_impl<0, Ts...>;
  AlwaysInline inline constexpr mp_tuple() : base_t() {}
  AlwaysInline inline constexpr mp_tuple(Ts... values) : base_t(values...) {}
};

template<>
struct mp_tuple<>
{
  AlwaysInline inline constexpr mp_tuple() {}
};


// mp_tuple_element
template<std::size_t idx, typename _Tp>
struct mp_tuple_element;

template<std::size_t idx, typename T1, typename... Ts>
struct mp_tuple_element<idx, mp_tuple<T1, Ts...> >
  : mp_tuple_element<idx - 1, mp_tuple<Ts...> >
{};

template<typename T1, typename... Ts>
struct mp_tuple_element<0, mp_tuple<T1, Ts...> >
{
  using type = T1;
};


// mp_get_v
template<std::size_t idx, typename T1, typename... Ts>
AlwaysInline inline constexpr T1 mp_get_v_impl(mp_tuple_impl<idx, T1, Ts...> const &t)
{
  return t.value;
}

template<std::size_t idx, typename... Ts>
AlwaysInline inline constexpr typename mp_tuple_element<idx, mp_tuple<Ts...> >::type
mp_get_v(mp_tuple<Ts...> const &t)
{
  return mp_get_v_impl<idx>(t);
}


// mp_get_r [non-const]
template<std::size_t idx, typename T1, typename... Ts>
AlwaysInline inline constexpr T1 &mp_get_r_impl(mp_tuple_impl<idx, T1, Ts...> &t)
{
  return t.value;
}

template<std::size_t idx, typename... Ts>
AlwaysInline inline constexpr typename mp_tuple_element<idx, mp_tuple<Ts...> >::type &
mp_get_r(mp_tuple<Ts...> &t)
{
  return mp_get_r_impl<idx>(t);
}


// mp_get_r [const]
template<std::size_t idx, typename T1, typename... Ts>
AlwaysInline inline constexpr T1 const &mp_get_r_impl(mp_tuple_impl<idx, T1, Ts...> const &t)
{
  return t.value;
}

template<std::size_t idx, typename... Ts>
AlwaysInline inline constexpr typename mp_tuple_element<idx, mp_tuple<Ts...> >::type const &
mp_get_r(mp_tuple<Ts...> const &t)
{
  return mp_get_r_impl<idx>(t);
}

#endif

#endif // _mp_tuple_h_
