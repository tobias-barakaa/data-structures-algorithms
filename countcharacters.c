#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for reading
    FILE *file = fopen(filename, "r");

    // Check if the file exists
    if (file == NULL) {
        printf("File not found or unable to open.\n");
        return 1;
    }

    char line[1000];
    int charCount = 0;
    int lineCount = 0;
    int wordCount = 0;

    // Create an array to store unique words
    char uniqueWords[1000][MAX_WORD_LENGTH];
    int uniqueWordCount = 0;

    // Read the file line by line
    while (fgets(line, sizeof(line), file) != NULL) {
        lineCount++;

        // Count characters
        charCount += strlen(line);

        // Tokenize the line into words
        char *token = strtok(line, " \t\n");

        while (token != NULL) {
            wordCount++;

            // Check if the word is unique
            int isUnique = 1;
            for (int i = 0; i < uniqueWordCount; i++) {
                if (strcmp(uniqueWords[i], token) == 0) {
                    isUnique = 0;
                    break;
                }
            }

            // If the word is unique, add it to the uniqueWords array
            if (isUnique) {
                strcpy(uniqueWords[uniqueWordCount], token);
                uniqueWordCount++;
            }

            // Get the next word
            token = strtok(NULL, " \t\n");
        }
    }

    // Close the file
    fclose(file);

    printf("Character count: %d\n", charCount);
    printf("Line count: %d\n", lineCount);
    printf("Word count: %d\n", wordCount);
    printf("Unique word count: %d\n", uniqueWordCount);

    return 0;
}
