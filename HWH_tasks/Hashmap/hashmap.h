#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

#define INITSIZE 1000
#define STRLEN 50
#define IF_KOEF 0,8
#define ENC_KOEF 1,5

typedef struct node_t
{
    struct node_t  *next;
    char            *str;
} node_t;

typedef struct bucket
{
    node_t          *top;
} bucket;

typedef struct
{
    bucket        *array;
    unsigned    capacity;
    unsigned   insertion;
} hashmap;


int Hash_Dtor  (hashmap *hshmp);
int Hash_Resz  (hashmap *hshmp);
int Hash_Fill  (hashmap *hshmp, FILE *file);
int Hash_Ctor  (hashmap *hshmp, unsigned capacity);
int Hash_Insrt (hashmap *hshmp, int key, char *str, unsigned size_buff);

unsigned Hash_Calc (const char *str, unsigned mapsz);

void Hash_Dump (hashmap hshmp);

void File_Open (FILE *file);
void File_Clse (FILE *file);
