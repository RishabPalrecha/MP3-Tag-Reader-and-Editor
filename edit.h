#ifndef EDIT_H
#define EDIT_H

#include "view.h"

/* Edit Function prototype*/

/* Menu */
void menu();

/* Get frame id */
char* get_frame(char ch);

/* Tag Validation */
Status validate_edit_tag(char ch);

/* Read and validate edit args from argv */
Status read_and_validate_edit_args(char *argv[],ViewInfo *viewinfo);

/* Perform the edit */
Status do_edit(ViewInfo *viewinfo);

/* Creating temp.mp3 file */
Status create_file(ViewInfo *viewinfo);

/* Copying the header to temp file */
Status copy_header(ViewInfo *viewinfo);

/* Edit the tag data and size */
Status edit_tag(ViewInfo *viewinfo, char tag_buffer[]);

/* Copy the data */
Status copy_data(ViewInfo *viewinfo, char tag_buffer[]);

/* Reading value in Big endian format */
Status big_endian_to_integer(char buffer[], ViewInfo *viewinfo);

#endif 