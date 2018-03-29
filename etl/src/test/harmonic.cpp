#include "harmonic.h"


void harmonic(double const _alpha,
              double const _beta,
              double const _gamma,
              double const _beta2,
              double const _beta3,
              double * _f)
{
  double const t1 = cos(_beta);
  double const t2 = cos(_alpha);
  double const t3 = sin(_beta2);
  double const t4 = t2 - t3;
  double const t5 = t2 + t3;
  double const t6 = t1*t1;
  double const t7 = t6 + double(0.1e1)*_beta3;
  double const t8 = cos(_gamma);
  double const t9 = sin(_gamma);
  double const t10 = t2*t2;
  double const t11 = double(0.2e1) * t2;
  double const t12 = t10 + (-t11 - t3) * t3;
  double const t11_2 = t10 + (t11 - t3) * t3;
  double const t13 = double(0.1e1) + (double(0.6e1) + t6) * t6;
  double const t14 = t9*t9;
  double const t15 = t8*t8;
  double const t16 = t15*t15 + t14*t14;
  double const t17 = t15 - t14;
  double const t18 = sqrt(double(0.5e1));
  double const t19 = sin(_beta);
  double const t20 = sqrt(double(0.3e1));
  double const t21 = sqrt(double(0.7e1));
  double const t22 = sqrt(double(0.14e2));
  double const t23 = sqrt(double(0.30e2));
  double const t24 = t8 - t9;
  double const t25 = t8 + t9;
  double const t26 = t19*t19;
  double const t27 = t26*t26;
  double const t28 = sqrt(double(0.2e1));
  double const t29 = sqrt(double(0.6e1));
  double const t30 = sqrt(double(0.42e2));
  double const t31 = double(0.2e1) * t23;
  double const t32 = t18 * (double(0.4e1) * t20 + t28 * t29) * t30 + t31 * t20 * t21;
  double const t33 = t15 - t14 / double(0.3e1);
  double const t34 = t15 - double(0.3e1) * t14;
  double const t35 = t6 + double(0.3e1);
  double const t36 = t12 * t11_2;
  double const t37 = t29 * t20;
  double const t38 = t28 + t37;
  double const t39 = -double(0.3e1) / double(0.16e2);
  double const t40 = t15 + t14;
  double const t31_2 = t20 * (t6 * t18 * t29 + t31 * (t6 - t26 * t40 / double(0.2e1))) * t28 + (double(0.12e2) * t18 + t29 * t23) * t6;
  double const t41 = t40 * t6;
  double const t42 = t41 - t15 - t14 - double(0.2e1) * t26;
  double const t43 = sqrt(double(0.10e2));
  double const t44 = sqrt(double(0.15e2));
  double const t45 = t20 * t28;
  double const t46 = t45 * t42;
  double const t41_2 = t46 * t43 + (t41 - t15 - t14 - double(0.8e1) * t26) * t44;
  double const t47 = t1 - double(0.1e1);
  double const t48 = t1 + double(0.1e1);
  double const t30_2 = _alpha*t41_2 * sqrt(double(0.105e3)) - double(0.30e2) * t30 * t26 * t29 + double(0.15e2) * t40 * t47 * t48 * t21;
  double const t49 = _beta*t3*t3;
  double const t50 = t10*t10 + (-double(0.6e1) * t10 + t49) * t49*_beta2;
  double const t51 = double(0.4e1) * t2 * t3;
  double const t37_2 = (t45 * (t6 - double(0.3e1) / double(0.8e1) * t26 * t40) + t29 * t6 / double(0.2e1)) * t44 + (-t37 * t26 * t40 / double(0.2e1) + double(0.3e1) / double(0.2e1) * t28 * (t6 - double(0.5e1) / double(0.4e1) * t26 * t40)) * t18;
  double const t44_2 = sqrt(double(0.70e2));
  double const t52 = sqrt(double(0.21e2));
  double const t10_2 = t51 * (t10 - t49)*_beta3;
  double const t49_2 = t50 * t1;
  double const t53 = t18 / double(0.1680e4)*_beta2;
  double const t28_2 = t53 * ((double(0.6e1) * t28 * t44_2 * t43 + double(0.15e2) * t52 * t29) * t48 * t47 * t40 + t46 * t44_2 * t23 + t41_2 * sqrt(double(0.210e3)));
  double const t44_3 = t1 * t21 / double(0.6e1)*_beta*_gamma;
  double const t46_2 = -t26 * t40 / double(0.4e1);
  double const t53_2 = t26 * t25 * t24 * t31_2 * t21 / double(0.24e2) - t53 * t30_2 * (t36 * t7 * t25 * t24 - double(0.16e2) * t2 * t8 * t3 * t9 * t4 * t5 * t1);
  double const t54 = t19 * (t1 * t32 * t8 * t26 * t34 * t21 / double(0.96e2) - t38 * ((-double(0.36e2) * t6 - double(0.12e2)) * t33 * t9 * t5 * t4 * t3 * t2 + t36 * t8 * t34 * t1 * t35) * t18 / double(0.16e2));
  double const t55 = double(0.2e1) * t8;
  double const t55_2 = (-double(0.384e3) * t8 * t9 * t17 * t7 * t5 * t4 * t3 * t2 * t1 + t36 * t13 * (double(0.6e1) * t16 - double(0.36e2) * t14 * t15)) * t18 / double(0.48e2) + t27 * t20 * t21 * t22 * t23 * (t15 + (-t55 - t9) * t9) * (t15 + (t55 - t9) * t9) / double(0.48e2);

  double const _f_0 = ((double(0.24e2) * t16 - double(0.144e3) * t14 * t15) * t7 * t5 * t4 * t3 * t2 * t1 + double(0.6e1) * t9 * t12 * t11_2 * t13 * t8 * t17) * t18 / double(0.12e2) + t27 * t8 * t9 * t20 * t21 * t22 * t23 * t24 * t25 / double(0.12e2);
  double const _f_1 = t19 * (t9 * t1 * t26 * t32 * t33 * t21 / double(0.32e2) + t39 * ((double(0.4e1) * t6 + double(0.4e1) / double(0.3e1)) * t34 * t8 * t5 * t4 * t3 * t2 + t36 * t9 * t33 * t1 * t35) * t38 * t18);
  double const _f_2 = t21 * t9 * t31_2 * t26 * t8 / double(0.12e2) - t30_2 * (t7 * t50 * t9 * t8 + t51 * t24 * t25 * t4 * t5 * t1) * t18 / double(0.840e3);
  double const _f_3 = t19 * t44_3 * t9 * t37_2 + t28_2 * (t49_2 * t9 + t10_2 * t8);
  double const _f_4 = -t36 * (-t40 * t47 * t41_2 * t48 * t52 / double(0.2e1) + t26 * (t23 * t42 * t20 + double(0.6e1) * t43 * t40 * t47 * t48) * t22) * t18 / double(0.420e3) + t21 * (t46_2 * t45 * t29 * (t6 + t46_2) + (t6 - double(0.3e1) / double(0.2e1) * t26 * t40) * t6);
  double const _f_5 = t19 * (t44_3 * t37_2 * t8 + t28_2 * (t49_2 * t8 - t10_2 * t9));
  double const _f_6 = t53_2;
  double const _f_7 = t54*double(1);
  double const _f_8 = t55_2;

  *_f = _f_0 + _f_1 + _f_2 + _f_3 + _f_4 + _f_5 + _f_6 + _f_7 + _f_8;
}


void harmonic_uniq(Terminal<A> const &_alpha,
                   Terminal<B> const &_beta,
                   Terminal<C> const &_gamma,
                   Terminal<D> const &_beta2,
                   Terminal<E> const &_beta3,
                   Result<R> const &_f)
{
  auto const t1(cos(_beta));
  auto const t2(cos(_alpha));
  auto const t3(sin(_beta2));
  auto const t4(t2 - t3);
  auto const t5(t2 + t3);
  auto const t6(t1*t1);
  auto const t7(t6 + UQ(double(0.1e1))*_beta3);
  auto const t8(cos(_gamma));
  auto const t9(sin(_gamma));
  auto const t10(t2*t2);
  auto const t11(UQ(double(0.2e1)) * t2);
  auto const t12(t10 + (-t11 - t3) * t3);
  auto const t11_2(t10 + (t11 - t3) * t3);
  auto const t13(UQ(double(0.1e1)) + (UQ(double(0.6e1)) + t6) * t6);
  auto const t14(t9*t9);
  auto const t15(t8*t8);
  auto const t16(t15*t15 + t14*t14);
  auto const t17(t15 - t14);
  auto const t18 = sqrt(UQ(double(0.5e1)));
  auto const t19(sin(_beta));
  auto const t20 = sqrt(UQ(double(0.3e1)));
  auto const t21 = sqrt(UQ(double(0.7e1)));
  auto const t22 = sqrt(UQ(double(0.14e2)));
  auto const t23 = sqrt(UQ(double(0.30e2)));
  auto const t24(t8 - t9);
  auto const t25(t8 + t9);
  auto const t26(t19*t19);
  auto const t27(t26*t26);
  auto const t28 = sqrt(UQ(double(0.2e1)));
  auto const t29 = sqrt(UQ(double(0.6e1)));
  auto const t30 = sqrt(UQ(double(0.42e2)));
  auto const t31 = UQ(double(0.2e1)) * t23;
  auto const t32 = t18 * (UQ(double(0.4e1)) * t20 + t28 * t29) * t30 + t31 * t20 * t21;
  auto const t33(t15 - t14 / UQ(double(0.3e1)));
  auto const t34(t15 - UQ(double(0.3e1)) * t14);
  auto const t35(t6 + UQ(double(0.3e1)));
  auto const t36(t12 * t11_2);
  auto const t37 = t29 * t20;
  auto const t38 = t28 + t37;
  auto const t39 = -UQ(double(0.3e1)) / UQ(double(0.16e2));
  auto const t40(t15 + t14);
  auto const t31_2(t20 * (t6 * t18 * t29 + t31 * (t6 - t26 * t40 / UQ(double(0.2e1)))) * t28 + (UQ(double(0.12e2)) * t18 + t29 * t23) * t6);
  auto const t41(t40 * t6);
  auto const t42(t41 - t15 - t14 - UQ(double(0.2e1)) * t26);
  auto const t43 = sqrt(UQ(double(0.10e2)));
  auto const t44 = sqrt(UQ(double(0.15e2)));
  auto const t45 = t20 * t28;
  auto const t46(t45 * t42);
  auto const t41_2(t46 * t43 + (t41 - t15 - t14 - UQ(double(0.8e1)) * t26) * t44);
  auto const t47(t1 - UQ(double(0.1e1)));
  auto const t48(t1 + UQ(double(0.1e1)));
  auto const t30_2(_alpha*t41_2 * sqrt(UQ(double(0.105e3))) - UQ(double(0.30e2)) * t30 * t26 * t29 + UQ(double(0.15e2)) * t40 * t47 * t48 * t21);
  auto const t49(_beta*t3*t3);
  auto const t50(t10*t10 + (-UQ(double(0.6e1)) * t10 + t49) * t49*_beta2);
  auto const t51(UQ(double(0.4e1)) * t2 * t3);
  auto const t37_2((t45 * (t6 - UQ(double(0.3e1)) / UQ(double(0.8e1)) * t26 * t40) + t29 * t6 / UQ(double(0.2e1))) * t44 + (-t37 * t26 * t40 / UQ(double(0.2e1)) + UQ(double(0.3e1)) / UQ(double(0.2e1)) * t28 * (t6 - UQ(double(0.5e1)) / UQ(double(0.4e1)) * t26 * t40)) * t18);
  auto const t44_2 = sqrt(UQ(double(0.70e2)));
  auto const t52 = sqrt(UQ(double(0.21e2)));
  auto const t10_2(t51 * (t10 - t49)*_beta3);
  auto const t49_2(t50 * t1);
  auto const t53(t18 / UQ(double(0.1680e4))*_beta2);
  auto const t28_2(t53 * ((UQ(double(0.6e1)) * t28 * t44_2 * t43 + UQ(double(0.15e2)) * t52 * t29) * t48 * t47 * t40 + t46 * t44_2 * t23 + t41_2 * sqrt(UQ(double(0.210e3)))));
  auto const t44_3(t1 * t21 / UQ(double(0.6e1))*_beta*_gamma);
  auto const t46_2(-t26 * t40 / UQ(double(0.4e1)));
  auto const t53_2(t26 * t25 * t24 * t31_2 * t21 / UQ(double(0.24e2)) - t53 * t30_2 * (t36 * t7 * t25 * t24 - UQ(double(0.16e2)) * t2 * t8 * t3 * t9 * t4 * t5 * t1));
  auto const t54(t19 * (t1 * t32 * t8 * t26 * t34 * t21 / UQ(double(0.96e2)) - t38 * ((-UQ(double(0.36e2)) * t6 - UQ(double(0.12e2))) * t33 * t9 * t5 * t4 * t3 * t2 + t36 * t8 * t34 * t1 * t35) * t18 / UQ(double(0.16e2))));
  auto const t55(UQ(double(0.2e1)) * t8);
  auto const t55_2((-UQ(double(0.384e3)) * t8 * t9 * t17 * t7 * t5 * t4 * t3 * t2 * t1 + t36 * t13 * (UQ(double(0.6e1)) * t16 - UQ(double(0.36e2)) * t14 * t15)) * t18 / UQ(double(0.48e2)) + t27 * t20 * t21 * t22 * t23 * (t15 + (-t55 - t9) * t9) * (t15 + (t55 - t9) * t9) / UQ(double(0.48e2)));

  auto const _f_0(((UQ(double(0.24e2)) * t16 - UQ(double(0.144e3)) * t14 * t15) * t7 * t5 * t4 * t3 * t2 * t1 + UQ(double(0.6e1)) * t9 * t12 * t11_2 * t13 * t8 * t17) * t18 / UQ(double(0.12e2)) + t27 * t8 * t9 * t20 * t21 * t22 * t23 * t24 * t25 / UQ(double(0.12e2)));
  auto const _f_1(t19 * (t9 * t1 * t26 * t32 * t33 * t21 / UQ(double(0.32e2)) + t39 * ((UQ(double(0.4e1)) * t6 + UQ(double(0.4e1)) / UQ(double(0.3e1))) * t34 * t8 * t5 * t4 * t3 * t2 + t36 * t9 * t33 * t1 * t35) * t38 * t18));
  auto const _f_2(t21 * t9 * t31_2 * t26 * t8 / UQ(double(0.12e2)) - t30_2 * (t7 * t50 * t9 * t8 + t51 * t24 * t25 * t4 * t5 * t1) * t18 / UQ(double(0.840e3)));
  auto const _f_3(t19 * t44_3 * t9 * t37_2 + t28_2 * (t49_2 * t9 + t10_2 * t8));
  auto const _f_4(-t36 * (-t40 * t47 * t41_2 * t48 * t52 / UQ(double(0.2e1)) + t26 * (t23 * t42 * t20 + UQ(double(0.6e1)) * t43 * t40 * t47 * t48) * t22) * t18 / UQ(double(0.420e3)) + t21 * (t46_2 * t45 * t29 * (t6 + t46_2) + (t6 - UQ(double(0.3e1)) / UQ(double(0.2e1)) * t26 * t40) * t6));
  auto const _f_5(t19 * (t44_3 * t37_2 * t8 + t28_2 * (t49_2 * t8 - t10_2 * t9)));
  auto const &_f_6(t53_2);
  auto const _f_7(t54*UQ(double(1)));
  auto const &_f_8(t55_2);

  _f = _f_0 + _f_1 + _f_2 + _f_3 + _f_4 + _f_5 + _f_6 + _f_7 + _f_8;
}




void harmonic_adjoint_tapenade(double _alpha, double *alphab,
                               double _beta, double *betab,
                               double _gamma, double *gammab,
                               double _beta2, double *beta2b,
                               double _beta3, double *beta3b,
                               double _f, double *_fb)
{
  double _alphab;
  double _betab;
  double _gammab;
  double _beta2b;
  double _beta3b;
  double t1;
  double t1b;
  double temp3;
  double temp29;
  double tempb52;
  double temp2;
  double temp28;
  double tempb51;
  double temp1;
  double temp27;
  double tempb50;
  double temp0;
  double temp26;
  double temp25;
  double temp24;
  double temp23;
  double temp22;
  double temp21;
  double temp20;
  double tempb9;
  double tempb8;
  double tempb7;
  double tempb6;
  double tempb5;
  double tempb4;
  double tempb19;
  double tempb3;
  double tempb18;
  double tempb2;
  double tempb17;
  double tempb1;
  double tempb16;
  double tempb0;
  double tempb15;
  double tempb14;
  double tempb13;
  double tempb12;
  double tempb49;
  double tempb11;
  double tempb48;
  double tempb10;
  double tempb47;
  double tempb46;
  double tempb45;
  double tempb44;
  double tempb43;
  double temp19;
  double tempb42;
  double temp18;
  double tempb41;
  double temp17;
  double tempb40;
  double temp16;
  double temp15;
  double temp14;
  double temp13;
  double tempb73;
  double temp12;
  double tempb72;
  double temp11;
  double tempb71;
  double temp10;
  double tempb70;
  double tempb;
  double tempb39;
  double tempb38;
  double tempb37;
  double tempb36;
  double tempb35;
  double tempb34;
  double tempb33;
  double tempb32;
  double tempb69;
  double tempb31;
  double tempb68;
  double tempb30;
  double tempb67;
  double tempb66;
  double tempb65;
  double tempb64;
  double tempb63;
  double tempb62;
  double tempb61;
  double tempb60;
  double temp31;
  double temp30;
  double tempb29;
  double tempb28;
  double tempb27;
  double tempb26;
  double tempb25;
  double temp;
  double tempb24;
  double tempb23;
  double tempb22;
  double tempb59;
  double temp9;
  double tempb21;
  double tempb58;
  double temp8;
  double tempb20;
  double tempb57;
  double temp7;
  double tempb56;
  double temp6;
  double tempb55;
  double temp5;
  double tempb54;
  double temp4;
  double tempb53;
  t1 = cos(_beta);
  double t2;
  double t2b;
  t2 = cos(_alpha);
  double t3;
  double t3b;
  t3 = sin(_beta2);
  double t4 = t2 - t3;
  double t4b;
  double t5 = t2 + t3;
  double t5b;
  double t6 = t1*t1;
  double t6b;
  double t7 = t6 + 0.1e1*_beta3;
  double t7b;
  double t8;
  double t8b;
  t8 = cos(_gamma);
  double t9;
  double t9b;
  t9 = sin(_gamma);
  double t10 = t2*t2;
  double t10b;
  double t11 = 0.2e1*t2;
  double t11b;
  double t12 = t10 + (-t11-t3)*t3;
  double t12b;
  double t11_2 = t10 + (t11-t3)*t3;
  double t11_2b;
  double t13 = 0.1e1 + (0.6e1+t6)*t6;
  double t13b;
  double t14 = t9*t9;
  double t14b;
  double t15 = t8*t8;
  double t15b;
  double t16 = t15*t15 + t14*t14;
  double t16b;
  double t17 = t15 - t14;
  double t17b;
  double t18;
  t18 = sqrt(0.5e1);
  double t19;
  double t19b;
  t19 = sin(_beta);
  double t20;
  t20 = sqrt(0.3e1);
  double t21;
  t21 = sqrt(0.7e1);
  double t22;
  t22 = sqrt(0.14e2);
  double t23;
  t23 = sqrt(0.30e2);
  double t24 = t8 - t9;
  double t24b;
  double t25 = t8 + t9;
  double t25b;
  double t26 = t19*t19;
  double t26b;
  double t27 = t26*t26;
  double t27b;
  double t28;
  t28 = sqrt(0.2e1);
  double t29;
  t29 = sqrt(0.6e1);
  double t30;
  t30 = sqrt(0.42e2);
  double t31 = 0.2e1*t23;
  double t32 = t18*(0.4e1*t20+t28*t29)*t30 + t31*t20*t21;
  double t33 = t15 - t14/0.3e1;
  double t33b;
  double t34 = t15 - 0.3e1*t14;
  double t34b;
  double t35 = t6 + 0.3e1;
  double t35b;
  double t36 = t12*t11_2;
  double t36b;
  double t37 = t29*t20;
  double t38 = t28 + t37;
  double t39 = -0.3e1/0.16e2;
  double t40 = t15 + t14;
  double t40b;
  double t31_2 = t20*(t6*t18*t29+t31*(t6-t26*t40/0.2e1))*t28 + (0.12e2*t18+
                                                                t29*t23)*t6;
  double t31_2b;
  double t41 = t40*t6;
  double t41b;
  double t42 = t41 - t15 - t14 - 0.2e1*t26;
  double t42b;
  double t43;
  t43 = sqrt(0.10e2);
  double t44;
  t44 = sqrt(0.15e2);
  double t45 = t20*t28;
  double t46 = t45*t42;
  double t46b;
  double t41_2 = t46*t43 + (t41-t15-t14-0.8e1*t26)*t44;
  double t41_2b;
  double t47 = t1 - 0.1e1;
  double t47b;
  double t48 = t1 + 0.1e1;
  double t48b;
  double t30_2 = _alpha*t41_2*sqrt(0.105e3) - 0.30e2*t30*t26*t29 + 0.15e2*
    t40*t47*t48*t21;
  double t30_2b;
  double t49 = _beta*t3*t3;
  double t49b;
  double t50 = t10*t10 + (-0.6e1*t10+t49)*t49*_beta2;
  double t50b;
  double t51 = 0.4e1*t2*t3;
  double t51b;
  double t37_2 = (t45*(t6-0.3e1/0.8e1*t26*t40)+t29*t6/0.2e1)*t44 + (-t37*t26
                                                                    *t40/0.2e1+0.3e1/0.2e1*t28*(t6-0.5e1/0.4e1*t26*t40))*t18;
  double t37_2b;
  double t44_2;
  t44_2 = sqrt(0.70e2);
  double t52;
  t52 = sqrt(0.21e2);
  double t10_2 = t51*(t10-t49)*_beta3;
  double t10_2b;
  double t49_2 = t50*t1;
  double t49_2b;
  double t53 = t18/0.1680e4*_beta2;
  double t53b;
  double t28_2 = t53*((0.6e1*t28*t44_2*t43+0.15e2*t52*t29)*t48*t47*t40+t46*
                      t44_2*t23+t41_2*sqrt(0.210e3));
  double t28_2b;
  double t44_3 = t1*t21/0.6e1*_beta*_gamma;
  double t44_3b;
  double t46_2 = -t26*t40/0.4e1;
  double t46_2b;
  double t53_2;
  double t53_2b;
  double t54;
  double t54b;
  double t55 = 0.2e1*t8;
  double t55b;
  double t55_2;
  double t55_2b;
  double _f_0;
  double _f_0b;
  double _f_1;
  double _f_1b;
  double _f_2;
  double _f_2b;
  double _f_3;
  double _f_3b;
  double _f_4;
  double _f_4b;
  double _f_5;
  double _f_5b;
  double _f_6;
  double _f_6b;
  double _f_7;
  double _f_7b;
  double _f_8;
  double _f_8b;
  temp = 0.6e1*t28*t44_2*t43 + 0.15e2*t52*t29;
  temp0 = sqrt(0.210e3);
  _f_0b = _fb[0];
  _f_2b = _fb[0];
  _f_3b = _fb[0];
  _f_6b = _fb[0];
  _f_8b = _fb[0];
  _f_1b = _fb[0];
  _f_4b = _fb[0];
  _f_5b = _fb[0];
  _f_7b = _fb[0];
  _fb[0] = 0.0;
  t55_2b = _f_8b;
  t54b = _f_7b;
  t53_2b = _f_6b;
  temp31 = t49_2*t8 - t10_2*t9;
  tempb = t19*_f_5b;
  tempb0 = t28_2*tempb;
  t28_2b = (t49_2*t9+t10_2*t8)*_f_3b + temp31*tempb;
  tempb20 = t21*_f_4b;
  tempb21 = t45*t29*tempb20;
  tempb22 = t6*tempb20;
  temp30 = t47*t41_2;
  temp29 = t40*t48/0.2e1;
  temp28 = t23*t20*t42 + 0.6e1*t43*t40*t47*t48;
  tempb23 = -(t18*t36*_f_4b/0.420e3);
  tempb24 = t22*tempb23;
  tempb25 = t26*t43*0.6e1*tempb24;
  tempb26 = -(t52*tempb23);
  t46_2b = (2*t46_2+t6)*tempb21;
  tempb1 = t9*t37_2*_f_3b;
  t44_3b = t19*tempb1 + t8*t37_2*tempb;
  tempb2 = t19*t44_3*_f_3b;
  t37_2b = t9*tempb2 + t8*t44_3*tempb;
  tempb3 = t28_2*_f_3b;
  t49_2b = t9*tempb3 + t8*tempb0;
  t10_2b = t8*tempb3 - t9*tempb0;
  tempb12 = t21*t31_2*t26*_f_2b;
  tempb33 = t21*t9*t8*_f_2b/0.12e2;
  temp27 = t25*t4;
  temp26 = t51*t24*temp27;
  temp25 = t9*t8;
  tempb43 = -(t18*t30_2*_f_2b/0.840e3);
  tempb11 = t7*t50*tempb43;
  tempb44 = t5*t1*tempb43;
  tempb45 = t51*t24*tempb44;
  t50b = t1*t49_2b + temp25*t7*tempb43;
  t51b = (t10-t49)*_beta3*t10_2b + temp27*t24*tempb44;
  temp20 = t36*t9*t35;
  temp19 = t5*t4;
  temp18 = t34*t8*temp19;
  temp24 = 0.4e1/0.3e1 + 0.4e1*t6;
  temp17 = temp24*t3*t2;
  temp23 = t39*t38*t18;
  temp22 = t1*t26;
  temp21 = t9*t33/0.32e2;
  tempb13 = t19*t32*t21*_f_1b;
  tempb57 = t19*temp23*_f_1b;
  tempb27 = temp18*tempb57;
  tempb4 = temp17*tempb57;
  tempb52 = t34*t8*tempb4;
  tempb14 = t33*t1*tempb57;
  temp16 = t11_2*t13;
  temp15 = t4*t3;
  temp14 = 0.24e2*t16 - 0.144e3*t14*t15;
  tempb61 = t18*_f_0b/0.12e2;
  tempb58 = t7*t5*temp15*tempb61;
  tempb62 = t2*t1*tempb58;
  tempb47 = temp14*t2*t1*tempb61;
  tempb56 = t7*t5*tempb47;
  tempb19 = 0.6e1*t8*t17*tempb61;
  tempb63 = t9*t12*tempb19;
  tempb10 = 0.6e1*t9*t12*temp16*tempb61;
  tempb64 = t20*t21*t22*t23*_f_0b;
  tempb65 = t24*t25*tempb64;
  tempb9 = t27*tempb65/0.12e2;
  tempb49 = t27*t8*t9*tempb64/0.12e2;
  temp12 = t5*t4;
  temp11 = t8*t9*t1;
  tempb68 = t18*t55_2b/0.48e2;
  tempb40 = (0.6e1*t16-0.36e2*(t14*t15))*tempb68;
  t13b = t36*tempb40 + t11_2*tempb63;
  tempb66 = t36*t13*tempb68;
  t16b = 0.6e1*tempb66 + 0.24e2*tempb62;
  tempb60 = -(0.384e3*t17*t7*temp12*tempb68);
  tempb5 = t3*t2*tempb60;
  tempb48 = -(0.384e3*temp11*t3*t2*tempb68);
  t17b = temp12*t7*tempb48 + t8*tempb10;
  tempb53 = t17*t7*tempb48;
  temp13 = t15 + (t55-t9)*t9;
  tempb69 = t20*t21*t22*t23*t55_2b;
  tempb15 = t27*temp13*tempb69/0.48e2;
  tempb67 = (t15+(-t55-t9)*t9)*tempb69;
  t27b = temp13*tempb67/0.48e2 + t8*t9*tempb65/0.12e2;
  tempb16 = t27*tempb67/0.48e2;
  t55b = t9*tempb16 - t9*tempb15;
  temp7 = t36*t8*t35;
  temp6 = t3*t2;
  temp5 = t5*t4*temp6;
  temp10 = (-(0.36e2*t6)-0.12e2)*t33*t9;
  temp9 = t8*t26;
  temp8 = t1*t34/0.96e2;
  tempb6 = t19*t32*t21*t54b;
  tempb32 = -(t38*t18*t19*t54b/0.16e2);
  t34b = temp9*t1*tempb6/0.96e2 + temp7*t1*tempb32 + temp19*t8*tempb4;
  tempb18 = temp5*(-0.12e2-0.36e2*t6)*tempb32;
  t33b = t9*tempb18 + temp20*t1*tempb57 + temp22*t9*tempb13/0.32e2;
  tempb55 = temp10*tempb32;
  tempb59 = t5*t4*tempb55;
  tempb7 = t34*t1*tempb32;
  t35b = t36*t8*tempb7 + t36*t9*tempb14;
  tempb36 = t21*t25*t24*t53_2b;
  t31_2b = t26*tempb36/0.24e2 + t26*tempb33;
  tempb51 = t21*t26*t31_2*t53_2b/0.24e2;
  temp4 = t4*t5;
  temp3 = t3*t9*temp4;
  temp2 = t2*t8*t1;
  temp1 = t25*t24;
  tempb46 = -((t36*t7*temp1-0.16e2*(temp2*temp3))*t53_2b);
  t30_2b = t53*tempb46 - (t7*t50*temp25+temp26*(t5*t1))*t18*_f_2b/0.840e3;
  tempb39 = -(t53*t30_2*t53_2b);
  t36b = t35*t9*tempb14 + t35*t8*tempb7 + temp1*t7*tempb39 + t13*tempb40 - (
    t22*(t26*temp28)-t52*(temp29*temp30))*t18*_f_4b/0.420e3;
  t7b = temp15*t5*tempb47 + temp1*t36*tempb39 + temp12*t17*tempb48 + temp25*
    t50*tempb43;
  t12b = t11_2*t36b + temp16*t9*tempb19;
  t11_2b = t12*t36b + t13*tempb63;
  tempb50 = t36*t7*tempb39;
  t24b = t25*tempb49 + t25*tempb50 + t25*tempb51 + temp27*t51*tempb44;
  t25b = t24*tempb49 + t24*tempb50 + t24*tempb51 + t4*tempb45;
  tempb8 = -(0.16e2*temp3*tempb39);
  tempb17 = -(0.16e2*temp2*tempb39);
  tempb54 = t3*t9*tempb17;
  t4b = t5*tempb52 + t5*tempb53 + t5*tempb54 + temp6*t5*tempb55 + t3*tempb56
    + t25*tempb45;
  t5b = t4*tempb52 + t4*tempb53 + t4*tempb54 + temp6*t4*tempb55 + temp15*t7*
    tempb47 + temp26*t1*tempb43;
  t53b = (temp*(t48*t47*t40)+t44_2*t23*t46+temp0*t41_2)*t28_2b + t30_2*
    tempb46;
  tempb70 = t21*t1*t44_3b/0.6e1;
  tempb41 = t53*t28_2b;
  tempb38 = temp*tempb41;
  tempb72 = t51*_beta3*t10_2b;
  _beta3b = t7b + (t10-t49)*t51*t10_2b;
  tempb28 = t44*t45*t37_2b;
  tempb35 = t18*t37_2b;
  tempb29 = t28*0.3e1*tempb35/0.2e1;
  tempb73 = t49*_beta2*t50b;
  t10b = 2*t10*t50b - 0.6e1*tempb73 + t12b + t11_2b + tempb72;
  tempb71 = (t49-0.6e1*t10)*t50b;
  t49b = tempb73 + _beta2*tempb71 - tempb72;
  t3b = t4*tempb56 + t2*tempb59 + 0.4e1*t2*t51b + (t11-2*t3)*t11_2b + t5b -
    t4b + (-t11-2*t3)*t12b + _beta*2*t3*t49b + temp4*t9*tempb17 + temp11*
    t2*tempb60 + temp24*t2*tempb27;
  _beta2b = t49*tempb71 + cos(_beta2)*t3b + t18*t53b/0.1680e4;
  tempb42 = sqrt(0.105e3)*t30_2b;
  t41_2b = temp0*tempb41 + _alpha*tempb42 + temp29*t47*tempb26;
  t46b = t43*t41_2b + t44_2*t23*tempb41;
  t42b = t45*t46b + t26*t23*t20*tempb24;
  tempb37 = t21*0.15e2*t30_2b;
  t47b = t40*t48*tempb38 + t48*t40*tempb37 + temp29*t41_2*tempb26 + t48*t40*
    tempb25;
  t48b = t40*t47*tempb38 + t40*t47*tempb37 + temp30*t40*tempb26/0.2e1 + t40*
    t47*tempb25;
  tempb34 = t44*t41_2b;
  t41b = t42b + tempb34;
  tempb30 = t20*t28*t31_2b;
  tempb31 = t31*tempb30;
  t6b = t3*t2*0.4e1*tempb27 + tempb28 + t29*t44*t37_2b/0.2e1 + tempb29 + t18
    *t29*tempb30 + tempb31 + (t18*0.12e2+t29*t23)*t31_2b + (2*t6+0.6e1)*
    t13b + t7b + t35b + t40*t41b - t33*t9*temp5*0.36e2*tempb32 + (t6-0.3e1
                                                                  *(t26/0.2e1*t40))*tempb20 + tempb22 + t46_2*tempb21;
  t26b = t31_2*tempb33 + temp8*t8*tempb6 - t40*t46_2b/0.4e1 - t30*0.30e2*t29
    *t30_2b - 0.2e1*t42b + 2*t26*t27b - t40*tempb31/0.2e1 - 0.8e1*tempb34
    - t40*t37*tempb35/0.2e1 - t40*0.5e1*tempb29/0.4e1 - t40*0.3e1*tempb28/
    0.8e1 + t31_2*tempb36/0.24e2 + temp21*t1*tempb13 + temp28*tempb24 -
    t40*0.3e1*tempb22/0.2e1;
  t19b = t44_3*tempb1 + (t32*t21*(temp8*temp9)-t38*t18*((temp10*temp5+temp7*
                                                         (t34*t1))/0.16e2))*t54b + 2*t19*t26b + (t32*t21*(temp21*temp22)+temp23
                                                                                                 *(temp17*temp18+temp20*(t33*t1)))*_f_1b + (t44_3*t37_2*t8+t28_2*temp31
                                                                                                   )*_f_5b;
  t40b = t6*t41b - 0.3e1*t26*tempb28/0.8e1 - 0.5e1*t26*tempb29/0.4e1 - t37*
    t26*tempb35/0.2e1 - t26*t46_2b/0.4e1 - t26*tempb31/0.2e1 + t48*t47*
    tempb37 + t48*t47*tempb38 + t48*temp30*tempb26/0.2e1 + t48*t47*tempb25
    - 0.3e1*t26*tempb22/0.2e1;
  t1b = temp21*t26*tempb13 + temp20*t33*tempb57 + t8*t9*tempb5 + t2*t8*
    tempb8 + t50*t49_2b + t47b + 2*t1*t6b + t48b + _beta*_gamma*t21*t44_3b
    /0.6e1 + temp7*t34*tempb32 + t34*temp9*tempb6/0.96e2 + temp14*t2*
    tempb58 + temp26*t5*tempb43;
  t14b = 2*t14*t16b - t42b - 0.3e1*t34b - t17b - 0.36e2*t15*tempb66 - t33b/
    0.3e1 + t40b - tempb34 - 0.144e3*t15*tempb62;
  t9b = t37_2*tempb2 + t49_2*tempb3 + t33*temp22*tempb13/0.32e2 + t35*t36*
    tempb14 + t1*t8*tempb5 + (-t55-2*t9)*tempb15 + (t55-2*t9)*tempb16 +
    temp4*t3*tempb17 - t24b + 2*t9*t14b + t25b + t33*tempb18 + t8*tempb9 +
    temp16*t12*tempb19 + t8*tempb11 + t8*tempb12/0.12e2 - t10_2*tempb0;
  t15b = tempb15 - 0.36e2*t14*tempb66 + tempb16 - t42b + t34b + t17b + 2*t15
    *t16b + t33b + t40b - tempb34 - 0.144e3*t14*tempb62;
  t8b = t10_2*tempb3 + temp19*t34*tempb4 + t1*t9*tempb5 + temp8*t26*tempb6 +
    t35*t36*tempb7 + t25b + 2*t8*t15b + t24b + t1*t2*tempb8 + 0.2e1*t55b +
    t9*tempb9 + t17*tempb10 + t9*tempb11 + t9*tempb12/0.12e2 + t49_2*
    tempb0 + t44_3*t37_2*tempb;
  _betab = t3*t3*t49b - sin(_beta)*t1b + cos(_beta)*t19b + _gamma*tempb70;
  _gammab = cos(_gamma)*t9b - sin(_gamma)*t8b + _beta*tempb70;
  t11b = t3*t11_2b - t3*t12b;
  t2b = temp14*t1*tempb58 + t3*tempb59 + 0.4e1*t3*t51b + 2*t2*t10b + t4b +
    t5b + 0.2e1*t11b + t1*t8*tempb8 + temp11*t3*tempb60 + temp24*t3*
    tempb27;
  _alphab = t41_2*tempb42 - sin(_alpha)*t2b;
  beta3b[0] += _beta3b;
  beta2b[0] += _beta2b;
  gammab[0] += _gammab;
  betab[0] += _betab;
  alphab[0] += _alphab;
}
