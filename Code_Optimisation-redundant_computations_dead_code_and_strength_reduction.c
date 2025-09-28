#include <stdio.h>

int main() {
    printf("Original Code:\n");
    printf("x = 2 * 8\n");
    printf("y = x * 1\n");
    printf("z = y + 0\n");

    int x = 2 * 8;  
    int z = x;      

    printf("\nOptimized Code:\n");
    printf("x = %d\n", x);
    printf("z = x\n");

    return 0;
}
