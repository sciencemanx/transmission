#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

extern int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size);

int main(int argc, char **argv) {
    char *filename;
    uint8_t *data;
    size_t size;
    FILE *file;
    int ret;

    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "rb");
    if (f == NULL) return 1;

    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fseek(f, 0, SEEK_SET);  /* same as rewind(f); */

    data = malloc(size + 1);
    if (data == NULL) return 1;

    fread(data, 1, size, f);

    fclose(f);

    data[size] = 0;

    ret = LLVMFuzzerTestOneInput(data, size);

    free(data);

    return ret;
}
