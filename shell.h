#ifndef SHELL_H
#define SHELL_H

#define MAX_FILES 100
#define MAX_NAME  50
#define MAX_DIR   50

// Each file has a name and a directory
typedef struct {
    char name[MAX_NAME];
    char directory[MAX_DIR];
} File;

// Global variables: file array and file count
extern File files[MAX_FILES];
extern int file_count;

// Function declarations — Member 1
void start_shell();
void help();
void parse_command(char *input);

// Function declarations — Member 2
void list();
void create(char *name, char *dir);
void move_file(char *name, char *new_dir);

// Function declarations — Member 3
void rename_file(char *old_name, char *new_name);
void delete_file(char *name);

#endif