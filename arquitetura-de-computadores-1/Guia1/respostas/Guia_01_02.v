/*
 Guia_01_02.v
 867160 - MiguelPessoaLimaFerreira
*/
module Guia_01_02;//inicia o modulo

integer x = 0; //define um valor para x na base decimal
reg [7:0]b = 8'b0001101;//define um valor em binario para b
//o valor reg é um registrador, que define a quantidade de bits
//da variavel, em posicoes de 0 a 7, totalizando 8 bits
initial //define o bloco que sera executado ao iniciar o simulador

begin:main //nomeia o bloco
$display ("Guia_01_02 - Tests");
$display ("x = %d", x);
$display ("b = %8b", b);
x = b; // dessa vez, faz a conversao reversa
$display ("b = %d", x); //mostra o numero b em decimal
end

endmodule
