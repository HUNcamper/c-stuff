/***********************************************************************
* A PROGRAMBAN NEM SZEREPELHETNEK AZ ALÁBBI SOROK:
* #include <string.h>
* #include <math.h>
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>

/***********************************************************************
************************************************************************
**		ETTŐL A PONTTÓL DOLGOZHATSZ A FELADATOKON
************************************************************************
***********************************************************************/

/*
1. feladat (5 pont)

A leghosszabb() fuggveny feladata a parameterben kapott szovegben meghatarozni
a leghosszabb szo hosszat. A szovegben a szavakat szokozok valasztjak el, de
a szoveg legvegen nem feltetlenul van szokoz. A szavak az angol abece kis- es
nagybetuit, valamint szamokat tartalmazhatnak. Vesszok, pontok, felkialtojelek,
kerdojelek vagy egyeb irasjelek nincsenek a szovegben. A fuggveny a leghosszabb
szo hosszaval terne vissza.

A fuggveny megvalositasa hibakat tartalmaz.
Javitsd ki ezeket a hibakat.
*/
int leghosszabb(char szoveg[]) {
    int i, szohossz = 0, maxszohossz = 0;
    for (i = 0; szoveg[i] != '\0'; ++i) {
        if (szoveg[i] != ' ') {
            ++szohossz;
        } else {
            if (szohossz > maxszohossz) {
                maxszohossz = szohossz;
            }
            szohossz = 0;
        }
    }
    return szohossz > maxszohossz ? szohossz : maxszohossz;
}

/*
2. feladat (5 pont)

Az alabbi fuggveny elso parametere egy egeszekbol allo tomb, aminek a
meretet a fuggveny utolso elotti parametereben kapjuk meg. A feladat a
fuznivalo nevu tomb elemeinek hozzafuzese az elso parameterhez. E masik
tomb meretet az utolso parameterben kapjuk.
Figyelj arra, hogy az eredmeny-tomb meretevel terjen vissza a fuggvenyed!
Az eredmenyt a masodik parameterben kapott eredmeny nevu tombben kell
elkesziteni.
Kodold le a fuggvenyt C nyelven. A fuggveny fejlecen ne valtoztass!
*/
int tombosszefuzes(int tomb[], int eredmeny[], int fuznivalo[], int meret, int fmeret) {
    int e_i = 0;

    for (int i = 0; i < meret; ++i) {
        eredmeny[e_i++] = tomb[i];
    }

    for (int i = 0; i < fmeret; ++i) {
        eredmeny[e_i++] = fuznivalo[i];
    }

    return e_i;
}
/***********************************************************************
************************************************************************
**
**	EZEN A PONTON TÚL NE VÁLTOZTASS SEMMIT SEM A FÁJLON!
**
************************************************************************
***********************************************************************/

void call_1()
{
    char szoveg[128];

    int i;
    for (i = 0; i < 128; ++i)
        szoveg[i] = ' ';
    szoveg[i-1] = '0';

    if (fgets(szoveg, 128, stdin) == NULL) {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }

    fprintf(stdout, "%d\n", leghosszabb(szoveg));
}
void test_1()
{
    int i, eredmeny;
    struct {char szoveg[128]; int eredmeny;} testlist[1] = {
            {"eez az ez az ki mi", 3},
    };
    for (i = 0; i < 1; ++i) {
        eredmeny = leghosszabb(testlist[i].szoveg);
        if (eredmeny != testlist[i].eredmeny) {
            fprintf(stderr, "HIBA: leghosszabb(\"%s\")\n"
                            "\telvárt eredmény: %d\n"
                            "\tkapott eredmény: %d\n",
                    testlist[i].szoveg, testlist[i].eredmeny, eredmeny);
        }
    }
}

void call_2()
{
    char x=0;
    int i, n=0, m=0, l=0, a[32]={-2}, c[32]={-2}, r[32]={-2};
    if(fscanf(stdin, "%c", &x)!=1) {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }
    if(fscanf(stdin, "%d", &n)!=1) {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }
    for(i=0; i<n; i++) {
        if(fscanf(stdin, "%d", a+i)!=1) {
            fprintf(stderr, "HIBA: Nem olvasható adat!\n");
            return;
        }
    }
    if(fscanf(stdin, "%d", &m)!=1) {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }
    for(i=0; i<m; i++) {
        if(fscanf(stdin, "%d", c+i)!=1) {
            fprintf(stderr, "HIBA: Nem olvasható adat!\n");
            return;
        }
    }
    l=tombosszefuzes(a, r, c, n, m);
    if(x=='R') {
        fprintf(stdout, "R:%d\n", l);
    } else {
        if(x=='E') l=n+m;
        for(i=0; i<l; i++) {
            fprintf(stdout, "%d\n", r[i]);
        }
    }
}
void test_2()
{
    int i, j, ret = 0, tomb[20] = {0}, eredmeny[20] = {0};
    struct {int tomb[20]; int meret; int fuznivalo[20]; int fuznimeret; int eredmeny[20]; int e_meret;} testlist[2] = {
            {{1,2,3}, 3, {4,5,6},   3, {1,2,3,4,5,6}, 6},
            {{},      0, {5,4,5,4}, 4, {5,4,5,4},     4},
    };
    for (i = 0; i < 2; ++i) {
        for(j = 0; j < testlist[i].meret; tomb[j] = testlist[i].tomb[j], ++j);
        ret = tombosszefuzes(tomb, eredmeny, testlist[i].fuznivalo, testlist[i].meret, testlist[i].fuznimeret);
        for(j = 0; j < ret && j < testlist[i].e_meret && eredmeny[j] == testlist[i].eredmeny[j]; ++j);
        if (j != ret || j != testlist[i].e_meret) {
            fprintf(stderr, "HIBA: tombosszefuzes({");
            for(j = 0; j < testlist[i].meret - 1; fprintf(stderr, "%d,", testlist[i].tomb[j++]));
            fprintf(stderr, "%d}, {...}, {", testlist[i].tomb[j]);
            for(j = 0; j < testlist[i].fuznimeret - 1; fprintf(stderr, "%d,", testlist[i].fuznivalo[j++]));
            fprintf(stderr, "%d}, %d, %d)\n", testlist[i].fuznivalo[j], testlist[i].e_meret, testlist[i].fuznimeret);
            fprintf(stderr, "\telvárt eredmény: %d {", testlist[i].e_meret);
            for(j = 0; j < testlist[i].e_meret - 1; fprintf(stderr, "%d,", testlist[i].eredmeny[j++]));
            fprintf(stderr, "%d}\n", testlist[i].eredmeny[j]);
            fprintf(stderr, "\tkapott eredmény: %d {", ret);
            for(j = 0; j < ret - 1 && j < 10; fprintf(stderr, "%d,", eredmeny[j++]));
            if (j < 10) {
                if (j > 0) {
                    fprintf(stderr, "%d}\n", eredmeny[j]);
                } else {
                    fprintf(stderr, "}\n");
                }
            } else {
                fprintf(stderr, "...}\n");
            }
        }
    }
}

typedef void (*call_function)();

call_function call_table[] = {
        call_1,
        call_2,
        NULL
};


call_function test_table[] = {
        test_1,
        test_2,
        NULL
};

static int __arg_check_helper(const char * exp, const char * arg) {
    while (*exp && *arg && *exp == *arg) {
        ++exp;
        ++arg;
    }
    return *exp == *arg;
}

int main(int argc, char *argv[])
{
    int feladat, calltabsize;
    if ((argc > 1) && !(__arg_check_helper("-t", argv[1]) && __arg_check_helper("--test", argv[1]))) {
        if (argc > 2) {
            feladat = atoi(argv[2]);
            for (calltabsize=0; test_table[calltabsize]; calltabsize++);
            if (feladat <= 0 || calltabsize < feladat) {
                fprintf(stderr, "HIBA: rossz feladat sorszám: %d!\n", feladat);
                return 1;
            }
            (*test_table[feladat-1])();
        } else {
            for (feladat=0; test_table[feladat]; ++feladat) {
                (*test_table[feladat])();
            }
        }
        return 0;
    }
    if (!freopen("be.txt", "r", stdin)) {
        fprintf(stderr, "HIBA: Hiányzik a `be.txt'!\n");
        return 1;
    }
    if (!freopen("ki.txt", "w", stdout)) {
        fprintf(stderr, "HIBA: A `ki.txt' nem írható!\n");
        return 1;
    }
    for (calltabsize=0; call_table[calltabsize]; calltabsize++);
    if (fscanf(stdin, "%d%*[^\n]", &feladat)!=1) {
        fprintf(stderr, "HIBA: Nem olvasható a feladat sorszám!\n");
        return 1;
    }
    fgetc(stdin);
    if (0<feladat && feladat<=calltabsize) {
        (*call_table[feladat-1])();
    } else {
        fprintf(stderr, "HIBA: Rossz feladat sorszám: %d!\n", feladat);
        return 1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
