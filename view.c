#include<stdio.h>
#include<string.h>
#include "view.h"
#include "types.h"

Status read_and_validate_args(char *argv[],MP3 *vinfo)
{
    char *dot = strchr(argv[2],'.');
    if(strcmp(dot,".mp3")!=0)
    {
        printf("ERROR : Source file extention must be .mp3\n");
        return e_failure;
    }
    vinfo -> mp3_fname = argv[2];

    // open file
    if(open_files(vinfo) == e_failure)
    {
        printf("ERROR : Unable to access the file\n");
        return e_failure;
    }

    // check signature first 3 byts as (V_MP3INFO)
    char signature[3];
    fread(signature,3,1,vinfo -> fptr_mp3fname);
    signature[3]=0;
    if(strcmp(signature,"ID3")!=0)
    {
        printf("ERROR : Signature of MP3 file does not match\n");
         return e_failure;
    }

    // set offset at 10th position
    fseek(vinfo->fptr_mp3fname,10,SEEK_SET);
    return e_success;
}


Status open_files(MP3 *vinfo)
{
    vinfo -> fptr_mp3fname = fopen(vinfo -> mp3_fname,"rb");
    // check for NULL
    if(vinfo -> fptr_mp3fname == NULL)
    {
        return e_failure;
    }
    return e_success;
}

