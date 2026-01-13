#include "insert.h"
#define BPTREE_IMPLEMENTATION
#include "bptree.h"

#define PAGE_SIZE 4096

// index record
typedef struct record {
    /** @brief The numeric key used for indexing in the B+ tree. */
    int64_t id;
	uint32_t page_id;
	uint32_t offset;
} record_t;



static int record_compare(const bptree_key_t* a, const bptree_key_t* b) {
    // Assumes BPTREE_NUMERIC_TYPE is defined (default is int64_t)
    return (*a < *b) ? -1 : ((*a > *b) ? 1 : 0);
}

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

int main(int argc, char * argv[]){
	if (argc < 2){
		printf("program Usage : ./main file.csv");
		exit(1);
	}
	bptree * tree = bptree_create(4, record_compare, true);
    printf("b tree created , maxKeys : %d \n", tree->max_keys);
	create_record(1, 0, 0);
	size_t * fileLen = malloc(sizeof(size_t));
	struct Row* data =  parseIncomingData(argv[1],fileLen);
	FILE* dbWrite = openDB("ab");
	insert(dbWrite, data, fileLen ); // this should be length of file
	// fclose(dbWrite);
	// free(data);
	return 0;
}