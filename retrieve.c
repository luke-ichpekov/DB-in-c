#include "retrieve.h"

bptree * tree;

static int record_compare(const bptree_key_t* a, const bptree_key_t* b) {
    // Assumes BPTREE_NUMERIC_TYPE is defined (default is int64_t)
    return (*a < *b) ? -1 : ((*a > *b) ? 1 : 0);
}
static void print_key(const bptree_key_t key) {
    printf("%lld", (long long)key);  // Use %lld for int64_t
}

void readInBtree(FILE* bTreePath){
	fread(tree, sizeof(tree), 1, bTreePath);
}

void retrieve(FILE* db, record_t * dOut, bptree_key_t key){
	//check if in btree first
	const bptree_key_t search_key = 3;
	bptree_status status = bptree_get(tree, &search_key, (bptree_value_t*)&dOut);
	if (status != BPTREE_OK) {
		printf("MAAAAAN \n");
	}
	printf("got the key from the tree :  \n");
	print_key(dOut->id);
	// while(fread(dOut, sizeof(struct record_t*), 1, db)){
    //     if ( dOut.	 == key){
    //         printf("found row: %ld, %s, %s \n", dOut->id, dOut->name, dOut->location);
    //     }
	// }
}

int main(int argc, char * argv[]){
	if (argc < 2){
		printf("program Usage : ./retrieve id");
		exit(1);
	}

    bptree_key_t id = strtol(argv[1], NULL, 10);
    printf("ID we are getting : %ld \n", id);
	// record_t * retrievalRow = malloc(sizeof(record_t));
	record_t * retrievalRow = NULL;
	// try and get the index / Btree first
	tree = bptree_create(4, record_compare, true);
	FILE* bTreeFile = openFile("outFile.bin", "rb");
	readInBtree(bTreeFile);	
	printf("tree count : %d \n : ", tree->count);
	FILE* dbRead = openFile(PATH_TO_DB, "rb");
    retrieve(dbRead, retrievalRow, id);
	return 0;
}