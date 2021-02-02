#include <stdio.h>

typedef struct {
    char name;
    float korido;
    int kopas_kezd;
    float kopas_mertek;
    int elhaszn_kezd;
    float elhaszn_mertek;
} gumikeverek;

gumikeverek findGumikeverek(gumikeverek* gk, char name, int n) {
    printf("searching for %c\n", name);
    for (int i = 0; i < n; ++i) {
        if(gk[i].name == name) {
            return gk[i];
        }
    }

    printf("ERROR!!!!\n");
    return gk[0];
}

char getNextChar(char* string, int *i) {
    printf("start: %d %c\n", *i, string[*i]);
    for (int j = *i; string[j] != '\0'; ++j) {

        if(string[j] == 'A' || string[j] == 'B' || string[j] == 'C') {
            *i = j+1;
            return string[j];
        }
    }

    return '\0';
}

int main() {
    printf("Hello, World!\n");

    FILE* file = fopen("be.txt", "r");

    gumikeverek gk[3];

    for (int i = 0; i < 3; ++i) {
        fscanf(file, "%c %f %d %f %d %f\n", &gk[i].name, &gk[i].korido, &gk[i].kopas_kezd, &gk[i].kopas_mertek, &gk[i].elhaszn_kezd, &gk[i].elhaszn_mertek);
        printf("%c, %f, %d, %f, %d, %f\n", gk[i].name, gk[i].korido, gk[i].kopas_kezd, gk[i].kopas_mertek, gk[i].elhaszn_kezd, gk[i].elhaszn_mertek);
    }

    int korok;
    float box_kiallas;
    fscanf(file, "%d\n", &korok);
    fscanf(file, "%f\n", &box_kiallas);


    int kovetkezo;
    char kovetkezo_name;
    fscanf(file, "%d%c", &kovetkezo, &kovetkezo_name);

    int beolvasott_i = 0;

    int jelenlegi_name = kovetkezo_name;

    for (int i = 0; i < korok; ++i) {
        gumikeverek jelenlegi_gumi = findGumikeverek(gk, jelenlegi_name, 3);

        if(kovetkezo == i) {
            if (beolvasott_i == 2) {
                continue;
            }
            fscanf(file, "%d%c", &kovetkezo, &kovetkezo_name);
            beolvasott_i++;
        }
    }

    printf("%d %c", kezdo_kor, name);

    //gumikeverek elso = findGumikeverek(gk, getNextChar(strategia, &i), 3);
    //gumikeverek masodik = findGumikeverek(gk, getNextChar(strategia, &i), 3);
    //gumikeverek harmadik = findGumikeverek(gk, getNextChar(strategia, &i), 3);

    //printf("%d", i);

    fclose(file);
    return 0;
}
