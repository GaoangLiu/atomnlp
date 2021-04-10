#include <stdio.h>
#include <ctype.h>

char *lower(char *str){ 
    char *pc = str;
    for(; *pc; pc++) *pc = tolower(*pc);
    return str;
}


int main(int argc, char *argv[]){
    char *str = "CAPTILAIZE";
    // lower(str);
}

