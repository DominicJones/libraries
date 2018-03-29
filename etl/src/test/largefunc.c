

void largefunc(double const &arg0,
               double const &arg1,
               double const &arg2,
               double const &arg3,
               double const &arg4,
               double * result)
{
#define LTYPE auto const
#define CTYPE auto const

  CTYPE c1 = (double(1));
  CTYPE c2 = (double(2));
  CTYPE c3 = (double(3));
  CTYPE c4 = (double(4));
  CTYPE c5 = (double(5));
  CTYPE c6 = (double(6));
  CTYPE c7 = (double(7));
  CTYPE c8 = (double(8));
  CTYPE c9 = (double(9));
  CTYPE c10 = (double(10));
  CTYPE c11 = (double(11));
  CTYPE c12 = (double(12));
  LTYPE tmp0=(c1 * arg0 * sin(arg0) / cos(arg1) * c2);
  LTYPE tmp1=(arg1 * c3 * sin(arg1) / cos(arg0));
  LTYPE tmp2=(sin(tmp0) * tmp1 + sin(tmp1) * tmp0);
  LTYPE tmp3=(sin(tmp2) / cos(tmp2) + cos(tmp0) * c4 / sin(tmp0));
  LTYPE tmp4=(sin(tmp2) / c5 * cos(tmp2) + cos(tmp1) / sin(tmp3));
  LTYPE tmp5=(sin(tmp2) * cos(tmp4) + cos(tmp0) * sin(tmp1));
  LTYPE tmp6=(c6 * sin(tmp2) / cos(tmp5) + cos(tmp0) / sin(tmp3));
  LTYPE tmp7=(sin(tmp4) + cos(tmp6) + cos(tmp0) * c7 / sin(tmp5));
  LTYPE tmp8=(sin(tmp1) / cos(tmp5) * cos(tmp0) * sin(tmp6));
  LTYPE tmp9=(sin(tmp6) + c8 * cos(tmp4) + cos(tmp0) / sin(tmp1));
  LTYPE tmp10=(sin(tmp5) / cos(tmp3) + cos(tmp7) + sin(tmp2));
  LTYPE tmp11=(sin(tmp8) * c9 * cos(tmp2) + cos(tmp0) / sin(tmp3));
  LTYPE tmp12=(c10 * sin(tmp10) / cos(tmp1) + cos(tmp0) / sin(tmp4));
  LTYPE tmp13=(sin(tmp12) + cos(tmp0) * c11 + cos(tmp0) / sin(tmp3));
  LTYPE tmp14=(cos(tmp13 / sin(tmp0) + tmp6 / sin(tmp11) * c12 * tmp13 * tmp11 * tmp9));
  *result = tmp14;

#undef LTYPE
#undef CTYPE
}
