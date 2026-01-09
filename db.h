#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 64
#define LOCATION_SIZE 64
#define PATH_TO_DB "dbFile.bin"

struct Row {
	long id;
	char name[NAME_SIZE];
	char location[LOCATION_SIZE];
};

FILE* openDB(char* mode);
