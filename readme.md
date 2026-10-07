# MP3 Tag Reader and Editor

A command-line based **MP3 Tag Reader and Editor** developed in C to read and modify metadata stored in MP3 files using ID3 tags.

## Overview

This project allows the user to:

- View MP3 metadata
- Edit individual MP3 metadata fields
- Validate MP3 files using the `ID3` signature
- Read and write binary file data
- Modify MP3 tag information using file handling operations

The project is implemented using separate source and header files for better code organization and modularity.

## Features

### View MP3 Tags

The application can read and display:

- Title
- Artist
- Album
- Year
- Genre / Content Type
- Comment

### Edit MP3 Tags

The application supports editing the following fields:

| Option | ID3 Tag | Information |
|---|---|---|
| `-t` | `TIT2` | Song Title |
| `-a` | `TPE1` | Artist |
| `-A` | `TALB` | Album |
| `-y` | `TYER` | Year |
| `-m` | `COMM` | Comment |
| `-c` | `TCON` | Genre / Content Type |

## Technologies Used

- **Language:** C
- **Compiler:** GCC
- **IDE:** VS Code
- **Version Control:** Git & GitHub

## C Concepts Used

- Structures
- Pointers
- Functions
- Header files
- Modular programming
- File handling
- Binary file operations
- Command-line arguments
- String manipulation
- Endianness
- Input validation
- Temporary file handling

## Project Structure

```text
MP3-Tag-Reader-and-Editor/
│
├── main.c
├── view.c
├── view.h
├── edit.c
├── edit.h
├── types.h
├── print.h
├── sample.mp3
└── README.md
```

### File Description

| File | Purpose |
|---|---|
| `main.c` | Handles command-line arguments and selects the required operation |
| `view.c` | Contains functions for reading and displaying MP3 tags |
| `view.h` | Header file for view-related functions and structures |
| `edit.c` | Contains functions for editing MP3 tags |
| `edit.h` | Header file for edit-related functions and structures |
| `types.h` | Contains common data types and status definitions |
| `print.h` | Contains printing-related definitions |
| `sample.mp3` | Sample MP3 file used for testing |

## Compilation

Compile the project using GCC:

```bash
gcc main.c view.c edit.c
```

This generates the default executable:

```text
a.out
```

## Usage

### View MP3 Metadata

Use the `-v` option:

```bash
./a.out -v sample.mp3
```

This reads and displays the available MP3 metadata.

### Edit MP3 Metadata

The general syntax is:

```bash
./a.out -e <option> "new_value" filename.mp3
```

### Edit Song Title

```bash
./a.out -e -t "New Song Title" sample.mp3
```

Updates the `TIT2` tag.

### Edit Artist

```bash
./a.out -e -a "Artist Name" sample.mp3
```

Updates the `TPE1` tag.

### Edit Album

```bash
./a.out -e -A "Album Name" sample.mp3
```

Updates the `TALB` tag.

### Edit Year

```bash
./a.out -e -y "2026" sample.mp3
```

Updates the `TYER` tag.

### Edit Comment

```bash
./a.out -e -m "My Favourite Song" sample.mp3
```

Updates the `COMM` tag.

### Edit Genre / Content Type

```bash
./a.out -e -c "Rock" sample.mp3
```

Updates the `TCON` tag.

## Help

To display the available commands:

```bash
./a.out --help
```

## How the Project Works

### View Operation

The view operation:

1. Accepts the MP3 filename through command-line arguments.
2. Opens the MP3 file.
3. Checks for the `ID3` signature.
4. Reads the ID3 header.
5. Reads the tag identifiers and their sizes.
6. Performs the required byte-order conversion.
7. Reads the tag data.
8. Displays the metadata.

### Edit Operation

The edit operation:

1. Accepts the MP3 filename, tag option, and new value.
2. Validates the command-line arguments.
3. Checks the MP3 file extension.
4. Opens the original MP3 file in binary mode.
5. Creates a temporary file named `temp.mp3`.
6. Copies the required MP3 data.
7. Identifies the selected ID3 tag.
8. Writes the updated tag information.
9. Copies the remaining MP3 data.
10. Closes the files.
11. Removes the original file.
12. Renames `temp.mp3` to the original filename.

This allows the metadata to be modified while preserving the MP3 audio data.

## ID3 Tags Used

The project works with these ID3 tags:

```text
TIT2 → Title
TPE1 → Artist
TALB → Album
TYER → Year
COMM → Comment
TCON → Genre / Content Type
```

## File Handling

The project uses standard C file-handling functions such as:

```c
fopen()
fread()
fwrite()
fseek()
rewind()
fclose()
remove()
rename()
```

These functions are used to read, modify, and write binary MP3 data.

## Endianness

The project performs byte-order conversion while processing tag size information.

This provides practical experience with:

- Big-endian data
- Byte-level data manipulation
- Binary data representation
- Converting data before reading and writing

Understanding endianness is useful in low-level programming and Embedded C.

## Error Handling

The program performs validation for conditions such as:

- Missing command-line arguments
- Invalid operations
- Invalid MP3 file extension
- Failure to open the file
- Invalid MP3/ID3 signature
- Unsupported tag options

## Learning Outcomes

Through this project, I practiced:

- C file handling
- Binary file operations
- Structures and pointers
- Command-line arguments
- String manipulation
- MP3 metadata processing
- ID3 tag handling
- Endianness and byte-order conversion
- Modular programming
- Header files
- Input validation
- Temporary file handling

## Embedded Systems Relevance

Although this project works with MP3 files rather than a microcontroller, it helped strengthen several concepts relevant to **Embedded C**, including:

- Pointer manipulation
- Structures
- Byte-level data processing
- Binary data handling
- Endianness
- Memory organization
- Modular C programming
- Data validation

These concepts are useful when working with communication protocols, hardware registers, and other low-level data formats.

## Future Improvements

Possible improvements include:

- Support for additional ID3 tags
- Improved input validation
- Support for different ID3 versions
- More robust error handling
- Additional metadata fields
- Improved command-line interface

## Author

**Rishab Palrecha**

Electronics and Communication Engineering Graduate

Interested in **Embedded Systems, Embedded C, IoT, and Electronics Engineering**.