#include <stdio.h>
#include <complex.h>
#include <math.h>
//I used complex.h library in order to reach both imag and real part of the complex numbers.

double complex f(double complex x)      
{
    return (x * x * x * x) - (3 * x * x * x) + (x * x) + x + 1;
}

double complex calculatep3(double complex p0, double complex p1, double complex p2)     //Calculating roots by using Muller's Method.
{
    double complex h0 = p1 - p0;
    double complex h1 = p2 - p1;
    double complex j0 = (f(p1) - f(p0)) / h0;
    double complex j1 = (f(p2) - f(p1)) / h1;
    double complex a = (j1 - j0) / (h1 + h0);
    double complex b = a * h1 + j1;
    double complex c = f(p2);

    double complex p3 = p2 + ((-2 * c) / (b + csqrt(b * b - 4 * a * c)));
    return p3;
}

int main()
{
    double complex p0 = 0.5;     
    double complex p1 = -0.5;
    double complex p2 = 0;
    double complex p3 = 0;
    double complex fp3 = 0;

    printf("p0 = 0.5, p1 = -0.5, p2 = 0\ni\tPi\t\t\tf(Pi)\n");

    for (int i = 0; i < 7; i++)     //Printing the values on board.
    {
        printf("%d\t", i + 3);

        p3 = calculatep3(p0, p1, p2);
        printf("%lf %lfi\t", creal(p3), cimag(p3));

        fp3 = f(p3);
        printf("%lf %lfi\n", creal(fp3), cimag(fp3));

        p0 = p1;        //Preparing roots for the next iteration.
        p1 = p2;
        p2 = p3;
    }
    return 0;
}
