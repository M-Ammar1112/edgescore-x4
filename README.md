# EdgeScore-X4

EdgeScore-X4 is a small RISC-V TinyML coprocessor project for four-lane packed
INT8 operations.

## Status

Bootstrap / Work in Progress. The C++ golden model and build foundation are
usable; the accelerator hardware is planned and is not implemented yet.

## What EdgeScore-X4 Will Provide

The project will explore a compact PicoRV32 PCPI coprocessor, firmware APIs,
verification infrastructure, and small INT8 machine-learning applications.

## Planned Instructions

- `ESX.DOT4`: four-lane signed INT8 dot product
- `ESX.SAD4`: four-lane signed INT8 sum of absolute differences

## Architecture

```text
                    +----------------+
                    |    PicoRV32    |
                    |      PCPI      |
                    +-------+--------+
                            |
                            v
                    +----------------+
                    |  EdgeScore-X4  |
                    |   DOT4 / SAD4  |
                    +----------------+
```

## Repository Layout

`model/` contains the C++ reference, `rtl/` the SystemVerilog shell,
`firmware/` and `tests/asm/` future software surfaces, `verification/` the
Verilator/UVM scaffolding, and `docs/` the project specifications.

## Quick Start

```sh
git clone --recursive https://github.com/M-Ammar1112/edgescore-x4.git
cd edgescore-x4
make doctor
make configure
make build
make test
make lint-rtl
```

## Tool Requirements

Required: Git, CMake, Make, and a C++17 compiler. Optional: Verilator for RTL
lint, plus Yosys, a RISC-V GCC toolchain, and Icarus Verilog for future work.

## Development Roadmap

See [docs/roadmap.md](docs/roadmap.md). The next hardware milestone is DOT4.

## Verification Strategy

See [docs/verification.md](docs/verification.md). C++ tests are active now;
UVM and processor integration remain future layers.

## License

To be determined before the first public IP release.# edgescore-x4
Timy hardware accelerator
