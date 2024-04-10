#ifndef C_CIPHER_MACHINE_UTIL_H
#define C_CIPHER_MACHINE_UTIL_H

#define MAX_INPUT 50

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "cmdline.h"
#include "cipher.h"

/**
 * @brief Get the input from the user
 * @return The input from the user
 */
char *get_input()
{
    char *input = (char *) malloc(MAX_INPUT * sizeof(char));
    fgets(input, MAX_INPUT, stdin);
    return input;
}

/**
 * @brief Check if the input is valid
 * @param input The input to check
 * @return 1 if the input is valid, 0 otherwise
 */
int is_valid_input(const char *input)
{
    char input_copy[MAX_INPUT];
    strcpy(input_copy, input);

    const char *token = strtok(input_copy, "(");
    return (strcmp(token, "encrypt") == 0 || strcmp(token, "decrypt") == 0) && input[strlen(input) - 2] == ')';
}

// Get the command from the input
char *get_command(const char *input)
{
    char input_copy[MAX_INPUT];
    strcpy(input_copy, input);
    char *token = strtok(input_copy, "(");
    return token;
}

// ask the user for input, get the string, get the command, then call the appropriate function
void start()
{
    char *input = get_input();
    while (strcmp(input, "exit\n") != 0) {
        if (is_valid_input(input)) {
            const char *command = get_command(input);
            if (strcmp(command, "encrypt") == 0) {
                strtok(input, "(");
                const char *value_to_encrypt = strtok(NULL, ")");
                const char *res = encrypt(value_to_encrypt);
                printf("%s\n", res);
                free(res);
            }
            else if (strcmp(command, "decrypt") == 0) {
                strtok(input, "(");
                const char *value_to_decrypt = strtok(NULL, ")");
                const char *res = decrypt(value_to_decrypt);
                printf("%s\n", res);
                free(res);
            }
        }
        free(input);
        input = get_input();
    }
    free(input);
}

#endif