CC=gcc

compile:
	cargo build
	cbindgen --config cbindgen.toml --crate precompiles --output precompiles.h --lang c
	$(CC) precompiles.c -o precomp -lprecompiles -L./target/debug

run: precomp
	LD_LIBRARY_PATH=./target/debug ./precomp