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

    
    /* Changes message from lower case to uppercase*/
    
    while(message[i] != '\0') {
        if (message[i]>= 'a' && message[i] <= 'z')
        message[i] = message [i] - 32;
        ++i;
    }
    //calls function to encrypt message.
    encryption(message, key);
    printf("%s\n", message);
}    
//Function definition
void encryption (char *x,int key){
    int i = 0; 
    while (x[i] != '\0')    {
        x[i] = x[i] + key;
        if(x[i] > 'Z')  {
            if(x[i] > 91 + key)  {//symbols above Z will not change
                x[i] = x[i] - key + 26;
            }
            x[i] = x[i] - 26;
        }


        else if(x[i] < 'A')   {
            if(x[i]  < 65 + key) { //symbols below A will not change
                x[i] = x[i] - key - 26;
            }
            x[i] = x[i] +26;
        }

        i++;
    }
    }
