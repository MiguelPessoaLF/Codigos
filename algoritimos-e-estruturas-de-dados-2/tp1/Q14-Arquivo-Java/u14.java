import java.io.RandomAccessFile;
import java.io.IOException;
class u14 {
    public static void main(String[] zzz) throws IOException {
        //abre um arquivo pubin para escrita
        RandomAccessFile arquivo = new RandomAccessFile("pubin.txt", "rw");
        int n = MyIO.readInt(); //le a primeira linha e guarda para contagem de repetições
        //escreve os valores double no arquivo
        for (int i = 0; i < n; i++) 
        {
            double x = MyIO.readDouble();
            arquivo.writeDouble(x);
        }
        arquivo.close(); //fecha o arquivo para escrita
        //abre o mesmo arquivo para leitura
        arquivo = new RandomAccessFile("pubin.txt", "r");
        //le os valores de tras para frente
        for (int o = n - 1; o >= 0; o--) 
        {
            arquivo.seek(o * 8); //posiciona o ponteiro na linha final e com tamanho para a leitura
            //de um valor double
            double num = arquivo.readDouble(); //le valores double no arquivo
            int num_int = (int)num;//valores decimais com casas decdimais = a 0 serao
            //mostrado apenas como int
            if(num == num_int) {MyIO.println(num_int);}
            else {MyIO.println(num);}
        }
        arquivo.close();//fecha o arquivo final
    }
}