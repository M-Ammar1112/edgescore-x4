# Development

Clone with submodules, then inspect the environment with `make doctor`.
Initialize dependencies with `make submodules`.

Use `make configure`, `make build`, and `make test` for the C++ model. Use
`make lint-rtl` for Verilator lint; missing optional tools are reported rather
than treated as bootstrap failures. `make clean` removes local build output,
and `make ci` runs the local CI-equivalent checks.

Use C++17, explicit signed-width arithmetic, LF line endings, and focused
deterministic tests. Do not format or modify third-party submodules. Keep
unfinished functionality marked with concise `TODO(EdgeScore)` notes.