## RV32I Core - Microarchitecture Evaluation for RV32I base ISA
This project aims to evaluate 4 basic microarchitectures for RV32I base ISA. 
1. Single-cycle
2. Multi-cycle
3. 5-staged pipeline (no data forwarding)
4. 5-staged pipeline (with data forwarding)

### Single-cycle Core.pdf
&nbsp;
![Singlecycle](https://github.com/SachiniW/RISC-V_Processor/blob/main/Images/Single_cycle_datapath.png).
&nbsp;

### Multi-cycle Core
&nbsp;
![Multicycle](https://github.com/SachiniW/RISC-V_Processor/blob/main/Images/Multi_cycle_datapath.png).
### 5-staged pipeline Core
&nbsp;
![Pipeline](https://github.com/SachiniW/RISC-V_Processor/blob/main/Images/Pipeline_datapath.png).
&nbsp;

### Directory Hierarchy

The repo is organized as follows:
- `Images` : Block diagrams of microarchitectures
- `PyRV32I`  : A tiny python based riscv emulator (https://github.com/vithurson/PyRV32I)
- `rtl` : Contains all the RTL files and verilator drivers
- `testcase_gen` : RV32I ISA random test cases generator (https://github.com/Amrsaeed/riscv_test_generator)

### Simulation using verilator 

This project uses `verilator` for simulation and `PyRV32I` as the compiler for C programs.

- First clone the RV32I Core
```
git clone https://github.com/SachiniW/RISC-V_Processor.git
```
- The RV32I instructions for a basic C code is added to the repo as `rtl/src/instruction_memory.mem`. To run the simulation the default C code,
```
cd RISC-V Processor/rtl/src
./run.sh
```
- Simulation can be carried out in 3 paths
    1. Simulation using 5-staged pipelined design with the default C code in the memory.
        ```
        ./run.sh
        ```
    2. Simulation using a selected design with the default C code in the memory.
        ```
        ./run.sh eval
        ```
    3. Simulation using a selected design with a custom C code in the memory. 
       - To execute this command toolchain should be present in `PyRV32I/toolChain` folder. 
       - Download tool chain from https://github.com/stnolting/riscv-gcc-prebuilt/releases/download/rv32i-2.0.0/riscv32-unknown-elf.gcc-10.2.0.rv32i.ilp32.newlib.tar.gz
       - Extract and put the contents into toolChain folder
        ```
        ./run.sh eval new
        ```
### Synthesizing for FPGAs

The project was initially intended to support synthesis on FPGAs. Hence, the current designs have been synthesized but have not been tested in hardware. 
### Followings are the **`Verilog HDL`** modules and testbenches used in the project.
- Verilog modules : `rtl/src/`
- Testbenches : `rtl/tb/`

| Module | Testbench | Description |
| --- | --- | --- |
| `CorePipeForwarding.v` | `-` | Core for the pipelined processor with a forwarding unit |
| `CorePipe.v` | `CorePipeTB.v` | Core for the pipelined processor without a forwarding unit |
| `CoreMS.v` | `CoreMSTB.v` | Core for the multi cycle processor |
| `Core.v` | `CoreTB.v` | Integrates the modules needed for a single cycle processor core |
| `ControlMS.v` | `ControlMS.v` | Control unit of the multi cycle processor |
| `Control.v` | `-` | Control unit of the single cycle and pipelined processor |
| `DataMemory.v` | `DataMemoryTB.v` | Contains the data memory |
| `InstMemory.v` | `InstMemoryTB.v` | Contains the instruction memory |
| `ImmExtend.v` | `ImmExtendTB.v` | Performs sign extension on the immediates |
| `PCSelect.v` | `-` | Updates the program counter |
| `RegFile.v` | `RegFileTB.v` | 32 bit register file for the single cycle and multi cycle processors |
| `RegFilePipe.v` | `-` | 32 bit register file for the pipelined processor |
| `StallUnit.v` | `StallUnitTB.v` | Stalling unit for the pipelined processor |
| `ForwardingUnit.v` | `-` | Forwarding unit for the pipelined processor |
| `ALU.v` | `ALU_tb.v` | Arithmetic and logic unit of the core |
| `BranchLogic.v` | `BranchLogic_tb.v` | Unit to decide the branching instruction operations |
| `define.v` | `-` | File which defines the used parameters |

### Future work

- Testing on hardware