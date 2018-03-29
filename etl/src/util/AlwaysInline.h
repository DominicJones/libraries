// -*- C++ -*-

#ifndef _AlwaysInline_h_
#define _AlwaysInline_h_

#define AlwaysInlineGCC __attribute__((always_inline))

// #define AlwaysInline __attribute__((always_inline))

#define AlwaysInline
#define AlwaysInlineCtor AlwaysInlineGCC

#endif // _AlwaysInline_h_
