/*
 Guia_02_02.v
 867160 - MiguelPessoaLimaFerreira
*/
module Guia_0202;
real
x = 0.75;
integer y = 7;
reg [7:0] b = 0;
initial
begin : main
$display ("Guia_0202 - Tests");
$display ("x = %f" , x);
$display ("b = 0.%8b", b);
while (x > 0 && y >= 0)
begin
if (x*2 >= 1)
begin
b[y] = 1;
x = x*2.0 - 1.0;
end
else
begin
b[y] = 0;
x = x*2.0;
end
$display ( "b = 0.%8b", b );
y=y-1;
end
end
endmodule
//end e begin são p abre chave e fecha chave do verilog