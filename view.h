#ifndef MP3_HEADER_H
#define MP3_HEADER_H

#include<stdio.h>
#include "types.h"

typedef struct
{

    char *mp3_fname;
    FILE *fptr_mp3fname;

}MP3;

OperationType check_operationtype(char opt);
Status read_and_validate_args(char *argv[],MP3 *vinfo);
Status open_files(MP3 *vinfo);
void view_operation(MP3 *vinfo);
unsigned int get_size(unsigned char *size_buffer);

#endif





























#endif