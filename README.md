# C API for ethereum precompiles 

## Generating C headers file

`make build`

## Example usage from C code

Shown in `.c` files in `examples`.

For each program you want to run:
```
gcc program.c -o program -lprecompiles -L../target/debug/
LD_LIBRARY_PATH=../target/debug ./program
```

