#include <stdio.h>
#include <string.h>
#include <ctype.h>

char getCodeChar(char inputChar, int i) {
    if (i%2==0) {
        char codedChar = (inputChar +2) <= 'Z' ? (inputChar+2) : (inputChar+2-26) ;
        return codedChar;
    }
    else{
        char codedChar = (inputChar +4)<= 'Z' ? (inputChar+4) : (inputChar+4-26) ;
        return codedChar;
    }
}

int main() {
    char inputString[100];
    char uppChar;
    scanf("%s", inputString);

    for (int i = 0; i < strlen(inputString); i++) {
        uppChar= toupper(inputString[i]);
        printf("%c", getCodeChar(uppChar,i));
    }

    return 0;
}
