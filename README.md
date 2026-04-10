# OS-Virtual-File-Management-System

A command-line virtual file management system built in C, simulating core operating system file management concepts through an interactive terminal interface.

---

## Project Overview

This program simulates a basic OS file management environment. Users interact with the system by typing commands into a terminal-style interface. All file data is stored in memory arrays — no real disk operations are performed.

---

## Project Structure

```
OS-Virtual-File-Management-System/
├── shell.h          — Data structures and function declarations
├── main.c           — Main loop, command parsing, help command
├── commands_a.c     — list, create, move commands
├── commands_b.c     — rename, delete commands and error handling
└── README.md        — Project documentation
```

---

## Supported Commands

| Command | Syntax | Description |
|---------|--------|-------------|
| list | `list` | Display all files and their directories |
| create | `create <filename> <directory>` | Create a new file |
| delete | `delete <filename>` | Delete a file |
| rename | `rename <old_name> <new_name>` | Rename a file |
| move | `move <filename> <new_directory>` | Move a file to a new directory |
| help | `help` | Show all available commands |
| exit | `exit` | Exit the system |

---

## How to Compile and Run

**Requirements:** GCC compiler (macOS: install via `xcode-select --install`)

**Step 1 — Navigate to the project folder:**
```bash
cd path/to/OS-Virtual-File-Management-System
```

**Step 2 — Compile:**
```bash
gcc main.c commands_a.c commands_b.c -o myos
```

**Step 3 — Run:**
```bash
./myos
```

---

## Example Usage

```
============================================
   Virtual File Management OS v1.0
   Type 'help' to see available commands
============================================

myos> create notes.txt /home
Success: file 'notes.txt' created in '/home'.

myos> create photo.jpg /images
Success: file 'photo.jpg' created in '/images'.

myos> list
ID    Name                 Directory
----------------------------------------------
1     notes.txt            /home
2     photo.jpg            /images

myos> rename notes.txt readme.txt
Success: 'notes.txt' renamed to 'readme.txt'.

myos> move photo.jpg /backup
Success: 'photo.jpg' moved to '/backup'.

myos> delete readme.txt
Success: file 'readme.txt' deleted.

myos> exit
Goodbye!
```

---

## Development Environment

| Tool | Purpose |
|------|---------|
| VS Code | Code editor |
| GCC | C compiler |
| Git + GitHub | Version control |

---

## Course Information

**Course:** CSYE6230 Operating Systems  
**Project:** Final Project — Virtual File Management OS