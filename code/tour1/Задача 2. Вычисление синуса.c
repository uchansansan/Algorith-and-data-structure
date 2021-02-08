#include <stdio.h>
#include <math.h>

#define E 0.000000000001

int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  int n;
  scanf("%d",&n);
  double s, x;
  int n1=n;
  for(int i = 0; i < n1; i++){
    scanf("%lf",&x);
    double an = x;
    s=0;
    int j=1;
    while(fabs(an)>E){   
      s+=an;
      j+=2;
      an*=(-1)*x*x/(j*(j-1));         
    }
    printf("%0.15lf\n",s);
  }

  fclose(stdin);
  fclose(stdout);
  return 0;
}
