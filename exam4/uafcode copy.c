#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv)
{
    int *p = malloc(20);
    int x,y;
    scanf("%d %d",&x,&y);
    if(x==1){
        printf("%d",p[0]);
        free(p);
    }
    if(y==1){
        printf("%d",p[0]);
        free(p);
    }
}
