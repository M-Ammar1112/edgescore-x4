# Firmware applications

Application code is intentionally deferred until the RISC-V custom-instruction
encoding and PicoRV32 PCPI integration are tested.

The C++ model is currently the executable golden implementation. Firmware must
not silently substitute a host implementation for hardware behavior.