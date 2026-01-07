#include "insert.h"
#include "retrieve.h"

// intiially, data will be structured as  [id | name | location] - for easy mapping in the file

void insert(FILE* db, struct Row* data){
	int res = fwrite(data, sizeof(struct Row), 1, db);
	if (res){
		printf("successfully inserted into the DB \n");
	} else{
		printf("Error occured while writing exiting \n");
	}
}

void parseIncomingData(char* filePath){
	// this should call retrieve maybe? in the other file, so we can reuse it
	printf("opening csv.. ");
}

struct Row* parseArgs(char* args[]){
	struct Row* data = (struct Row*)malloc(sizeof(struct Row));
	strcpy(data->id , args[1]);
	strcpy(data->name , args[2]);
	strcpy(data->location , args[3]);
	return data;
}

int main(int argc, char * argv[]){
	if (argc < 4){
		printf("program Usage : ./main file.csv");
		exit(1);
	}
	struct Row* data = parseArgs(argv);
	FILE* dbWrite = openDB("ab");
	insert(dbWrite, data);
	fclose(dbWrite);
	free(data);
	return 0;
}