#include <stdio.h>
#include <string.h>
#include "shell.h"

// Rename a file
void rename_file(char *old_name, char *new_name) {
    // Check if the new name already exists
    for (int i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, new_name) == 0) {
            printf("Error: file '%s' already exists.\n", new_name);
            return;
        }
    }
    // Find the file and rename it
    for (int i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, old_name) == 0) {
            strcpy(files[i].name, new_name);
            printf("Success: '%s' renamed to '%s'.\n", old_name, new_name);
            return;
        }
    }
    printf("Error: file '%s' not found.\n", old_name);
}

// Delete a file
void delete_file(char *name) {
    for (int i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, name) == 0) {
            // Shift remaining files forward to fill the gap
            for (int j = i; j < file_count - 1; j++) {
                files[j] = files[j + 1];
            }
            file_count--;
            printf("Success: file '%s' deleted.\n", name);
            return;
        }
    }
    printf("Error: file '%s' not found.\n", name);
}

// Clear all files
void clear_files() {
    file_count = 0;
    printf("All files have been cleared.\n");
}