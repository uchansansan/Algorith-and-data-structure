#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#define E 0.00000000001

double msin(double xa,double ya,double xb,double yb,double xc,double yc){

  double a = sqrt((xb-xa)*(xb-xa)+(yb-ya)*(yb-ya));
  double b = sqrt((xc-xa)*(xc-xa)+(yc-ya)*(yc-ya));
  double c = sqrt((xb-xc)*(xb-xc)+(yb-yc)*(yb-yc));
  double x1 = xb-xa;
  double y1 = yb-ya;
  double x2 = xc-xa;
  double y2 = yc-ya;

  if(a==0 || b==0 || c==0)
    return 0;
  
  double p = (a+b+c)/2.00000000000000000000000000;
  double s = fabs(x1*y2-x2*y1)/2.00000000000000000000000000;
  double sin = (2*s)/(a*b);

  return sin;
}

double mcos(double xa,double ya,double xb,double yb,double xc,double yc){
  double x1 = xb-xa;
  double y1 = yb-ya;
  double x2 = xc-xa;
  double y2 = yc-ya;
  double chis = x1*x2 + y1*y2;
  double znam = sqrt((x1*x1+y1*y1)*(x2*x2+y2*y2));
  double cos = chis/znam;
  return cos;
}

int main(void) {
  int n;
  scanf("%d",&n);
  double xa, ya, xb, yb, xc, yc;

  for(int i = 0; i < n; i++){

    scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &xb, &yb, &xc, &yc);

    printf("%.20g\n", atan2(msin(xa, ya, xb, yb, xc, yc),mcos(xa, ya, xb, yb, xc, yc))*180/M_PI);
  }
  return 0;
}
