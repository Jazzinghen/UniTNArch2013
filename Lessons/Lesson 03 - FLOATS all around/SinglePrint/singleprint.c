#include <stdio.h>
#include <stdint.h>

void print_byte(char byte){
    int8_t i;
    uint8_t blah;

    for (i = 0; i < 8; i++){
        blah = byte;
        blah <<= i;
        blah >>= 7;
        printf ("%d ", blah);
    }
}

void print_float(const char *data){
    int8_t i;
    uint8_t blah;
    uint8_t exp;
    
    printf("Sign Bit: \n");
    blah = data[3];
    blah >>= 7;
    printf("\t%d\n\n", blah);

    printf("Exponent: \n");
    exp = data[3] << 1;
    blah = data[2];
    blah >>= 7;
    exp += blah;
    if (exp > 0){
        printf("(%i - 127 = %i)\n\t", exp, exp - 127);
    } else {
        printf("(-127 + 1= 126)\n\t");
    }
    for (i = 1; i < 8; i++){
        blah = data[3];
        blah <<= i;
        blah >>= 7;
        printf ("%d ", blah);
    }
    blah = data[2];
    blah >>= 7;
    printf("%d\n\n", blah);

    printf("Mantissa: \n");

    if (exp > 0) {
        printf("1.\n\t");
    } else {
        printf("0.\n\t");
    }

    for (i = 1; i < 8; i++){
        blah = data[2];
        blah <<= i;
        blah >>= 7;
        printf ("%d ", blah);
    }
    for (i = 0; i < 8; i++){
        blah = data[1];
        blah <<= i;
        blah >>= 7;
        printf ("%d ", blah);
    }
    for (i = 0; i < 8; i++){
        blah = data[0];
        blah <<= i;
        blah >>= 7;
        printf ("%d ", blah);
    }
    
    printf("\n\n");

}

int main (int *argc, char **argv){
    float test;
    union {
        float point;
        char  bytes[4];
    } merged;

    sscanf(argv[1], "%f", &test);

    merged.point = test;

    print_float(merged.bytes);
    printf("RAW Float: \n\t");
    print_byte(merged.bytes[3]);
    print_byte(merged.bytes[2]);
    print_byte(merged.bytes[1]);
    print_byte(merged.bytes[0]);
    printf ("\n");

    return 0;
}
