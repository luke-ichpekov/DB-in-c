#define BPTREE_VALUE_TYPE struct record*  // Configure tree to store pointers to records
#pragma once
#include "db.h"
#include "bptree.h"
#define PAGE_SIZE 4096 // bytes
#define BPTREE_IMPLEMENTATION
#include "insert.h"


void constructTree(FILE* db, bptree * tree);
void insert(FILE* db, struct Row* data, size_t * dataLen);
struct Row* parseIncomingData(char* filePath, size_t*fileLen);
static record_t* create_record(const bptree_key_t id, uint32_t page_id, uint32_t offset);