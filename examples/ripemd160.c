#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../precompiles.h"

#define LENGTH 20

int main(void) {
    const uint8_t input_data[3] = {'a', 'l', 'a'};
    size_t input_size = 3;
    uint8_t result[LENGTH] = {'0'};

    ripemd160(input_data, input_size, &result);

    for (size_t i = 0; i < LENGTH; i ++) {
        printf("%X", result[i]);
    }
}
