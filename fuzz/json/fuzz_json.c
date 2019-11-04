#include <stdint.h>
#include <string.h>
#include <sys/types.h>

#include <stdbool.h>
#include <stdlib.h>

#include "variant.h"

extern int __tr_message_level;

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    tr_variant var;
    uint8_t *buf;

    __tr_message_level = 0;

    memset(&var, 0, sizeof(var));

    buf = malloc(Size + 1);
    memcpy(buf, Data, Size);
    buf[Size] = 0;

    tr_variantFromBuf(&var, TR_VARIANT_FMT_JSON, buf, Size, NULL, NULL);
    tr_variantFree(&var);

    free(buf);

    return 0;
}
