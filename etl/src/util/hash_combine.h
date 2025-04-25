// -*- C++ -*-
#pragma once

#include <cstdint>

constexpr uint64_t hash(uint64_t const &v)
{
  return v * uint64_t(104723);
}

constexpr uint64_t hash_combine(uint64_t const &seed, uint64_t const &v)
{
  return seed ^ (hash(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2));
}

template<typename... Args>
constexpr uint64_t hash_combine(uint64_t const &seed, uint64_t const &v, Args... args)
{
  return hash_combine(hash_combine(seed, args...), v);
}

#define HashCombine2(V0, V1) hash_combine(uint64_t(0), uint64_t(V0), uint64_t(V1))
#define HashCombine3(V0, V1, V2) hash_combine(uint64_t(V0), uint64_t(V1), uint64_t(V2))
