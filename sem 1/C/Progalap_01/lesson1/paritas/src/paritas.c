#include <stdio.h>

int main() {
    int dobottErtek;

    printf("Milyen szamot dobtal?\n");
    scanf("%d", &dobottErtek);

    if (/* feltetel */) {
        printf("Nyertel!");
    } else {
        printf("Vesztettel!");
    }

    return 0;
}