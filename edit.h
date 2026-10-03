#ifndef EDIT_HEADER_H
#define EDIT_HEADER_H
#include<stdio.h>
#include "types.h"

typedef struct 
{
    char *mp3_fname;
    FILE *fptr_mp3;

    char *tag_to_edit;
    char *new_data;

    char *temp_mp3_fname;
    FILE *fptr_temp_mp3fname;
}EDIT_MP3;

OperationType check_operationtype(char opt);
Status read_and_validate_edit_args(char *argv[],EDIT_MP3 *einfo);
Status get_tag_to_edit(char e_tag,EDIT_MP3 *einfo);
Status open_edit_files(EDIT_MP3 *einfo);
void do_edit(EDIT_MP3 *einfo);
void convet_little_to_big(int size, unsigned char *new_size);
unsigned int get_e_size(unsigned char *size_buffer);


#endif