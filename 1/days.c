#include <stdlib.h>
#include <stdio.h>

char *numToDay(int n);

int main(int argc, char *argv[]) {

    int num = atoi(argv[1]);

    printf("%s\n", numToDay(num));

    return EXIT_SUCCESS;
}

char *numToDay(int n) {
    char *day;
    if (n == 0) {
        day = "Sun";
    } else if (n == 1) {
        day = "Mon";
    } else if (n == 2) {
        day = "Tue";
    } else if (n == 3) {
        day = "Wed";
    } else if (n == 4) {
        day = "Thu";
    } else if (n == 5) {
        day = "Fri";
    } else if (n == 6) {
        day = "Sat";
    }
    return day;
}


char *numToDaySwitch(int n) {
    char *day;
    switch (n) {
        case 0: day = "Sun"; break;
        case 1: day = "Mon"; break;
        case 2: day = "Tue"; break;
        case 3: day = "Wed"; break;
        case 4: day = "Thu"; break;
        case 5: day = "Fri"; break;
        case 6: day = "Sat"; break;
    }

    return day;

}

char *numToDayArray(int n) {
    char *days[7] = { "Sun", ... };

    return days[n];
}
