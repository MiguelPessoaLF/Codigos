import java.time.*;
import java.time.format.DateTimeFormatter;
import java.util.*;
import java.io.*;
import java.text.SimpleDateFormat;

public class tp4 {
    public static int comp = 0;

    public static class MyDate {// classe data
        private String date_added;
        private String date_realese;
    }

    public static class Show {// classe show que armazena todos os dados lidos, inclusive, em
        // um atributo da classe data
        private String SHOW_ID;
        private String TYPE;
        private String TITLE;
        private String[] DIRECTOR;
        private String[] CAST;
        private String COUNTRY;
        private MyDate DATE = new MyDate();
        private String RATING;
        private String DURATION;
        private String[] LISTED_IN;
        private String DESCRIPTION;
        public int QUESTION;

        Show() {// construtor nulo
        }

        Show(
                String SHOW_ID,
                String TYPE,
                String TITLE,
                String[] DIRECTOR,
                String[] CAST,
                String COUNTRY,
                String DATE_ADDED,

                String DATE_REALESE,
                String RATING,
                String DURATION,
                String[] LISTED_IN,
                String DESCRIPTION)// construtor padrao
        {
            this.SHOW_ID = SHOW_ID;
            this.TYPE = TYPE;
            this.TITLE = TITLE;
            this.DIRECTOR = DIRECTOR;
            this.CAST = CAST;
            this.COUNTRY = COUNTRY;
            this.DATE.date_added = DATE_ADDED;
            this.DATE.date_realese = DATE_REALESE;
            this.RATING = RATING;
            this.DURATION = DURATION;
            this.LISTED_IN = LISTED_IN;
            this.DESCRIPTION = DESCRIPTION;
        }

        // gets e sets
        public void set_SHOW_ID(String id) {
            this.SHOW_ID = id;
        }

        public void set_TYPE(String type) {
            this.TYPE = type;
        }

        public void set_TITLE(String title) {
            this.TITLE = title;
        }

        public void set_DIRECTOR(String[] director) {
            this.DIRECTOR = director;
        }

        public void set_CAST(String[] cast) {
            this.CAST = cast;
        }

        public void set_COUNTRY(String country) {
            this.COUNTRY = country;
        }

        public void set_DATE_ADDED(String date) {
            this.DATE.date_added = date;
        }

        public void set_DATE_REALESE(String date) {
            this.DATE.date_realese = date;
        }

        public void set_RATING(String rating) {
            this.RATING = rating;
        }

        public void set_DURATION(String duration) {
            this.DURATION = duration;
        }

        public void set_LISTED_IN(String[] listed_in) {
            this.LISTED_IN = listed_in;
        }

        public void set_DESCRIPTION(String descrition) {
            this.DESCRIPTION = descrition;
        }

        public String get_SHOW_ID() {
            return SHOW_ID;
        }

        public String get_TYPE() {
            return TYPE;
        }

        public String get_TITLE() {
            return TITLE;
        }

        public String[] get_DIRECTOR() {
            return DIRECTOR;
        }

        public String[] get_CAST() {
            return CAST;
        }

        public String get_COUNTRY() {
            return COUNTRY;
        }

        public String get_DATE_ADDED() {
            return DATE.date_added;
        }

        public String get_DATE_REALESE() {
            return DATE.date_realese;
        }

        public String get_RATING() {
            return RATING;
        }

        public String get_DURATION() {
            return DURATION;
        }

        public String[] get_LISTED_IN() {
            return LISTED_IN;
        }

        public String get_DESCRIPTION() {
            return DESCRIPTION;
        }

        public Show make(String x) {// recebe a string lida e interpreta cada parte da sequencia
            Show new_show = new Show();
            new_show.DIRECTOR = new String[50];
            new_show.CAST = new String[50];
            new_show.LISTED_IN = new String[50];
            int i = 0;
            String temp = "";

            // SHOW_ID
            while (i < x.length() && x.charAt(i) != ',') {
                if (x.charAt(i) != '"')
                    temp += x.charAt(i);
                i++;
            }
            if (temp.equals(""))
                temp = "NaN";
            new_show.SHOW_ID = temp;
            temp = "";
            if (i + 1 < x.length())
                i++;

            // TYPE
            while (i < x.length() && x.charAt(i) != ',') {
                if (x.charAt(i) != '"')
                    temp += x.charAt(i);
                i++;
            }
            if (temp.equals(""))
                temp = "NaN";
            new_show.TYPE = temp;
            temp = "";
            if (i + 1 < x.length())
                i++;
            int stop = 0;
            // TITLE
            if (x.charAt(i) == '"') {
                i++;
                while (i < x.length() && stop == 0) {
                    if (x.charAt(i) == '"' && x.charAt(i + 1) == '"')
                        i += 2;
                    if (x.charAt(i) == '"' && x.charAt(i + 1) != '"')
                        stop++;
                    if (x.charAt(i) != '"')
                        temp += x.charAt(i);
                    i++;
                }
            } else {
                while (i < x.length() && x.charAt(i) != ',') {
                    if (x.charAt(i) != '"')
                        temp += x.charAt(i);
                    i++;
                }
            }
            if (temp.equals(""))
                temp = "NaN";
            new_show.TITLE = temp;
            temp = "";
            if (i + 1 < x.length())
                i++;
            // DIRECTOR
            int directorIndex = 0;
            temp = "";
            if (i < x.length() && x.charAt(i) == '"') {
                i++;
                while (i < x.length() && x.charAt(i) != '"') {
                    if (x.charAt(i) == ',') {
                        new_show.DIRECTOR[directorIndex++] = Space_remove(temp);
                        temp = "";
                    } else {
                        temp += x.charAt(i);
                    }
                    i++;
                }
                if (!temp.isEmpty())
                    new_show.DIRECTOR[directorIndex++] = Space_remove(temp);
                i++;
            } else {
                while (i < x.length() && x.charAt(i) != ',') {
                    if (x.charAt(i) != '"')
                        temp += x.charAt(i);
                    i++;
                }
                new_show.DIRECTOR[directorIndex] = temp;
            }
            if (new_show.DIRECTOR[directorIndex] == "")
                new_show.DIRECTOR[directorIndex] = "NaN";
            if (i < x.length() && x.charAt(i) == ',')
                i++;

            // CAST

            int castIndex = 0;
            temp = "";
            stop = 0;
            if (i < x.length() && x.charAt(i) == '"') {
                i++;
                while (i < x.length() && stop == 0) {
                    if (x.charAt(i) == ',') {
                        new_show.CAST[castIndex++] = Space_remove(temp);
                        temp = "";
                    } else {
                        if (x.charAt(i) == '"' && x.charAt(i + 1) == '"')
                            i += 2;
                        if (x.charAt(i) == '"' && x.charAt(i + 1) != '"')
                            stop++;
                        if (x.charAt(i) != '"')
                            temp += x.charAt(i);
                    }
                    i++;
                }
                if (!temp.isEmpty())
                    new_show.CAST[castIndex++] = Space_remove(temp);
            } else {
                while (i < x.length() && x.charAt(i) != ',') {
                    if (x.charAt(i) != '"')
                        temp += x.charAt(i);
                    i++;
                }
                new_show.CAST[castIndex] = temp;
            }
            if (new_show.CAST[castIndex] == "")
                new_show.CAST[castIndex] = "NaN";
            if (i < x.length() && x.charAt(i) == ',')
                i++;

            // COUNTRY
            temp = "";
            if (i < x.length() && x.charAt(i) == '"') {
                i++;
                while (i < x.length() && x.charAt(i) != '"') {
                    temp += x.charAt(i);
                    i++;
                }
                i++;
            } else {
                while (i < x.length() && x.charAt(i) != ',') {
                    temp += x.charAt(i);
                    i++;
                }
            }
            if (temp.equals(""))
                temp = "NaN";
            new_show.COUNTRY = Space_remove(temp);
            if (i < x.length() && x.charAt(i) == ',')
                i++;

            // DATE_ADDED
            temp = "";
            if (i < x.length() && x.charAt(i) == '"') {
                i++;
                while (i < x.length() && x.charAt(i) != '"') {
                    temp += x.charAt(i);
                    i++;
                }
                i++;
            }
            if (temp.equals(""))
                temp = "March 1, 1900";
            new_show.DATE.date_added = temp;
            if (i < x.length() && x.charAt(i) == ',')
                i++;

            // DATE_RELEASE
            temp = "";
            while (i < x.length() && x.charAt(i) != ',') {
                if (x.charAt(i) != '"')
                    temp += x.charAt(i);
                i++;
            }
            if (temp.equals(""))
                temp = "NaN";
            new_show.DATE.date_realese = temp;
            temp = "";
            if (i < x.length() && x.charAt(i) == ',')
                i++;

            // RATING
            while (i < x.length() && x.charAt(i) != ',') {
                if (x.charAt(i) != '"')
                    temp += x.charAt(i);
                i++;
            }
            if (temp.equals(""))
                temp = "NaN";
            new_show.RATING = temp;
            temp = "";
            if (i < x.length() && x.charAt(i) == ',')
                i++;

            // DURATION
            while (i < x.length() && x.charAt(i) != ',') {
                if (x.charAt(i) != '"')
                    temp += x.charAt(i);
                i++;
            }
            if (temp.equals(""))
                temp = "NaN";
            new_show.DURATION = temp;
            temp = "";
            if (i < x.length() && x.charAt(i) == ',')
                i++;

            // LISTED_IN
            int listedIndex = 0;
            temp = "";
            if (i < x.length() && x.charAt(i) == '"') {
                i++;
                while (i < x.length() && x.charAt(i) != '"') {
                    if (x.charAt(i) == ',') {
                        new_show.LISTED_IN[listedIndex++] = Space_remove(temp);
                        temp = "";
                    } else {
                        temp += x.charAt(i);
                    }
                    i++;
                }
                if (!temp.isEmpty())
                    new_show.LISTED_IN[listedIndex++] = Space_remove(temp);
                i++;
            } else {
                while (i < x.length() && x.charAt(i) != ',') {
                    if (x.charAt(i) != '"')
                        temp += x.charAt(i);
                    i++;
                }
                new_show.LISTED_IN[listedIndex] = temp;
            }
            if (new_show.LISTED_IN[listedIndex] == "")
                new_show.LISTED_IN[listedIndex] = "NaN";
            if (i < x.length() && x.charAt(i) == ',')
                i++;

            // DESCRIPTION
            while (i < x.length()) {
                if (x.charAt(i) != '"')
                    temp += x.charAt(i);
                i++;
            }
            if (temp.equals(""))
                temp = "NaN";
            new_show.DESCRIPTION = temp;

            return new_show;// retorna o objeto completo
        }

        public static Show[] read(String filename) throws Exception {// cria uma sequencia de objetos show e chama o
                                                                     // metodo make para interpretar cada uma delas
            Show[] ss = new Show[1400];// criação do arranjo de objetos
            Show call = new Show();// objeto chamador
            File f = new File(filename);
            Scanner s = new Scanner(f);
            String temp = s.nextLine();
            int i = 0;
            while (s.hasNext()) {// leitura
                temp = s.nextLine();
                // System.out.println(temp);
                ss[i] = call.make(temp);
                i++;
            }
            s.close();
            return ss;
        }

        public static boolean bigger(String a, String b) {
            int len = Math.min(a.length(), b.length());
            for (int i = 0; i < len; i++) {
                comp++;
                if (a.charAt(i) > b.charAt(i))
                    return true;
                comp++;
                if (a.charAt(i) < b.charAt(i))
                    return false;
            }
            comp++;
            return a.length() > b.length();
        }

        public static void ord(String[] array, int tamanho) {// ordena strings por ordem alfabetica
            for (int i = 0; i < tamanho - 1; i++) {
                for (int j = 0; j < tamanho - i - 1; j++) {
                    if (array[j] != null && array[j + 1] != null && bigger(array[j], array[j + 1])) {
                        String temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                }
            }
        }

        public void print(Show show) {// mostra cada atributo do objeto escolhido, lidando com atributos
                                      // multivalorados que exigem ordenação de forma adequada
            // shows[o].QUESTION = 1;
            System.out.print("=> " + show.SHOW_ID + " ## " + show.TITLE + " ## " + show.TYPE + " ## ");
            for (int j = 0; j < show.DIRECTOR.length && show.DIRECTOR[j] != null; j++) {
                if (j > 0)
                    System.out.print(", ");
                System.out.print(show.DIRECTOR[j]);
            }
            System.out.print(" ## [");
            ord(show.CAST, show.CAST.length);
            for (int j = 0; j < show.CAST.length && show.CAST[j] != null; j++) {
                if (j > 0)
                    System.out.print(", ");
                System.out.print(show.CAST[j]);
            }
            System.out.print("] ## " + show.COUNTRY + " ## " + show.DATE.date_added + " ## " + show.DATE.date_realese
                    + " ## " + show.RATING + " ## " + show.DURATION + " ## [");
            ord(show.LISTED_IN, show.LISTED_IN.length);
            for (int j = 0; j < show.LISTED_IN.length && show.LISTED_IN[j] != null; j++) {
                if (j > 0)
                    System.out.print(", ");
                System.out.print(show.LISTED_IN[j]);
            }
            System.out.println("] ##");
        }

        public void mark(String x, Show[] shows) {
            int o = Integer.parseInt(x) - 1;
            shows[o].QUESTION = 1;
        }

        public int getAno() {// transforma string data em inteiro
            try {
                return Integer.parseInt(this.DATE.date_realese.trim());
            } catch (Exception e) {
                return 0; // ano inválido
            }
        }

        public static int bigger_date(Show[] array, int len) {
            int maior = array[0].getAno();
            for (int i = 1; i < len; i++) {
                if (array[i].getAno() > maior) {
                    maior = array[i].getAno();
                }
            }
            return maior;
        }

        public int get_RELEASE_YEAR() {
            return stringToInt(this.get_DATE_REALESE());
        }
    }

    public static String Char_remove(String x, int i) {// remove um termo escolhido de um arranjo
        String copy = "";
        for (int a = 0; a < x.length(); a++) {
            if (a != i) {
                copy = copy + x.charAt(a);
            }
        }
        return copy;
    }

    public static String Space_remove(String str) {// trim
        int start = 0;
        int end = str.length() - 1;
        while (start <= end && str.charAt(start) == ' ') {
            start++;
        }
        while (end >= start && str.charAt(end) == ' ') {
            end--;
        }
        String result = "";
        for (int i = start; i <= end; i++) {
            result += str.charAt(i);
        }
        return result;
    }

    public static class ListaArranjo {
        private Show[] array;
        private int n;

        public ListaArranjo() {
            this(100);
        }

        public ListaArranjo(int capacidade) {
            array = new Show[capacidade];
            n = 0;
        }

        public void inserirInicio(Show x) throws Exception {
            if (n >= array.length) {
                throw new Exception("Lista cheia!");
            }

            for (int i = n; i > 0; i--) {
                array[i] = array[i - 1];
            }

            array[0] = x;
            n++;
        }

        public void inserirFim(Show x) throws Exception {
            if (n >= array.length) {
                throw new Exception("Lista cheia!");
            }

            array[n++] = x;
        }

        public void inserir(Show x, int pos) throws Exception {
            if (n >= array.length || pos < 0 || pos > n) {
                throw new Exception("Posição inválida!");
            }

            for (int i = n; i > pos; i--) {
                array[i] = array[i - 1];
            }

            array[pos] = x;
            n++;
        }

        public String removerInicio() throws Exception {
            if (n == 0) {
                throw new Exception("Lista vazia!");
            }

            Show temp = array[0];
            for (int i = 0; i < n - 1; i++) {
                array[i] = array[i + 1];
            }
            String resp = temp.get_TITLE();
            array[--n] = null;
            return resp;
        }

        public String removerFim() throws Exception {
            if (n == 0) {
                throw new Exception("Lista vazia!");
            }

            Show temp = array[--n];
            array[n] = null;
            String resp = temp.get_TITLE();
            return resp;
        }

        public String remover(int pos) throws Exception {
            if (n == 0 || pos < 0 || pos >= n) {
                throw new Exception("Posição inválida!");
            }
            Show temp = array[pos];
            for (int i = pos; i < n - 1; i++) {
                array[i] = array[i + 1];
            }
            String resp = temp.get_TITLE();
            array[--n] = null;
            return resp;
        }

        public void mostrar() {
            Show call = new Show();
            for (int i = 0; i < n; i++) {
                call.print(array[i]);
            }
        }

        public boolean pesquisar(Show x) {
            for (int i = 0; i < n; i++) {
                if (array[i] == x) {
                    return true;
                }
            }
            return false;
        }

        public int tamanho() {
            return n;
        }
    }

    public static class Celula { // flexivel
        public Show elemento;
        public Celula prox;

        public Celula() {

        }

        public Celula(Show elemento) {
            this.elemento = elemento;
            this.prox = null;
        }
    }

    public static class Lista { // flexivel
        private Celula primeiro;
        private Celula ultimo;

        public Lista() {
            primeiro = new Celula();
            ultimo = primeiro;
        }

        public void inserirInicio(Show x) {
            Celula tmp = new Celula(x);
            tmp.prox = primeiro.prox;
            primeiro.prox = tmp;
            if (primeiro == ultimo) {
                ultimo = tmp;
            }
            tmp = null;
        }

        public void inserirFim(Show x) {
            ultimo.prox = new Celula(x);
            ultimo = ultimo.prox;
        }

        public Show removerInicio() throws Exception {
            if (primeiro == ultimo) {
                throw new Exception("lista vazia.");
            }
            Celula tmp = primeiro;
            primeiro = primeiro.prox;
            Show resp = primeiro.elemento;
            tmp.prox = null;
            tmp = null;
            return resp;
        }

        public Show removerFim() throws Exception {
            if (primeiro == ultimo) {
                throw new Exception("lista vazia");
            }
            Celula i;
            for (i = primeiro; i.prox != ultimo; i = i.prox)
                ;

            Show resp = ultimo.elemento;
            ultimo = i;
            i = ultimo.prox = null;

            return resp;
        }

        public void inserir(Show x, int pos) throws Exception {

            int tamanho = tamanho();

            if (pos < 0 || pos > tamanho) {
                throw new Exception("Erro ao inserir posicao (" + pos + " / tamanho = " + tamanho + ") invalida!");
            } else if (pos == 0) {
                inserirInicio(x);
            } else if (pos == tamanho) {
                inserirFim(x);
            } else {
                Celula i = primeiro;
                for (int j = 0; j < pos; j++, i = i.prox)
                    ;
                Celula tmp = new Celula(x);
                tmp.prox = i.prox;
                i.prox = tmp;
                tmp = i = null;
            }
        }

        public Show remover(int pos) throws Exception {
            Show resp;
            int tamanho = tamanho();

            if (primeiro == ultimo) {
                throw new Exception("Erro ao remover (vazia)!");

            } else if (pos < 0 || pos >= tamanho) {
                throw new Exception("Erro ao remover (posicao " + pos + " / " + tamanho + " invalida!");
            } else if (pos == 0) {
                resp = removerInicio();
            } else if (pos == tamanho - 1) {
                resp = removerFim();
            } else {
                Celula i = primeiro;
                for (int j = 0; j < pos; j++, i = i.prox)
                    ;

                Celula tmp = i.prox;
                resp = tmp.elemento;
                i.prox = tmp.prox;
                tmp.prox = null;
                i = tmp = null;
            }
            return resp;
        }

        public void mostrar() {
            Show call = new Show();
            for (Celula i = primeiro.prox; i != null; i = i.prox) {
                call.print(i.elemento);
            }
        }

        public boolean pesquisar(Show x) {
            boolean resp = false;
            for (Celula i = primeiro.prox; i != null; i = i.prox) {
                if (i.elemento == x) {
                    resp = true;
                    i = ultimo;
                }
            }
            return resp;
        }

        public int tamanho() {
            int tamanho = 0;
            for (Celula i = primeiro; i != ultimo; i = i.prox, tamanho++)
                ;
            return tamanho;
        }
    }

    public static class Pilha {
        private Celula topo;

        public Pilha() {
            topo = null;
        }

        public void empilhar(Show x) {
            Celula tmp = new Celula(x);
            tmp.prox = topo;
            topo = tmp;
        }

        public String desempilhar() throws Exception {
            if (topo == null) {
                throw new Exception("Pilha vazia.");
            }
            Show elemento = topo.elemento;
            Celula tmp = topo;
            topo = topo.prox;
            tmp.prox = null;
            tmp = null;
            return elemento.get_TITLE();
        }

        public int tamanho() {
            int count = 0;
            for (Celula i = topo; i != null; i = i.prox) {
                count++;
            }
            return count;
        }

        public void mostrar_pilha() {
            int x = tamanho() - 1;
            for (Celula i = topo; i != null; i = i.prox) {
                System.out.print("[" + x-- + "] ");
                i.elemento.print(i.elemento);
            }
        }
    }

    public static int stringToInt(String str) {
        int result = 0;

        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (c >= '0' && c <= '9') {
                result = result * 10 + (c - '0');
            } else {
                continue;
            }
        }

        return result;
    }

    public static boolean startsWith(String texto, String prefixo) {
        if (prefixo.length() > texto.length()) {
            return false;
        }
        for (int i = 0; i < prefixo.length(); i++) {
            if (texto.charAt(i) != prefixo.charAt(i)) {
                return false;
            }
        }
        return true;
    }

    public static class No {
        public Show elemento; // Conteudo do no.
        public No esq, dir; // Filhos da esq e dir.

        public No(Show elemento) {
            this(elemento, null, null);
        }

        public No(Show elemento, No esq, No dir) {
            this.elemento = elemento;
            this.esq = esq;
            this.dir = dir;
        }
    }

    public static class ArvoreBinaria {
        private No raiz; // Raiz da arvore.

        public ArvoreBinaria() {
            raiz = null;
        }

        public boolean pesquisar(String x) {
            System.out.print("=>raiz ");
            return pesquisar(x, raiz);
        }

        private boolean pesquisar(String x, No i) {
            if (i == null) {
                return false;
            }

            int cmp = x.compareTo(i.elemento.get_TITLE());

            if (cmp == 0) {
                return true;
            } else if (cmp < 0) {
                System.out.print("esq ");
                return pesquisar(x, i.esq);
            } else {
                System.out.print("dir ");
                return pesquisar(x, i.dir);
            }
        }

        public void caminharCentral() {
            caminharCentral(raiz);
        }

        private void caminharCentral(No i) {
            if (i != null) {
                caminharCentral(i.esq); // Elementos da esquerda.
                System.out.println(i.elemento.get_TITLE()); // Conteudo do no.
                caminharCentral(i.dir); // Elementos da direita.
            }
        }

        public void inserir(Show x) throws Exception {
            raiz = inserir(x, raiz);
        }

        private No inserir(Show x, No i) {
            if (i == null) {
                i = new No(x);

            } else {
                int cmp = x.get_TITLE().compareTo(i.elemento.get_TITLE());

                if (cmp < 0) {
                    i.esq = inserir(x, i.esq);
                } else if (cmp > 0) {
                    i.dir = inserir(x, i.dir);
                }
                // se cmp == 0, é título repetido -> ignora
            }

            return i;
        }
    }

    public static class NoSec {
        public Show elemento;
        public NoSec esq, dir;

        public NoSec(Show elemento) {
            this.elemento = elemento;
            this.esq = this.dir = null;
        }
    }

    public static class NoPrim {
        public int chave;
        public NoPrim esq, dir;
        public NoSec raizSec;

        public NoPrim(int chave) {
            this.chave = chave;
            this.raizSec = null;
            this.esq = this.dir = null;
        }
    }

    public static class ArvoreDeArvores {
        private NoPrim raiz;

        public ArvoreDeArvores() {
            raiz = null;
            int[] ordem = { 7, 3, 11, 1, 5, 9, 13, 0, 2, 4, 6, 8, 10, 12, 14 };
            for (int chave : ordem) {
                raiz = inserirPrim(chave, raiz);
            }
        }

        // Inserção na árvore principal
        private NoPrim inserirPrim(int chave, NoPrim i) {
            if (i == null) {
                return new NoPrim(chave);
            }
            if (chave < i.chave) {
                i.esq = inserirPrim(chave, i.esq);
            } else if (chave > i.chave) {
                i.dir = inserirPrim(chave, i.dir);
            }
            return i;
        }

        // Inserção de Show
        public void inserir(Show s) {
            int chave = s.get_RELEASE_YEAR() % 15;
            NoPrim no = buscarNoPrim(chave, raiz);
            if (no != null) {
                no.raizSec = inserirSec(s, no.raizSec);
            }
        }

        // Busca do nó principal
        private NoPrim buscarNoPrim(int chave, NoPrim i) {
            if (i == null)
                return null;
            if (chave == i.chave)
                return i;
            if (chave < i.chave)
                return buscarNoPrim(chave, i.esq);
            return buscarNoPrim(chave, i.dir);
        }

        // Inserção na árvore secundária (por title)
        private NoSec inserirSec(Show s, NoSec i) {
            if (i == null)
                return new NoSec(s);
            int cmp = s.get_TITLE().compareTo(i.elemento.get_TITLE());
            if (cmp < 0)
                i.esq = inserirSec(s, i.esq);
            else if (cmp > 0)
                i.dir = inserirSec(s, i.dir);
            return i; // ignora duplicados
        }

        // Pesquisa por título com caminho
        public boolean pesquisar(String title) {
            System.out.print("raiz ");
            return pesquisar(title, raiz);
        }

        private boolean pesquisar(String title, NoPrim i) {
            if (i == null)
                return false;
            if (pesquisarSec(title, i.raizSec)) {
                return true;
            }
            System.out.print("ESQ ");
            if (pesquisar(title, i.esq)) {
                return true;
            }
            System.out.print("DIR ");
            return pesquisar(title, i.dir);
        }

        private boolean pesquisarSec(String title, NoSec i) {
            if (i == null)
                return false;

            int cmp = title.compareTo(i.elemento.get_TITLE());

            if (cmp == 0) {
                return true;
            } else if (cmp < 0) {
                System.out.print("esq ");
                return pesquisarSec(title, i.esq);
            } else {
                System.out.print("dir ");
                return pesquisarSec(title, i.dir);
            }
        }
    }

    public static class NoR {
        public Show elemento;
        public NoR esq, dir;
        public boolean cor; // true = RED, false = BLACK

        public NoR(Show elemento) {
            this(elemento, null, null, true);
        }

        public NoR(Show elemento, NoR esq, NoR dir, boolean cor) {
            this.elemento = elemento;
            this.esq = esq;
            this.dir = dir;
            this.cor = cor;
        }
    }

    public static class ArvoreAlvinegra {
        private NoR raiz;
        public static int comp = 0;

        public ArvoreAlvinegra() {
            raiz = null;
        }

        public boolean pesquisar(String title) {
            StringBuilder caminho = new StringBuilder("=>raiz ");
            boolean achou = pesquisarComCaminho(title, raiz, caminho);
            System.out.println(caminho.toString() + (achou ? "SIM" : "NAO"));
            return achou;
        }

        private boolean pesquisarComCaminho(String title, NoR i, StringBuilder caminho) {
            if (i == null) {
                return false;
            }

            comp++;
            int cmp = title.compareTo(i.elemento.get_TITLE());

            if (cmp == 0) {
                return true;
            } else if (cmp < 0) {
                caminho.append("esq ");
                return pesquisarComCaminho(title, i.esq, caminho);
            } else {
                caminho.append("dir ");
                return pesquisarComCaminho(title, i.dir, caminho);
            }
        }

        public void inserir(Show elemento) throws Exception {
            raiz = inserir(elemento, raiz);
            raiz.cor = false;
        }

        private NoR inserir(Show elemento, NoR i) throws Exception {
            if (i == null) {
                return new NoR(elemento);
            }

            comp++;
            int cmp = elemento.get_TITLE().compareTo(i.elemento.get_TITLE());

            if (cmp < 0) {
                i.esq = inserir(elemento, i.esq);
            } else if (cmp > 0) {
                i.dir = inserir(elemento, i.dir);
            } else {
                throw new Exception("Erro: elemento repetido!");
            }

            if (isRed(i.dir) && !isRed(i.esq)) {
                i = rotacaoEsq(i);
            }
            if (isRed(i.esq) && isRed(i.esq.esq)) {
                i = rotacaoDir(i);
            }
            if (isRed(i.esq) && isRed(i.dir)) {
                trocaCor(i);
            }

            return i;
        }

        private boolean isRed(NoR i) {
            return (i != null) && (i.cor == true);
        }

        private NoR rotacaoEsq(NoR i) {
            NoR dir = i.dir;
            i.dir = dir.esq;
            dir.esq = i;
            dir.cor = i.cor;
            i.cor = true;
            return dir;
        }

        private NoR rotacaoDir(NoR i) {
            NoR esq = i.esq;
            i.esq = esq.dir;
            esq.dir = i;
            esq.cor = i.cor;
            i.cor = true;
            return esq;
        }

        private void trocaCor(NoR i) {
            i.cor = true;
            if (i.esq != null)
                i.esq.cor = false;
            if (i.dir != null)
                i.dir.cor = false;
        }
    }

    public static class HashReserva {
        private Show[] tabela;
        private int tamPrincipal = 21;
        private int posReserva = 21; // começa após a principal
        private int comp = 0;

        public HashReserva() {
            this.tabela = new Show[30]; // 21 principais + 9 reserva
        }

        private int hash(String titulo) {
            int soma = 0;
            for (int i = 0; i < titulo.length(); i++) {
                soma += titulo.charAt(i);
            }
            return soma % tamPrincipal;
        }

        public boolean inserir(Show x) {
            int pos = hash(x.get_TITLE());
            if (tabela[pos] == null) {
                tabela[pos] = x;
                return true;
            } else {
                // colisão: insere na reserva
                if (posReserva < tabela.length) {
                    tabela[posReserva++] = x;
                    return true;
                } else {
                    return false;
                }
            }
        }

        public int pesquisar(String titulo) {
            comp++;
            int pos = hash(titulo);

            // Tenta encontrar na posição principal
            if (tabela[pos] != null && tabela[pos].get_TITLE().equals(titulo)) {
                System.out.println(" (Posicao: " + pos + ") SIM");
                return pos;
            } else {
                // Busca na reserva
                for (int i = 21; i < posReserva; i++) {
                    comp++;
                    if (tabela[i] != null && tabela[i].get_TITLE().equals(titulo)) {
                        // Encontrado na reserva, mas mostramos a posição da tabela principal
                        System.out.println(" (Posicao: " + pos + ") SIM");
                        return pos;
                    }
                }
            }

            // Não encontrado
            System.out.println(" (Posicao: " + pos + ") NAO");
            return -1;
        }

        public int getComp() {
            return comp;
        }
    }

    public static class HashRehash {
        private Show[] tabela;
        private int comp = 0;

        public HashRehash() {
            this.tabela = new Show[21]; // TABELA FIXA COM 21 POSIÇÕES
        }

        private int hash(String titulo) {
            int soma = 0;
            for (int i = 0; i < titulo.length(); i++) {
                soma += titulo.charAt(i);
            }
            return soma % 21; // tamTab = 21
        }

        public boolean inserir(Show x) {
            int pos = hash(x.get_TITLE());

            for (int i = 0; i < 21; i++) {
                int tentativa = (pos + i) % 21;
                if (tabela[tentativa] == null) {
                    tabela[tentativa] = x;
                    return true;
                } else if (tabela[tentativa].get_TITLE().equals(x.get_TITLE())) {
                    return false;
                }
            }

            return false;
        }

        public int pesquisar(String titulo) {
            comp++;
            int pos = hash(titulo);

            for (int i = 0; i < 21; i++) {
                int tentativa = (pos + i) % 21;
                if (tabela[tentativa] == null) {
                    System.out.println(" (Posicao: " + tentativa + ") NAO");
                    return -1;
                }
                if (tabela[tentativa].get_TITLE().equals(titulo)) {
                    System.out.println(" (Posicao: " + tentativa + ") SIM");
                    return tentativa;
                }
                comp++;
            }

            System.out.println(" (Posicao: " + pos + ") NAO");
            return -1;
        }

        public int getComp() {
            return comp;
        }
    }

    public static class CelulaHash {
        Show elemento;
        CelulaHash prox;

        public CelulaHash(Show elemento) {
            this.elemento = elemento;
            this.prox = null;
        }
    }

    public static class HashLista {
        private CelulaHash[] tabela;
        private int comp = 0;

        public HashLista() {
            tabela = new CelulaHash[21];
        }

        private int hash(String titulo) {
            int soma = 0;
            for (int i = 0; i < titulo.length(); i++) {
                soma += titulo.charAt(i);
            }
            return soma % 21;
        }

        public boolean inserir(Show x) {
            int pos = hash(x.get_TITLE());

            if (tabela[pos] == null) {
                tabela[pos] = new CelulaHash(x);
            } else {
                CelulaHash nova = new CelulaHash(x);
                nova.prox = tabela[pos];
                tabela[pos] = nova;
            }
            return true;
        }

        public boolean pesquisar(String titulo) {
            int pos = hash(titulo);
            CelulaHash atual = tabela[pos];
            while (atual != null) {
                comp++;
                if (atual.elemento.get_TITLE().equals(titulo)) {
                    System.out.println(" (Posicao: " + pos + ") SIM");
                    return true;
                }
                atual = atual.prox;
            }
            System.out.println(" (Posicao: " + pos + ") NAO");
            return false;
        }

        public int getComp() {
            return comp;
        }
    }
    public static void main(String[] args) throws Exception {
        Scanner s = new Scanner(System.in);
        String filename = "/tmp/disneyplus.csv";
        Show[] shows = Show.read(filename);
        HashLista hash = new HashLista();
        String temp = s.nextLine();
        while (!temp.equals("FIM")) {
            int id = stringToInt(Char_remove(temp, 0)) - 1;
            hash.inserir(shows[id]);
            temp = s.nextLine();
        }
        long startTime = System.currentTimeMillis();
        temp = s.nextLine();
        while (!temp.equals("FIM")) {
            hash.pesquisar(temp);
            temp = s.nextLine();
        }
        long endTime = System.currentTimeMillis();
        long totalTime = endTime - startTime;
        s.close();
        try (FileWriter logWriter = new FileWriter("867160_tp4.txt")) {
            logWriter.write("867160" + "\t" + totalTime + "\t" + hash.getComp() + "\n");
        }
    }

}