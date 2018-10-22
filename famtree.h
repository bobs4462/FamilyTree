#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct famtree {
    char *name;
    struct famtree *parent;
    struct famtree **kids;
    int kidsc;
};

typedef struct famtree * ftptr;

ftptr build_tree(FILE *treefile);
ftptr create_member(char *value, ftptr ancestor);
char** getwords(char *line, size_t *size);
void search(ftptr ancestor, char * target, char c);
int lineget(char **text, FILE *fileptr);
