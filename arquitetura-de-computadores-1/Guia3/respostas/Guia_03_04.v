/*
 Guia_03_04.v
 867160 - MiguelPessoaLimaFerreira
*/
module Guia_03_04;
reg signed [7:0] a = 8'b1111_1010;
reg signed [6:0] b = 8'b1111_101;
reg signed [5:0] c = 8'b0001_10;
reg signed [7:0] d = 0;
reg signed [6:0] e = 0;
reg signed [5:0] f = 0;

initial
begin : main
$display ("Guia_0304");
$display ("a = %8b = %d", a, a);
$display ("b = %8b = %d", b, b);
$display ("c = %8b = %d", c, c);
d = a-b;
$display ("d = a-b = %8b-%8b = %8b = %d", a, b, d, d);
d = b-a;
$display ("d = b-a = %8b-%8b = %8b = %d", b, a, d, d);
d = a-c;
$display ("d = a-c = %8b-%8b = %8b = %d", a, c, d, d);
d = c-a;
$display ("d = c-a = %8b-%8b = %8b = %d", c, a, d, d);

end 
endmodule 