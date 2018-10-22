#include <famtree.h>
#include <ctype.h>

void goodbye(void);

int main(int argc, char **argv) 
{
    char *searchterm = NULL, c = 0;
    size_t len = 0;
    if(argc < 2) {
        printf("Program usage is 'famtree <filename>'");
        exit(1);
    }
    FILE *openfile = fopen(argv[1], "r");
    ftptr ancestor = build_tree(openfile);
    printf("Построение семейного древа успешно завершено!\n\n");
    sleep(1);
    while(1) {
    printf("Пожалуйста выберите режим поиска: d/w/q\n");
    printf("d для поиска в глубину w для поиска в ширину,\n");
    printf("q для выхода. ==> ");
    c = getchar();
    while(getchar() != '\n');
    c = tolower(c);
    if (c == 'q')
        goodbye();
    printf("Теперь введите искомое имя в древе\n==> ");
    lineget(&searchterm, stdin);
    fflush(stdin);
    search(ancestor, searchterm, c);
    }
    return 0;
}

void goodbye(void)
{
    printf("Хорошего вам дня!!!\n");
    exit(0);
}

