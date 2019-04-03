#include <stdio.h>



// declare function
void encryption(char *x, int key);

int main()  {
    
    // Initialise variables and string
char message[100];
int key, i=0;

    /*Prompts user to enter message and key and stores them as string array and integer value k*/
    printf("Enter message you want encrypted\n");
    scanf("%s", message);
    printf("Enter the encryption key between -25 and 25\n");
    scanf("%d", &key);

    
    /* While loop Changes message from lower case to uppercase by testing if ascii value of the 
    letters are between a and z and then taking away 32 to make them a capital letter*/
    
    while(message[i] != '\0') {
        if (message[i]>= 'a' && message[i] <= 'z')
        message[i] = message [i] - 32;
        ++i;
    }
    //calls function to encrypt message and then print the result.
    encryption(message, key);
    printf("%s\n", message);
}    
/*Function definition. This function has a while loop that adds the key to the i'th value to encrypt
the message. It also has if statements that test whether the input message has symbols in it and
does not encrypt them.
*/
void encryption (char *x,int key){
    int i = 0; 
    while (x[i] != '\0')    {
        x[i] = x[i] + key;
        if(x[i] > 'Z')  {
            if(x[i] > 91 + key)  {//symbols above Z will not be encrypted
                x[i] = x[i] - key + 26;
            }
            x[i] = x[i] - 26;
        }


        else if(x[i] < 'A')   {
            if(x[i]  < 65 + key) { //symbols below A will not be encrypted
                x[i] = x[i] - key - 26;
            }
            x[i] = x[i] +26;
        }

        i++;
    }
    }
