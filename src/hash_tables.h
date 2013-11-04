#ifndef H_HASH_TABLES
#define H_HASH_TABLES

#include <stdint.h>
#include <stdlib.h>
#include "hints.h"

/*  Abstract macros  */

#define HT_DENSE_SIZE 16
#define HT_DENSE_SIZE_LOG 4

#define HASH_TABLE_STRUCT(name, keytype, valuetype) \
    struct name ## _entry { \
        uint32_t hash; \
        keytype key; \
        valuetype value; \
    }; \
    struct name { \
        struct name ## _entry dense[HT_DENSE_SIZE]; \
        size_t table_size; \
        size_t len; \
        struct name ## _entry *table; \
    };


/*  Definitions  */

struct topology;

HASH_TABLE_STRUCT(topht, const char *, struct topology *);
void topht_init(struct topht *table);
int topht_set(struct topht *table, const char *key, struct topology *value)
    TT_USE_RESULT;
struct topology *topht_get(struct topht *table, const char *key);
void topht_free(struct topht *table, void (*free_elm)(struct topology *));


struct role;

HASH_TABLE_STRUCT(roleht, const char *, struct role *);
void roleht_init(struct roleht *table);
int roleht_set(struct roleht *table, const char *key, struct role *value)
    TT_USE_RESULT;
struct role *roleht_get(struct roleht *table, const char *key);
void roleht_free(struct roleht *table, void (*free_elm)(struct role *));

#endif  /*  H_HASH_TABLES  */
