#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void deepsearch(ftptr ancestor, char * target);
void widesearch(ftptr ancestor, char * target);
int lineget(char **text, FILE *fileptr);
int sift(char **text);
