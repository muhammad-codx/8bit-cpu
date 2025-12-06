# 8bit-cpu

This project is a minimal 8-bit CPU emulator and arithmetic logic unit implemented using a combination of C and Assembly. It demonstrates basic operations such as 8-bit addition, subtraction, multiplication, and comparison—executed using custom assembly routines and called from C code.

## Features

- 8-bit addition, subtraction, multiplication, and equality comparison
- Usage of C to demonstrate and test the assembler routines
- Example of mixing C and Assembly for performance or demonstration purposes

## Repository Structure

```
/
├── .vscode/            # Editor configuration
├── LICENSE             # License file
├── README.md           # Project documentation (this file)
├── complex-cpu.c       # Main C file, invokes assembly routines
├── complex-cpu.s       # Assembly source for CPU ALU operations
├── complex-cpu.o       # Compiled object file (may be regenerated)
└── .DS_Store           # (macOS) Finder metadata
```

## Build & Run

This project uses both C and Assembly files. The example commands below show how to build the executable using GCC for ARM or x86 targets (ensure you are on an appropriate platform or emulator):

1. **Compile assembly source to object file:**
   ```sh
   gcc -c complex-cpu.s -o complex-cpu.o
   ```
2. **Compile C source and link with assembly object:**
   ```sh
   gcc -o complex-cpu complex-cpu.c complex-cpu.o
   ```
3. **Run the example:**
   ```sh
   ./complex-cpu
   ```

## Example Output

```
ADD: 10 + 25 = 35
SUB: 25 - 10 = 15
MUL: 10 * 25 = 244 (8-bit overflow)
CMP: A != B
Memory contents: 10 25 244 15 
```

## Example Code

### C (`complex-cpu.c`)
```c
#include <stdio.h>
#include <stdint.h>

// Declare external assembly functions
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
```

### Assembly (`complex-cpu.s`)
```assembly
        .global cpu_add
        .global cpu_sub
        .global cpu_mul
        .global cpu_cmp

// 8-bit addition
cpu_add:
        add w0, w0, w1
        and w0, w0, #0xFF   // mask 8-bit
        ret

// 8-bit subtraction
cpu_sub:
        sub w0, w0, w1
        and w0, w0, #0xFF
        ret

// 8-bit multiplication
cpu_mul:
        mul w0, w0, w1
        and w0, w0, #0xFF
        ret

// 8-bit comparison
cpu_cmp:
        cmp w0, w1
        cset w0, eq         // w0 = 1 if equal else 0
        ret
```

## Prerequisites

- GCC or compatible C/ASM compiler (tested with gcc)
- Linux/Unix or emulator environment for ARM/x86 assembly (note: syntax uses ARM registers)

## License

[MIT](LICENSE)

## Author

- [muhammad-codx](https://github.com/muhammad-codx)
