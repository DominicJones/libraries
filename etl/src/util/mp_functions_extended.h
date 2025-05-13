// -*- C++ -*-
#pragma once


// mp_type_of
template<class T> struct mp_type_of
{
  using type = typename T::type;
};

template<class T> using mp_type_of_t = typename mp_type_of<T>::type;


// mp_sizeof
template<class T> struct mp_sizeof
{
  using type = std::integral_constant<std::size_t, sizeof(T)>;
};

template<class T> using mp_sizeof_t = typename mp_sizeof<T>::type;


// mp_reverse
/*
template<class L>
struct mp_reverse_impl;

template<template<class...> class L>
struct mp_reverse_impl<L<>>
{
  using type = L<>;
};

template<template<class...> class L, typename T1, typename... T>
struct mp_reverse_impl<L<T1, T...>>
{
  using _head = L<T1>;
  using _tail = typename mp_reverse_impl<L<T...> >::type;
  using type = mp_append<_tail, _head>;
};

template<class L> using mp_reverse = typename mp_reverse_impl<L>::type;
*/
template<class L> using mp_reverse = brigand::reverse<L>;


// mp_get
template<std::size_t N, class T, class... Args>
struct mp_get_impl
{
  static constexpr auto value = N;
};

template<std::size_t N, class T, class... Args>
struct mp_get_impl<N, T, T, Args...>
{
  static constexpr auto value = N;
};

template<std::size_t N, class T, class U, class... Args>
struct mp_get_impl<N, T, U, Args...>
{
  static constexpr auto value = mp_get_impl<N + 1, T, Args...>::value;
};

template<class T, class... Args>
T mp_get(const mp_tuple<Args...>& t)
{
  std::size_t constexpr I = mp_get_impl<0, T, Args...>::value;
  return mp_get_v<I>(t);
}


// mp_get_left
template<std::size_t I>
struct mp_get_left
{
  template<class T,
           template<class...> class L0, class... T0s,
           template<class...> class L1, class... T1s>
  static T get(L0<T0s...> l0, L1<T1s...> l1)
  {
    std::size_t constexpr I0 = I;
    return mp_get_v<I0>(l0);
  }
};


// mp_get_right
template<std::size_t I>
struct mp_get_right
{
  template<class T,
           template<class...> class L0, class... T0s,
           template<class...> class L1, class... T1s>
  static T get(L0<T0s...> l0, L1<T1s...> l1)
  {
    std::size_t constexpr I0 = mp_get_impl<0, T, T1s...>::value;
    return mp_get_v<I0>(l1);
  }
};


// mp_get_pair
template<class T, class... T0s, class... T1s>
T mp_get_pair(mp_tuple<T0s...> t0, mp_tuple<T1s...> t1)
{
  std::size_t constexpr I0 = mp_get_impl<0, T, T0s...>::value;
  std::size_t constexpr N0 = sizeof...(T0s);
  return mp_if_c<I0 != N0, mp_get_left<I0>, mp_get_right<0> >::template get<T>(t0, t1);
}


// mp_merge
template<class L1, class L2>
struct mp_merge_impl;

template<class L1, class L2> using mp_merge = typename mp_merge_impl<L1, L2>::type;

template<template<class...> class L1, class... T1, template<class...> class L2, class... T2>
struct mp_merge_impl<L1<T1...>, L2<T2...> >
{
  using type = L1<mp_append<T1, T2>... >;
};


// mp_flatten
/*
template<class L>
struct mp_flatten_impl;

template<template<class...> class L, class... T>
struct mp_flatten_impl<L<T...> >
{
  using type = mp_append<T...>;
};

template<class L> using mp_flatten = typename mp_flatten_impl<L>::type;
*/
template<class L> using mp_flatten = brigand::flatten<L>;


// mp_match
template<class T> struct mp_match { using type = T; };
template<class T> using mp_match_t = typename mp_match<T>::type;


// mp_find_map_key
template<int I, typename T, typename L, typename H>
struct mp_find_map_key_impl;

template<int I, typename T, template<class...> class L, template<class...> class H, typename... HIs>
struct mp_find_map_key_impl<I, T, L<>, H<HIs...> >
{
  static constexpr auto value = I;
  using type = H<HIs...>;
};

template<int I, template<class...> class L, typename T, typename... Us, typename... Ts, template<class...> class H, typename... HIs>
struct mp_find_map_key_impl<I, T, L<mp_tuple<mp_identity<T>, Us...>, Ts...>, H<HIs...> >
{
  static constexpr auto value = I - (1 + sizeof...(Ts));
  using type = mp_append<H<HIs...>, L<mp_tuple<mp_identity<mp_match<T> >, Us...>, Ts...> >;
};

template<int I, typename T, template<class...> class L, typename U, typename... Us, typename... Ts, template<class...> class H, typename... HIs>
struct mp_find_map_key_impl<I, T, L<mp_tuple<mp_identity<U>, Us...>, Ts...>, H<HIs...> >
  : mp_find_map_key_impl<I, T, L<Ts...>, mp_append<H<HIs...>, L<mp_tuple<mp_identity<U>, Us...> > > >
{};

template<class T, class L> using mp_find_map_key = mp_find_map_key_impl<mp_size<L>::value, T, L, mp_list<> >;


// mp_insert_all
template<class S, class L> struct mp_insert_all_impl;

template<class S, class L> using mp_insert_all = typename mp_insert_all_impl<S, L>::type;

template<class S, template<class...> class L> struct mp_insert_all_impl<S, L<> >
{
  using type = S;
};

template<class S, template<class...> class L, class T1, class... T>
struct mp_insert_all_impl<S, L<T1, T...> >
{
  using _S1 = brigand::insert<S, T1>;
  using type = mp_insert_all<_S1, L<T...> >;
};


// mp_uniq_merge
template<class L1, class L2>
struct mp_uniq_merge_impl;

template<class L1, class L2> using mp_uniq_merge = typename mp_uniq_merge_impl<L1, L2>::type;

template<template<class...> class L1, class... T1, template<class...> class L2, class... T2>
struct mp_uniq_merge_impl<L1<T1...>, L2<T2...> >
{
  using type = L1<brigand::as_list<mp_insert_all<brigand::as_set<T1>, brigand::as_set<T2> > >... >;
};


// mp_resize
template<std::size_t N, class L, class T>
struct mp_resize_lazy_impl
{
  using type = mp_append<L, mp_fill<mp_iota_v<N>, T> >;
};

template<std::size_t N, class L, class T>
struct mp_resize_impl
{
  static std::size_t constexpr _NL = {mp_size<L>::value};
  static std::size_t constexpr _M = {N - _NL};
  using type = typename mp_if_c<bool(N > _NL), mp_resize_lazy_impl<_M, L, T>, mp_identity<L> >::type;
};

template<std::size_t N, class L, class T> using mp_resize = typename mp_resize_impl<N, L, T>::type;


// mp_select
template<template<class...> class LR, class... TR, template<class...> class L, class... T>
LR<TR...> mp_select_fn_impl(LR<TR...> lr, L<T...> l)
{
  return LR<TR...>{mp_get<TR>(l)...};
}

template<class R, class L>
R mp_select_fn(R r, L l)
{
  return mp_select_fn_impl(r, l);
}


// mp_cumulative
template<class L, class S>
struct mp_cumulative_impl;

template<class L, template<class _SX, _SX...> class S, class ST, ST... SVs>
struct mp_cumulative_impl<L, S<ST, SVs...> >
{
  using LR = mp_reverse<L>;
  using LC = mp_list<std::integral_constant<std::size_t, mp_apply<mp_plus, mp_drop_c<LR, SVs> >::value>...>;
  using type = mp_reverse<LC>;
};

template<class L>
struct mp_cumulative_entry
{
  static auto constexpr v = mp_size<L>::value;
  using S = std::make_index_sequence<v>;
  using LS = mp_transform<mp_size, L>;
  using type = typename mp_cumulative_impl<LS, S>::type;
};

template<class L> using mp_cumulative = typename mp_cumulative_entry<L>::type;


// mp_subgroup_find
template<class M, class L, class C, std::size_t NI> struct mp_subgroup_find_impl;

template<template<class...> class M, class L, class C, std::size_t NI>
struct mp_subgroup_find_impl<M<>, L, C, NI>
{
  using type = mp_list<>;
};

template<template<class...> class M, class... Us, class L, class C, std::size_t NI>
struct mp_subgroup_find_impl<M<mp_void, Us...>, L, C, NI>
{
  using _head = std::integral_constant<std::size_t, NI>;
  using _tail = typename mp_subgroup_find_impl<M<Us...>, L, C, NI>::type;
  using type = mp_append<mp_list<_head>, _tail>;
};

template<template<class...> class M, class U, class... Us, class L, class C, std::size_t NI>
struct mp_subgroup_find_impl<M<U, Us...>, L, C, NI>
{
  auto static constexpr depth = U::value;
  using SL = mp_at_c<L, depth>;

  auto static constexpr base = mp_at_c<C, depth>::value;
  auto static constexpr position = mp_find<U, SL>::value;
  auto static constexpr offset = std::size_t{base + position};

  using _head = std::integral_constant<std::size_t, offset>;
  using _tail = typename mp_subgroup_find_impl<M<Us...>, L, C, NI>::type;
  using type = mp_append<mp_list<_head>, _tail>;
};

template<class M, class L>
struct mp_subgroup_find_entry
{
  static auto constexpr NI = mp_size<mp_flatten<L> >::value;
  using LE = mp_push_front<L, mp_list<> >;
  using C = mp_cumulative<LE>;
  using type = typename mp_subgroup_find_impl<M, L, C, NI>::type;
};

template<class M, class L> using mp_subgroup_find = typename mp_subgroup_find_entry<M, L>::type;


// mp_incr
template<typename T0, typename T1>
using mp_incr = brigand::bool_<(T0::value < T1::value)>;


// mp_map_incr
template<typename T0, typename T1>
using mp_map_incr = brigand::bool_<(mp_first<T0>::value < mp_first<T1>::value)>;


// mp_swap (if L < R)
template<class L, class R, bool swap>
struct mp_swap_impl
{
  using Left = L;
  using Right = R;
  inline static Left left(L const &l, R const &r) { return l; }
  inline static Right right(L const &l, R const &r) { return r; }
};

template<class L, class R>
struct mp_swap_impl<L, R, true>
{
  using Left = R;
  using Right = L;
  inline static Left left(L const &l, R const &r) { return r; }
  inline static Right right(L const &l, R const &r) { return l; }
};

template<class L, class R>
struct mp_swap
{
  static bool constexpr _swap = mp_size<L>::value < mp_size<R>::value;
  using _impl = mp_swap_impl<L, R, _swap>;
  using Left = typename _impl::Left;
  using Right = typename _impl::Right;
  inline static Left left(L const &l, R const &r) { return _impl::left(l, r); }
  inline static Right right(L const &l, R const &r) { return _impl::right(l, r); }
};


// mp_get_if
template<bool c, std::size_t i>
struct mp_get_if
{
  template<typename L, typename T>
  inline static T &apply(L &l, T &) { return mp_get_r<i>(l); }
};

template<std::size_t i>
struct mp_get_if<false, i>
{
  template<typename L, typename T>
  inline static T &apply(L &, T &nul) { return nul; }
};
