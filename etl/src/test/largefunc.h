// -*- C++ -*-

#ifndef _largefunc_h_
#define _largefunc_h_


#include "expr/Terminal.h"
#include "expr/Unary.h"
#include "expr/Binary.h"
#include "expr/Result.h"
#include "expr/mathop.h"

#include "Identifiers.h"


void largefunc(double const &arg0,
               double const &arg1,
               double const &arg2,
               double const &arg3,
               double const &arg4,
               double * result);


void largefunc_uniq(Terminal<A> const &arg0,
                    Terminal<B> const &arg1,
                    Terminal<C> const &arg2,
                    Terminal<D> const &arg3,
                    Terminal<E> const &arg4,
                    Result<R> const &result);


void largefunc_adjoint_tapenade(double const &arg0, double *arg0b,
                                double const &arg1, double *arg1b,
                                double const &arg2, double *arg2b,
                                double const &arg3, double *arg3b,
                                double const &arg4, double *arg4b,
                                double const &result, double *resultb);


#endif // _largefunc_h_
