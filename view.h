#ifndef VIEW_H
#define VIEW_H

#include<stdio.h>
#include "types.h"

#define MAX_FRAME_ID_SIZE 5

typedef struct _ViewInfo
{
    /* MP3 audio file info */
    char *mp3_fname;
    FILE *fptr_mp3;

    /* Frame info */
    char frame_id[MAX_FRAME_ID_SIZE];
    uint frame_size;

    /* Edit info */
    char *edit_frame;
    char *edit_data;
    char *temp_mp3_fname;
    FILE *fptr_temp_mp3;
    uint new_frame_size;



} ViewInfo;


/* View Function prototype */

/* Check operation type */
OperationType checkoperation_type(char ch);

/* Read and validate view args from argv */
Status read_and_validate_view_args(char *argv[],ViewInfo *viewinfo);

/* Perform the view */
Status do_view(ViewInfo *viewinfo);

/* Tag Validation */
Status validate(char frameid[]);


#endif