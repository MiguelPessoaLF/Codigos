/*
 Guia_02_05.v
 867160 - MiguelPessoaLimaFerreira
*/
module Guia_0205;
reg [7:0] a = 8'b000_1010 ;
reg [7:0] b = 8'b000_1100 ;
reg [7:0] c;
initial
begin : main
$display ("Guia_0205 - Tests");
$display ("a = %8b", a);
$display ("b = %8b", b);
c = a+b;
$display ("c = a+b = %8b", c);
c = a-b;
$display ("c = a-b = %8b", c);
c = b-a;
$display ("c = b-a = %8b", c);
c = a*b;
$display ("c = a*b = %8b", c);
c = b/a;
$display ("c = b/a = %8b", c);
c = b%a;
$display ("c = b%%a = %8b", c);
end
endmodule