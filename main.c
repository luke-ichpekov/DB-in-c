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
    while(true){

        printf("_|_     _|_     _|_     _|_     _|_     _|_     _|_     _\n \n");
        printf("Welcome to the DB ^_^ \n");
        printf("Would you like to read or insert (r/i)? \n");
        char input;
        scanf("%c", &input);

        if (input == "i"){
            printf("===== insert mode ======= \n");
            dbFile = openFile(PATH_TO_DB, "ab");
            constructTree(dbFile, tree);
            fclose(dbFile);
        }
        else if (input == "r"){
            printf("===== retrieve mode ======= \n");
            dbFile = openFile(PATH_TO_DB, "rb");
            // in retrieve mode we need to create the bTree
                        
            fclose(dbFile);
        }
        else {
            printf("Not a valid mode, enter ('r' or 'i') \n");
        }

    }
    return 0;
}