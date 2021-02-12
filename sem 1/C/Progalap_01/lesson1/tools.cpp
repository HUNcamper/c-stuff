FILE* fp_read;
FILE* fp_write;
int stdin_backup;
int stdout_backup;

/**
 * <h2>szoveg:</h2>
 * a feladathoz tartozó input (ezt fogja a hallgató beolvasni)
 * <br><br>
 * <h2>result:</h2>
 * az utasítás, amely tartalmazza a függvényhívást (pl. eltárolhatjuk a visszaadott értéket)
 * <br><br>
 * <h2>Példa:</h2>
 *   BEOLVAS("10", int res = beolvas(2, 7)) <br>
 *   ASSERT_EQ(19, res);
 *
 */
#define BEOLVAS(szoveg, result) \
    FILE* f = fopen("tmp.txt", "w"); \
    fprintf(f, "%s\n", szoveg); \
    fclose(f); \
    stdin_backup = dup(fileno(stdin)); \
    fp_read = fopen("tmp.txt", "r"); \
    dup2(fileno(fp_read), fileno(stdin)); \
    result; \
    /*fclose(fp_read);*/ \
    dup2(stdin_backup, fileno(stdin)); \

/**
 * <h2>fuggvenyhivas:</h2>
 * a hallgató által megírt függvény, amiben kiír valamit a képernyőre
 * <br><br>
 * <h2>visszaadott fájl: </h2> file
 * <br><br>
 * <h2>Példa: </h2>
 *   KIIR(fgv(5, 7)) <br>
 *   fscanf(file, "%s", result); <br>
 *   ASSERT_STREQ("MACSKA", result); <br>
 */
#define KIIR(fuggvenyhivas) \
        stdout_backup = dup(fileno(stdout)); \
        fp_write = fopen("tmp.txt", "w"); \
        dup2(fileno(fp_write), fileno(stdout)); \
        fuggvenyhivas; \
        fflush(stdout); \
        fflush(fp_write); \
        fclose(fp_write); \
        dup2(stdout_backup, fileno(stdout)); \
        FILE* file = fopen("tmp.txt", "r");

#define IO(szoveg, fuggvenyhivas, string) \
    FILE* f = fopen("input.txt", "w"); \
    fprintf(f, "%s\n", szoveg); \
    fclose(f); \
    stdin_backup = dup(fileno(stdin)); \
    fp_read = fopen("input.txt", "r"); \
    dup2(fileno(fp_read), fileno(stdin)); \
    stdout_backup = dup(fileno(stdout)); \
    fp_write = fopen("output.txt", "w"); \
    dup2(fileno(fp_write), fileno(stdout)); \
    fuggvenyhivas; \
    fflush(stdout); \
    fflush(fp_write); \
    fclose(fp_write); \
    dup2(stdout_backup, fileno(stdout)); \
    dup2(stdin_backup, fileno(stdin)); \
    FILE* file = fopen("output.txt", "r"); \
    readstring(file, string); \
    fclose(file); \

char* readstring(FILE* file, char* str) {
    if (str == nullptr) {
        do {
            fscanf(file, "%*c");
        } while (!feof(file));

        return nullptr;
    }

    int index = 0;
    do {
        fscanf(file, "%c", &str[index]);
        index++;
    } while (!feof(file));
    str[index-1] = 0;
    return str;
}