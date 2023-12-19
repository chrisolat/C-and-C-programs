#include <stdio.h>
#include <string.h>

int main() {
    char input[] = "apple,banana,grape,orange";
    const char *delimiter = ",";  // Delimiter as a string

    // Initialize an array of character pointers to store substrings
    char *tokens[100];  // Adjust the size as needed

    // Tokenize the input string
    char *token = strtok(input, delimiter);
	printf("TOKEN: %s", token);
    int count = 0;

    while (token != NULL) {
        tokens[count++] = token;
        token = strtok(NULL, delimiter);
    }

    // Now, 'tokens' contains the individual substrings
    for (int i = 0; i < count; i++) {
        printf("Token %d: %s\n", i + 1, tokens[i]);
    }

    return 0;
}