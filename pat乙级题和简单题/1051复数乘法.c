#include <stdio.h>
#include <math.h>

int main()
{
    double r1, p1, r2, p2, a, b;
    scanf("%lf %lf %lf %lf", &r1, &p1, &r2, &p2);
    a = r1 * r2 * (cos(p1) * cos(p2) - sin(p1) * sin (p2));
    b = r1 * r2 * (sin(p1) * cos(p2) + cos(p1) * sin(p2));
    if(a + 0.005 >= 0 && a < 0)
        printf("0.00");
    else
        printf("%.2lf", a);
    if(b + 0.005 >= 0 && b < 0)
        printf("+0.00i");
    else if(b > 0)
        printf("+%.2lfi", b);
    else
        printf("%.2lfi", b);
    return 0;
}
