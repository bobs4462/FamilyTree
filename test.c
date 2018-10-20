#include <stdio.h>
#include <stdlib.h>

int lineget(char **text, FILE *fileptr)
{
    char buffer[2048];
    int i = 0, t;
    while (((t = getc(fileptr)) != EOF) && (t != '\n'))
            buffer[i++] = t;
    if (t == '\n')
        buffer[i] = t;
    else if (t == EOF)
        return 0;
    buffer[++i] = '\0';
    *text = realloc(*text, sizeof(char) * (i + 1));
    for (int j = 0; j < i + 1; ++j)
        (*text)[j] = buffer[j];
         
    return i + 1;
} 

int main(int argc, char **argv)
{
    char *text = NULL;
    FILE *fp = fopen(argv[1], "r");
    while (lineget(&text, fp))
        printf("%s\n",text);
    return 0;
}



    
    
