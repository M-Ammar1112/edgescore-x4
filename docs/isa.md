# Instruction Set Draft

## Draft v0.1

EdgeScore-X4 plans two project-specific RISC-V custom instructions using
`CUSTOM-0` (`opcode = 0x0B`) and an R-type-style encoding:

| Field | Value | Instruction |
| --- | --- | --- |
| `funct7` | `0000000` | reserved for this draft |
| `funct3` | `000` | `ESX.DOT4` |
| `funct3` | `001` | `ESX.SAD4` |

`rd` receives the result and `rs1`/`rs2` provide packed operands. Bits 7:0,
15:8, 23:16, and 31:24 are lanes 0 through 3. Every lane is interpreted as a
signed two's-complement INT8 value.

`ESX.DOT4` returns the signed sum of four lane products. `ESX.SAD4` returns the
unsigned sum of four absolute signed lane differences, with a maximum of 1020.

These encodings are project-specific and may change before the ISA is frozen.
GCC and binutils are not patched in this milestone. Assembly tests will use
`.insn` or `.word` once the encoding and integration are tested.