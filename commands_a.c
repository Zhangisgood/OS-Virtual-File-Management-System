#include <stdio.h>
#include <string.h>
#include "shell.h"

// List all files
void list() {
    if (file_count == 0) {
        printf("No files found.\n");
        return;
    }
    printf("\n%-5s %-20s %-20s\n", "ID", "Name", "Directory");
    printf("----------------------------------------------\n");
    for (int i = 0; i < file_count; i++) {
        printf("%-5d %-20s %-20s\n", i + 1, files[i].name, files[i].directory);
    }
    printf("\n");
}

// Create a new file
void create(char *name, char *dir) {
    // Check if the file system is full
    if (file_count >= MAX_FILES) {
        printf("Error: file system is full.\n");
        return;
    }
    // Check if filename already exists
    for (int i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("Error: file '%s' already exists.\n", name);
            return;
        }
    }
    // Add the new file
    strcpy(files[file_count].name, name);
    // Default directory is /root if none is specified
    if (strlen(dir) == 0) {
        strcpy(files[file_count].directory, "/root");
    } else {
        strcpy(files[file_count].directory, dir);
    }
    file_count++;
    printf("Success: file '%s' created in '%s'.\n", name, files[file_count - 1].directory);
}

// Move a file to a new directory
void move_file(char *name, char *new_dir) {
    for (int i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcpy(files[i].directory, new_dir);
            printf("Success: '%s' moved to '%s'.\n", name, new_dir);
            return;
        }
    }
    printf("Error: file '%s' not found.\n", name);
}

// Search files by keyword
void search(char *keyword) {
    int found = 0;
    printf("\n%-5s %-20s %-20s\n", "ID", "Name", "Directory");
    printf("----------------------------------------------\n");
    for (int i = 0; i < file_count; i++) {
        if (strstr(files[i].name, keyword) != NULL) {
            printf("%-5d %-20s %-20s\n", i + 1, files[i].name, files[i].directory);
            found++;
        }
    }
    if (found == 0) {
        printf("No files found matching '%s'.\n", keyword);
    }
    printf("\n");
}