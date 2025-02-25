/*
 Guia_01_01.v
 867160 - MiguelPessoaLimaFerreira
*/
module Guia_01_03;
integer x = 13;
reg[7:0] b = 0;

initial
begin:main
$display ("x = %d", x);
$display ("b = %8b", b);
b = x;
$display ("b = %B (2) = %o(8) = %x(16) = %X(16)", b, b, b, b);
//%B == binario
//%o == octal
//%x == hexadecimal
//%X == hexadecimal, a diferença é a forma de exibição?
end

endmodule