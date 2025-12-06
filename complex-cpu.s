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
