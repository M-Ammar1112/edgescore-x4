# Directed ESX.DOT4 test skeleton.
# Inputs: four packed signed INT8 lanes in rs1 and rs2.
# Expected result: signed sum of four lane products in rd.
# Encoding: CUSTOM-0 (0x0b), funct7=0, funct3=000, R-type fields.
# TODO(EdgeScore): Emit .insn/.word after the encoding is frozen and wire pass/fail.
# Pass path: report success to the future PicoRV32 test harness.
# Fail path: report the observed result and halt.