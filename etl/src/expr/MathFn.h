// -*- C++ -*-
#pragma once

#include "expr/cond.h"

#include <cmath>


struct Neg
{
  static constexpr bool is_trivial = true;
  static constexpr std::size_t hash_value = 106961;
  static char const * name() { return "-"; }
  inline static double primal(double a) { return -a; }
  inline static void adjoint(double a, double &ad, double rd) { ad -= rd; }
};

struct Sqrt
{
  static constexpr bool is_trivial = false;
  static constexpr std::size_t hash_value = 112331;
  static char const * name() { return "sqrt"; }
  inline static double primal(double a) { return std::sqrt(a); }
  inline static void adjoint(double a, double &ad, double rd) { ad += double{0.5} * rd / a; }
};

struct Sin
{
  static constexpr bool is_trivial = false;
  static constexpr std::size_t hash_value = 125453;
  static char const * name() { return "sin"; }
  inline static double primal(double a) { return std::sin(a); }
  inline static void adjoint(double a, double &ad, double rd) { ad += rd * std::cos(a); }
};

struct Cos
{
  static constexpr bool is_trivial = false;
  static constexpr std::size_t hash_value = 138547;
  static char const * name() { return "cos"; }
  inline static double primal(double a) { return std::cos(a); }
  inline static void adjoint(double a, double &ad, double rd) { ad -= rd * std::sin(a); }
};


struct Add
{
  static constexpr bool is_trivial = true;
  static constexpr std::size_t hash_value = 148693;
  static char const * name() { return "+"; }
  inline static double primal(double a, double b) { return a + b; }
  inline static void adjoint(double a, double &ad, double b, double &bd, double rd) { ad += rd; bd += rd; }
};

struct Sub
{
  static constexpr bool is_trivial = true;
  static constexpr std::size_t hash_value = 154043;
  static char const * name() { return "-"; }
  inline static double primal(double a, double b) { return a - b; }
  inline static void adjoint(double a, double &ad, double b, double &bd, double rd) { ad += rd; bd -= rd; }
};

struct Mul
{
  static constexpr bool is_trivial = false;
  static constexpr std::size_t hash_value = 167771;
  static char const * name() { return "*"; }
  inline static double primal(double a, double b) { return a * b; }
  inline static void adjoint(double a, double &ad, double b, double &bd, double rd) { ad += b * rd; bd += a * rd; }
};

struct Div
{
  static constexpr bool is_trivial = false;
  static constexpr std::size_t hash_value = 176243;
  static char const * name() { return "/"; }
  inline static double primal(double a, double b) { return a / b; }
  inline static void adjoint(double a, double &ad, double b, double &bd, double rd) { double br{1/b}; ad += rd * br; bd -= a * rd * br * br; }
};


struct Cond
{
  static constexpr bool is_trivial = true;
  static constexpr std::size_t hash_value = 182941;
  static char const * name() { return "?"; }
  inline static double primal(bool c, double a, double b) { return cond(c, a, b); }
  inline static void adjoint(bool c, bool &, double a, double &ad, double b, double &bd, double rd) { if (c) { ad += rd; } else { bd += rd; } }
};
