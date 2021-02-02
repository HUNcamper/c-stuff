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

Irj egy rombusz nevu strukturat, ami az
e es f nevu float tipusu mezoiben
egy rombusz ket atlojat tarolja.
Irj egy compare nevu fuggvenyt, ami ket ilyen
rombuszt kap parameterul, es a nagyobb teruletuvel ter vissza.
Amennyiben a ket rombusz terulete egyforma, akkor a fuggveny
az elso parameterben kapott rombuszt adja vissza.
A rombusz terulete: (e*f)/2.
*/
/****************************************************
 * A kovetkezo sor programba illesztese eseten      *
 * (// torlese a #define elol) a feladat nem okoz   *
 * forditasi hibat, de pontot sem fog erni.         *
 ****************************************************/
//#define KIHAGY_1
#if ! (defined(KIHAGY_1) || defined(KIHAGY_MIND))

rombusz compare(rombusz r1, rombusz r2) {
}

#endif

/*
2. feladat (5 pont)

Egy turautvonalon tobb ellenorzopont van, amiknek egyenkent ismert a
magassagkulonbsege a kiinduloponthoz kepest. Ezek a pontok az utvonalat
szakaszokra bontjak. A feladatunk meghatarozni az utvonal szintemelkedeset,
ami ugy szamolhato, hogy a felfele vezeto szakaszok ket vegpontjanak
magassagkulonbsegeit osszeadjuk. A lefele vezeto szakaszokkal nem kell
foglalkozni. A fuggveny elso parametere egy tomb, amiben az ellenorzopontok
magassagait kapjuk, olyan sorrendben, ahogy kovetik egymast. A masodik
parameter egy egesz szam, ami a tomb meretet adja meg. A kiindulopont
magassaga 0. A fuggveny visszateresi erteke az utvonal szintemelkedese legyen.
*/

int szintemelkedes(int magassagok[], int pontok) {
}
/***********************************************************************
************************************************************************
**
**	EZEN A PONTON TÚL NE VÁLTOZTASS SEMMIT SEM A FÁJLON!
**
************************************************************************
***********************************************************************/

void call_1(){
#if ! (defined(KIHAGY_1) || defined(KIHAGY_MIND))
  int v;
  rombusz a, b, x;
  if(fscanf(stdin, "%d", &v)!=1) {
    fprintf(stderr, "HIBA: Nem olvasható adat!\n");
    return;
  }
  switch(v) {
  case 1:
    if(fscanf(stdin, "%d", &v)!=1) {
      fprintf(stderr, "HIBA: Nem olvasható adat!\n");
      return;
    }
    fprintf(stdout, "fordul%d\n", v);
    break;
  default:
    if(fscanf(stdin, "%f %f", &a.e, &a.f)!=2) {
      fprintf(stderr, "HIBA: Nem olvasható adat!\n");
      return;
    }
    if(fscanf(stdin, "%f %f", &b.e, &b.f)!=2) {
      fprintf(stderr, "HIBA: Nem olvasható adat!\n");
      return;
    }
    x = compare(a, b);
    fprintf(stdout, "[%f,%f]\n", x.e, x.f);
    break;
  }
#endif
}
void test_1(){
#if ! (defined(KIHAGY_1) || defined(KIHAGY_MIND))
  int i;
  rombusz eredmeny;
  struct {rombusz a, b, eredmeny;} testlist[2] = {
    {{.e=3, .f=10}, {.e=6, .f=5 }, {.e=3, .f=10}},
    {{.e=2, .f=5 }, {.e=3, .f=14}, {.e=3, .f=14}}
  };
  for (i = 0; i < 2; ++i) {
    eredmeny = compare(testlist[i].a, testlist[i].b);
    if (eredmeny.e != testlist[i].eredmeny.e || eredmeny.f != testlist[i].eredmeny.f) {
      fprintf(stderr, "HIBA: compare([%f,%f], [%f,%f])\n"
		      "\telvárt eredmény: [%f,%f]\n"
		      "\tkapott eredmény: [%f,%f]\n",
		      testlist[i].a.e, testlist[i].a.f, testlist[i].b.e, testlist[i].b.f,
		      testlist[i].eredmeny.e, testlist[i].eredmeny.f,
		      eredmeny.e, eredmeny.f
      );
    }
  }
#endif
}

void call_2()
{
	int i=0, n=0, eredmeny;
	int magassagok[1000];
	if(fscanf(stdin,"%d",&n)!=1) {
		fprintf(stderr, "HIBA: Nem olvasható adat!\n");
		return;
	}
	while(i<n) {
		if(fscanf(stdin, "%d", magassagok+i)!=1) {
			fprintf(stderr, "HIBA: Nem olvasható adat!\n");
			return;
		}
		i++;
	}
	eredmeny=szintemelkedes(magassagok, n);
	fprintf(stdout, "%d\n", eredmeny);
}
void test_2()
{
  int i, eredmeny;
  struct {int magassagok[100]; int n; int eredmeny;} testlist[2] = {
    {{10,20,20,50,0,50}, 6, 100},
    {{10,20,30,15,0,0},  6,  30}
  };
  for (i = 0; i < 2; ++i) {
  	eredmeny = szintemelkedes(testlist[i].magassagok, testlist[i].n);
    if (eredmeny != testlist[i].eredmeny) {
      fprintf(stderr, "HIBA: szintemelkedes({...}, %d)\n"
                      "\telvárt eredmény: %d\n"
                      "\tkapott eredmény: %d\n",
              testlist[i].n, testlist[i].eredmeny, eredmeny);
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
