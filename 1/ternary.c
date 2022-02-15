#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> // For isdigit

int main(int argc, char *argv[]) {

    int ch = getchar();

    char *type;
//     if (isdigit(ch)) {
//         type = "digit";
//     } else {
//         type = "non-digit";
//     }

    type = isdigit(ch) ? "digit" : "non-digit";

    // condition ? result_if_true : result_if_false;

    printf("'%c' is a %s\n", ch, type);

    return EXIT_SUCCESS;
}
