#include <stdio.h>
#include <math.h>
#define E 0.000000000001


double Arccos(double x, double eps){
  double arccos=x;
  double a=x;
  int i=1;
  while(a > eps){
    a*=x*x*(2*i-1)*(2*i-1)/((2*i+1)*2*i);
    arccos+=a;
    i++;
  }
  return M_PI/2-arccos;
}


double co(double xa,double ya,double xb,double yb,double xc,double yc){
  double x1 = xb-xa;
  double y1 = yb-ya;
  double x2 = xc-xa;
  double y2 = yc-ya;

  return (x1*x2+y1*y2)/(sqrt(x1*x1+y1*y1)*sqrt(x2*x2+y2*y2));

}
int main() {
    int n;
    scanf("%d",&n);

    double xa,ya,xb,yb,xc,yc;
    printf("\n");
    for(int i = 0; i < n; i++){
        scanf("%lf%lf%lf%lf%lf%lf",&xa,&ya,&xb,&yb,&xc,&yc);
        printf("%0.20g\n", (Arccos(co(xa,ya,xb,yb,xc,yc),E)*180)/M_PI);
        //printf("%0.20Lf\n",co(xa,ya,xb,yb,xc,yc));
    }
    return 0;
}
