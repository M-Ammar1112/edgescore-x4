# Directed corner-case skeleton for ESX.DOT4 and ESX.SAD4.
# Inputs include signed INT8 values -128 and 127, plus all-zero vectors.
# Expected SAD4 maximum is 1020; DOT4 must preserve signed products.
# TODO(EdgeScore): Add executable instructions after PCPI integration is tested.
# Pass/fail paths will be provided by the future RISC-V harness.