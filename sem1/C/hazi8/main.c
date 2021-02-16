#include <stdio.h>

enum dontes {Jobbra, Marad, Balra};

// Hány db elpusztítatlan meteor van az adott sorban?
int meteor_szamolas(int sor[], int sor_n, int robot_poz) {
    int db = 0;

    for (int i = 0; i < sor_n; ++i) {
        // Amin a robot áll az el van pusztítva, ne legyen beleszámolva.
        if(i == robot_poz) continue;

        if(sor[i]) db++;
    }

    return db;
}

// A robot kezdő pozíciójának megválasztása
int robot_kezdo_poz(int sor[], int sor_n) {
    for (int i = 0; i < sor_n; ++i) {
        if(sor[i]) return i;
    }

    return 0;
}

// Robot mozgatása döntés alapján
int robot_mozog(int poz, int n, int dontes) {
    switch (dontes) {
        case Jobbra:
            if(poz < n-1) poz++;
            break;
        case Balra:
            if(poz > 0) poz--;
            break;
    }

    return poz;
}

// Döntés, hogy a robot melyik irányba haladjon tovább
int robot_dontes(int sor[], int sor_n, int robot_poz) {
    int balra_db = 0, jobbra_db = 0;

    // Meteor a robot pozícióján
    if(sor[robot_poz]) return Marad;

    // Megnézzük a robot szomszédos celláit
    int poz_balra = robot_mozog(robot_poz, sor_n, Balra);
    int poz_jobbra = robot_mozog(robot_poz,sor_n, Jobbra);

    if(sor[poz_balra] && sor[poz_jobbra]) return Marad;  // ha 1-1 akkor maradjon.
    if(sor[poz_balra])                    return Balra;  // ha 1-0 akkor menjen balra
    if(sor[poz_jobbra])                   return Jobbra; // ha 0-1 akkor menjen jobbra

    // Ha a szomszédos cellákban nincs meteor, akkor összeszámoljuk a maradékot, és az alapján döntünk.
    for (int i = 0; i < sor_n; ++i) {
        if(!sor[i]) continue;

        if(i < robot_poz)       balra_db++;
        else                    jobbra_db++;
    }

    // Ha egyenlő db van jobbra és balra akkor maradjunk.
    if(balra_db == jobbra_db) return Marad;

    //printf("(b_db: %d, j_db: %d)", balra_db, jobbra_db);

    return balra_db > jobbra_db ? Balra : Jobbra;
}

// Main
int main() {
    FILE* file_be = fopen("be.txt", "r");
    FILE* file_ki = fopen("ki.txt", "w");

    // Beolvasás
    int sor, oszlop;
    fscanf(file_be, "%d %d\n", &sor, &oszlop);

    int robot_poz;
    int megmaradt_meteor_db = 0;

    for (int i = 0; i < sor; ++i) {

        int jelenlegi_sor[oszlop];

        for (int j = 0; j < oszlop; ++j) {
            // Jelenlegi mátrix sor beolvasása
            int ertek;
            fscanf(file_be, "%d", &ertek);
            jelenlegi_sor[j] = ertek;
        }
        fscanf(file_be, "\n");

        // Első iteráció, a robot pozíciójának megválasztása
        if(i == 0) robot_poz = robot_kezdo_poz(jelenlegi_sor, oszlop);

        int dontes = robot_dontes(jelenlegi_sor, oszlop, robot_poz);
        robot_poz = robot_mozog(robot_poz, oszlop, dontes);

        megmaradt_meteor_db += meteor_szamolas(jelenlegi_sor, oszlop, robot_poz);

        /*
        //DEBUG KIRAJZOLÁS
        for (int j = 0; j < oszlop; ++j) {
            if(j == robot_poz && jelenlegi_sor[j] == 1) printf("X ");
            else if(j == robot_poz) printf("R ");
            else printf("%d ", jelenlegi_sor[j]);
        }
        if(dontes == Jobbra) printf(" ->");
        if(dontes == Balra)  printf(" <-");
        printf("\n");
        //DEBUG KIRAJZOLÁS
         */
    }

    // Kiírás
    fprintf(file_ki, "%d\n", megmaradt_meteor_db);

    fclose(file_be);
    fclose(file_ki);

    return 0;
}
