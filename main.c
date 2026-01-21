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


int main(){
    while(true){

        printf("_|_     _|_     _|_     _|_     _|_     _|_     _|_     _\n \n");
        printf("Welcome to the DB ^_^ \n");
        printf("Would you like to read or insert (r/i)? \n");
        char input;
        scanf("%c", &input);
        if (input == "i"){
            printf("===== insert mode ======= \n");
        }
        FILE* dbWrite = openFile(PATH_TO_DB, "ab");

    }
    return 0;
}