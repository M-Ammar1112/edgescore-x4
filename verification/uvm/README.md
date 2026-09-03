# UVM scaffolding

The intended verification flow is:

```text
UVM sequence -> driver -> PCPI interface -> EdgeScore RTL
                                      monitor -> scoreboard -> DPI-C -> C++ model
```

This directory contains only the PCPI-facing interface and compile-oriented
top-level/package shells. The planned package components are
`edgescore_item`, `edgescore_sequence`, `edgescore_driver`, `edgescore_monitor`,
`edgescore_agent`, `edgescore_scoreboard`, `edgescore_env`, and
`edgescore_base_test`.

UVM execution is deferred because simulator availability varies; it is not a
default open-source CI requirement.