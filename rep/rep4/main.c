#include <stdio.h>

extern int my_factorial(int);

int main()
{
    int result = my_factorial(5);
    printf("Factorial: %d\n", result);
    return 0;
}
