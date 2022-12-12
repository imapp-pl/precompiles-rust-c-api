#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../precompiles.h"

const uint8_t LENGTH = 32;

int main(void) {
    const uint8_t input_data[3] = {'a', 'l', 'a'};
    size_t input_size = 3;
    uint8_t* result = (uint8_t*) malloc(LENGTH * sizeof(uint8_t));

    ripemd160(input_data, input_size, result);

    for (size_t i = 0; i < LENGTH; i ++) {
        printf("%X", result[i]);
    }
}
