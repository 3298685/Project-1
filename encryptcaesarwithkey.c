#include <stdio.h> //Standard input and output
#include "input.h"


// declare function
void encryption(char *x, int key);

void CaesarEncrypt()  {
    
    // Initialise variables and string
char message[1000];
int i=0;

FILE * input;
input = fopen("input.txt", "r");
if(message == NULL) {
perror("fopen()");
return;
}

fscanf(input, "%d %s", &key, message);

printf("\n\n%d %s\n\n", &key, message);

    
    /* While loop Changes message from lower case to uppercase by testing if ascii value of the 
    letters are between a and z and then taking away 32 to make them a capital letter*/
    
    while(message[i] != '\0') {//while the i'th value of message does not equal null the loop continues
        if (message[i]>= 'a' && message[i] <= 'z')
        message[i] = message [i] - 32;
        ++i;
    }

    //calls function to encrypt message and then print the result.
    encryption(message, key);
    printf("%s\n", message);
}    
/*  Function definition. This function has a while loop that checks if the i'th value is a symbol or a letter
    via the first while if statements. If a symbol is found it sends out the value and continues to the next i value.
    The capital letters left over are then given a value from A=0 to Z=26 by subtracting 65 from the ascii value.
    The encryption key is then added and modulus 26 used which makes letters greater than 25 rotate back to A */
void encryption (char *x,int key){
    int i = 0; //initialise integer i to 0 to allow it to start at first array input
    while (x[i] != '\0')    {//while the i'th value does not equal null the loop continues
        if (x[i] < 'A' || x[i] > 'Z'){//All symbols below the ascii 'A' and above ascii 'Z' value are not encrypted 
            x[i] = x[i];
            i++;// adds 1 onto i to move onto the next value
        }
        else {//while the i'th value of message does not equal null the loop continues
            x[i] = ((x[i] - 65 + key ) % 26) + 65;//The letters are given a value between 0 and 25 then encrypted and given back there original ascii number.
            i++;
        }
    }
}