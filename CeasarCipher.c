#include <stdio.h>



// declare function
char encryption(char x, int key);
int main()  {
    
    // Initialise variables and string
char message[100]= "Encrypt This";
int key=5, i=0;

    /*Prompts user to enter message and key and stores them as string array and integer value k*/
    /*------------- String and key hardcoded for testing, ignore this shit.------------
    printf("Enter message you want encrypted\n");
    scanf("%c", message);
    printf("Enter the encryption key between -25 and 25\n");
    scanf("%d", &key);
    ---------------------------------------------------------------------------------*/
    
    /* Changes message from lower case to uppercase*/
    
    while(message[i] != '\0') {
        if (message[i]>= 'a' && message[i] <= 'z')
        message[i] = message [i] - 32;
        ++i;
    }
    char encrypted = encryption(message[i], key);
    printf("%c", encrypted);
}    

char encryption (char x,int key){
    int i = 0;
    while (i < '\0')
    x = x + key;
        if(x > 'Z')    {
        x = x - 26;
        ++i;
        }
    return x;
    }
