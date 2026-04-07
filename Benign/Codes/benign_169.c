
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

static volatile uint64_t arr[1024];

static void init_arr(void) {
    for (int i = 0; i < 1024; i++) {
        arr[i] = (uint64_t)i * 6364136223846793005ull;
    }
}

static inline uint64_t rdcycle(void) {
    uint64_t x;
    asm volatile("rdcycle %0" : "=r"(x));
    return x;
}

static uint64_t benign_compute(int iters) {
    uint64_t sum = 0;
    for (int i = 0; i < iters; i++) {
        int idx = (i * 9 + 8) & (1024 - 1);
        sum += (arr[idx] ^ (uint64_t)(i * 3 + 3));
    }
    return sum;
}

int main(void) {
    int outer = 1500;
    int inner = 640;

    init_arr();
    volatile uint64_t dummy = 0;

    for (int i = 0; i < outer; i++) {
        uint64_t t1 = rdcycle();
        dummy ^= benign_compute(inner);
        uint64_t t2 = rdcycle();
        uint64_t delta = t2 - t1;
        if ((delta & 1u) == 0) {
            dummy ^= delta;
        }
    }

    printf("benign_169 done, dummy=%llu\n", (unsigned long long)dummy);
    return 0;
}
