import java.time.*;
import java.time.format.DateTimeFormatter;
import java.util.*;
import java.io.*;
import java.text.SimpleDateFormat;
public class tp2{
    public static int comp = 0;
    public static class MyDate{//classe data
        private String date_added;
        private String date_realese;
    }
    public static class Show{//classe show que armazena todos os dados lidos, inclusive, em
        //um atributo da classe data
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

        Show(){//construtor nulo
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
        String DESCRIPTION)//construtor padrao
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
        //gets e sets
        public void set_SHOW_ID(String id){
           this.SHOW_ID = id;
        }
        public void set_TYPE(String type){
            this.TYPE = type;
        }
        public void set_TITLE(String title){
            this.TITLE = title;
        }
        public void set_DIRECTOR(String[] director){
                this.DIRECTOR = director;
        }
        public void set_CAST(String[] cast){
                this.CAST = cast;
        }
        public void set_COUNTRY(String country){
            this.COUNTRY = country;
        }
        public void set_DATE_ADDED(String date){
            this.DATE.date_added = date;
        }
        public void set_DATE_REALESE(String date){
            this.DATE.date_realese = date;
        }
        public void set_RATING(String rating){
            this.RATING = rating;
        }
        public void set_DURATION(String duration){
            this.DURATION = duration;
        }
        public void set_LISTED_IN(String[] listed_in){
            this.LISTED_IN = listed_in;
        }
        public void set_DESCRIPTION(String descrition){
            this.DESCRIPTION = descrition;
        }
        public String get_SHOW_ID(){
            return SHOW_ID;
        }
        public String get_TYPE(){
            return TYPE;
        }
         public String get_TITLE(){
            return TITLE;
        }
         public String[] get_DIRECTOR(){
             return DIRECTOR;
        }
         public String[] get_CAST(){
            return CAST;
        }
         public String get_COUNTRY(){
            return COUNTRY;
        }
         public String get_DATE_ADDED(){
            return DATE.date_added;
        }
        public String get_DATE_REALESE(){
            return DATE.date_realese;
        }
        public String get_RATING(){
            return RATING;
        }
        public String get_DURATION(){
            return DURATION;
        }
        public String[] get_LISTED_IN(){
            return LISTED_IN;
        }
        public String get_DESCRIPTION(){
            return DESCRIPTION;
        }
        public Show make(String x) {//recebe a string lida e interpreta cada parte da sequencia
            Show new_show = new Show();
            new_show.DIRECTOR = new String[50]; 
            new_show.CAST = new String[50];       
            new_show.LISTED_IN = new String[50]; 
            int i = 0;
            String temp = "";
        
            //SHOW_ID
            while (i < x.length() && x.charAt(i) != ',') {
                if (x.charAt(i) != '"') temp += x.charAt(i);
                i++;
            }
            if (temp.equals("")) temp = "NaN";
            new_show.SHOW_ID = temp;
            temp = ""; if (i + 1 < x.length()) i++;
        
            //TYPE
            while (i < x.length() && x.charAt(i) != ','){
                if (x.charAt(i) != '"') temp += x.charAt(i);
                i++;
            }
            if (temp.equals("")) temp = "NaN";
            new_show.TYPE = temp;
            temp = ""; if (i + 1 < x.length()) i++;
            int stop = 0;
            //TITLE
            if (x.charAt(i) == '"'){
                i++;
                while (i < x.length() && stop == 0) {
                    if (x.charAt(i) == '"' && x.charAt(i + 1) == '"') i += 2;
                    if (x.charAt(i) == '"' && x.charAt(i + 1) != '"') stop++;
                    if (x.charAt(i) != '"') temp += x.charAt(i);
                    i++;
                }
            }
            else{
                while (i < x.length() && x.charAt(i) != ',') {
                    if (x.charAt(i) != '"') temp += x.charAt(i);
                    i++;
                }
            }
            if (temp.equals("")) temp = "NaN";
            new_show.TITLE = temp;
            temp = ""; if (i + 1 < x.length()) i++;
            //DIRECTOR
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
                if (!temp.isEmpty()) new_show.DIRECTOR[directorIndex++] = Space_remove(temp);
                i++;
            } else {
                while (i < x.length() && x.charAt(i) != ',') {
                    if (x.charAt(i) != '"') temp += x.charAt(i);
                    i++;
                }
                new_show.DIRECTOR[directorIndex] = temp;
            }
            if (new_show.DIRECTOR[directorIndex] == "") new_show.DIRECTOR[directorIndex] = "NaN";
            if (i < x.length() && x.charAt(i) == ',') i++;
        
            //CAST
            
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
                        if (x.charAt(i) == '"' && x.charAt(i + 1) == '"') i += 2;
                        if (x.charAt(i) == '"' && x.charAt(i + 1) != '"') stop++;
                        if (x.charAt(i) != '"') temp += x.charAt(i);
                    }
                    i++;
                }
                if (!temp.isEmpty()) new_show.CAST[castIndex++] = Space_remove(temp);
            } else {
                while (i < x.length() && x.charAt(i) != ',') {
                    if (x.charAt(i) != '"') temp += x.charAt(i);
                    i++;
                }
                new_show.CAST[castIndex] = temp;
            }
            if (new_show.CAST[castIndex] == "") new_show.CAST[castIndex] = "NaN";
            if (i < x.length() && x.charAt(i) == ',') i++;
        
            //COUNTRY
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
            if (temp.equals("")) temp = "NaN";
            new_show.COUNTRY = Space_remove(temp);
            if (i < x.length() && x.charAt(i) == ',') i++;
        
            //DATE_ADDED
            temp = "";
            if (i < x.length() && x.charAt(i) == '"') {
                i++;
                while (i < x.length() && x.charAt(i) != '"') {
                    temp += x.charAt(i);
                    i++;
                }
                i++;
            }
            if (temp.equals("")) temp = "March 1, 1900";
            new_show.DATE.date_added = temp;
            if (i < x.length() && x.charAt(i) == ',') i++;
        
            //DATE_RELEASE
            temp = "";
            while (i < x.length() && x.charAt(i) != ',') {
                if (x.charAt(i) != '"') temp += x.charAt(i);
                i++;
            }
            if (temp.equals("")) temp = "NaN";
            new_show.DATE.date_realese = temp;
            temp = ""; if (i < x.length() && x.charAt(i) == ',') i++;
        
            //RATING
            while (i < x.length() && x.charAt(i) != ',') {
                if (x.charAt(i) != '"') temp += x.charAt(i);
                i++;
            }
            if (temp.equals("")) temp = "NaN";
            new_show.RATING = temp;
            temp = ""; if (i < x.length() && x.charAt(i) == ',') i++;
        
            //DURATION
            while (i < x.length() && x.charAt(i) != ',') {
                if (x.charAt(i) != '"') temp += x.charAt(i);
                i++;
            }
            if (temp.equals("")) temp = "NaN";
            new_show.DURATION = temp;
            temp = ""; if (i < x.length() && x.charAt(i) == ',') i++;
        
            //LISTED_IN
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
                if (!temp.isEmpty()) new_show.LISTED_IN[listedIndex++] = Space_remove(temp);
                i++;
            } else {
                while (i < x.length() && x.charAt(i) != ',') {
                    if (x.charAt(i) != '"') temp += x.charAt(i);
                    i++;
                }
                new_show.LISTED_IN[listedIndex] = temp;
            }
            if (new_show.LISTED_IN[listedIndex] == "") new_show.LISTED_IN[listedIndex] = "NaN";
            if (i < x.length() && x.charAt(i) == ',') i++;
        
            //DESCRIPTION
            while (i < x.length()) {
                if (x.charAt(i) != '"') temp += x.charAt(i);
                i++;
            }
            if (temp.equals("")) temp = "NaN";
            new_show.DESCRIPTION = temp;
        
            return new_show;//retorna o objeto completo
        }
        public static Show[] read (String filename) throws Exception{//cria uma sequencia de objetos show e chama o metodo make para interpretar cada uma delas
        Show[] ss = new Show[1400];//criação do arranjo de objetos
        Show call = new Show();//objeto chamador
        File f = new File(filename);
        Scanner s = new Scanner(f);
        String temp = s.nextLine();
        int i = 0;
        while(s.hasNext()){//leitura
            temp = s.nextLine();
            //System.out.println(temp);
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
                if (a.charAt(i) > b.charAt(i)) return true;
                comp++;
                if (a.charAt(i) < b.charAt(i)) return false;
            }
            comp++;
            return a.length() > b.length();
        }
    public static void ord(String[] array, int tamanho) {//ordena strings por ordem alfabetica
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
    public void print (String x, Show[] shows){//mostra cada atributo do objeto escolhido, lidando com atributos multivalorados que exigem ordenação de forma adequada
            int o = Integer.parseInt(x) - 1;
            shows[o].QUESTION = 1;
            System.out.print("=> " + shows[o].SHOW_ID + " ## " + shows[o].TITLE + " ## " + shows[o].TYPE + " ## ");
            for (int j = 0; j < shows[o].DIRECTOR.length && shows[o].DIRECTOR[j] != null; j++) {
                if (j > 0) System.out.print(", ");
                System.out.print(shows[o].DIRECTOR[j]);
            }
            System.out.print(" ## [");
            ord(shows[o].CAST, shows[o].CAST.length);
            for (int j = 0; j < shows[o].CAST.length && shows[o].CAST[j] != null; j++) {
                if (j > 0) System.out.print(", ");
                System.out.print(shows[o].CAST[j]);
            }
            System.out.print("] ## " + shows[o].COUNTRY + " ## " + shows[o].DATE.date_added + " ## " + shows[o].DATE.date_realese + " ## " + shows[o].RATING + " ## " + shows[o].DURATION + " ## [");
            ord(shows[o].LISTED_IN, shows[o].LISTED_IN.length);
            for (int j = 0; j < shows[o].LISTED_IN.length && shows[o].LISTED_IN[j] != null; j++) {
                if (j > 0) System.out.print(", ");
                System.out.print(shows[o].LISTED_IN[j]);
            }
            System.out.println("] ##");
    }
    public void print (Show show){//mostra cada atributo do objeto escolhido, lidando com atributos multivalorados que exigem ordenação de forma adequada
        //shows[o].QUESTION = 1;
        System.out.print("=> " + show.SHOW_ID + " ## " + show.TITLE + " ## " + show.TYPE + " ## ");
        for (int j = 0; j < show.DIRECTOR.length && show.DIRECTOR[j] != null; j++) {
            if (j > 0) System.out.print(", ");
            System.out.print(show.DIRECTOR[j]);
        }
        System.out.print(" ## [");
        ord(show.CAST, show.CAST.length);
        for (int j = 0; j < show.CAST.length && show.CAST[j] != null; j++) {
            if (j > 0) System.out.print(", ");
            System.out.print(show.CAST[j]);
        }
        System.out.print("] ## " + show.COUNTRY + " ## " + show.DATE.date_added + " ## " + show.DATE.date_realese + " ## " + show.RATING + " ## " + show.DURATION + " ## [");
        ord(show.LISTED_IN, show.LISTED_IN.length);
        for (int j = 0; j < show.LISTED_IN.length && show.LISTED_IN[j] != null; j++) {
            if (j > 0) System.out.print(", ");
            System.out.print(show.LISTED_IN[j]);
        }
        System.out.println("] ##");
    }
    public void printq (Show show){//mostra cada atributo do objeto escolhido, lidando com atributos multivalorados que exigem ordenação de forma adequada e verificando
        //se ele fez parte da entrada.
        //shows[o].QUESTION = 1;
        if (show.QUESTION == 1){
        System.out.print("=> " + show.SHOW_ID + " ## " + show.TITLE + " ## " + show.TYPE + " ## ");
        for (int j = 0; j < show.DIRECTOR.length && show.DIRECTOR[j] != null; j++) {
            if (j > 0) System.out.print(", ");
            System.out.print(show.DIRECTOR[j]);
        }
        System.out.print(" ## [");
        ord(show.CAST, show.CAST.length);
        for (int j = 0; j < show.CAST.length && show.CAST[j] != null; j++) {
            if (j > 0) System.out.print(", ");
            System.out.print(show.CAST[j]);
        }
        System.out.print("] ## " + show.COUNTRY + " ## " + show.DATE.date_added + " ## " + show.DATE.date_realese + " ## " + show.RATING + " ## " + show.DURATION + " ## [");
        ord(show.LISTED_IN, show.LISTED_IN.length);
        for (int j = 0; j < show.LISTED_IN.length && show.LISTED_IN[j] != null; j++) {
            if (j > 0) System.out.print(", ");
            System.out.print(show.LISTED_IN[j]);
        }
        System.out.println("] ##");
        }
    }
    public void mark (String x, Show[] shows){
        int o = Integer.parseInt(x) - 1;
        shows[o].QUESTION = 1;
    }
    public static Show[] ord_show_S(Show[] shows) {//ordena por seleçao somente os shows citados na entrada
        Show[] filtered = new Show[shows.length];
        int filteredCount = 0;
        for (int i = 0; i < shows.length; i++) {//faz o array com shows da entrada
            if (shows[i] != null && shows[i].QUESTION == 1 && shows[i].TITLE != null) {
                filtered[filteredCount++] = shows[i];
            }
        }
        //selection sort
        for (int i = 0; i < filteredCount - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < filteredCount; j++) {
                comp++;
                if (filtered[j].TITLE.compareTo(filtered[minIndex].TITLE) < 0) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                Show temp = filtered[i];
                filtered[i] = filtered[minIndex];
                filtered[minIndex] = temp;
            }
        }
        Show[] result = new Show[filteredCount];
        for (int i = 0; i < filteredCount; i++) {
            result[i] = filtered[i];
        }
        return result;
    }
    public static Show[] ord_show_S_p(Show[] shows) {
        int k = 10; //constante que limita a ordenação
        Show[] filtered = new Show[shows.length];
        int filteredCount = 0;
        for (int i = 0; i < shows.length; i++) {//faz o array com shows da entrada
            if (shows[i] != null && shows[i].QUESTION == 1 && shows[i].TITLE != null) {
                filtered[filteredCount++] = shows[i];
            }
        }
        //selection sort parcial
        for (int i = 0; i < Math.min(k, filteredCount); i++) {
            int minIndex = i;
            for (int j = i + 1; j < filteredCount; j++) {
                comp++;
                if (filtered[j].TITLE.compareTo(filtered[minIndex].TITLE) < 0) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                Show temp = filtered[i];
                filtered[i] = filtered[minIndex];
                filtered[minIndex] = temp;
            }
        }
        Show[] result = new Show[filteredCount];
        for (int i = 0; i < filteredCount; i++) {
            result[i] = filtered[i];
        }
        return result;
    }    
    public static Show[] ord_show_I(Show[] shows) {//ordena os shows por iserção baseado no atributo type
            Show[] filtered = new Show[shows.length];
            int filteredCount = 0;
            for (int i = 0; i < shows.length; i++) {
                if (shows[i] != null && shows[i].QUESTION == 1 &&
                    shows[i].TYPE != null && shows[i].TITLE != null) {
                    filtered[filteredCount++] = shows[i];
                }
            }
            //insertion sort
            for (int i = 1; i < filteredCount; i++) {
                Show key = filtered[i];
                int j = i - 1;
                boolean shouldShift = true;
                while (j >= 0 && shouldShift) {
                    comp++;
                    comp++;
                    int cmpType = key.TYPE.compareTo(filtered[j].TYPE);
                    if (cmpType < 0 || (cmpType == 0 && key.TITLE.compareTo(filtered[j].TITLE) < 0)) {
                        filtered[j + 1] = filtered[j];
                        j--;
                    } else {
                        shouldShift = false;
                    }
                }
                filtered[j + 1] = key;
            }        
            Show[] result = new Show[filteredCount];
            for (int i = 0; i < filteredCount; i++) {
                result[i] = filtered[i];
            }
            return result;
        }
        public int getAno() {//transforma string data em inteiro
            try {
                return Integer.parseInt(this.DATE.date_realese.trim());
            } catch (Exception e) {
                return 0; // ano inválido
            }
        }
        public static int bigger_date(Show[] array, int len){
            int maior = array[0].getAno();
            for(int i = 1; i < len; i++){
                if(array[i].getAno() > maior){
                    maior = array[i].getAno();
                }
            }
            return maior;
        }        
        public static Show[] ord_show_HS(Show[] shows) {
            Show[] filtered = new Show[shows.length];
            int count = 0;
            for (Show show : shows) {
                if (show != null && show.QUESTION == 1 && show.DIRECTOR[0] != null) {
                    filtered[count++] = show;
                }
            }
            // heap
            for (int i = count / 2 - 1; i >= 0; i--) {
                heap(filtered, count, i);
            }
            for (int i = count - 1; i > 0; i--) {
                Show temp = filtered[0];
                filtered[0] = filtered[i];
                filtered[i] = temp;
                heap(filtered, i, 0);
            }
            Show[] result = new Show[count];
            for (int i = 0; i < count; i++) result[i] = filtered[i];
            return result;
        }
        public static void heap(Show[] arr, int n, int i) {//metodo auxiliar
                int largest = i;       
                int left = 2 * i + 1;  
                int right = 2 * i + 2;          
                if (arr[i] == null) return;//evita nullpointerexcepction
                if (left < n && arr[left] != null) {
                    comp++;
                    comp++;
                    int cmp = arr[left].DIRECTOR[0].compareTo(arr[largest].DIRECTOR[0]);
                    if (cmp > 0 || (cmp == 0 && arr[left].TITLE.compareTo(arr[largest].TITLE) > 0)) {
                        largest = left;
                    }
                }
                if (right < n && arr[right] != null) {
                    comp++;
                    comp++;
                    int cmp = arr[right].DIRECTOR[0].compareTo(arr[largest].DIRECTOR[0]);
                    if (cmp > 0 || (cmp == 0 && arr[right].TITLE.compareTo(arr[largest].TITLE) > 0)) {
                        largest = right;
                    }
                }
                if (largest != i) {
                    Show temp = arr[i];
                    arr[i] = arr[largest];
                    arr[largest] = temp;
                    heap(arr, n, largest);
                }
            }
            public static Show[] ord_show_CS(Show[] array) {//ordena por counting sort usando date_realese como chave principal
                List<Show> filtrados = new ArrayList<>();
                for (Show show : array) {
                    if (show != null && show.QUESTION == 1) {
                        filtrados.add(show);
                    }
                }
                int tam = filtrados.size();
                if (tam == 0) return new Show[0];
                Show[] result = new Show[tam];
                int maxAno = bigger_date(filtrados.toArray(new Show[0]), tam);
                int[] count = new int[maxAno + 2];
                for (Show show : filtrados) {
                    count[show.getAno()]++;
                }
                for (int i = 1; i <= maxAno; i++) {
                    count[i] += count[i - 1];
                }
                for (int i = tam - 1; i >= 0; i--) {
                    Show show = filtrados.get(i);
                    result[count[show.getAno()] - 1] = show;
                    count[show.getAno()]--;
                }
                for (int i = 0; i < tam; ) {
                    int anoAtual = result[i].getAno();
                    int j = i;
                    while (j < tam && result[j].getAno() == anoAtual) {
                        j++;
                    }
                    for (int k = i + 1; k < j; k++) {
                        Show key = result[k];
                        int l = k - 1;
                        comp++;
                        while (l >= i && key.TITLE.compareToIgnoreCase(result[l].TITLE) < 0) {
                            result[l + 1] = result[l];
                            l--;
                        }
                        result[l + 1] = key;
                    }
                    i = j; 
                }
                return result;
            }         
    public static Show[] ord_show_MS(Show[] shows) {
        List<Show> filtered = new ArrayList<>();
        for (Show show : shows) {
            if (show != null && show.QUESTION == 1) {
                filtered.add(show);
            }
        }
        Show[] arr = filtered.toArray(new Show[0]);
        mergeSort(arr, 0, arr.length - 1);
        return arr;
    }
    private static void mergeSort(Show[] arr, int left, int right) {//funcao mergesort recursiva
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
    private static void merge(Show[] arr, int left, int mid, int right) {//funcao principal do mergesort
        int n1 = mid - left + 1;
        int n2 = right - mid;
        Show[] L = new Show[n1];
        Show[] R = new Show[n2];
        for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
        for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            comp++;
            comp++;
            int cmp = L[i].get_DURATION().compareToIgnoreCase(R[j].get_DURATION());
            if (cmp < 0 || (cmp == 0 && L[i].get_TITLE().compareToIgnoreCase(R[j].get_TITLE()) <= 0)) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }    
    public static void Search_S (String x, Show[] shows){
        int find = 0;
        for (int i = 0; i < 1368; i++){
            if (x.equals(shows[i].TITLE) && shows[i].QUESTION == 1){
                find++;
                i = shows.length;
            }
        }
        if (find > 0){
            System.out.println("SIM");
        }else{
            System.out.println("NAO");
        }
    }
    public static LocalDate parseDate(String dateStr){//função para leitura das datas
    try {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("MMMM d, yyyy", Locale.ENGLISH);
        return LocalDate.parse(dateStr, formatter);
    } catch (Exception e) {
        return LocalDate.of(1900, 1, 1);
    }
    }
    public static void quicksort(Show[] arr, int low, int high) {//divisão recursiva do quicksort
        if (low < high) {
            int pi = quick(arr, low, high);
            quicksort(arr, low, pi - 1);
            quicksort(arr, pi + 1, high);
        }
    }
    public static int quick(Show[] arr, int low, int high){//ordenação propriamente dita
        Show pivot = arr[high];
        LocalDate pivotDate = parseDate(pivot.get_DATE_ADDED());
        int i = low - 1;
        for (int j = low; j < high; j++) {
            comp++;
            comp++;
            LocalDate currentDate = parseDate(arr[j].get_DATE_ADDED());
            int cmp = currentDate.compareTo(pivotDate);
            if (cmp < 0 || (cmp == 0 && arr[j].get_TITLE().compareTo(pivot.get_TITLE()) < 0)) {
                i++;
                Show temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        Show temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1;
    }    
    public static Show[] ord_show_QS_p(Show[] shows){//funcao principal
        int k = 10;
        Show[] filtered = new Show[shows.length];
        int filteredCount = 0;
        for (int i = 0; i < shows.length; i++) {
            if (shows[i] != null && shows[i].QUESTION == 1 &&
                shows[i].get_DATE_ADDED() != null && !shows[i].get_DATE_ADDED().equals("NaN")) {
                filtered[filteredCount++] = shows[i];
            }
        }
        quicksort(filtered, 0, filteredCount - 1);
        int limite = Math.min(k, filteredCount);
        Show[] result = new Show[limite];
        for (int i = 0; i < limite; i++) {
            result[i] = filtered[i];
        }
        return result;
    }
}
    public static String Char_remove(String x, int i){//remove um termo escolhido de um arranjo
        String copy = "";
        for (int a = 0; a < x.length(); a++){
            if (a != i){
            copy = copy + x.charAt(a);
            }
        }
        return copy;
    }
        public static String Space_remove(String str){//trim
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
    public static void ord_show_SSR(Show[] arr, int index) {//orderdenação por seleção recursiva
        if (index >= arr.length - 1) {
            return;
        }
        int minIndex = index;
        for (int i = index + 1; i < arr.length; i++) {
            comp++;
            if (arr[i] != null && arr[minIndex] != null && arr[i].get_TITLE().compareTo(arr[minIndex].get_TITLE()) < 0) {
                minIndex = i;
            }
        }
        if (minIndex != index) {
            Show temp = arr[index];
            arr[index] = arr[minIndex];
            arr[minIndex] = temp;
        }
        ord_show_SSR(arr, index + 1);
    }
    public static void main (String zzz[]) throws Exception{
        int count = 0;
        long start_time = System.currentTimeMillis();
        Scanner s = new Scanner (System.in);
        Show call = new Show();
        String filename = "disneyplus.csv";
        Show[] shows = Show.read(filename);//chama o creador de arranjos de objetos
        String temp = s.next();
        while (!(temp.equals("FIM"))){
            count++;
            temp = Char_remove(temp, 0);//remove o primeiro digito para conseguir o id como inteiro
            //call.print(temp, shows);//chama print com o objeto escolhido
            call.mark(temp, shows);//chama mark com o objeto escolhido
            temp = s.next();//le o proximo dado
        }
        //Show[] ords = Show.ord_show_S(shows);
        //Show[] ords = Show.ord_show_I(shows);
        //Show[] ords = Show.ord_show_HS(shows);
        //Show[] ords = Show.ord_show_CS(shows);
        //Show[] ords = Show.ord_show_MS(shows);
        //Show[] ords = Show.ord_show_S_p(shows);
        //Show[] ords = Show.ord_show_QS_p(shows);
        //ord_show_SSR(shows, 0);
        //for (int i = 0; i < 1368; i ++){
            //call.print(ords[i]);
            //call.printq(shows[i]);
        //}
        temp = s.nextLine();
        temp = s.nextLine();
        while (!(temp.equals("FIM"))){
            call.Search_S(temp, shows);
            temp = s.nextLine();
        }
        s.close();
        long end_time = System.currentTimeMillis();
        long total_time = end_time - start_time;
        String log = "tp2_log.txt";
        FileWriter logWriter = new FileWriter(log);
        logWriter.write("867129\t" + total_time + "\t" + comp + "\n");
        logWriter.close();
    }
}