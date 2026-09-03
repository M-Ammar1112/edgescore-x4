#!/usr/bin/env sh
set -u

printf '%s\n\n' 'EdgeScore-X4 development environment'
required_missing=0

printf '%s\n' 'Required:'
for tool in git cmake make c++; do
  if command -v "$tool" >/dev/null 2>&1; then
    printf '[FOUND] %s %s\n' "$tool" "$("$tool" --version 2>/dev/null | head -n 1)"
  else
    printf '[MISSING REQUIRED] %s\n' "$tool"
    required_missing=1
  fi
done

printf '%s\n' '' 'Optional:'
for tool in verilator yosys riscv64-unknown-elf-gcc riscv32-unknown-elf-gcc iverilog; do
  if command -v "$tool" >/dev/null 2>&1; then
    printf '[FOUND] %s %s\n' "$tool" "$("$tool" --version 2>/dev/null | head -n 1)"
  else
    printf '[MISSING OPTIONAL] %s\n' "$tool"
  fi
done

printf '%s\n' '' 'Submodules:'
for path in third_party/googletest third_party/picorv32; do
  if git submodule status -- "$path" | grep -q '^[ -+ ]'; then
    printf '[OK] %s\n' "$path"
  else
    printf '[MISSING] %s\n' "$path"
  fi
done

exit "$required_missing"