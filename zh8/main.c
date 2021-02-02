#include <stdio.h>

int main() {
    int sor, oszlop;

    FILE* file_be = fopen("be.txt", "r");

    fscanf(file_be, "%d %d\n", &sor, &oszlop);

    int oszlop_min[oszlop]; // Adott oszlopban mi a jelenlegi minimum

    for (int i = 0; i < oszlop; ++i) {
        oszlop_min[i] = 0; // y koordináta, melyik oszlopban van?
    }

    // Beolvasás
    int jelenlegi_elem;
    int matrix[sor][oszlop];

    for (int y = 0; y < sor; ++y) {

        for (int x = 0; x < oszlop; ++x) {
            fscanf(file_be, "%d", &jelenlegi_elem);

            matrix[y][x] = jelenlegi_elem;
        }
        fscanf(file_be, "\n");
    }
    fclose(file_be);


    int nyeregpont[2]; // x és y koordináta
    nyeregpont[0] = -1;
    nyeregpont[1] = -1;

    for (int y = 0; y < sor; ++y) {

        for (int x = 0; x < oszlop; ++x) {
            // Sorban maximum?
            int sor_max = matrix[y][x]; // tfh. jelenlegi érték
            for (int x_2 = 0; x_2 < oszlop; ++x_2) {
                if(sor_max < matrix[y][x_2]) {
                    sor_max = matrix[y][x_2];
                }
            }
            printf("%d. sor max: %d\n", y, sor_max);

            // Oszlopban minimum?
            int oszlop_min = matrix[y][x]; // tfh. jelenlegi érték
            for (int y_2 = 0; y_2 < sor; ++y_2) {
                // Végigpásztázunk a jelenlegi oszlopon
                if(oszlop_min > matrix[y_2][x]) {
                    oszlop_min = matrix[y_2][x];
                }
            }

            if(sor_max == matrix[y][x] && oszlop_min == matrix[y][x]) {
                nyeregpont[0] = x;
                nyeregpont[1] = y;
                break;
                //printf("Uj nyeregpont: %d (x: %d y: %d)\n", jelenlegi_elem, x, y);
            }
        }

        if(nyeregpont[0] != -1 && nyeregpont[1] != -1) {
            break;
        }
    }

    int x = nyeregpont[0];
    int y = nyeregpont[1];

    int nyeregpont_n = y * oszlop + x;

    if(nyeregpont[0] == -1 || nyeregpont[1] == -1) {
        nyeregpont_n = -1;
    }

    FILE* file_ki = fopen("ki.txt", "w");
    fprintf(file_ki, "%d\n", nyeregpont_n);
    fclose(file_ki);

    //printf("Nyeregpont x: %d, y: %d", nyeregpont[0], nyeregpont[1]);

    return 0;
}
