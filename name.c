// sub program for exp3
#include <stdio.h>

int main(){
    char name[100];
    int len;

    printf("Enter your name: ");
    scanf("%s", name);

    for(len=0; name[len]!='\0'; ++len);
    printf("Length of the string is: %d\n", len);
    return 0;
}