#include <stdio.h>

void printNumber(int number) {
    printf("%d\n", number);
}

int main() {
    int num = 15;
    printNumber(num);
    for (int i = 0; i < 100; i++)
    {
        printf("%d. Macska\n", i+1);
    }
    
    return 0;
}

// -t kapcsolo: teszt esetek fajlnev atiras helyett