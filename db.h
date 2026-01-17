#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define NAME_SIZE 64
#define LOCATION_SIZE 64
#define PATH_TO_DB "dbFile.bin"

struct Row {
	int64_t id;
	char name[NAME_SIZE];
	char location[LOCATION_SIZE];
};

FILE* openFile(char *filePath, char* mode);
