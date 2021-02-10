#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#define E 0.000000000001

double Arccos(double x, double eps)
{
    double arccos=x;
    double a=x;
    int i=1;
    while(a > eps)
    {
        a*=x*x*(2*i-1)*(2*i-1)/((2*i+1)*2*i);
        arccos+=a;
        i++;
    }
    return M_PI/2-arccos;
}


double co(double xa,double ya,double xb,double yb,double xc,double yc){
    return ((xc-xa)*(xb-xa)+(yb-ya)*(yc-ya))/(sqrt((xb-xa)*(xb-xa)+(yb-ya)*(yb-ya))*sqrt((xc-xa)*(xc-xa)+(yc-ya)*(yc-ya)));

}
int main() {
    int n;
    scanf("%d",&n);
    double xa,ya,xb,yb,xc,yc;
    for(int i = 0; i < n; i++){
        scanf("%lf%lf%lf%lf%lf%lf",&xa,&ya,&xb,&yb,&xc,&yc);
        printf("%0.20g\n", Arccos(co(xa,ya,xb,yb,xc,yc),E));
    }
    return 0;
}
