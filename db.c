#include "db.h"

FILE* openFile(char *filePath, char* mode){
	FILE* db = fopen(filePath, mode);
	if (db == NULL){
		printf("error opening the DB exiting..");
		exit(1);
	}
	return db;
}