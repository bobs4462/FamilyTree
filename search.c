#include <famtree.h>

void deepsearch(ftptr ancestor, char * target)
{
    ftptr *OPEN = NULL;
    ftptr *temp = NULL;
    size_t opsz = 1;
    OPEN = malloc(sizeof(ftptr *));
    OPEN[0] = ancestor;
    ftptr vertice = NULL, tracker = NULL;
    size_t ts = 0;
    char **names = getwords(target, &ts);
    while (OPEN != NULL) {
        vertice = OPEN[0];
        if (!strcmp(vertice->name,names[0])) {
            tracker = vertice;
            while (tracker->parent != NULL) {
                printf("%s => ", tracker->name);
                tracker = tracker->parent;
            }
            printf("%s ++\n", tracker->name);
        }
        if ((vertice->kids != NULL) && (opsz == 1)) {
            OPEN = realloc(OPEN, sizeof(ftptr) * (opsz = vertice->kidsc));
            for (int i = 0; i < opsz; ++i)
                OPEN[i] = vertice->kids[i];

        }
        else if (vertice->kids != NULL) {
            temp = realloc(temp, sizeof(ftptr) * (opsz - 1));
            for (int i = 1; i < opsz; ++i)
                temp[i - 1] = OPEN[i];
            OPEN = realloc(OPEN, sizeof(ftptr) * (opsz += vertice->kidsc - 1));
            for (int i = 0; i < vertice->kidsc; ++i)
                OPEN[i] = vertice->kids[i];
            for (int i = vertice->kidsc; i < opsz; ++i)
                OPEN[i] = temp[i - vertice->kidsc];
        }
        else if (opsz > 1) {
            for (int i = 0; i < opsz; ++i)
                OPEN[i] = OPEN[i + 1];
            OPEN = realloc(OPEN, sizeof(ftptr) * (--opsz));
        }
        else if ((opsz == 1) && (vertice->kids == NULL)) {
            free(OPEN);
            OPEN = NULL;
        }
    }
}

void widesearch(ftptr ancestor, char * target)
{
    ftptr *OPEN = NULL;
    ftptr *temp = NULL;
    size_t opsz = 1;
    OPEN = malloc(sizeof(ftptr *));
    OPEN[0] = ancestor;
    ftptr vertice = NULL, tracker = NULL;
    size_t ts = 0;
    char **names = getwords(target, &ts);
    while (OPEN != NULL) {
        vertice = OPEN[0];
        if (!strcmp(vertice->name,names[0])) {
            tracker = vertice;
            while (tracker->parent != NULL) {
                printf("%s => ", tracker->name);
                tracker = tracker->parent;
            }
            printf("%s ++\n", tracker->name);
        }
        if ((vertice->kids != NULL) && (opsz == 1)) {
            OPEN = realloc(OPEN, sizeof(ftptr) * (opsz = vertice->kidsc));
            for (int i = 0; i < opsz; ++i)
                OPEN[i] = vertice->kids[i];

        }
        else if (vertice->kids != NULL) {
            temp = realloc(temp, sizeof(ftptr) * (opsz - 1));
            for (int i = 1; i < opsz; ++i)
                temp[i - 1] = OPEN[i];
            ts = opsz - 1;
            OPEN = realloc(OPEN, sizeof(ftptr) * (opsz += vertice->kidsc - 1));
            for (int i = 0; i < opsz - vertice->kidsc; ++i)
                OPEN[i] = temp[i];
            for (int i = ts; i < opsz; ++i)
                OPEN[i] = vertice->kids[i - ts];
        }
        else if (opsz > 1) {
            for (int i = 0; i < opsz; ++i)
                OPEN[i] = OPEN[i + 1];
            OPEN = realloc(OPEN, sizeof(ftptr) * (--opsz));
        }
        else if ((opsz == 1) && (vertice->kids == NULL)) {
            free(OPEN);
            OPEN = NULL;
        }
    }
}
