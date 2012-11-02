#include <stdint.h>
#include <stdio.h>

int
main()
{
    uint64_t item = 0x0000000000000001;
    uint64_t mask = 0xfffffffff0000000;
    uint64_t clear = 0x000000000fffffff;
    int i;

    printf("0x%llx\n", item);

    for (i = 0; i < 56; i++)
    {
        item <<= 1;
        printf("0x%llx\n", item);
        printf("shifted off 0x%llx\n", item & mask);
        printf("wrapped 0x%llx\n", item ^ ((item & mask) >> 28));
        item = ((item ^ ((item & mask) >> 28)) & clear);
        printf("cleared 0x%llx\n", item);
    }

    return 0;
}
