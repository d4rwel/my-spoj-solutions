#include <stdio.h>
#include <math.h>

int powt(int b, int e)
{
        int c=1;
        int bit;
        int i;
        if(b==0 && e==0) return 0;
        for(i=30;i>=0;i--) {
                bit=pow(2,i);
                c=(c*c)%10;
                if(e/bit==1) {e=e-bit;c=(b*c)%10;}
        }
        return c;
}

int main()
{
        int t;
        scanf("%i", &t);
        int i;
        for(i=0;i<t;i++) {
                int a;
                int b;
                scanf("%i",&a);
                scanf("%i",&b);
                int c=powt(a,b);
                printf("%i\n",c);
        }
        return 0;
}
