#include<stdio.h>
#include<string.h>
#include "types.h"
#include "view.h"
#include "print.h"

Status read_and_validate_view_args(char* argv[],ViewInfo *viewinfo){

    /* Validate MP3 file name given or not */
    if(argv[2] == NULL){
        printf("./a.out -v sample_file.mp3\n");
        return e_failure;
    }

    /* Validate MP3 file name */
    char *dot = strchr(argv[2],'.');
    if((dot == NULL) || (strcmp(dot,".mp3") != 0)){
        printf("Error : File must be .mp3 file\n");
        return e_failure;
    }

    viewinfo->mp3_fname = argv[2];      //storing mp3 file name

    viewinfo->fptr_mp3 = fopen(viewinfo->mp3_fname,"r");    //open mp3 file

    if(viewinfo->fptr_mp3 == NULL){
        printf("Error : MP3 file not opened\n");
        return e_failure;
    }


    /* Validate signature */
    char signature [3];
    if(fread(signature,3,1,viewinfo->fptr_mp3) == 0){
        printf("Error : Unable to read ID3 signature\n");
        return e_failure;
    }
    
    if(strncmp(signature,"ID3",3) != 0){
        printf("Error : ID3 signature invalid\n");
        return e_failure;
    }
    
    return e_success;

}

Status do_view(ViewInfo *viewinfo)
{
    print_start_format();

    fseek(viewinfo->fptr_mp3,10,SEEK_SET);      /* Move offset to 10th pos */

    
    for(int i=0;i<6;i++)
    {
        /* Read frame ID */
        if(fread(viewinfo->frame_id,4,1,viewinfo->fptr_mp3) == 0){
            printf("Error : Unable to read Frame ID from MP3 file\n");
            return e_failure;
        }

        viewinfo->frame_id[4] = '\0';

        /* Read frame size */
        unsigned char buffer[4];

        if(fread(buffer,4,1,viewinfo->fptr_mp3) == 0){
            printf("Error : Unable to read size of Frame from MP3 file\n");
            return e_failure;
        }

            /* Change endianess */
        viewinfo->frame_size = 0;

        for(int j=0;j<4;j++){
            viewinfo->frame_size = (viewinfo->frame_size << 8) | buffer[j];
        }

        
        fseek(viewinfo->fptr_mp3,2,SEEK_CUR);       /* Moving offset by 2 pos */

        if(validate(viewinfo->frame_id) == e_success)
        {
            printf("%d\t|\t%s\t|\t",i+1,viewinfo->frame_id);

            /* Printing the meta data */
            char data_buffer[viewinfo->frame_size + 1];

            if(fread(data_buffer,viewinfo->frame_size,1,viewinfo->fptr_mp3) == 0){
                printf("Error : Unable to read Frame data\n");
                return e_failure;
            }

            data_buffer[viewinfo->frame_size] = '\0';

            printf("%s\n",data_buffer+1);
        }
        else
        {
            /* Skip unrecognised frame data */
            fseek(viewinfo->fptr_mp3,viewinfo->frame_size,SEEK_CUR);
        }
    }
    print_end_format();

    return e_success;
}

Status validate(char frameid[]){
    if ((strcmp(frameid,"TPE1") == 0) ||
        (strcmp(frameid,"TIT2") == 0) ||
        (strcmp(frameid,"TALB") == 0) ||
        (strcmp(frameid,"TYER") == 0) ||
        (strcmp(frameid,"TCON") == 0) ||
        (strcmp(frameid,"COMM") == 0))
    {
        return e_success;
    }

    return e_failure;
}