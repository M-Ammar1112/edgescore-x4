# Architecture

EdgeScore-X4 is deliberately small: it targets four packed INT8 lanes and a
simple PCPI attachment rather than a complete accelerator platform.

```text
C++ golden model -> unit tests
                 -> future DPI-C/UVM scoreboard

RISC-V firmware -> PicoRV32 -> PCPI -> EdgeScore-X4 RTL
```

The C++ model is the current executable architectural specification. Future
RTL will implement the two operations, and PicoRV32 will provide the processor
context through PCPI. Firmware will expose a stable C API after that contract
is tested. Planned TinyML applications will consume the operations without
requiring a TensorFlow runtime.