#include <stdio.h>

int main() {
    FILE* file_be = fopen("be.txt", "r");

    int oszlop_n;
    fscanf(file_be, "%d", &oszlop_n);

    int sorrend[10];
    for (int i = 0; i < 10; ++i) {
        sorrend[i] = -1;
    }

    for (int i = 0; i < oszlop_n; ++i) {
        int elem;

        fscanf(file_be, "%d", &elem);

        sorrend[i] = elem;
    }

    // Beolvasás
    char string[255]; int string_hossz = 0;
    char string_out[255];
    int string_i = 0;
    int sorrend_i = 0;
    int ok = 1;

    // String beolvasása
    fscanf(file_be, "%s", string);
    printf("%s\n", string);

    // String hossza
    for (int i = 0; string[i] != '\0'; ++i) {
        string_hossz++;
    }

    //hibakezelés
    if(string_hossz % oszlop_n != 0) {
        sprintf(string_out, "HIBA:MARADEK");
        ok = 0;
    }
    //hibakezelés vége

    int oszlopok_szama = string_hossz / oszlop_n;
    printf("%d\n", oszlopok_szama);

    while(ok) {
        if(string[string_i] == '\0') break;

        int jelenlegi_sorrend = sorrend[sorrend_i++] - 1;

        //hibakezelés
        if(jelenlegi_sorrend >= oszlop_n) {
            sprintf(string_out, "HIBA:OSZLOP:%d", jelenlegi_sorrend+1);
            break;
        }
        //hibakezelés vége

        for (int i = 0; i < oszlopok_szama; ++i) {
            char elem = string[string_i++];

            int uj_i = i * oszlop_n + jelenlegi_sorrend;
            string_out[uj_i] = elem;
        }

        string_out[string_hossz] = '\0';
    }

    fclose(file_be);

    FILE* file_ki = fopen("ki.txt", "w");

    fprintf(file_ki, "%s\n", string_out);

    fclose(file_ki);

    return 0;
}
