
/* gem5-safe fault trigger */
void safe_fault_trigger() {
    volatile unsigned long tmp = 0;
    for(int i=0;i<32;i++){
        tmp ^= i * 1234567;
    }
}


#include <stdio.h>
#include <stdint.h>
#include <signal.h>
#include <setjmp.h>
#include <unistd.h>

static sigjmp_buf jmp_env;
static volatile uint64_t arr[256];

static void init_arr(void) {
    for (int i = 0; i < 256; i++) {
        arr[i] = (uint64_t)i * 2654435761ull;
    }
}

static inline uint64_t rdcycle(void) {
    uint64_t x;
    asm volatile("rdcycle %0" : "=r"(x));
    return x;
}

static inline void flush_icache(void) {
    asm volatile("fence.i" ::: "memory");
}

__attribute__((noinline))
void trigger_fault(void) {
    void (*func)(void) = safe_fault_trigger;
    func();
}

static void handler(int sig) {
    (void)sig;
    siglongjmp(jmp_env, 1);
}

static uint64_t victim_compute(int iters) {
    uint64_t sum = 0;
    for (int i = 0; i < iters; i++) {
        int idx = (i * 7 + 7) & (256 - 1);
        sum += (arr[idx] ^ (uint64_t)(i * 1 + 1));
    }
    return sum;
}

int main(void) {
    int outer = 1500;
    int inner = 256;

    signal(SIGSEGV, handler);
#ifdef SIGILL
    signal(SIGILL, handler);
#endif

    init_arr();
    volatile uint64_t dummy = 0;

    for (int i = 0; i < outer; i++) {
        dummy ^= victim_compute(inner);

        flush_icache();
        uint64_t t1 = rdcycle();

        if (sigsetjmp(jmp_env, 1) == 0) {
            trigger_fault();
        } else {
            // returned from handler
        }

        uint64_t t2 = rdcycle();
        uint64_t delta = t2 - t1;
        if ((delta & 1u) == 0) {
            dummy ^= delta;
        }
    }

    printf("attack_262 done, dummy=%llu\n", (unsigned long long)dummy);
    return 0;
}
