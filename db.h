#include <stdio.h>

char* PATH_TO_DB = "dbFile.bin";
const int ID_SIZE = 20;
const int NAME_SIZE = 20;
const int LOCATION_SIZE = 20;

struct Row {
	char id[ID_SIZE];
	char name[NAME_SIZE];
	char location[LOCATION_SIZE];
};

FILE* openDB(char* mode);
