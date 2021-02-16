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

Az alabbi fuggveny elso parametere egy egeszekbol allo tomb, aminek
a meretet a fuggveny utolso parametereben kapjuk meg. A feladat a
tomb megforditasa. A feladat megoldhato egy ciklus es ket szamlalo
hasznalataval. Az elso szamlalo a tomb elejerol, a masodik az
eredmeny-tomb vegerol indul. Minden lepesben az elso szamlalo altal
mutatott elemet kell beszurni az eredmeny-tombbe a masodik szamlalo
altal mutatott helyre. Figyelj arra, hogy az eredmeny-tomb meretevel
terjen vissza a fuggvenyed!
Az eredmenyt a masodik parameterben kapott eredmeny nevu tombben kell
elkesziteni.
Kodold le a fuggvenyt C nyelven. A fuggveny fejlecen ne valtoztass!
*/
int tombmegforditas(int tomb[], int eredmeny[], int meret) {
    int elol = 0;
    int hatul = meret-1;

    while(elol < meret) {
        eredmeny[elol++] = tomb[hatul--];
    }

    return meret;
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
    char x=0;
    long l=0;
    int i, n=0, a[32]={-2}, r[32]={-2};
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
    l=tombmegforditas(a, r, n);
    if(x=='R') {
        fprintf(stdout, "R:%ld\n", l);
    } else {
        if(x=='E') l=n;
        for(i=0; i<l; i++) {
            fprintf(stdout, "%d\n", r[i]);
        }
    }
}
void test_1()
{
    int i, j, ret = 0, tomb[20] = {0}, eredmeny[20] = {0};
    struct {int tomb[20]; int meret; int eredmeny[20]; int e_meret;} testlist[2] = {
            {{3,2,1,2,3},   5, {3,2,1,2,3},   5},
            {{1,2,3,4,5,6}, 6, {6,5,4,3,2,1}, 6},
    };
    for (i = 0; i < 2; ++i) {
        for(j = 0; j < testlist[i].meret; tomb[j] = testlist[i].tomb[j], ++j);
        ret = tombmegforditas(tomb, eredmeny, testlist[i].meret);
        for(j = 0; j < ret && j < testlist[i].e_meret && eredmeny[j] == testlist[i].eredmeny[j]; ++j);
        if (j != ret || j != testlist[i].e_meret) {
            fprintf(stderr, "HIBA: tombmegforditas({");
            for(j = 0; j < testlist[i].meret - 1; fprintf(stderr, "%d,", testlist[i].tomb[j++]));
            fprintf(stderr, "%d}, {...}, %d)\n", testlist[i].tomb[j], testlist[i].e_meret);
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
        NULL
};


call_function test_table[] = {
        test_1,
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
