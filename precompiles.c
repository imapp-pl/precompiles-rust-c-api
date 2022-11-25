#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "precompiles.h"

int main(void) {
    const uint8_t input_data[3] = {'a', 'l', 'a'};
    size_t input_size = 3;
    uint8_t* result = (uint8_t*) malloc(20 * sizeof(uint8_t));

    ripemd160(input_data, input_size, result);

    for (size_t i = 0; i < 20; i ++) {
        printf("%X", result[i]);
    }
}
