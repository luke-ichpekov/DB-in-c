#include "retrieve.h"

void retrieve(FILE* db, struct Row * dOut){
	while(fread(dOut, sizeof(struct Row), 1, db)){
		printf("retrieved : %s, %s, %s \n", dOut->id, dOut->name, dOut->location);
	}
}

int main(int argc, char * argv[]){
	if (argc < 2){
		printf("program Usage : ./retrieve id");
		exit(1);
	}
	struct Row* retrievalRow = malloc(sizeof(struct Row)); 
	FILE* dbRead = openDB("rb");
	retrieve(dbRead, retrievalRow);
	return 0;
}