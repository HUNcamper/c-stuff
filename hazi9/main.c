#include <stdio.h>

int karaktertSzamol(char* string, char karakter) {
    int db = 0;

    for (int i = 0; string[i] != '\0'; ++i) {
        if(string[i] == karakter) {
            db++;
        }
    }

    return db;
}

int exponential(int base, int exp) {
    int out = 1;
    for (int i = 0; i < exp; ++i) {
        out *= base;
    }

    return out;
}

int strToInt(char string[]) {
    int out = 0;

    int length = 0;
    for (int i = 0; string[i] != '\0'; ++i) {
        length++;
    }

    int j = length-1;
    for (int i = 0; i < length; ++i) {
        int num = string[i] - '0';

        out += num * exponential(10, j--);
    }

    return out;
}


//printf("%s\n", sor);
//printf("%d\n", vesszok);

enum direction {
    Jobbra,
    Fel,
    Balra,
    Le
};

int main() {
    FILE* file = fopen("be.txt", "r");

    int matrix[20][20];
    int visited[20][20];

    for (int y = 0; y < 20; ++y) {
        for (int x = 0; x < 20; ++x) {
            matrix[y][x] = -1;
            visited[y][x] = 0;
        }
    }

    int kezdopoz[2];
    int kezdopoz_i = 0;

    char sor[255];
    int sor_i = 0;
    int x = 0, y = 0;

    while(1) {
        fscanf(file, "%s\n", sor);
        char szam_c[255];
        int szam_c_i = 0;

        if(sor[0] == '-') break;

        for (int i = 0; ; ++i) {
            if(sor[i] == ',' || sor[i] == '\0') {
                szam_c[szam_c_i] = '\0';
                int szam = strToInt(szam_c);

                if(sor_i == 0) {
                    // első sor, kezdő poz.
                    kezdopoz[kezdopoz_i++] = szam;

                } else {
                    matrix[y][x] = szam;
                    visited[y][x] = 2;
                    x++;
                }

                szam_c_i = 0;;

                if(sor[i] == '\0') break;
                continue;
            }

            szam_c[szam_c_i++] = sor[i];
        }

        if(sor_i > 0) {
            x = 0; y++;
        }
        sor_i++;

    }

    fclose(file);

    printf("kezdo: [%d, %d]\n\n", kezdopoz[0], kezdopoz[1]);

    // Mozgás
    int dir = Fel;
    x = kezdopoz[0]; y = kezdopoz[1];

    int ok = 0;

    while(ok != 1) {
        visited[y][x] = 1;
        switch (dir) {
            case Fel:
                if(visited[y-1][x] != 0 && visited[y-1][x] != 2) {
                    dir = Balra;
                    break;
                }
                y--;
                break;
            case Balra:
                if(visited[y][x-1] != 0 && visited[y][x-1] != 2) {
                    dir = Le;
                    break;
                }
                x--;
                break;
            case Le:
                if(visited[y+1][x] != 0 && visited[y+1][x] != 2) {
                    dir = Jobbra;
                    break;
                }
                y++;
                break;
            case Jobbra:
                if(visited[y][x+1] != 0 && visited[y][x+1] != 2) {
                    dir = Fel;
                    break;
                }
                x++;
                break;
        }

        ok = 1;
        for (int y = 0; y < 20; ++y) {
            for (int x = 0; x < 20; ++x) {
                if(visited[y][x] == 2) ok = 0;
            }
        }

        switch (dir) {
            case Balra:
                printf("Balra");
                break;
            case Jobbra:
                printf("Jobbra");
                break;
            case Le:
                printf("Le");
                break;
            case Fel:
                printf("Fel");
                break;
        }
        printf("\n");

        for (int y = 0; y < 20; ++y) {
            for (int x = 0; x < 20; ++x) {
                printf("%d ", visited[y][x]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
