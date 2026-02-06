#include <assert.h>
#include <stdalign.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define PATH_TO_DB "dbFile.bin"
#include "createBtree.h"


FILE * dbFile;
bptree * tree;

int main(){
    
    // printf("_|_     _|_     _|_     _|_     _|_     _|_     _|_     _\n \n");
    printf("Welcome to the DB ^_^ \n");
    while(true){
        printf("Would you like to read or insert (r/i)? \n");
        char input;
        scanf("%c", &input);

        if (input == 'i'){
            printf("===== insert mode ======= \n \n");
            dbFile = openFile(PATH_TO_DB, "ab");

            printf("enter a path to a file \n");
            char filePath[256];
            scanf("%s", filePath);
            printf("the file path is : %s \n", filePath);
            size_t * fileLen = malloc(sizeof(size_t)); // length of the file which will be updated in `parseIncomingData`
	        struct Row* data =  parseIncomingData(filePath, fileLen);
            insert(dbFile, data, fileLen, tree);
            fclose(dbFile);
            continue;
        }
        if (input == 'r'){
            printf("===== retrieve mode ======= \n");
            dbFile = openFile(PATH_TO_DB, "rb");
            // in retrieve mode we need to create the bTree
            constructTree(dbFile, tree);
                        
            fclose(dbFile);
        }
        else {
            printf("Not a valid mode, enter ('r' or 'i') \n");
        }

    }
    return 0;
}