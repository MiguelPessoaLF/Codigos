/*
 Guia_02_01.v
 867160 - MiguelPessoaLimaFerreira
*/
module Guia_0201;
real
x = 0;
real power2 = 1.0;
integer
y = 7;
reg[7:0] b = 8'b10100000;
initial
begin : main
$display ("Guia_0201 - Tests");
$display ("x = %f" , x);
$display ("b = 0.%8b", b);
while(y >= 0)
begin
power2 = power2 /2.0;
if (b[y] == 1)
begin
x = x + power2;
end
$display ("x = %f", x);
y = y-1;
end
end
endmodule