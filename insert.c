#include "insert.h"


// intiially, data will be structured as  [id | name | location] - for easy mapping in the file
void insert(FILE* db, struct Row* data, size_t * dataLen){
	printf("inserting into the db \n \n");
	// start at 1 so we don't write the header
	int page_id=0;
	int offset = 0;
	for(size_t i =1; i < *dataLen; i++){
		long curPos = ftell(db);
		page_id = curPos / PAGE_SIZE;
		offset = curPos - (page_id*PAGE_SIZE);
		// record_t * rec = create_record((long long)data[i].id, page_id, offset);
		// printf("record I am inserting, id: %d \n", &rec->id);

		// bptree_status status = bptree_put(tree, &rec->id, rec);
		// if (status != BPTREE_OK) {
		// printf("shoot \n");
		// }
		int res = fwrite(&data[i], sizeof(struct Row), 1, db);
		if (!res){
			printf("Error occured while writing exiting \n");
		}
		else{
			printf("Successfully inserted : %d, %s, %s \n", data[i].id, data[i].name, data[i].location);
		}
	}
	printf("data was successfully inserted into the DB \n");
}

size_t loopOverCSV(struct Row* arrayOfRows, FILE* csv){
	char line[1024];
	int count =0;
	while(fgets(line, sizeof(line), csv)){
		if (arrayOfRows != NULL){
			arrayOfRows[count].id = strtol(strtok(line,","), NULL, 10);
			strcpy(arrayOfRows[count].name , strtok(NULL,","));
			strcpy(arrayOfRows[count].location , strtok(NULL,","));
			// printf("parsed : %ld, %s, %s \n", arrayOfRows[count].id, arrayOfRows[count].name, arrayOfRows[count].location);
		}
		count+=1;
	}
	return count;
}

static record_t* create_record(const bptree_key_t id, uint32_t page_id, uint32_t offset) {
    record_t* rec = malloc(sizeof(record_t));
    if (!rec) {
        perror("Failed to allocate memory for record");
        return NULL;
    }

	rec->id = id;
	rec->page_id = page_id;
	rec->offset = offset;
    return rec;
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

static void print_key(const bptree_key_t key) {
    printf("FOUND KEY : %lld \n", (long long)key);  // Use %lld for int64_t
}
static void print_value(const bptree_value_t value) {
    printf("FOUND PAGE_ID : %lld \n", (long long)value->page_id);  
    printf("FOUND PAGE_ID : %lld \n", (long long)value->offset);  
}


// int main(int argc, char * argv[]){
// 	if (argc < 2){
// 		printf("program Usage : ./main file.csv");
// 		exit(1);
// 	}

// 	// print_key(newRecord->id);
// 	// print_value(newRecord);

// 	size_t * fileLen = malloc(sizeof(size_t));
// 	struct Row* data =  parseIncomingData(argv[1], fileLen);
// 	FILE* dbWrite = openFile(PATH_TO_DB, "ab");
// 	FILE* outFile = openFile("outFile.bin", "ab");
// 	insert(dbWrite, data, fileLen); // this should be length of file
	
// 	fclose(outFile);
// 	fclose(dbWrite);
// 	free(data);
// 	return 0;
// }