#include <stdio.h>

/*
Az alabbi fuggveny elso parametere egy sztring. A feladat a fuznivalo
nevu sztring hozzafuzese az elso parameterhez. A feladat megoldhato
egy ciklus es ket szamlalo hasznalataval. Az elso szamlalo az elso
parameterben kapott sztring vegenel indul, a masodik a hozzafuzendo
sztring elejerol. Minden lepesben a masodik szamlalo altal mutatott
elemet kell atirni az eredmeny-sztring elso szamlalo altal mutatott
helyere. Figyelj arra, hogy az eredmeny-sztring veget lezard a sztring
veget jelzo 0 kodu karakterrel!
Az eredmenyt az eredeti str nevu sztringben kell elkesziteni.
Kodold le a fuggvenyt C nyelven. A fuggveny fejlecen ne valtoztass!
 */

void osszefuz(char str[], char fuznivalo[]) {
    int str_vege = 0;
    int fuznivalo_eleje = 0;

    while(1) {
        if(str[str_vege] != '\0') {
            str_vege++;
        }
        else if(fuznivalo[fuznivalo_eleje] != '\0')
        {
            str[str_vege] = fuznivalo[fuznivalo_eleje++];
            str[++str_vege] = '\0';
        }
        else break;
    }
}

int main() {
    char string[] = "Hello ";
    osszefuz(string, "World!");
    printf(string);
    return 0;
}