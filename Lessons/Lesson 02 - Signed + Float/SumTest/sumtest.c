#include <stdio.h>
#include <stdint.h>

int main (int argc, char **argv){
    uint8_t     i, j;
    int8_t      k;

    i = 250;
    k = -15;

    j = i + k;

    printf ("The sum of %d + %i is %d\n", i, k, j);

    return 0;
}
