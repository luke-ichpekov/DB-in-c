#include "insert.h"

// intiially, data will be structured as  [id | name | location] - for easy mapping in the file
void insert(FILE* db, struct Row* data, size_t dataLen){
	for(int i =0; i < dataLen; i++){
		int res = fwrite(&data[i], sizeof(struct Row), 1, db);
		if (res){
			printf("successfully inserted into the DB \n");
		} else{
			printf("Error occured while writing exiting \n");
		}
	}
}

struct Row* parseIncomingData(char* filePath){
	printf("opening csv..  %s \n", filePath);
	FILE* csv = fopen(filePath, "r");
	char line[1024];
	int lengthOfFile = 100; // get actual length
	struct Row* arrayOfRows = malloc(lengthOfFile*sizeof(struct Row));
	int count =0;
	while(fgets(line, sizeof(line), csv)){
		// strcpy(data->id, strtok(line,","));
		// strcpy(data->name, strtok(NULL,","));
		// strcpy(data->location, strtok(NULL,","));
		strcpy(arrayOfRows[count].id , strtok(line,","));
		strcpy(arrayOfRows[count].name , strtok(NULL,","));
		strcpy(arrayOfRows[count].location , strtok(NULL,","));
		printf("parsed : %s, %s, %s \n", arrayOfRows[count].id, arrayOfRows[count].name, arrayOfRows[count].location);
		count+=1;
		// printf("parsed : %s, %s, %s \n", data->id, data->name, data->location);
	}
	return arrayOfRows;
}

struct Row* parseArgs(char* args[]){
	struct Row* data = (struct Row*)malloc(sizeof(struct Row));
	strcpy(data->id , args[1]);
	strcpy(data->name , args[2]);
	strcpy(data->location , args[3]);
	return data;
}

int main(int argc, char * argv[]){
	if (argc < 2){
		printf("program Usage : ./main file.csv");
		exit(1);
	}
	struct Row* data =  parseIncomingData(argv[1]);
	FILE* dbWrite = openDB("ab");
	insert(dbWrite, data, 100 ); // this should be length of file
	// fclose(dbWrite);
	// free(data);
	return 0;
}