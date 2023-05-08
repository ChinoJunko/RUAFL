#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void doSomeThingUselessA(char *ch)
{
    printf("A wrong path!");
    if (ch[10] == '1')
        if (ch[11] == '2')
            if (ch[12] == '3')
                if (ch[13] == '4')
                    if (ch[14] == '5')
                        if (ch[15] == '6')
                            if (ch[16] == '7')
                                if (ch[17] == '8')
                                    if (ch[18] == '9')
                                    {
                                        printf("totally A wrong Path!");
                                    }
}

void doSomeThingUselessB(char *ch)
{
    printf("A wrong path!");
    if (ch[10] == '1')
        if (ch[11] == '2')
            if (ch[12] == '3')
                if (ch[13] == '4')
                    if (ch[14] == '5')
                        if (ch[15] == '6')
                            if (ch[16] == '7')
                                if (ch[17] == '8')
                                    if (ch[18] == '9')
                                    {
                                        printf("totally A wrong Path!");
                                    }
}

void doSomeThingUselessC(char *ch)
{
    printf("A wrong path!");
    if (ch[10] == '1')
        if (ch[11] == '2')
            if (ch[12] == '3')
                if (ch[13] == '4')
                    if (ch[14] == '5')
                        if (ch[15] == '6')
                            if (ch[16] == '7')
                                if (ch[17] == '8')
                                    if (ch[18] == '9')
                                    {
                                        printf("totally A wrong Path!");
                                    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("usage: %s filename", argv[0]);
        return 0;
    }
    FILE *stream = fopen(argv[1], "r");
    char s[20];
    int *p = malloc(20);
    int *q = p;
    memset(s, 0, 20);
    fgets(s, 20, stream);
    if (s[0] == 'a')
    {
        printf("%d",p[0]);
        free(p);
        if (s[1] == 'b')
        {
            if (s[2] == 'c')
            {
                if (s[3] == 'd')
                {
                    if (s[4] == 'e')
                    {
                        printf("%d",p[1]);
                        free(p);
                        
                    }
                    else if (s[4] == ';')
                    {
                        doSomeThingUselessA(s);
                    }
                }
                else if (s[3] == '5')
                {
                    doSomeThingUselessA(s);
                }
            }
            else if (s[2] == '3')
            {
                doSomeThingUselessB(s);
            }
        }
        else if (s[1] == '5')
        {
            doSomeThingUselessB(s);
        }
    }
    else if (s[0] == '8')
    {
        doSomeThingUselessC(s);
    }
}
