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

Epits a memoriaban dinamikusan egy 10x10-es tablat. Hozz letre
dinamikusan egy valoban ketdimenzios char tombot (azaz eloszor
helyet foglalunk a 10 sor pointereinek, majd megfelelo modon minden
sor 10-10 darab elemenek is), majd a letrejott tombot toltsd is fel a
parameterben kapott igen, nem vagy hiba karakterekkel aszerint, hogy
a mezo sorszama oszthato-e az oszlopszammal (a 0-val osztas hiba).
A fuggveny a lefoglalt dinamikus memoriara mutato pointerrel terjen
vissza. A lefoglalt memoria felszabaditasaval nem kell foglalkoznod.
*/

char** oszthatosag(char igen, char nem, char hiba) {
}

/*
2. feladat (5 pont)

A feladat az, hogy egy matematikai kifejezesben eldontsuk, hogy a
zarojelezes helyes-e. A kifejezesben a '(', ')' zarojelek, '+', '-',
'*', '/' muveleti jelek, kis es nagybetuk, illetve szamok szerepelhetnek.
A kovetkezo fuggveny egy sztringet kap parametereul, melyben az adott
kifejezes szerepel. A fuggvenynek meg kell mondania azt a legkisebb
poziciot, ahol a kifejezesben eloszor elofordul egy zarojelezesi hiba.
(Ha a hiba egy hianyzo bezaro zarojel, akkor a hiba a sztring vegen van.)
Ha a kifejezesben nem fordul elo hiba, akkor a fuggvenynek a -1 erteket
kell visszaadnia! A kifejezes esetleges egyeb hibaival (pl. muveleti jel
elmaradasa) ne foglalkozzunk!
*/

int zarojel(char* kifejezes) {
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
	const int n=10;
	int chck;
	int i, j;
	char **ptr = NULL, igen, nem, hiba;
	if(fscanf(stdin, "%d %c %c %c", &chck, &igen, &nem, &hiba)!=4) {
		fprintf(stderr, "HIBA: Nem olvasható adat!\n");
		return;
	}
	ptr = oszthatosag(igen, nem, hiba);
	switch (chck) {
		case 1:
			if (ptr != NULL) {
				free(ptr);
				fprintf(stdout,"%d\n", chck);
			} else {
				fprintf(stdout,"NULL\n");
			}
			break;
		case 2:
			for(i=0; i<n; i++) {
				free(ptr[i]);
				fprintf(stdout,"%d", chck);
			}
			fputc('\n', stdout);
			break;
		case 3:
			for(i=0; i<n; i++) {
		        	for(j=0; j<n; j++) {
					fputc(ptr[i][j], stdout);
				}
				fputc('\n', stdout);
			}
			break;
		default:
			if(fscanf(stdin, "%d %d", &i, &j)!=2) {
				fprintf(stderr, "HIBA: Nem olvasható adat!\n");
				return;
			}
			fprintf(stdout,"%c\n", ptr[i][j]);
			break;
	}
}
void test_1()
{
	const int n = 10;
	int i, j, k;
  char **ptr = NULL;
  struct {char ptr[10][10]; char igen; char nem; char hiba;} testlist[1] = {
  	{
  		{
				{"hiiiiiiiii"},
				{"hinnnnnnnn"},
				{"hiinnnnnnn"},
				{"hininnnnnn"},
				{"hiininnnnn"},
				{"hinnninnnn"},
				{"hiiinninnn"},
				{"hinnnnninn"},
				{"hiininnnin"},
				{"hininnnnni"}
  		},
  		'i',
  		'n',
  		'h'
  	}
  };
  for (i = 0; i < 1; ++i) {
    ptr = oszthatosag(testlist[i].igen, testlist[i].nem, testlist[i].hiba);
    if (ptr == NULL) {
    	fprintf(stderr, "HIBA: NULL pointer\n");
    	return;
    } else {
    	for (j = 0; j < n; ++j) {
    		if (ptr[j] == NULL) {
		    	fprintf(stderr, "HIBA: NULL pointer\n");
		    	return;
    		} else {
	    		for (k = 0; k < n; ++k) {
	    			if (ptr[j][k] != testlist[i].ptr[j][k]) {
	    				fprintf(stderr, "HIBA a(z) (%d,%d) pozíción\n"
	    					              "\telvárt eredmény: %c\n"
	    					              "\tkapott eredmény: %c\n",
	    					              j, k, testlist[i].ptr[j][k], ptr[j][k]);
	    				return;
	    			}
	    		}
	    	}
    	}
    }
    for (j = 0; j < n; free(ptr[j++]));
    free(ptr);
  }
}

void call_2()
{
	int i = 0;
	char kif[100];
	if(fscanf(stdin, "%s", kif)!=1) {
		fprintf(stderr, "HIBA: Nem olvasható adat!\n");
		return;
	}
	i = zarojel(kif);
	fprintf(stdout,"%d\n",i);
}
void test_2()
{
	int i, eredmeny;
	struct {char kif[100]; int eredmeny;} testlist[2] = {
		{"x)(a*x*x-b*x-c)/12*d", 1},
		{"(((0-0)))", -1}
	};
	for (i = 0; i < 2; ++i) {
		eredmeny = zarojel(testlist[i].kif);
		if (testlist[i].eredmeny != eredmeny) {
			fprintf(stderr, "HIBA: zarojel(\"%s\")\n"
							"\telvárt eredmény: %d\n"
							"\tkapott eredmény: %d\n",
					testlist[i].kif, testlist[i].eredmeny, eredmeny);
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
