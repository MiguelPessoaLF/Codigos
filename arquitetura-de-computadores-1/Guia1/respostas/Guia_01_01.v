/*
 Guia_01_01.v
 867160 - MiguelPessoaLimaFerreira
*/
module Guia_01_01;//inicia o modulo

integer x = 13;//define um valor inteiro para x em decimal
reg[7:0] b = 0;//define b como um valor em binario de 8 bits

initial//bloco que é executado quando o simulador inicia
begin : main//nomeia o bloco
$display ("Guia_01_01 - tests");//indentificação
$display ("x = %d", x);//mostra x
$display ("b = %8b", b);//mostra b em binario, com 8 bits
b = x;//modifica o valor de b e ja converte para binario
$display ("b = %8b, b");//mostra novamente
end//finaliza o bloco initial

endmodule
//fecha o modulo