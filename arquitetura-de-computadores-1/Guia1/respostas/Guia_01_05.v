/*
 Guia_01_01.v
 867160 - MiguelPessoaLimaFerreira
*/
module Guia_01_05;

integer x = 13;//define um valor inteiro para x
reg[7:0] b = 0;//define b como um valor em binario
reg[0:2][7:0] s = "PUC"; //guarda puc na variavel s
initial//bloco que é executado quando o simulador inicia
begin:main//nomeia o bloco
$display ("Guia_01_01 - tests");//indentificação
$display ("x = %d", x);//mostra x
$display ("b = %8b", b);//mostra b em binario, com 8 bits
$display ( "s = %s" , s );//mostra o "array" puc
b = x;//modifica o valor de b e ja converte para binario
$display ("b = [%4b][%4b] = %h , %h", b[7:4],b[3:0],b[7:4],b[3:0]);//mostra os valores de x e b em binario e hexadecimal
s[0] = "-";//muda o valor da primeira posicao de s para "-"
s[1] = 8'b01001101;//muda o valor da segunda posicao de s para o valor de "M" na tabela ascii em binario
s[2] = 71;//muda o valor da terceira posicao de s para o valor de "G" na tabela ascii em hexadecimal
$display ("s = %s", s);//exibe oque foi guardado nas posicoes em formato char
end

endmodule