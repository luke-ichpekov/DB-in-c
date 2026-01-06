#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Row* parseArgs(char* args[]);
FILE* openDB(char* mode);
void insert(FILE* db, struct Row* data);

const int ID_SIZE = 20;
const int NAME_SIZE = 20;
const int LOCATION_SIZE = 20;

char* PATH_TO_DB = "dbFile.bin";
// intiially, data will be structured as  [id | name | location] - for easy mapping in the file
struct Row {
	char id[ID_SIZE];
	char name[NAME_SIZE];
	char* location[LOCATION_SIZE];
};

FILE* openDB(char* mode){
	FILE* db = fopen(PATH_TO_DB, mode);
	if (db == NULL){
		printf("error opening the DB exiting..");
		exit(1);
	}
	return db;
}
void insert(FILE* db, struct Row* data){
	int res = fwrite(data, sizeof(struct Row), 1, db);
	printf("flag : %d \n", res);
}

struct Row* parseArgs(char* args[]){
	struct Row* data = (struct Row*)malloc(sizeof(struct Row));
	strcpy(data->id , args[1]);
	strcpy(data->name , args[2]);
	strcpy(data->location , args[3]);
	return data;
}
void retrieve(FILE* db, struct Row * dOut){
	while(fread(dOut, sizeof(struct Row), 1, db)){
		printf("retrieved : %s, %s, %s \n", dOut->id, dOut->name, dOut->location);
	}
}

int main(int argc, char * argv[]){
	// if (argc < 4){
	// 	printf("program Usage : ./main id name location");
	// 	exit(1);
	// }
	// struct Row* data = parseArgs(argv);
	// FILE* dbWrite = openDB("ab");
	// insert(dbWrite, data);
	// fclose(dbWrite);
	// free(data);

	struct Row* retrievalRow = malloc(sizeof(struct Row)); 
	FILE* dbRead = openDB("rb");
	retrieve(dbRead, retrievalRow);
	return 0;
}