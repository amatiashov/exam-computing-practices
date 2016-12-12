#include <stdio.h>
#include <iostream>
#include <math.h>


double dichotomia     (double (*pf)(double), double a,double b, double &xm, int &count, double eps=1E-5);
double golden_section (double (*pf)(double), double a,double b, double &xm, int &count, double eps=1E-5);
double fibonachi      (double (*pf)(double), double a,double b, double &xm, int &count, double eps=1E-5);
double function(double x);

int main(){
  double xm;
  int count_operation;
  double result = dichotomia(function, -1.57, 3.14, xm, count_operation);
  printf("-------------------------\n");
  printf("This is dichotomia method\n");
  printf("function - sin()\n");
  printf("Ymax: %f\n X: %f\n", result, xm);
  printf("Operation count: %i\n", count_operation);
  printf("-------------------------\n");

  result = golden_section(function, -1.57, 3.14, xm, count_operation);
  printf("-------------------------\n");
  printf("This is golden section method\n");
  printf("function - sin()\n");
  printf("Ymax: %f\n X: %f\n", result, xm);
  printf("Operation count: %i\n", count_operation);
  printf("-------------------------\n");

  printf("%f\n", M_PI_2);

};


double function(double x){
  return sin(x);
};

double dichotomia(double (*pf)(double), double a,double b, double &xm, int &count, double eps) {
  count = 0;
  double c = a + (b-a)/2;
  double delta = (b-a) / 100;
  while (b-a > eps) {
    double xl = c - delta;
    double xr = c + delta;
    if (pf(xl) > pf(xr))
      b = xr;
    else
      a = xl;
    c = a + (b-a)/2;
    delta = (b-a) / 100;
    count += 2;
  };
  xm = c;
  return pf(c);
};

double golden_section(double (*pf)(double), double a,double b, double &xm, int &count, double eps){
  count = 2;
  double t = (sqrt(5)-1) / 2;

  double xl = b -  (b-a) * t;
  double xr = a + (b-a) * t;

  double y_l = pf(xl);
  double y_r = pf(xr);

  while (b-a > eps) {
    if ( y_l > y_r ){
      b = xr;
      xr = xl;
      xl = b -  (b-a) * t;
      y_r = y_l;
      y_l = pf(xl);
   }
    else{
      a = xl;
      xl = xr;
      xr = a + (b-a) * t;
      y_l = y_r;
      y_r = pf(xr);
  }
  count ++;
  }
  xm = (a+b) / 2;
  return pf(xm);
};
