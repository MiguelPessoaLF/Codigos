import java.time.*;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.*;
import java.io.*;
import java.text.SimpleDateFormat;

public class tp3_quick {
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

    public static class Node {
        Show data;
        Node prev;
        Node next;

        Node(Show data) {
            this.data = data;
            this.prev = null;
            this.next = null;
        }
    }

    public static class DoublyLinkedList {
        private Node head;
        private Node tail;

        public DoublyLinkedList() {
            this.head = null;
            this.tail = null;
        }

        public void insertEnd(Show show) {
            Node newNode = new Node(show);
            if (head == null) {
                head = tail = newNode;
            } else {
                tail.next = newNode;
                newNode.prev = tail;
                tail = newNode;
            }
        }

        public void printList() {
            Node current = head;
            while (current != null) {
                current.data.print(current.data);
                current = current.next;
            }
        }

        void swap(Node a, Node b) {
            Show temp = a.data;
            a.data = b.data;
            b.data = temp;
        }

        Node lastNode(Node node) {
            while (node != null && node.next != null) {
                node = node.next;
            }
            return node;
        }

        public static LocalDate parseDate(String dateStr) {
            try {
                DateTimeFormatter formatter = DateTimeFormatter.ofPattern("MMMM d, yyyy", Locale.ENGLISH);
                return LocalDate.parse(dateStr, formatter);
            } catch (Exception e) {
                return LocalDate.of(1900, 1, 1);
            }
        }

        public void quicksort(Node low, Node high) {
            if (high != null && low != high && low != high.next) {
                Node p = partition(low, high);
                quicksort(low, p.prev);
                quicksort(p.next, high);
            }
        }

        private Node partition(Node low, Node high) {
            Show pivot = high.data;
            LocalDate pivotDate = parseDate(pivot.get_DATE_ADDED());
            Node i = low.prev;

            for (Node j = low; j != high; j = j.next) {
                LocalDate currentDate = parseDate(j.data.get_DATE_ADDED());
                int cmp = currentDate.compareTo(pivotDate);
                if (cmp < 0 || (cmp == 0 && j.data.get_TITLE().compareTo(pivot.get_TITLE()) < 0)) {
                    i = (i == null) ? low : i.next;
                    swap(i, j);
                }
            }
            i = (i == null) ? low : i.next;
            swap(i, high);
            return i;
        }

        public void sort() {
            Node last = lastNode(head);
            quicksort(head, last);
        }

    }

    public static void main(String zzz[]) throws Exception {
        int count = 0;
        long start_time = System.currentTimeMillis();
        Scanner s = new Scanner(System.in);
        Show call = new Show();
        String filename = "/tmp/disneyplus.csv";
        Show[] shows = Show.read(filename); // chama o creador de arranjos de objetos
        DoublyLinkedList list = new DoublyLinkedList();
        int id = 0;
        String temp = s.next();
        while (!temp.equals("FIM")) {
            temp = Char_remove(temp, 0); // remove o primeiro dígito para conseguir o id como inteiro
            id = stringToInt(temp) - 1;
            list.insertEnd(shows[id]);
            temp = s.next();
        }
        list.sort();
        list.printList();
        s.close();
        long end_time = System.currentTimeMillis();
        long total_time = end_time - start_time;
        String log = "tp2_log.txt";
        FileWriter logWriter = new FileWriter(log);
        logWriter.write("867129\t" + total_time + "\t" + comp + "\n");
        logWriter.close();
    }
}
