import java.io.IOException;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.util.Scanner;

class u13 {
    public static boolean LF_isFim(String array) //condicao de parada ao encontrar a string fim
    {
        if (array.charAt(0) == 'F' && array.charAt(1) == 'I' && array.charAt(2) == 'M') 
        {
            return true;
        }
        return false;
    }
    public static String getHtml(String endereco) //codigo para ler pagina html,
    //feita com o exempplo do github
    {
        StringBuilder resp = new StringBuilder();
        try 
        {
            HttpClient client = HttpClient.newHttpClient();
            HttpRequest request = HttpRequest.newBuilder()
                    .uri(URI.create(endereco))
                    .GET()
                    .build();
            HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
            if (response.statusCode() == 200) 
            {
                resp.append(response.body());
            } else 
            {
                System.out.println("Erro na conexão: " + response.statusCode());
            }
        } catch (IOException | InterruptedException e) 
        {
            e.printStackTrace();
        }
        return resp.toString();
    }
    public static void main(String[] zzz) 
    {
        Scanner s = new Scanner(System.in);
        String name = s.nextLine();
        String endereco = s.nextLine();
        String html = getHtml(endereco);
        //adicionaum contador para cada tipo de caracter
        int a = 0;
        int e = 0;
        int i = 0;
        int o = 0;
        int u = 0;
        int b = 0;
        int c = 0;
        int f = 0;
        int g = 0;
        int h = 0;
        int j = 0;
        int k = 0;
        int l = 0;
        int m = 0;
        int n = 0;
        int p = 0;
        int q = 0;
        int r = 0;
        int t = 0;
        int v = 0;
        int w = 0;
        int x = 0;
        int consoante = 0;
        int br = 0;
        int table = 0;
        while (!LF_isFim(name)) //verifica cada termo e aumenta seu contador
        {
            for (int z = 0; z < html.length(); z++) 
            {
                if (html.charAt(z) == 'a') 
                {
                    a++;
                }
                if (html.charAt(z) == 'e') 
                {
                    e++;
                }
                if (html.charAt(z) == 'i') 
                {
                    i++;
                }
                if (html.charAt(z) == 'o') 
                {
                    o++;
                }
                if (html.charAt(z) == 'u') 
                {
                    u++;
                }
                if (html.charAt(z) == '\u00e1') 
                {
                    b++;
                }
                if (html.charAt(z) == '\u00e9') 
                {
                    c++;
                }
                if (html.charAt(z) == '\u00ed') 
                {
                    f++;
                }
                if (html.charAt(z) == '\u00f3') 
                {
                    g++;
                }
                if (html.charAt(z) == '\u00fa') 
                {
                    h++;
                }
                if (html.charAt(z) == '\u00e0') 
                {
                    j++;
                }
                if (html.charAt(z) == '\u00e8') 
                {
                    k++;
                }
                if (html.charAt(z) == '\u00ec')
                {
                    l++;
                }
                if (html.charAt(z) == '\u00f2') 
                {
                    m++;
                }
                if (html.charAt(z) == '\u00f9') 
                {
                    n++;
                }
                if (html.charAt(z) == '\u00e3') 
                {
                    p++;
                }
                if (html.charAt(z) == '\u00f5') 
                {
                    q++;
                }
                if (html.charAt(z) == '\u00e2')
                {
                    r++;
                }
                if (html.charAt(z) == '\u00ea') 
                {
                    t++;
                }
                if (html.charAt(z) == '\u00ee') 
                {
                    v++;
                }
                if (html.charAt(z) == '\u00f4') 
                {
                    w++;
                }
                if (html.charAt(z) == '\u00fb') 
                {
                    x++;
                }
                if (z + 3 < html.length() && html.charAt(z) == '<' && html.charAt(z + 1) == 'b' && html.charAt(z + 2) == 'r' && html.charAt(z + 3) == '>') 
                {
                    br++;
                    z += 3;
                }
                if (z + 6 < html.length() && html.charAt(z) == '<' && html.charAt(z + 1) == 't' && html.charAt(z + 2) == 'a' &&
                        html.charAt(z + 3) == 'b' && html.charAt(z + 4) == 'l' && html.charAt(z + 5) == 'e' && html.charAt(z + 6) == '>') 
                {
                    table++;
                    z += 6;
                }
                if ((html.charAt(z) >= 'a' && html.charAt(z) <= 'z') && html.charAt(z) != 'a' && html.charAt(z) != 'e'
                        && html.charAt(z) != 'i' && html.charAt(z) != 'o' && html.charAt(z) != 'u' && html.charAt(z) != '\u00e1' && html.charAt(z) != '\u00e9'
                        && html.charAt(z) != '\u00ed' && html.charAt(z) != '\u00f3' && html.charAt(z) != '\u00fa' && html.charAt(z) != '\u00e3'
                        && html.charAt(z) != '\u00f5' && html.charAt(z) != '\u00e0' && html.charAt(z) != '\u00e8' && html.charAt(z) != '\u00ec'
                        && html.charAt(z) != '\u00f2' && html.charAt(z) != '\u00f9') {
                    consoante++;
                }
            }
            //mostra cada contador
            MyIO.print("a(" + a + ") ");
            MyIO.print("e(" + e + ") ");
            MyIO.print("i(" + i + ") ");
            MyIO.print("o(" + o + ") ");
            MyIO.print("u(" + u + ") ");
            MyIO.print("á(" + b + ") ");
            MyIO.print("é(" + c + ") ");
            MyIO.print("í(" + f + ") ");
            MyIO.print("ó(" + g + ") ");
            MyIO.print("ú(" + h + ") ");
            MyIO.print("à(" + j + ") ");
            MyIO.print("è(" + k + ") ");
            MyIO.print("ì(" + l + ") ");
            MyIO.print("ò(" + m + ") ");
            MyIO.print("ù(" + n + ") ");
            MyIO.print("ã(" + p + ") ");
            MyIO.print("õ(" + q + ") ");
            MyIO.print("â(" + r + ") ");
            MyIO.print("ê(" + t + ") ");
            MyIO.print("î(" + v + ") ");
            MyIO.print("ô(" + w + ") ");
            MyIO.print("û(" + x + ") ");
            MyIO.print("consoante(" + consoante + ") ");
            MyIO.print("<br>(" + br + ") ");
            MyIO.print("<table>(" + table + ") ");
            MyIO.print(name);
            //reinicia variaveis
            a = 0;
            e = 0;
            i = 0;
            o = 0;
            u = 0;
            b = 0;
            c = 0;
            f = 0;
            g = 0;
            h = 0;
            j = 0;
            k = 0;
            l = 0;
            m = 0;
            n = 0;
            p = 0;
            q = 0;
            r = 0;
            t = 0;
            v = 0;
            w = 0;
            x = 0;
            consoante = 0;
            br = 0;
            table = 0;
            //le os dados novamente
            name = s.nextLine();
            if (!LF_isFim(name)) {
                endereco = s.nextLine();
                html = getHtml(endereco);
            }
            System.out.println();
        }
        s.close();
    }
}