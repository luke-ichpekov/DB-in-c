#define PAGE_SIZE 4096 // bytes
// index record
bptree * tree;

static int record_compare(const bptree_key_t* a, const bptree_key_t* b) {
    // Assumes BPTREE_NUMERIC_TYPE is defined (default is int64_t)
    return (*a < *b) ? -1 : ((*a > *b) ? 1 : 0);
}

void constructTree(FILE* db, record_t * dOut, bptree_key_t key){
    int page_id=0;
	int offset = 0;
    while(fread(dOut, sizeof(struct record_t*), 1, db)){
    long curPos = ftell(db);
    page_id = curPos / PAGE_SIZE;
    offset = curPos - (page_id*PAGE_SIZE);
    record_t * rec = create_record((long long)dOut->id , page_id, offset);
    printf("record I am inserting, id: %d \n", &rec->id);
    bptree_status status = bptree_put(tree, &rec->id, rec);

    if (status != BPTREE_OK) {
    printf("shoot \n");
    }
    
            printf("found row: %ld, %s, %s \n", dOut->id, dOut->name, dOut->location);
        }
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


void createTree(FILE* db, struct Row* data, size_t * dataLen){
	// start at 1 so we don't write the header
	int page_id=0;
	int offset = 0;
	for(size_t i =1; i < *dataLen; i++){
		long curPos = ftell(db);
		page_id = curPos / PAGE_SIZE;
		offset = curPos - (page_id*PAGE_SIZE);
		record_t * rec = create_record((long long)data[i].id, page_id, offset);

		int res = fwrite(&data[i], sizeof(struct Row), 1, db);
		if (res){
			// printf("successfully inserted into the DB \n");
		} else{
			printf("Error occured while writing exiting \n");
		}
	}
}

int main(){
    tree = bptree_create(4, record_compare, true);

}