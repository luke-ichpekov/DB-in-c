#pragma once
#include "db.h"

void insert(FILE* db, struct Row* data, size_t dataLen);
struct Row* parseIncomingData(char* filePath);
struct Row* parseArgs(char* args[]);