#include "db.h"

void insert(FILE* db, struct Row* data);
void parseIncomingData(char* filePath);
struct Row* parseArgs(char* args[]);
