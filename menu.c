#include <stdio.h>
#include "input.h"


int main() {
    FILE * input;
    int key = 0; 
    char message[1000];
input = fopen("input.txt", "r");
if(message == NULL) {
perror("fopen()");
return;
}

fscanf(input, "%d %s", &key, message);

printf("\n\n%d %s, %d, %s\n\n", key, message, new_number, new);




   /*printf("%d/n", TASK);
   void CaesarEncrypt()
   void CaesarDecrypt()
    return 0;*/
}