#include "createBtree.h"

static int record_compare(const bptree_key_t* a, const bptree_key_t* b) {
    // Assumes BPTREE_NUMERIC_TYPE is defined (default is int64_t)
    return (*a < *b) ? -1 : ((*a > *b) ? 1 : 0);
}

void constructTree(FILE* db, bptree * tree){
    printf("constructing the Btree \n");
    int page_id=0;
	int offset = 0;
	record_t * retrievalRow = NULL;
    while(fread(retrievalRow, sizeof(struct record_t*), 1, db)){
    long curPos = ftell(db);
    page_id = curPos / PAGE_SIZE;
    offset = curPos - (page_id*PAGE_SIZE);
    printf("record I am inserting, id: %d \n", &retrievalRow->id);
    bptree_status status = bptree_put(tree, &retrievalRow->id, retrievalRow);
    if (status != BPTREE_OK) {
    printf("shoot \n");
    }
}
}

static record_t* create_record(const bptree_key_t id, uint32_t page_id, uint32_t offset) {
    record_t* rec = malloc(sizeof(record_t));
    if (!rec) {
        perror("Failed to allocate memory for record");
        return NULL;
    }

	rec->id = id;
	rec->page_id = page_id;
	rec->offset = offset;
    return rec;
}