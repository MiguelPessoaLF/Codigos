/*
 Guia_01_04.v
 867160 - MiguelPessoaLimaFerreira
*/
module Guia_01_04;
integer x = 13;
reg[7:0] b = 0;

initial
begin:main
$display ("Guia_01_04 - tests");
$display ("x = %d", x);
b = x;
$display ("b = [%4b][%4b] = %x , %x", b[7:4],b[3:0],b[7:4],b[3:0]);
end
//separa em blocos o valor de b,
//exibindo os 4 primeiros bits em uma parte e os outros na outra
endmodule