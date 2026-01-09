#include "retrieve.h"

void retrieve(FILE* db, struct Row * dOut, long key){
	while(fread(dOut, sizeof(struct Row), 1, db)){
        if (dOut->id == key){
            printf("found row: %ld, %s, %s \n", dOut->id, dOut->name, dOut->location);
        }
	}
}

int main(int argc, char * argv[]){
	if (argc < 2){
		printf("program Usage : ./retrieve id");
		exit(1);
	}
    long id = strtol(argv[1], NULL, 10);
    printf("ID we are getting : %ld \n", id);
	struct Row* retrievalRow = malloc(sizeof(struct Row)); 
	FILE* dbRead = openDB("rb");
    retrieve(dbRead, retrievalRow, id);
	return 0;
}