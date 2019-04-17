#include <stdio.h>
#include <math.h>
#include "input.h"//header file which has the task number in it.

/* User interface: Changing what the Task is equal to in the header file (input.h) will choose between
 which task you would like to do.

Task = 1    Caesar Cipher Encryption with key.
Task = 2    Caesar Cipher Decryption with key.
Task = 3    Substitution Cipher Encryption with key.
Task = 4    Substitution Cipher Decryption with key.

To input the caesar cipher key and message into the function the file "input.txt" must be modified.
The caesar cipher will read an integer key between 0 and 26 from the first line.
All functions will read the message to be encrypted/decrypted from the second line.

The substitution message will read from the second line of tthe file input.txt. The key must be hardcoded into
the string named subkey.

*/
void encryption(char *x, int key);//declare encryption function.
void decryption(char *x, int key);//declare decryption function.
void substitution_encryption(char *x, char *y);
void substitution_decryption(char *x, char *y, char*z);


int main() {//main function.

     char message[1000];//declare string variable.
     int key, i=0;//declare integer variable.
     char subkey[] = "qwertyuiopasdfghjklzxcvbnm";
     char alphabet []  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
     

    FILE * input;//pointer to a file.
    FILE * output;//pointer to a file.
    input = fopen("input.txt", "r");//open file for reading.
    output = fopen ("output.txt", "w");//open file for writing.
    fscanf(input, "%d\n%[^\n]s", &key, message);//scans from input file and stores integer as key and string as message.
    if(message == NULL) {//if statement to ensure data was read from file and show error if nothing was stored in message.
        perror("fopen()");
    return 0;
    }
    
    //while loop converts lower case letters to uppercase letters.
    while(message[i] != '\0') {//while the i'th value of message does not equal null the loop continues.
        if (message[i]>= 'a' && message[i] <= 'z')//if messasge has lower case letters eg. between 'a' and 'z'.
        message[i] = message [i] - 32;//add 32 onto lower case letters to make them Upper case.
        ++i;//adds one onto counter so loop goes through complete string.
    }

    //while loop converts lowercase letters to uppercase.
    i = 0;
    while(subkey[i] != '\0') {//while the i'th value of message does not equal null the loop continues. message to upper case letters
        if (subkey[i]>= 'a' && subkey[i] <= 'z')
        subkey[i] = subkey[i] - 32;
        ++i;
    }
    
    //This switch case statement chooses what encryption method you would like to do and then completes the function in the case statement.
    switch (Task) {
        case '1': {// if task = 1 in header file then case 1 is selected.
            encryption(message, key);//call encryption function to encrypt message with key.
            printf("%s\n", message);//encrypted message is printed to console.
            fprintf(output,"%s", message);//encrypted message is printed to file output.txt.
            break; //breaks from switch case statement
            }
        case '2': {// if task = 2 in header file then case 2 is selected.
            decryption(message, key);//call encryption function to encrypt message with key.
            printf("%s\n", message);//calls decryption function
            fprintf(output,"%s", message);//decrypted message is printed to file output.txt.
            break; //breaks from switch case statement
            }
        case '3': {//if task = 3 in header file then case 3 is selected
            substitution_encryption(message, subkey);
            printf("%s\n", message);
            fprintf(output,"%s", message);//encrypted message is printed to file output.txt.
            break; //breaks from switch case statement
            }
        case '4': {//if task = 4 in header file then case 4 is selected
            substitution_decryption(message, subkey, alphabet);
            printf("%s\n", message);
            fprintf(output,"%s", message);//decrypted message is printed to file output.txt.
        }

    }

}
// Caesar encryption function------------------------------------------------------------------//
/*  Function definition. This function has a while loop that checks if the i'th value is a symbol or a letter
    via the first while if statements. The function has two inputs, an integer named key and a string named message. If a symbol is found it sends out the value and continues to the next i value.
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
// End of caesar encryption function---------------------------------------------------------------------

// Start of caesar decryption function------------------------------------------------------------------- 

/*  Function definition. This function has a while loop that checks if the i'th value is a symbol or a letter
    via the first while if statements. The inputs are an integer named key and a string named message. If a symbol is found it sends out the value and continues to the next i'th value.
    The capital letters left over are then given a value from A=0 to Z=26 by subtracting 65 from the ascii value.
    The encryption key is then added and modulus 26 used which makes letters greater than 25 rotate from Z to A */
void decryption (char *x,int key) {
    int i = 0; //initialise integer i to 0 to allow it to start at first array input
    while (x[i] != '\0')    {//while the i'th value does not equal null the loop continues
        if (x[i] < 'A' || x[i] > 'Z'){//All symbols below the ascii 'A' and above ascii 'Z' value are not encrypted 
            x[i] = x[i];
            i++;// adds 1 onto i to move onto the next value
        }
          else {//while the i'th value of message does not equal null the loop continues
            int a;//declare integer a.
            a = (x[i] - 65 - key );//gives letters a value between 0 and 25 then subtracts the key.
            if (a < 0) {//modulus operator does not work for negative numbers. If statement checks whether they are negative.
             a = a + 26;//If they are negative add 26 so letters less than 'A' rotate back to 'Z'.
            x[i] = a % 26 + 65;//use modulus to decrypt letter and add 65 to reassign letters to original ascii value.
            }
            else // else if letters are already positve then decrypt and reassign back to original ascii value.
            x[i] = a % 26 + 65;//The letters are given a value between 0 and 25 then encrypted and given back there original ascii number.
            i++;
        }   

    }
}
// End of caesar decryption-------------------------------------------------------------------
// Start of substitution encryption function---------------------------------------------------
void substitution_encryption(char *x, char *y){
    int i=0;
    while (x[i] != '\0'){
         if (x[i] < 'A' || x[i] > 'Z'){//All symbols below the ascii 'A' and above ascii 'Z' value are not encrypted 
            x[i] = x[i];
            i++;// adds 1 onto i to move onto the next value
         }
        else    {
            int c = x[i] - 65;
            x[i] = y[c];
            i++;
        }
    }
}
//End substitution encryption function---------------------------------------------
//Start of substitution decryption function-------------------------------------
void substitution_decryption(char *x, char *y, char *z){
    int i=0;
    while (x[i] != '\0'){
         int c=0;
         if (x[i] < 'A' || x[i] > 'Z'){//All symbols below the ascii 'A' and above ascii 'Z' value are not encrypted 
            x[i] = x[i];
            i++;// adds 1 onto i to move onto the next value
         }
        else    {
             while (c < 30) {
                if (x[i] == y[c]){
                   x[i] = z[c];
                   break;
                }
                else
                c++;
            }
            i++; 
        }
    }
}
