// -*- C++ -*-
#pragma once


template<class, class> struct Unary;
template<class, class, class> struct Binary;
template<class, class, class, class> struct Ternary;

template<std::size_t, class> struct Unique;


// mp_left
template<class T>
struct mp_left_impl
{
  using type = mp_void;
};

template<class F, class L>
struct mp_left_impl<Unary<F, L> >
{
  using type = L;
};

template<class F, class L, class R>
struct mp_left_impl<Binary<F, L, R> >
{
  using type = L;
};

template<class F, std::size_t ID, class T, class R>
struct mp_left_impl<Binary<F, Unique<ID, T>, R> >
{
  using type = mp_void;
};

template<class F, class L, class M, class R>
struct mp_left_impl<Ternary<F, L, M, R> >
{
  using type = L;
};

template<class F, std::size_t ID, class T, class M, class R>
struct mp_left_impl<Ternary<F, Unique<ID, T>, M, R> >
{
  using type = mp_void;
};

template<class T> using mp_left = typename mp_left_impl<T>::type;


// mp_middle
template<class T>
struct mp_middle_impl
{
  using type = mp_void;
};

template<class F, class L>
struct mp_middle_impl<Unary<F, L> >
{
  using type = mp_void;
};

template<class F, class L, class R>
struct mp_middle_impl<Binary<F, L, R> >
{
  using type = R;
};

template<class F, class L, std::size_t ID, class T>
struct mp_middle_impl<Binary<F, L, Unique<ID, T> > >
{
  using type = mp_void;
};

template<class F, class L, class M, class R>
struct mp_middle_impl<Ternary<F, L, M, R> >
{
  using type = M;
};

template<class F, class L, std::size_t ID, class T, class R>
struct mp_middle_impl<Ternary<F, L, Unique<ID, T>, R> >
{
  using type = mp_void;
};

template<class T> using mp_middle = typename mp_middle_impl<T>::type;


// mp_right
template<class T>
struct mp_right_impl
{
  using type = mp_void;
};

template<class F, class L>
struct mp_right_impl<Unary<F, L> >
{
  using type = mp_void;
};

template<class F, class L, class R>
struct mp_right_impl<Binary<F, L, R> >
{
  using type = mp_void;
};

template<class F, class L, class M, class R>
struct mp_right_impl<Ternary<F, L, M, R> >
{
  using type = R;
};

template<class F, class L, class M, std::size_t ID, class T>
struct mp_right_impl<Ternary<F, L, M, Unique<ID, T> > >
{
  using type = mp_void;
};

template<class T> using mp_right = typename mp_right_impl<T>::type;
