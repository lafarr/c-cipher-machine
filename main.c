#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_INPUT 50

// Getting string inside command by itself for processing.
char* getString(char arr[])
{
    char input[MAX_INPUT];
    strcpy(input, arr);
    char* byItself = strtok(input, "(");
    // If string is "encrypt" return.
    if(strcmp(byItself, "encrypt") == 0)
    {
        char* encrypt = "encrypt";
        return encrypt;
    }
    // If string is "decrypt" return.
    else if(strcmp(byItself, "decrypt") == 0)
    {
        char* decrypt = "decrypt";
        return decrypt;
    }
    // If neither of these are the case, return error string.
    return "ERROR";
}
// Encryption
void encrypt(char arr[])
{
    int ascii;
    char input[MAX_INPUT];
    strcpy(input, arr);
    char* token = strtok(input, "(");
    token = strtok(NULL, ")");
    int len = strlen(token);
    int encrypted[len];
    // For each character in the array, encrypt the character...
    for(int x = 0; x < len; x++)
    {
        ascii = (int)token[x];
        // Checking if ascii code is >= 127 to prevent the result of addings 3 being over 127, thus not coming  back to the beginning of the ASCII character set.
        if(ascii >= 125)
        {
            // If it is...... subtract rather than add to get the correct character.
            encrypted[x] = ((int)token[x] - 125);
        }
       else
       {
           encrypted[x] = ((int)token[x]) + 3;
       }
    }
    // Printing out each character in the array
    for(int i = 0; i < len; i++)
    {
        printf("%c", encrypted[i]);
    }
    printf("\n");
}
// Decryption
void decrypt(char arr[])
{
    int ascii;
    char input[MAX_INPUT];
    strcpy(input, arr);
    char* ptr = input;
    ptr = strtok(input, "(");
    ptr = strtok(NULL, ")");
    int decrypted[strlen(ptr)];
    // For each character in the array, decrypt the character
    for(int i = 0; i < strlen(ptr); i++)
    {
        ascii = (int)ptr[i];
        // Checking ASCII code to prevent a bug of a negative ASCII code.
        if(ascii <= 2 && ascii >= 0)
        {
            // Add intead of subtract to get result.
            decrypted[i] = ((int)ptr[i] + 125);
        }
        else
        {
        decrypted[i] = (int)ptr[i] - 3;
        }
    }
    // Printing out each character in the array
    for(int x = 0; x < strlen(ptr); x++)
    {
        printf("%c", decrypted[x]);
    }
    printf("\n");
}
// Input validation
bool validateInput(char arr[])
{
    int x = 0;
    char input[MAX_INPUT];
    strcpy(input, arr);
    char* firstToken = input;
    // Checking number of parenthesis...
    for(int i = 0; i < strlen(firstToken); i++)
    {
        if(firstToken[i] == '(' || firstToken[i] == ')')
        {
            x  = x + 1;
        }
    }
     firstToken = strtok(input, "(");
    // If command contains only two parenthesis and first token is "encrypt"...
    if(strcmp(firstToken, "encrypt") == 0 && x == 2)
    {
       firstToken = strtok(NULL, "");
       for(int z = 0; z < strlen(firstToken); z++)
        {
            // Checking if string contains any forbidden characters...
            if((int)firstToken[z] > 127 || (int)firstToken[z] < 0)
            {
                printf("[ERROR] Invalid characters present.\n");
                return false;
            }
        }
       // If last character in command is parenthesis, return true.
        if(firstToken[strlen(firstToken) - 2] == ')')
        {
            return true;
        }
    }
        // if first token is "decrypt" and command contains only two parenthesis...
    if(strcmp(firstToken, "decrypt") == 0 && x == 2)
    {
        firstToken = strtok(NULL, "");
        for(int z = 0; z < strlen(firstToken); z++)
        {
            // Checking if string contains any forbidden characters...
            if((int)firstToken[z] > 127 || (int)firstToken[z] < 0)
            {
                printf("[ERROR] Invalid characters present.\n");
                return false;
            }
        }
        // If last character in command is a parenthesis, return true.
        if(firstToken[strlen(firstToken) -2] == ')')
        {
            return true;
        }
    }
    // If command is neither of the above, send error.
    printf("[ERROR] Please enter a valid command.\n");
    return false;
}

int main()
{
    char input[MAX_INPUT];
    printf("jlafarr $ ");
    fgets(input, MAX_INPUT, stdin);
            while(strcmp(input, "exit\n") != 0)
            {
                // If input is valid...
                if(validateInput(input))
                {
                    // if command is "encrypt"...
                    if(strcmp(getString(input), "encrypt") == 0)
                    {
                        encrypt(input);
                    }
                    // If command is "decrypt"...
                      if(strcmp(getString(input), "decrypt") == 0)
                    {
                        decrypt(input);
                    }
                }
                printf("jlafarr $ ");
                fgets(input, MAX_INPUT, stdin);
            }
            return 0;
}