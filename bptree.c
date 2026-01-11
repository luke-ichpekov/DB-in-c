#define BPTREE_IMPLEMENTATION
#include "bptree.h"

typedef struct record {
    /** @brief The numeric key used for indexing in the B+ tree. */
    bptree_key_t id;
    /** @brief A simple data field associated with the record. */
    char name[32];
} record_t;


static int record_compare(const bptree_key_t* a, const bptree_key_t* b) {
    // Assumes BPTREE_NUMERIC_TYPE is defined (default is int64_t)
    return (*a < *b) ? -1 : ((*a > *b) ? 1 : 0);
}

int main(){
    bptree * tree = bptree_create(4, record_compare, true);
    printf("b tree created , maxKeys : %d \n", tree->max_keys);
    
}