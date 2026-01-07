#include "retrieve.h"


FILE* openDB(char* mode){
	FILE* db = fopen(PATH_TO_DB, mode);
	if (db == NULL){
		printf("error opening the DB exiting..");
		exit(1);
	}
	return db;
}
void retrieve(FILE* db, struct Row * dOut){
	while(fread(dOut, sizeof(struct Row), 1, db)){
		printf("retrieved : %s, %s, %s \n", dOut->id, dOut->name, dOut->location);
	}
}

int main(int argc, char * argv[]){
	if (argc < 4){
		printf("program Usage : ./retrieve id");
		exit(1);
	}
	struct Row* retrievalRow = malloc(sizeof(struct Row)); 
	FILE* dbRead = openDB("rb");
	retrieve(dbRead, retrievalRow);
	return 0;
}