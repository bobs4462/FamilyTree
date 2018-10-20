#include <famtree.h>
#include <locale.h>

int main(int argc, char **argv) 
{
    setlocale(LC_ALL, "rus");
    char *searchterm = NULL;
    size_t len = 0;
    if(argc < 2) {
        printf("Program usage is 'famtree <filename>'");
        exit(1);
    }
    FILE *openfile = fopen(argv[1], "r");
    ftptr ancestor = build_tree(openfile);
    printf("Tree build completed successfully!\n");
    printf("Enter the member name to perform deepsearch!: ");
    lineget(&searchterm, stdin);
    widesearch(ancestor, searchterm);
    return 0;
}

