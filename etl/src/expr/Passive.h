// -*- C++ -*-

#ifndef _Passive_h_
#define _Passive_h_


template<typename T, typename V>
struct Passive
{
  operator T() const { return value; }
  using type = T;
  V value;
};


template<typename T, typename V>
std::ostream &operator<<(std::ostream &os, Passive<T, V> const &p)
{
  return os << p.value;
}


#endif // _Passive_h_
