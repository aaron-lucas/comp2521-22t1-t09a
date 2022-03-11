#include <stdlib.h>
#include <stdio.h>

int add(int x, int y) { 
    return x + y;
}

int subtract(int x, int y) {
    return x - y;
}

int multiply(int x, int y) {
    return x * y;
}

int divide(int x, int y) {
    return x / y;
}


int main(int argc, char *argv[]) {

    int (*operation)(int, int);     // Declare "operation" as a pointer to function with arguments (int, int) returning int
    int x, y;

    printf("Enter two numbers (x and y): ");
    scanf("%d %d", &x, &y);

    operation = add;  // Can set a function pointer this way...
    printf("adding: %d\n", operation(x, y));  // Call a function pointer as if it was a normal function

    operation = &subtract;  // or this way...
    printf("subtracting: %d\n", operation(x, y));

    operation = &(multiply);  // or this way
    printf("multiplying: %d\n", operation(x, y));

    operation = divide;
    printf("dividing: %d\n", operation(x, y));

    return EXIT_SUCCESS;
}
