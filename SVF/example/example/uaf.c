#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* A = malloc(10 * sizeof(char));
    char* B = A;
    int x = 1;
    int y = 1;
    if(x == 1){
    A[3] = 'a';
    free(B);
    }
    if(y == 2){
    A[4] = 's';
    }else{
    free(A);
    }
    return 0;
}
