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
1. feladat (2 pont)

A feladat a siknegyed fuggveny megirasa. A fuggveny egy sikbeli pont
x es y koordinatait kapja meg parameterkent, visszateresi
erteke pedig a siknegyed szama, amelyben a pont talalhato.
(A jobb felso az elso, bal felso a masodik, bal also a harmadik,
jobb also pedig a negyedik siknegyed.) A kapott pont nem illeszkedik
egyik tengelyre sem.

Kodold le C nyelven a fuggvenyt! A fuggveny fejlecen ne valtoztass!
A fuggveny inputjai a parameterek, outputja a visszateresi ertek.
A fuggveny nem vegez IO muveleteket!
*/

int siknegyed(double x, double y) {
    int siknegyed = 0;
    if(x < 0) {
        if (y > 0) {
            siknegyed = 2;
        } else if (y < 0) {
            siknegyed = 3;
        }
    }
    else if(x > 0) {
        if(y > 0) {
            siknegyed = 1;
        }
        else if(y < 0) {
            siknegyed = 4;
        }
    }

    return siknegyed;
}

/*
2. feladat (3 pont)

A feladat ket termeszetes szam legnagyobb kozos osztojanak meghatarozasa!
A fuggveny ket parametere ket nemnegativ egesz szam, visszateresi erteke pedig
a ket szam legnagyobb kozos osztoja, vagy -1, ha mindket szam 0 lenne.

Ha mindket parameter nulla, akkor a fuggveny terjen vissza a -1 ertekkel.
Kulonben szuksegunk lesz egy segedvaltozora, amit egyre inicializalunk, es egy ciklusra.
A ciklusvaltozo induljon egyrol, es menjen elegendoen hosszan, peldaul a+b+1-ig.
A ciklusmagban vizsgaljuk meg, hogy a ciklusvaltozo osztoja-e a-nak es b-nek.
Ha mindkettonek osztoja, akkor a segedvaltozoba mentsuk el a ciklusvaltozo aktualis erteket.
A vegen segedetvaltozo erteket adjuk vissza eredmenykent.

Kodold le C nyelven a fuggvenyt! A fuggveny fejlecen ne valtoztass!
A fuggveny inputjai a parameterek, outputja a visszateresi ertek.
A fuggveny nem vegez IO muveleteket!
*/

int lnko(int a, int b) {
    if(a == 0 && b == 0) return -1;

    int legnagyobb = 1;
    for (int i = 1; i < a+b+1; i++) {
        if(a % i == 0 && b % i == 0) {
            legnagyobb = i;
        }
    }

    return legnagyobb;
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
    double x, y;
    int eredmeny;
    if(fscanf(stdin, "%lf %lf", &x, &y)!=2) {
        fprintf(stderr, "HIBA: Nem olvasható adat!\n");
        return;
    }
    eredmeny=siknegyed(x, y);
    fprintf(stdout, "%d\n", eredmeny);
}
void test_1()
{
    int eredmeny, i;
    struct {double x; double y; int eredmeny;} testlist[2] = {{2.0, 0.5, 1}, {-0.2, 0.1, 2}};
    for (i = 0; i < 2; ++i) {
        eredmeny = siknegyed(testlist[i].x, testlist[i].y);
        if (eredmeny != testlist[i].eredmeny) {
            fprintf(stderr, "HIBA: siknegyed(%lf, %lf)\n"
                            "\telvárt eredmény: %d\n"
                            "\tkapott eredmény: %d\n",
                testlist[i].x, testlist[i].y, testlist[i].eredmeny, eredmeny);
        }
    }
}

void call_2()
{
	int a, b, eredmeny;
	if(fscanf(stdin, "%d %d", &a, &b)!=2) {
		fprintf(stderr, "HIBA: Nem olvasható adat!\n");
		return;
	}
	eredmeny=lnko(a, b);
	fprintf(stdout, "%d\n", eredmeny);
}
void test_2()
{
	int eredmeny, i;
	struct {int a; int b; int eredmeny;} testlist[2] = {{33, 55, 11}, {35, 70, 35}};
	for (i = 0; i < 2; ++i) {
		eredmeny = lnko(testlist[i].a, testlist[i].b);
		if (eredmeny != testlist[i].eredmeny) {
			fprintf(stderr, "HIBA: lnko(%d, %d)\n"
							"\telvárt eredmény: %d\n"
							"\tkapott eredmény: %d\n",
				testlist[i].a, testlist[i].b, testlist[i].eredmeny, eredmeny);
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
