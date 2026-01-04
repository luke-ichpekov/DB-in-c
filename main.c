#include <stdio.h>
#include <stdlib.h>

void parseArgs(char* args[]);

// intiially, data will be structured as  [id | name | location] - for easy mapping in the file
struct Row {
	char* id;
	char* name;
	char* location;
};


void parseArgs(char* args[]){
	struct Row data;
	data.id = args[1];
	data.name = args[2];
	data.location = args[3];
	printf("data.id: %s, data.name: %s, data.location: %s \n", data.id, data.name, data.location);
}

int main(int argc, char * argv[]){
	if (argc < 4){
		printf("program Usage : ./main id name location");
		exit(1);
	}
	parseArgs(argv);
	return 0;
}