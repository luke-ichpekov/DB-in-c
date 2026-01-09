#include "insert.h"

// intiially, data will be structured as  [id | name | location] - for easy mapping in the file
void insert(FILE* db, struct Row* data, size_t * dataLen){
	// start at 1 so we don't write the header
	for(size_t i =1; i < *dataLen; i++){
		int res = fwrite(&data[i], sizeof(struct Row), 1, db);
		if (res){
			printf("successfully inserted into the DB \n");
		} else{
			printf("Error occured while writing exiting \n");
		}
	}
}

size_t loopOverCSV(struct Row* arrayOfRows, FILE* csv){
	char line[1024];
	int count =0;
	while(fgets(line, sizeof(line), csv)){
		if (arrayOfRows != NULL){
			arrayOfRows[count].id = strtol(strtok(line,","), NULL, 10);
			strcpy(arrayOfRows[count].name , strtok(NULL,","));
			strcpy(arrayOfRows[count].location , strtok(NULL,","));
			printf("parsed : %ld, %s, %s \n", arrayOfRows[count].id, arrayOfRows[count].name, arrayOfRows[count].location);
		}
		count+=1;
	}
	return count;
}

struct Row* parseIncomingData(char* filePath, size_t*fileLen ){
	struct Row* arrayOfRows = NULL;
	printf("opening csv..  %s \n", filePath);
	FILE* csv = fopen(filePath, "r");
	*fileLen = loopOverCSV(arrayOfRows, csv) - 1;
	fseek(csv,0, SEEK_SET);
	arrayOfRows = malloc(*fileLen*sizeof(struct Row));
	loopOverCSV(arrayOfRows, csv);
	return arrayOfRows;
}

int main(int argc, char * argv[]){
	if (argc < 2){
		printf("program Usage : ./main file.csv");
		exit(1);
	}
	size_t * fileLen = malloc(sizeof(size_t));
	struct Row* data =  parseIncomingData(argv[1],fileLen);
	FILE* dbWrite = openDB("ab");
	insert(dbWrite, data, fileLen ); // this should be length of file
	// fclose(dbWrite);
	// free(data);
	return 0;
}