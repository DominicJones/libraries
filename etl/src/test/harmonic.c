

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
