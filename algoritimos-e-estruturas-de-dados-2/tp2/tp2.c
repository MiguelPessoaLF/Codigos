#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
struct MyDate{
    char date_added[50];
    char date_realese[50]; 
};
typedef struct MyDate Date;
struct Show{
    char SHOW_ID[450];
    char TYPE[450];
    char TITLE[450];
    char DIRECTOR[450][50];
    char CAST[450][50];
    char COUNTRY[450];
    Date DATE;
    char RATING[450];
    char DURATION[450];
    char LISTED_IN[450][50];
    char DESCRIPTION[450];
    int  QUESTION;
};
typedef struct Show show;
bool LF_isFim (char array[])//verifica se o array lido é igual a "FIM", usado como condicao de parada 
{
    if (array[0] == 'F' && array[1] == 'I' && array[2] == 'M')
    {
        return true;
    }
    return false;
}
int LF_Size_Of_Char (char array[])
{
    int contador = 0;
    for (int i = 0; array[i] != '\0'; i++)
    {
        contador++;
    }
    return contador;
} 
bool LF_Equals(char x[], char y[]){
    if (LF_Size_Of_Char(x) != LF_Size_Of_Char(y)) return false;
    for (int i = 0; i < LF_Size_Of_Char(x); i++){
        if (x[i] != y[i]){
            return false;
        }
    }
    return true;
}
void LF_Clean (char *x){
    while (*x) {
        *x = '\0';
        x++;
    }
}
bool LF_Bigger (char x[], char y[]) {//serve para encontrar o tamanho dentre duas strings
    int len = (LF_Size_Of_Char(x) < LF_Size_Of_Char(y)) ? LF_Size_Of_Char(x) : LF_Size_Of_Char(y);
    for (int i = 0; i < len; i++) {
        if (x[i] > y[i]) return true;
        if (x[i] < y[i]) return false;
    }
    return LF_Size_Of_Char(x) > LF_Size_Of_Char(y);
}
char* LF_Concat (char x[], char y[], char* result){
    int length = LF_Size_Of_Char(x) + LF_Size_Of_Char(y);
    int left = LF_Size_Of_Char(x);
    int resultIndex = 0;
    for (int i = 0; i < length; i++){
        if (i < left){
            result[i] = x[i];
        }else{
            result[i] = y[i];
        }
    }
    return result;
}
char* NaN_it (char* x){
    x[0] = 'N';
    x[1] = 'a';
    x[2] = 'N';
    for (int i = 3; i < 50; i++) {
        x[i] = '\0';
    }
    return x;
}
char* Space_remove(char* str){
    int start = 0;
    int end = LF_Size_Of_Char(str) - 1;

    while (start <= end && str[start] == ' ') start++;
    while (end >= start && str[end] == ' ') end--;
    int j = 0;
    for (int i = start; i <= end; i++) {
        str[j++] = str[i];
    }
    str[j] = '\0';
    return str;
}
int LF_Size_Of_show(char arr[][50]) {
    int count = 0;
    for (int i = 0; i < 450; i++) {
        if (arr[i][0] == '\0') break;
        count++;
    }
    return count;
}
void ord(char arr[50][50], int n) {
    char temp[50];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}
show* read(show* new_show, char x[]) {//tive que refazer minha read inteira...
    int i = 0, index = 0, field = 0;
    char temp[500];
    int len = LF_Size_Of_Char(x);
    bool inQuotes = false;
    int castIndex = 0, directorIndex = 0, listedIndex = 0;
    LF_Clean(temp);
    for (int f = 0; f < 450; f++) {
        LF_Clean(new_show->CAST[f]);
        LF_Clean(new_show->DIRECTOR[f]);
        LF_Clean(new_show->LISTED_IN[f]);
    }
    while (i <= len) {
        if ((x[i] == '"' && x[i + 1] == '"') && inQuotes) {
            temp[index++] = '"'; i += 2; continue;
        }
        if (x[i] == '"') {
            inQuotes = !inQuotes;
            i++; continue;
        }
        if ((x[i] == ',' && !inQuotes) || x[i] == '\0' || x[i] == '\n') {
            temp[index] = '\0';
            Space_remove(temp);
            if (LF_Equals(temp, "")) NaN_it(temp);

            switch (field) {
                case 0: strcpy(new_show->SHOW_ID, temp); break;
                case 1: strcpy(new_show->TYPE, temp); break;
                case 2: strcpy(new_show->TITLE, temp); break;
                case 3: {
                    char* tok = strtok(temp, ",");
                    while (tok) {
                        Space_remove(tok);
                        strcpy(new_show->DIRECTOR[directorIndex++], tok);
                        tok = strtok(NULL, ",");
                    }
                    if (directorIndex == 0) strcpy(new_show->DIRECTOR[0], "NaN");
                    break;
                }
                case 4: {
                    char* tok = strtok(temp, ",");
                    while (tok) {
                        Space_remove(tok);
                        strcpy(new_show->CAST[castIndex++], tok);
                        tok = strtok(NULL, ",");
                    }
                    if (castIndex == 0) strcpy(new_show->CAST[0], "NaN");
                    break;
                }
                case 5: strcpy(new_show->COUNTRY, temp); break;
                case 6: strcpy(new_show->DATE.date_added, temp); break;
                case 7: strcpy(new_show->DATE.date_realese, temp); break;
                case 8: strcpy(new_show->RATING, temp); break;
                case 9: strcpy(new_show->DURATION, temp); break;
                case 10: {
                    char* tok = strtok(temp, ",");
                    while (tok) {
                        Space_remove(tok);
                        strcpy(new_show->LISTED_IN[listedIndex++], tok);
                        tok = strtok(NULL, ",");
                    }
                    if (listedIndex == 0) strcpy(new_show->LISTED_IN[0], "NaN");
                    break;
                }
            }
            field++;
            index = 0;
            LF_Clean(temp);
            i++; continue;
        }
        temp[index++] = x[i++];
    }
    ord(new_show->CAST, LF_Size_Of_show(new_show->CAST));
    ord(new_show->LISTED_IN, LF_Size_Of_show(new_show->LISTED_IN));
    return new_show;
}
void mark (show* marked_show){
marked_show->QUESTION = 1;
}
void print (show* x){
    printf("%s%s%s%s%s%s%s", "=> ", x->SHOW_ID, " ## ", x->TITLE, " ## ", x->TYPE, " ## ");
    if (LF_Equals(x->DIRECTOR[0],"NaN")) printf("NaN");
    else{
    for (int j = 0; j < LF_Size_Of_show(x->DIRECTOR); j++) {
        if (j > 0) printf(", ");
        printf("%s", x->DIRECTOR[j]);
    }
    }
    printf(" ## [");
    if (LF_Equals(x->CAST[0],"NaN")) printf("NaN");
    else{
    for (int j = 0; j < LF_Size_Of_show(x->CAST); j++) {
        if (j > 0) printf(", ");
        printf("%s", x->CAST[j]);
    }
    }
    printf("%s%s%s%s%s%s%s%s%s%s%s", "] ## ", x->COUNTRY, " ## ", x->DATE.date_added, " ## ", x->DATE.date_realese, " ## ", x->RATING, " ## ", x->DURATION, " ## [");
    if (LF_Equals(x->LISTED_IN[0],"NaN")) printf("NaN");
    else{
    for (int j = 0; j < LF_Size_Of_show(x->LISTED_IN); j++) {
        if (j > 0) printf(", ");
        printf("%s", x->LISTED_IN[j]);
    }
    }
    printf("] ##\n");
}
int LF_Size_Of_shows(show arr[]) {
    int count = 0;
    while (arr[count].SHOW_ID[0] != '\0' && count < 1400) count++;
    return count;
}
int month_to_number(const char* month) {//tradutor de string pra mes
    if (strcmp(month, "January") == 0) return 1;
    if (strcmp(month, "February") == 0) return 2;
    if (strcmp(month, "March") == 0) return 3;
    if (strcmp(month, "April") == 0) return 4;
    if (strcmp(month, "May") == 0) return 5;
    if (strcmp(month, "June") == 0) return 6;
    if (strcmp(month, "July") == 0) return 7;
    if (strcmp(month, "August") == 0) return 8;
    if (strcmp(month, "September") == 0) return 9;
    if (strcmp(month, "October") == 0) return 10;
    if (strcmp(month, "November") == 0) return 11;
    if (strcmp(month, "December") == 0) return 12;
    return 0;
}
time_t parse_date(const char* date_str) {//leitor de datas
    char month[20];
    int day, year;
    struct tm tm_date = {0};
    if (sscanf(date_str, "%s %d, %d", month, &day, &year) != 3) {
        strcpy((char*)date_str, "March 1, 1900");
        sscanf(date_str, "%s %d, %d", month, &day, &year);
    }
    tm_date.tm_mday = day;
    tm_date.tm_mon = month_to_number(month);
    tm_date.tm_year = year - 1900;
    tm_date.tm_hour = 0;
    tm_date.tm_min = 0;
    tm_date.tm_sec = 0;
    if (tm_date.tm_mon < 0) {
        tm_date.tm_mday = 1;
        tm_date.tm_mon = 2;
        tm_date.tm_year = 0;
    }
    return mktime(&tm_date);
}
int compare_shows_date(const show* a, const show* b) {
    time_t timeA = parse_date(a->DATE.date_realese);
    time_t timeB = parse_date(b->DATE.date_realese);
    if (timeA < timeB) return -1;
    else if (timeA > timeB) return 1;
    return strcmp(a->TITLE, b->TITLE);
}
void ord_show(show shows[], int n) {//orenação alfabetica dos shows por atributo title
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(shows[j].TITLE, shows[j + 1].TITLE) > 0) {
                // troca
                show temp = shows[j];
                shows[j] = shows[j + 1];
                shows[j + 1] = temp;
            }
        }
    }
}
void ord_show_SR(show ords[], int start, int end) {//ordena por seleção recursiva com atributo chave o title
    if (start >= end) return;
    int min = start;
    for (int j = start + 1; j < end; j++) {
        if (strcmp(ords[j].TITLE, ords[min].TITLE) < 0) {
            min = j;
        }
    }
    if (min != start) {
        show temp = ords[start];
        ords[start] = ords[min];
        ords[min] = temp;
    }
    ord_show_SR(ords, start + 1, end);
}
void ord_show_SS(show ords[], int n, int *comp) {//ordena por shell short como atributo chave, type
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            show temp = ords[i];
            int j = i;
            int continueShift = 1;
            while (j >= gap && continueShift) {
                (*comp)++;
                int cmpType = strcmp(ords[j - gap].TYPE, temp.TYPE);
                int cmpTitle = strcmp(ords[j - gap].TITLE, temp.TITLE);
                if (cmpType > 0 || (cmpType == 0 && cmpTitle > 0)) {
                    ords[j] = ords[j - gap];
                    j -= gap;
                } else {
                    continueShift = 0;
                }
            }
            ords[j] = temp;
        }
    }
}
void quicksort(show arr[], int left, int right, int* comp) {//ordenação por quicksort com atributo chave date_added
    int i = left, j = right;
    show pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (compare_shows_date(&arr[i], &pivot) < 0) { i++; (*comp)++; }
        while (compare_shows_date(&arr[j], &pivot) > 0) { j--; (*comp)++; }
        if (i <= j) {
            show temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j) quicksort(arr, left, j, comp);
    if (i < right) quicksort(arr, i, right, comp);
}
void ord_show_QS(show arr[], int n, int* comp) {//funcao chamadora
    quicksort(arr, 0, n - 1, comp);
}
void ord_show_BS(show arr[], int n, int* comp) {//ordenação por bubblesort com atributo chave date_added
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comp)++;
            int cmp = compare_shows_date(&arr[j], &arr[j + 1]);
            if (cmp > 0) {
                show temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int get_year(const char* year_str) {//le o atributo como inteiro para aplicar no radixsort
    int year = 0;
    int i = 0;
    int stop = 1;
    while (year_str[i] != '\0') {
        if (stop && year_str[i] >= '0' && year_str[i] <= '9') {
            year = year * 10 + (year_str[i] - '0');
        } else {
            stop = 0;//condição de parada
        }
        i++;
    }
    return year;
}
int get_max_year(show arr[], int n) {//le dois anos e diz o maior
    int max = get_year(arr[0].DATE.date_realese);
    for (int i = 1; i < n; i++) {
        int year = get_year(arr[i].DATE.date_realese);
        if (year > max) max = year;
    }
    return max;
}
void radix_title(show arr[], int n) {//resolve o problema da ordenação por title
    int i = 0;
    while (i < n) {
        int j = i + 1;
        while (j < n && strcmp(arr[i].DATE.date_realese, arr[j].DATE.date_realese) == 0) {
            j++;
        }
        for (int k = i + 1; k < j; k++) {
            show key = arr[k];
            int l = k - 1;
            while (l >= i && strcmp(arr[l].TITLE, key.TITLE) > 0) {
                arr[l + 1] = arr[l];
                l--;
            }
            arr[l + 1] = key;
        }
        i = j;
    }
}
void radix(show arr[], int n, int exp) {//funcao radixsort
    show* output = malloc(n * sizeof(show));
    int count[10] = {0};
    for (int i = 0; i < n; i++) {
        int year = get_year(arr[i].DATE.date_realese);
        int digit = (year / exp) % 10;
        count[digit]++;
    }
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int year = get_year(arr[i].DATE.date_realese);
        int digit = (year / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
    free(output);
}
/*
o radixsort aplicado no codigo tem como base a ordenação por digitos, tratando cada ano com base em cada digito do seu numero,
o radixsort é  um algoritimo de ordenação estavel, e tem complexidade dependente da aplicação, nesse caso é Θ(n)
*/
void ord_show_RS(show arr[], int n) {
    int max = get_max_year(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
        radix(arr, n, exp);
    radix_title(arr, n);//corrige o problema de datas iguais
}
void ord_show_IS_p(show arr[], int n) {//ordena por inserção parcial
    int k = 10;
    for (int i = 1; i < n; i++) {
        show key = arr[i];
        int j = i - 1;
        if (i < k || strcmp(key.TYPE, arr[k - 1].TYPE) < 0 || 
            (strcmp(key.TYPE, arr[k - 1].TYPE) == 0 && strcmp(key.TITLE, arr[k - 1].TITLE) < 0)) {
            while (j >= 0 && (j >= k - 1 || 
                    (strcmp(arr[j].TYPE, key.TYPE) > 0 || 
                     (strcmp(arr[j].TYPE, key.TYPE) == 0 && strcmp(arr[j].TITLE, key.TITLE) > 0)))) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
}
int comp(show* a, show* b) {
    int cmp = strcmp(a->DIRECTOR[0], b->DIRECTOR[0]);
    if (cmp != 0) return cmp;
    return strcmp(a->TITLE, b->TITLE);
}
void heap_p(show arr[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && comp(&arr[l], &arr[smallest]) > 0)
        smallest = l;
    if (r < n && comp(&arr[r], &arr[smallest]) > 0)
        smallest = r;

    if (smallest != i) {
        show temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heap_p(arr, n, smallest);
    }
}
void max_heap(show arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heap_p(arr, n, i);
    }
}
void ord_show_HS_p(show arr[], int n) {
    int k = 10;
    if (n <= k) {
        ord_show(arr, n);
        return;
    }
    max_heap(arr, k);
    for (int i = k; i < n; i++) {
        if (comp(&arr[i], &arr[0]) < 0) {
            arr[0] = arr[i];
            heap_p(arr, k, 0);
        }
    }
    for (int i = 0; i < k - 1; i++) {//ordena os shows encontrados
        for (int j = i + 1; j < k; j++) {
            if (comp(&arr[i], &arr[j]) > 0) {
                show temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void swap(show* s1, show* s2)//swap da recursao
{
    show temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}
void ord_show_SSR(show array[], int n, int i, int j, int min)//selection sort recursivo
{
    if (i < n - 1)
    {
        if (j < n)
        {
            if (strcmp(array[min].TITLE, array[j].TITLE) > 0)
            {
                min = j;
            }
            ord_show_SSR(array, n, i, j + 1, min);
        }
        else
        {
            swap(&array[min], &array[i]);
            ord_show_SSR(array, n, i + 1, i + 2, i + 1);
        }
    }
}
void ord_show_SSRs(show array[], int n)//funcao gatilho
{
    ord_show_SSR(array, n, 0, 1, 0);
}
void Search_B(show* shows, int total, char target[], int* comp) {//pesquisa binaria que usa o atributo title como base
    int left = 0;
    int right = total - 1;
    int found = 0;
    while (left <= right) {
        int mid = (left + right) / 2;//faz a primeira divisão
        (*comp)++;//aumenta o numero de comparações
        int mid_marked = 0;
        int i = 0;
        while ((mid - i >= left || mid + i <= right) && mid_marked == 0) {
            if (mid - i >= left && shows[mid - i].QUESTION == 1) {
                mid = mid - i;
                mid_marked = 1;
            } else if (mid + i <= right && shows[mid + i].QUESTION == 1) {
                mid = mid + i;
                mid_marked = 1;
            }
            i++;
        }
        if (mid_marked == 0) {
            left = right + 1;
        } else {
            int cmp = strcmp(target, shows[mid].TITLE);
            (*comp)++;
            if (cmp == 0) {
                found = 1;
                left = right + 1;
            } else if (cmp < 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }
    if (found == 1) {
        printf("SIM\n");
    } else {
        printf("NAO\n");
    }
}
int main ( void ) {
    show* shows = malloc(1400 * sizeof(show));
    show* ords = malloc(1400 * sizeof(show));
    memset(shows, 0, 1400 * sizeof(show));
    memset(ords, 0, 1400 * sizeof(show));
    char line[5000];
    int showIndex = 0;
    FILE *arquivo = fopen("/tmp/disneyplus.csv", "r");
    if (arquivo == NULL) {
        arquivo = fopen("disneyplus.csv", "r");
    }
    clock_t start = clock();//inicia o timer
    int comp = 0; 
    int count = 0;
    fgets(line, sizeof(line), arquivo);//pula a primeira linha
    while (fgets(line, sizeof(line), arquivo) && showIndex < 1368){//le e monta o arranjo de shows
        read(&shows[showIndex],line);
        showIndex++;
    }
    fclose(arquivo);
    char array[100];
    ord_show(shows, 1368);
    scanf("%9[^\n]", array);
    while (!LF_isFim(array))
    {
        int found = 0;
        int pos = 0;
        for (int i = 0; i < showIndex; i++) {
            if (LF_Equals(array, shows[i].SHOW_ID)) {
                found = 1;
                pos = i;
                i = showIndex;
            }
        }
        if (found) {
            //print(&shows[pos]);
            count++;
            mark(&shows[pos]);//chama mark com o objeto escolhido
        } else {
            printf("Show com ID %s não encontrado!\n", array);
        }
        scanf(" %9[^\n]", array);
    }
    int filteredCount = 0;
    for (int i = 0; i < showIndex; i++) {
        if (shows[i].QUESTION == 1) {
            ords[filteredCount++] = shows[i];
        }
    }
    if (filteredCount > 0) {
        //ord_show_SR(ords, 0, filteredCount);
        //ord_show_SS(ords, filteredCount, &comp);
        //ord_show_QS(ords, filteredCount, &comp);
        //ord_show_BS(ords, filteredCount, &comp);
        //ord_show_RS(ords, filteredCount);
        //ord_show_IS_p(ords, filteredCount);
        //ord_show_HS_p(ords, filteredCount);
        //ord_show_SSRs(ords, filteredCount);
    }
    // imprimir ordenados:
    for (int i = 0; i < filteredCount; i++) {
        //print(&ords[i]);
    }
    scanf(" %99[^\n]", array);
    while (!LF_isFim(array)) {
        Search_B(shows, showIndex, array, &comp);
        scanf(" %99[^\n]", array);
    }
    clock_t end = clock(); // fim da contagem do tempo
    double total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    FILE *log = fopen("867129_selection_p_sortr.txt", "w");
    if (log != NULL) {
        fprintf(log, "867129\t%.6f\t%d\n", total_time, comp);
        fclose(log);
    } else {
        fprintf(stderr, "Erro ao criar o arquivo de log.\n");
    }
    return 0;
}