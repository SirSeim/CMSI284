#include <stdio.h>
#include <stdint.h>
#include <assert.h>

uint32_t onebits(int32_t x);

int main() {
    assert(onebits(0) == 0);
    assert(onebits(-1) == 32);
    assert(onebits(0x264b743d) == 16);
    assert(onebits(0x12345678) == 13);
    puts("All tests passed");
    return 0;
}