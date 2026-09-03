.PHONY: help doctor submodules configure build test lint-rtl clean ci

help:
	@printf '%s\n' \
		'make help       Show available developer targets' \
		'make doctor     Report required and optional tools' \
		'make submodules Initialize Git submodules' \
		'make configure  Configure CMake in build/' \
		'make build      Build project-owned C++ targets' \
		'make test       Run CTest with failure output' \
		'make lint-rtl   Run Verilator lint when installed' \
		'make clean      Remove build and RTL output' \
		'make ci         Run the bootstrap CI checks'

doctor:
	@./scripts/doctor.sh

submodules:
	@git submodule update --init --recursive

configure: submodules
	@cmake -S . -B build

build: configure
	@cmake --build build

test: build
	@ctest --test-dir build --output-on-failure

lint-rtl:
	@if command -v verilator >/dev/null 2>&1; then \
		verilator --lint-only --Wall -Wno-fatal --sv rtl/edgescore_pkg.sv rtl/edgescore_pcpi.sv; \
	else \
		printf '%s\n' 'Verilator: MISSING OPTIONAL (RTL lint skipped locally)'; \
	fi

clean:
	@rm -rf build obj_dir

ci: doctor submodules configure build test lint-rtl
	@git diff --check