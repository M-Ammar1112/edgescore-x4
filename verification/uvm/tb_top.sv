`default_nettype none

module tb_top;
  logic clk = 1'b0;
  always #5 clk = ~clk;

  edgescore_if pcpi_if(clk);

  // TODO(EdgeScore): Instantiate the DUT and connect the UVM testbench.
endmodule

`default_nettype wire
