#include <stdio.h>
#include <stdarg.h>

double average(double,double, ...);

int main(void){
    double v1 = 10.5, v2 = 2.5;  
    int num1 = 6, num2 = 5;  
    long num3 = 12L, num4 = 20L;  
    printf("Average = %.2lf\n", average(v1, 3.5, v2, 4.5, 0.0));  
    printf("Average = %.2lf\n", average(1.0, 2.0, 0.0));  
    printf("Average = %.2lf\n", average( num2, v2,(double)num1,  (double)num4, (double)num3, 0.0));  
    return 0;
    }


double average(double v1, double v2, ...){
    double value = 0.0;
    double sum = v1 + v2;
    unsigned int count = 2;
    va_list ptrArg;
    va_list ptrCopyOfArg;  
    va_start(ptrArg,v2);
    va_copy(ptrCopyOfArg, ptrArg);// use this macro to copy the object or arguments in ptrArg
                                // to ptrCopyOfArg, so that we can use the arguments later in our function.
                                //We must not use ptrCopyOfArg as destination of copy operation before you have executed va_end()
                                // for ptrCopyOfArg

    while((value = va_arg(ptrArg,double)) != 0.0){
        sum += value;
        ++count;
    }
    va_end(ptrArg);
    return sum/(double)count;
}