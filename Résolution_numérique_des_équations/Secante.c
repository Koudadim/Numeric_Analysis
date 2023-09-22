#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void Secante(double x, double extFix, double eps, int itMax, double(*f)(double a))
{
    double y;
    int it;
    y=x-(*f)(x)/(((*f)(x)-(*f)(extFix))/(x-extFix));
    it=1;
    while(fabs(y-x)>eps && it<=itMax)
    {
        x=y;
        y=x-(*f)(x)/(((*f)(x)-(*f)(extFix))/(x-extFix));
        it++;
    }
    if(fabs(y-x)<=eps)
        printf("Solution: %6.6f \n Nombre d'iterations: %d", y, it);
    else
        printf("Precision %1.0e non atteinte apres %d iterations.\n", eps, itMax);
}
