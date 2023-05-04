#include <stdio.h>
#include <stdlib.h>

void myfree(char* i){
    free(i);
}

void Additional(char *d, int a){
    if(a == 1){
    d[1]='2';
    free(d);
    }
}

int main()
{
    char* A = malloc(10 * sizeof(char));
    char* B = A;
    int x,y;
    //int x = 1;
    //int y = 1;
    scanf("%d %d",&x,&y);
    if(x == 1){
    A[3] = 'a';
    myfree(B);
    }
    if(y == 2){
    A[4] = 's';
    }else{
    myfree(A);
    }
    Additional(B, x);
    return 0;
}
