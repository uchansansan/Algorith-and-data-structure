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
        if(x>=0){
            double an = x;
            s=1;
            int j=1;
            while(fabs(an)>E){
                s+=an;
                j+=1;
                an*=  x/(j);
            }
        }
        else{
            x=fabs(x);
            double an = x;
            s=1;
            int j=1;
            while(fabs(an)>E){
                s+=an;
                j+=1;
                an*=  x/(j);
            }
            s=1/s;
        }

        printf("%0.15g\n",s);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
