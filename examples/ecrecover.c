// SPDX-License-Identifier: MIT

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../precompiles.h"

#define OUTPUT_LENGTH 32
#define HASH_LENGTH 32
#define INPUT_LENGTH 128

int main(void) {
    /*
    Wallet: 0x25Fdb3C8926091d47760CAb1c4C2b8299b8095e8
    Payload: 0x01234567890123456789012345678901234567890123456789012345678901230000000000000000000000000000000000000000000000000000000000000040000000000000000000000000000000000000000000000000000000000000000c48656c6c6f20576f726c64210000000000000000000000000000000000000000
    PayloadHash: 0xa1382ed7e01ff69cec5538a443f2c84e80c9c4f4c999408e1862edb7e2bfd7cc
    Signature: {
    r: '0xb3a9b3b9fb706618a6608aafceb11fa2fb28dbc6b003df22de2c1177f546be23',
    s: '0x24b8ad3defe80ab2e1c2f5882480ca118d57f868408e6a2991b1eb0acd4f567d',
    recoveryParam: 0,
    v: 27 }
    Recovered: 0x25Fdb3C8926091d47760CAb1c4C2b8299b8095e8
    Transaction: 0x993e1a2e56ce260f7cfb5e04db9010ecb4586eb13ae5901c777ae5acfc6d2587
    Receipt Status: 1
    Event: Registerd(bytes32,string,address) {
        hash: '0x0123456789012345678901234567890123456789012345678901234567890123',
        description: 'Hello World!',
        signer: '0x25Fdb3C8926091d47760CAb1c4C2b8299b8095e8',
        length: 3
    }

defmodule Splitter do
  def print_split("") do
    :ok
  end

  def print_split(string) do
    {hex, tail} = String.split_at(string, 2)
    IO.write("0x" <> hex <> ", ")
    print_split(tail)
  end
end
    */

    const uint8_t hash[HASH_LENGTH] = {0x38, 0xd1, 0x8a, 0xcb, 0x67, 0xd2, 0x5c, 0x8b, 0xb9, 0x94, 0x27, 0x64, 0xb6, 0x2f, 0x18, 0xe1, 0x70, 0x54, 0xf6, 0x6a, 0x81, 0x7b, 0xd4, 0x29, 0x54, 0x23, 0xad, 0xf9, 0xed, 0x98, 0x87, 0x3e};
    const uint8_t r[HASH_LENGTH] = {0x38, 0xd1, 0x8a, 0xcb, 0x67, 0xd2, 0x5c, 0x8b, 0xb9, 0x94, 0x27, 0x64, 0xb6, 0x2f, 0x18, 0xe1, 0x70, 0x54, 0xf6, 0x6a, 0x81, 0x7b, 0xd4, 0x29, 0x54, 0x23, 0xad, 0xf9, 0xed, 0x98, 0x87, 0x3e};
    const uint8_t s[HASH_LENGTH] = {0x78, 0x9d, 0x1d, 0xd4, 0x23, 0xd2, 0x5f, 0x07, 0x72, 0xd2, 0x74, 0x8d, 0x60, 0xf7, 0xe4, 0xb8, 0x1b, 0xb1, 0x4d, 0x08, 0x6e, 0xba, 0x8e, 0x8e, 0x8e, 0xfb, 0x6d, 0xcf, 0xf8, 0xa4, 0xae, 0x02};

    uint8_t result[OUTPUT_LENGTH] = {0};

    ecdsarecover(&hash, &r, &s, 1, &result);

    for (size_t i = 0; i < OUTPUT_LENGTH; i ++) {
        printf("%X", result[i]);
    }
}
