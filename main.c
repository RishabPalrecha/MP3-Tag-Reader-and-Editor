#include<stdio.h>
#include "types.h"
#include "view.h"
#include "edit.h"

int main(int argc , char *argv[])
{
    if(argc = 3 && check_operationtype(argv[1][1]) == e_view)
    {
        MP3 vinfo;
        if(read_and_validate_args(argv, &vinfo) == e_failure)
        {
            printf("\t---- Invalid Input ----\n");
            printf("To View Info : \t./a.out -v filename.mp3\n");
            return 0;
        }
        view_operation(&vinfo);
    }
    else if(argc == 5 && check_operationtype(argv[1][1]) == e_edit)
    {
        EDIT_MP3 einfo;
        if(read_and_validate_args(argv, &einfo) == e_failure)
        {
            printf("\t---- Invalid Input ----\n");
            printf("To Edit Info : \t./a.out -e -t/-a/-A/-m/-y/-c filename.mp3\n");
            return 0;
        }
        do_edit(&einfo);
    }
    else if(check_operationtype(argv[1][1]) == e_help)
    {
        printf("1.  -v  ->  To view MP3 file contents\n");
        printf("2.  -e  ->  To edit MP3 file contents\n");
        printf("\tChoose a tag to edit\n");
        printf("\t2.1  -t  ->  To edit Song title\n");
        printf("\t2.2  -a  ->  To edit Artist name\n");
        printf("\t2.3  -A  ->  To edit Album name\n");
        printf("\t2.4  -m  ->  To edit Content type / Genre\n");
        printf("\t2.5  -y  ->  To edit year\n");
        printf("\t2.6  -c  ->  To edit Comment\n");
    }

    else
    {
        printf("\t---- Invalid Input ----\n");
        printf("To View Info : \t./a.out -v filename.mp3\n");
        printf("To Edit Info : \t./a.out -e -t/-a/-A/-m/-y/-c filename.mp3\n");
        

    }
    return 0;


}




OperationType check_operationtype(char opt)
{
    if(opt == 'v')
    {
        return e_view;
    }
    else if(opt == 'e')
    {
        return e_edit;
    }
    else if(opt == 'h')
    {
        return e_help;
    }
    else
    {
        return e_unsupported;
    }
}



