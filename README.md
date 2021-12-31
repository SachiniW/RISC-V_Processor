# RISC-V_Processor
Pipelined processor design to support the RISC-V 32I ISA

## Followings are the **`Verilog HDL`** files used in the project.

| File | Description |
| --- | --- |
| `CorePipeForwarding.v` | Core for the pipelined processor with a forwarding unit |
| `CorePipe.v` | Core for the pipelined processor without a forwarding unit |
| `CoreMS.v` | Core for the multi cycle processor |
| `Core.v` | Integrates the modules needed for a single cycle processor core |
| `ControlMS.v` | Control unit of the multi cycle processor |
| `Control.v` | Control unit of the single cycle and pipelined processor |
| `DataMemory.v` | Contains the data memory |
| `InstMemory.v` | Contains the instruction memory |
| `ImmExtend.v` | Performs sign extension on the immediates |
| `PCSelect.v` | Updates the program counter |
| `RegFile.v` | 32 bit register file for the single cycle and multi cycle processors |
| `RegFilePipe.v` | 32 bit register file for the pipelined processor |
| `StallUnit.v` | Stalling unit for the pipelined processor |
| `ForwardingUnit.v` | Forwarding unit for the pipelined processor |
| `ALU.v` | Arithmetic and logic unit of the core |
| `BranchLogic.v` | Unit to decide the branching instruction operations |
| `define.v` | Module which defines the used parameters |
