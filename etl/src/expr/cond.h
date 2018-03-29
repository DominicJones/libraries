// -*- C++ -*-

#ifndef _cond_h_
#define _cond_h_


template<typename A, typename B>
auto cond(bool const &c, A const &a, B const &b)
  -> decltype(a + b)
{
  using R = decltype(a + b);
  if (c) { return R{a}; } else { return R{b}; }
}


#endif // _cond_h_
