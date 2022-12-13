build:
	cargo build
	cbindgen --config cbindgen.toml --crate precompiles --output precompiles.h --lang c
