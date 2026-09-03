# Verification Strategy

The project will grow through four layers:

1. C++ unit tests validate the signed lane semantics and corner cases.
2. Standalone RTL and UVM verification compare PCPI behavior with the model.
3. RISC-V assembly integration tests exercise encoded instructions on PicoRV32.
4. C firmware and application tests validate the user-facing API and demos.

Only the first layer and Verilator lint are active in the bootstrap.