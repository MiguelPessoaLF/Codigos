/*
 Guia_02_03.v
 867160 - MiguelPessoaLimaFerreira
*/
module Guia_0203;
real
x = 0.625;
reg [7:0] b = 8'b1010_0000;
initial
begin : main
$display ("Guia_0203 - Tests");
$display ("x = %f" , x);
$display ("b = 0.%8b", b);
$display ("b = 0.%x%x (16)", b[7:4],b[3:0]);
$display ("b = 0.%o%o%o (8) ", b[7:5],b[4:2],b[1:0]);
end
endmodule