#pragma once
#include "db.h"

void insert(FILE* db, struct Row* data, size_t * dataLen);
struct Row* parseIncomingData(char* filePath, size_t*fileLen);