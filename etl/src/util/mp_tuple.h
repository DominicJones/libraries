// -*- C++ -*-
#pragma once

#include <tuple>

template<typename... Ts> using mp_tuple = std::tuple<Ts...>;

template<std::size_t idx, typename... Ts> inline constexpr decltype(auto) mp_get_v(mp_tuple<Ts...> const &t) { return std::get<idx>(t); }
template<std::size_t idx, typename... Ts> inline constexpr decltype(auto) mp_get_r(mp_tuple<Ts...> const &t) { return(std::get<idx>(t)); }
template<std::size_t idx, typename... Ts> inline constexpr decltype(auto) mp_get_r(mp_tuple<Ts...> &t) { return(std::get<idx>(t)); }
