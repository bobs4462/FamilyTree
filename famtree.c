#include <famtree.h>

ftptr build_tree(FILE *treefile) 
{
    char *string = NULL, **names = NULL, t;
    size_t num = 0, clc = 1, nlc = 0;
    ftptr *clevel = NULL, *nlevel = NULL;

    num = lineget(&string, treefile);//
    names = getwords(string, &num);
    clevel = realloc(clevel, sizeof(ftptr) * clc);
    ftptr ancestor = clevel[0] = create_member(names[0], NULL);

    while ((t = getc(treefile)) != EOF) {
        ungetc(t, treefile);
        for (int i = 0; i < clc; ++i) {
            if ((num = lineget(&string, treefile)) < 5 && num != EOF) {
                clevel[i]->kids = NULL;
                continue;
            }
            else if (num == EOF)
                return ancestor;
            names = getwords(string, &num);
            nlc += num;
            nlevel = realloc(nlevel, sizeof(ftptr) * nlc);
            clevel[i]->kidsc = num;
            clevel[i]->kids = realloc(clevel[i]->kids, sizeof(ftptr) * num);
            for (int j = 0; j < num; ++j) {
                clevel[i]->kids[j] = nlevel[nlc - num + j] = create_member(names[j], clevel[i]);
            }
        }
        clc = nlc;
        num = nlc = 0;
        clevel = realloc(clevel, sizeof(ftptr) * clc);
        for (int k = 0; k < clc; ++k)
            clevel[k] = nlevel[k];

    }
    free(string);
    free(clevel);
    free(nlevel);
    return ancestor;
}

             

ftptr create_member(char *value, ftptr ancestor)
{
    ftptr temp = malloc(sizeof(struct famtree));
    temp->name = value;
    temp->parent = ancestor;
    temp->kidsc = 0;
    temp->kids = NULL;
    return temp;
}

char** getwords(char *line, size_t *size) 
{
    size_t wordc = 0, j = 0;
    static char **words = NULL;
    unsigned short mark = 0;

    for (size_t i = 0; line[i] != '\0'; ++i) {
        if (line[i] == ',' || line[i] == '\n') {
           ++wordc;
           words = realloc(words, sizeof(char *) * wordc);
           words[wordc - 1] = malloc(i - mark + 1);
           for (j = mark; j < i; ++j) 
               words[wordc - 1][j - mark] = line[j];
           words[wordc - 1][i - mark] = '\0';
           mark = i + 1;
        }
    }
    *size = wordc;
    return words;
}


int lineget(char **text, FILE *fileptr)
{
    char buffer[1024];
    int i = 0, t = 0;
    while ((t = getc(fileptr)) != '\n')
        if (t == EOF)
            return EOF;
        else
            buffer[i++] = t; 
    buffer[i++] = '\n';
    buffer[i] = '\0';
    *text = realloc(*text, sizeof(char) * (i + 1));
    for (int j = 0; j < i + 1; ++j)
        (*text)[j] = buffer[j];
         
    return i;
} 
    
    
