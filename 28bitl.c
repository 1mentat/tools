#include <stdint.h>
#include <stdio.h>

int
main()
{
    uint64_t item =             0x00a5a5a5a5a5a5a5;
    uint64_t mask_upper =       0x00fffffff0000000;
    uint64_t mask_lower =       0x000000000fffffff;
    uint64_t mask_bits =        0x0100000010000000;
    uint64_t bits =             0x0000000000000000;

    int i;

    printf("0x%llx 0x%llx\n", ((item & mask_upper) >> 28), item & mask_lower);

    for (i = 0; i < 56; i++)
    {
        item <<= 1;
        bits = item & mask_bits;
        bits >>= 28;
        item &= ~(mask_bits >> 28);
        item |= bits;
        printf("rotate: %d 0x%llx 0x%llx\n", i, ((item & mask_upper) >> 28), item & mask_lower);
    }

    return 0;
}
