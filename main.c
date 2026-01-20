#include <assert.h>
#include <stdalign.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    printf("_|_     _|_     _|_     _|_     _|_     _|_     _|_     _\n \n");
    printf("Welcome to the DB ^_^ \n");
    printf("Would you like to read or insert (r/i)? \n");
    char input;
    scanf("%s",input);
    // fix seg-fault
    printf("Your input is: %s", input);
    return 0;
}