#include "db.h"

FILE* openDB(char* mode){
	FILE* db = fopen(PATH_TO_DB, mode);
	if (db == NULL){
		printf("error opening the DB exiting..");
		exit(1);
	}
	return db;
}