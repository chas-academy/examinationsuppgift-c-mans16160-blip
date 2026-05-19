#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char names[5][11];
    int scores[5][13];
    double avgs[5];
    double total_sum = 0.0;

    //Läs in datan för eleverna och provresultaten
    for (int i = 0; i < 5; i++) {
        scanf("%s", names[i]);
        
        int sum = 0;
        for (int j = 0; j < 13; j++) {
            scanf("%d", &scores[i][j]);
            sum += scores[i][j];
        }
        avgs[i] = sum / 13.0;       //Elevens medelvärde
        total_sum += sum;
    }

    double group_avg = total_sum / (5.0 * 13.0);   //Gruppens medelvärde

    //Hitta eleven med högst medelvärde
    int max_idx = 0;
    for (int i = 1; i < 5; i++) {
        if (avgs[i] > avgs[max_idx]) {
            max_idx = i;
        }
    }

    //Skriv ut namnet på eleven med högst medelvärde med stor bokstav
    char highest[11];
    strcpy(highest, names[max_idx]);
    highest[0] = toupper(highest[0]);
    printf("%s\n", highest);

    //Skriv ut alla elever med resultat under snittet
    for (int i = 0; i < 5; i++) {
        if (avgs[i] < group_avg) {
            char name[11];
            strcpy(name, names[i]);
            name[0] = toupper(name[0]);
            printf("%s\n", name);
        }
    }

    return 0;
}