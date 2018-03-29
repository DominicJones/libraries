#include "smallfunc.h"


#include "smallfunc.c"
#include "smallfunc_b.c"


void smallfunc_uniq(Terminal<A> const &arg0,
                    Terminal<B> const &arg1,
                    Terminal<C> const &arg2,
                    Terminal<D> const &arg3,
                    Terminal<E> const &arg4,
                    Result<R> const &result)
{
#ifdef SMALLFUNC_UNIQ
#define LTYPE auto const

  LTYPE tmp0=(arg0 * sin(arg0) / cos(arg1));
  LTYPE tmp1=(arg1 * sin(arg1) / cos(arg0));
  LTYPE tmp2=(sin(tmp0) * tmp1 + sin(tmp1) * tmp0);
  LTYPE tmp3=(sin(tmp2) / cos(tmp2) + cos(tmp0) / sin(tmp0));
  result = tmp3;

#undef LTYPE
#endif
}
