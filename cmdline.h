#ifndef UTIL_H
#define UTIL_H

/**
 * @brief Get the input from the user
 */
char *get_input();

/**
 * @brief Check if the input is valid
 * @param input The input to check
 * @return 1 if the input is valid, 0 otherwise
 */
int is_valid_input(const char *input);

void start();

#endif