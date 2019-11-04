#include <stdint.h>
#include <string.h>
#include <sys/types.h>

#include <stdbool.h>
#include <stdlib.h>

#include "tr-macros.h"
#include "transmission.h"
#include "utils.h"

#define PATTERN_SIZE 100

extern int __tr_message_level;

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    char *text;
    char *pattern;
    size_t text_size;

    if (Size < PATTERN_SIZE + 1) return 0;

    __tr_message_level = 0;

    text_size = Size - PATTERN_SIZE;
    text = malloc(text_size + 1);
    memcpy(text, Data + PATTERN_SIZE, text_size);
    text[text_size] = 0;

    pattern = malloc(PATTERN_SIZE + 1);
    memcpy(pattern, Data, PATTERN_SIZE);
    pattern[PATTERN_SIZE] = 0;

    tr_wildmat(text, pattern);

    free(text);
    free(pattern);

    return 0;
}
