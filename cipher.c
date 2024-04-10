#include <string.h>
#include <stdlib.h>

#define MAX_INPUT 50

/**
 * @brief Compute the cipher character for a given character.
 * @param c
 * @return The cipher character.
 */
signed char get_cipher_letter(signed char c)
{
    if (c >= 125)
        return c - 125;
    return c + 3;
}

/**
 * @brief Encrypts a given string.
 * @param arr The string to encrypt.
 * @return The encrypted string.
 */
const char *encrypt(const char *arr)
{
    char *output = (char *) malloc(strlen(arr) * sizeof(char));
    int i = 0;
    while (arr[i] != '\0') {
        output[i] = get_cipher_letter(arr[i]);
        i++;
    }
    output[i] = '\0';
    return output;
}

// Decryption
const char *decrypt(const char *arr)
{
    char *output = (char *) malloc(strlen(arr) * sizeof(char));
    int i = 0;
    while (arr[i] != '\0') {
        if (arr[i] < 3) {
            output[i] = arr[i] + 125;
        } else {
            output[i] = arr[i] - 3;
        }
        i++;
    }
    output[i] = '\0';
    return output;
}