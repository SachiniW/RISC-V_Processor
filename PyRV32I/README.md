Tiny python based riscv emulator


Download tool chain from 
https://github.com/stnolting/riscv-gcc-prebuilt/releases/download/rv32i-2.0.0/riscv32-unknown-elf.gcc-10.2.0.rv32i.ilp32.newlib.tar.gz



extract and put the contents into toolChain folder



then run make

data_hex.txt will have the binary to be loaded to the processor

to make the printf function working, print the writes to this 0xe0001030 address as ascii char
