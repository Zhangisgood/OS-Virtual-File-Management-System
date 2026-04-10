#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

// Global variable definitions
File files[MAX_FILES];
int file_count = 0;

int main() {
    start_shell();
    return 0;
}

// Display welcome screen and start the main loop
void start_shell() {
    printf("============================================\n");
    printf("   Virtual File Management OS v1.0\n");
    printf("   Type 'help' to see available commands\n");
    printf("============================================\n\n");

    char input[200];

    // Main loop: keep reading user input
    while (1) {
        printf("myos> ");
        fgets(input, sizeof(input), stdin);

        // Remove trailing newline
        input[strcspn(input, "\n")] = 0;

        // Skip empty input
        if (strlen(input) == 0) continue;

        // Exit the shell
        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        // Parse and execute the command
        parse_command(input);
    }
}

// Parse input and call the corresponding function
void parse_command(char *input) {
    char cmd[50], arg1[50], arg2[50];
    arg1[0] = '\0';
    arg2[0] = '\0';

    sscanf(input, "%s %s %s", cmd, arg1, arg2);

    if (strcmp(cmd, "help") == 0) {
        help();
    } else if (strcmp(cmd, "list") == 0) {
        list();
    } else if (strcmp(cmd, "create") == 0) {
        if (strlen(arg1) == 0) {
            printf("Usage: create <filename> <directory>\n");
        } else {
            create(arg1, arg2);
        }
    } else if (strcmp(cmd, "delete") == 0) {
        if (strlen(arg1) == 0) {
            printf("Usage: delete <filename>\n");
        } else {
            delete_file(arg1);
        }
    } else if (strcmp(cmd, "rename") == 0) {
        if (strlen(arg1) == 0 || strlen(arg2) == 0) {
            printf("Usage: rename <old_name> <new_name>\n");
        } else {
            rename_file(arg1, arg2);
        }
    } else if (strcmp(cmd, "move") == 0) {
        if (strlen(arg1) == 0 || strlen(arg2) == 0) {
            printf("Usage: move <filename> <new_directory>\n");
        } else {
            move_file(arg1, arg2);
        }
    } else {
        printf("Unknown command: '%s'. Type 'help' for available commands.\n", cmd);
    }
}

// Print all available commands
void help() {
    printf("\n--- Available Commands ---\n");
    printf("  list                     List all files\n");
    printf("  create <name> <dir>      Create a new file\n");
    printf("  delete <name>            Delete a file\n");
    printf("  rename <old> <new>       Rename a file\n");
    printf("  move   <name> <dir>      Move a file to a new directory\n");
    printf("  help                     Show this help message\n");
    printf("  exit                     Exit the system\n");
    printf("--------------------------\n\n");
}