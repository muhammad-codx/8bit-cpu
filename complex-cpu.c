#include <stdio.h>
#include <stdint.h>

// Declare assembly functions
uint8_t cpu_add(uint8_t a, uint8_t b);
uint8_t cpu_sub(uint8_t a, uint8_t b);
uint8_t cpu_mul(uint8_t a, uint8_t b);
uint8_t cpu_cmp(uint8_t a, uint8_t b); // returns 1 if equal, 0 otherwise

int main() {
    uint8_t A = 10;
    uint8_t B = 25;
    uint8_t C, D;

    // Arithmetic operations
    C = cpu_add(A, B);
    D = cpu_sub(B, A);

    printf("ADD: %u + %u = %u\n", A, B, C);
    printf("SUB: %u - %u = %u\n", B, A, D);

    C = cpu_mul(A, B);
    printf("MUL: %u * %u = %u (8-bit overflow)\n", A, B, C);

    if(cpu_cmp(A, B)) {
        printf("CMP: A == B\n");
    } else {
        printf("CMP: A != B\n");
    }

    // Simulate memory array
    uint8_t memory[4] = {A, B, C, D};
    printf("Memory contents: ");
    for(int i=0;i<4;i++) {
        printf("%u ", memory[i]);
    }
    printf("\n");

    return 0;
}
