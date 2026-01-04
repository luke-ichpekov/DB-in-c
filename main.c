#include <stdio.h>
#include <stdlib.h>

struct Row* parseArgs(char* args[]);
FILE* openDB(char* mode);
void insert(FILE* db, struct Row* data);

char* PATH_TO_DB = "dbFile.bin";
// intiially, data will be structured as  [id | name | location] - for easy mapping in the file
struct Row {
	char* id;
	char* name;
	char* location;
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
	int res = fwrite(data, sizeof(*data), 1, db);
	printf("flag : %d \n", res);
}

struct Row* parseArgs(char* args[]){
	struct Row* data = (struct Row *) malloc(sizeof(struct Row));
	data->id = args[1];
	data->name = args[2];
	data->location = args[3];
	return data;
}
void retrieve(FILE* db){
	struct Row r;
	while (fread(&r, sizeof(struct Row), 2, db) == 1){
		printf("retrieved : %s, %s, %s", r.id, r.location, r.name);
	}
	
}

int main(int argc, char * argv[]){
	if (argc < 4){
		printf("program Usage : ./main id name location");
		exit(1);
	}
	// struct Row* data = parseArgs(argv);
	// FILE* dbWrite = openDB("wb");
	// insert(dbWrite, data);
	// free(data);
	// fclose(dbWrite);
	FILE* dbRead = openDB("rb");
	retrieve(dbRead);
	return 0;
}