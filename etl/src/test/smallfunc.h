// -*- C++ -*-

#ifndef _smallfunc_h_
#define _smallfunc_h_


#include "expr/MathFn.h"
#include "expr/Terminal.h"
#include "expr/Unary.h"
#include "expr/Binary.h"
#include "expr/Result.h"
#include "expr/mathop.h"

#include "Identifiers.h"


void smallfunc(double arg0,
               double arg1,
               double arg2,
               double arg3,
               double arg4,
               double * result);

// void smallfunc_b(double arg0, double *arg0b,
//                  double arg1, double *arg1b,
//                  double arg2, double *arg2b,
//                  double arg3, double *arg3b,
//                  double arg4, double *arg4b,
//                  double *result, double *resultb);

void smallfunc_b(double arg0, double *arg0b,
                 double arg1, double *arg1b,
                 double arg2,
                 double arg3,
                 double arg4,
                 double *result, double *resultb);

void smallfunc_uniq(Terminal<A> const &arg0,
                    Terminal<B> const &arg1,
                    Terminal<C> const &arg2,
                    Terminal<D> const &arg3,
                    Terminal<E> const &arg4,
                    Result<R> const &result);


#endif // _smallfunc_h_
