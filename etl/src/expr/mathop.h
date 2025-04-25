// -*- C++ -*-
#pragma once

#include "expr/MathFn.h"
#include "expr/cond.h"

#include "util/hash_combine.h"

#include <utility>


template<typename Fn, typename L>
struct Unary;

template<typename Fn, typename L, typename R>
struct Binary;

template<typename Fn, typename L, typename M, typename R>
struct Ternary;


#define GenerateUnaryOperator(Fn, Op)           \
  template<typename L>                          \
  inline constexpr Unary<Fn, L>    \
  Op(L const &l)                                \
  {                                             \
    return Unary<Fn, L>{l};                     \
  }

GenerateUnaryOperator(Neg, operator-);
GenerateUnaryOperator(Sin, sin);
GenerateUnaryOperator(Cos, cos);
GenerateUnaryOperator(Sqrt, sqrt);

#undef GenerateUnaryOperator


#define GenerateBinaryOperator(Fn, Op)                  \
  template<typename L, typename R>                      \
  inline constexpr Binary<Fn, L, R>        \
  Op(L const &l, R const &r)                            \
  {                                                     \
    return Binary<Fn, L, R>{l, r};                      \
  }

GenerateBinaryOperator(Add, operator+);
GenerateBinaryOperator(Sub, operator-);
GenerateBinaryOperator(Mul, operator*);
GenerateBinaryOperator(Div, operator/);

#undef GenerateBinaryOperator


#define GenerateTernaryOperator(Fn, Op)                 \
  template<typename L, typename M, typename R>          \
  inline constexpr Ternary<Fn, L, M, R>    \
  Op(L const &l, M const &m, R const &r)                \
  {                                                     \
    return Ternary<Fn, L, M, R>{l, m, r};               \
  }

GenerateTernaryOperator(Cond, cond);

#undef GenerateTernaryOperator




template<std::size_t ID, typename T>
struct Unique;


#define GenerateUniqueOperator(Fn, Op)                                  \
  template<std::size_t IL, typename L>                                  \
  inline constexpr auto                                    \
  Op(Unique<IL, L> const &l)                                            \
    -> Unique<HashCombine2(Fn::hash_value, IL), decltype(Fn::primal(L(l)))> \
  {                                                                     \
    return Unique<HashCombine2(Fn::hash_value, IL), decltype(Fn::primal(L(l)))>{Fn::primal(L(l))}; \
  }

GenerateUniqueOperator(Neg, operator-);
GenerateUniqueOperator(Sin, sin);
GenerateUniqueOperator(Cos, cos);
GenerateUniqueOperator(Sqrt, sqrt);

#undef GenerateUniqueOperator


#define GenerateUniqueOperator(Fn, Op)                                  \
  template<std::size_t IL, std::size_t IR, typename L, typename R>      \
  inline constexpr auto                                    \
  Op(Unique<IL, L> const &l, Unique<IR, R> const &r)                    \
    -> Unique<HashCombine3(Fn::hash_value, IL, IR), decltype(Fn::primal(L(l), R(r)))> \
  {                                                                     \
    return Unique<HashCombine3(Fn::hash_value, IL, IR), decltype(Fn::primal(L(l), R(r)))>{Fn::primal(L(l), R(r))}; \
  }

GenerateUniqueOperator(Add, operator+);
GenerateUniqueOperator(Sub, operator-);
GenerateUniqueOperator(Mul, operator*);
GenerateUniqueOperator(Div, operator/);

#undef GenerateUniqueOperator
