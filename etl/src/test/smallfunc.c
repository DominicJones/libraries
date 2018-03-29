

void smallfunc(double const arg0,
               double const arg1,
               double const arg2,
               double const arg3,
               double const arg4,
               double * result)
{
#define LTYPE double

  double c0 = 5;
  double c1 = 6;
  LTYPE tmp0=(c0 * arg0 * sin(arg0) / cos(arg1) * c1);
  LTYPE tmp1=(arg1 * sin(arg1) / c0 * cos(arg0));
  LTYPE tmp2=(sin(tmp0) * tmp1 + sin(tmp1) * tmp0);
  LTYPE tmp3=(sin(tmp2) / cos(tmp2) * c1  + cos(tmp0) / sin(tmp0));
  *result = tmp3;

#undef LTYPE
}
