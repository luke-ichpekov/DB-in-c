#define BPTREE_VALUE_TYPE struct record*  // Configure tree to store pointers to records
#pragma once
#include "db.h"
#include "bptree.h"
#define BPTREE_IMPLEMENTATION

typedef struct record {
    /** @brief The numeric key used for indexing in the B+ tree. */
    int64_t id;
	uint32_t page_id;
	uint32_t offset;
} record_t;

// void retrieve(FILE* db, struct record_t * dOut, long key);
