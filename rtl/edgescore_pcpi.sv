`default_nettype none

module edgescore_pcpi (
    input  logic        clk,
    input  logic        resetn,
    input  logic        pcpi_valid,
    input  logic [31:0] pcpi_insn,
    input  logic [31:0] pcpi_rs1,
    input  logic [31:0] pcpi_rs2,
    output logic        pcpi_wr,
    output logic [31:0] pcpi_rd,
    output logic        pcpi_wait,
    output logic        pcpi_ready
);
  always_comb begin
    pcpi_wr = 1'b0;
    pcpi_rd = 32'b0;
    pcpi_wait = 1'b0;
    pcpi_ready = 1'b0;
  end

  // TODO(EdgeScore): Decode CUSTOM-0 and add DOT4/SAD4 datapaths.
  // TODO(EdgeScore): Implement the PCPI completion handshake.
  logic unused_inputs;
  always_comb begin
    unused_inputs = clk ^ resetn ^ pcpi_valid ^ (^pcpi_insn) ^ (^pcpi_rs1) ^ (^pcpi_rs2);
  end
endmodule

`default_nettype wire
