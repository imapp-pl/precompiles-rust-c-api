#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../precompiles.h"

#define OUTPUT_LENGTH 32
#define INPUT_LENGTH 128

int main(void) {
    const uint8_t input_data[INPUT_LENGTH] = {0};

    uint8_t result[OUTPUT_LENGTH] = {0};

    ecdsarecover(&input_data, &result);

    for (size_t i = 0; i < OUTPUT_LENGTH; i ++) {
        printf("%X", result[i]);
    }
}
