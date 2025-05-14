#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to concatenate two strings
char* concatenateStrings(const char* str1, const char* str2) {
    // Calculate the length of the concatenated string
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t totalLen = len1 + len2;

    // Allocate memory for the concatenated string
    char* result = (char*)malloc((totalLen + 1) * sizeof(char));

    // Check if memory allocation was successful
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Copy the first string to the result
    strcpy(result, str1);

    // Concatenate the second string to the result
    strcat(result, str2);

    return result;
}

int main() {
    char string1[100], string2[100];

    // User input for the first string
    printf("Enter the first string: ");
    scanf("%s", string1);

    // User input for the second string
    printf("Enter the second string: ");
    scanf("%s", string2);

    // Concatenate the strings
    char* result = concatenateStrings(string1, string2);

    // Print the result
    printf("Concatenated String: %s\n", result);

    // Free the allocated memory
    free(result);

    return 0;
}
