#! /bin/bash
# https://barretts.club/posts/i-got-a-milkv-duo/

rustup toolchain install nightly --allow-downgrade -c rustfmt clippy
wget https://toolchains.bootlin.com/downloads/releases/toolchains/riscv64-lp64d/tarballs/riscv64-lp64d--musl--stable-2023.11-1.tar.bz2
mkdir -p toolchain
mv riscv64-lp64d--musl--stable-2023.11-1.tar.bz2 toolchain/
cd toolchain
tar -xvjf riscv64-lp64d--musl--stable-2023.11-1.tar.bz2
cd ..

cat >> $HOME/.cargo/config.toml << EOF
[target.riscv64gc-unknown-linux-musl]
linker = "`pwd`/toolchain/riscv64-lp64d--musl--stable-2023.11-1/bin/riscv64-buildroot-linux-musl-gcc.br_real"
rustflags = [
    "-C", "target-feature=-crt-static",
    "-C", "link-arg=--sysroot=`pwd`/toolchain/riscv64-lp64d--musl--stable-2023.11-1/riscv64-buildroot-linux-musl/sysroot",
    # "-C", "target-feature=+crt-static", # Uncomment me to force static compilation
    # "-C", "panic=abort", # Uncomment me to avoid compiling in panics
]
EOF

# compile command:
# cargo +nightly build --target riscv64gc-unknown-linux-musl -Zbuild-std --release
