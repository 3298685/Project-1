#include <stdio.h>
#include "input.h"


int main() {
    FILE * input;
input = fopen("input.txt", "r");
if(message == NULL) {
perror("fopen()");
return;
}

fscanf(input, "%d %s", &key, message);

printf("\n\n%d %s\n\n", &key, message);
   /*printf("%d/n", TASK);
   void CaesarEncrypt()
   void CaesarDecrypt()
    return 0;*/
}