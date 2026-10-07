#include <stdio.h>
#include <string.h>
#include "types.h"
#include "view.h"
#include "edit.h"

int main(int argc,char *argv[])
{
    if(argc == 1)
    {
        printf("\n\t*** Invalid Input ***\n");
        printf("To vinfo : \t./a.out -v filename.mp3\n");
        printf("To Edit : \t./a.out -e -t/-a/-A/-m/-y/-c  'Data to be edited'  filename.mp3\n");
        printf("To help menu : \t./a.out -help\n\n");
        return 0;
    }

   // check argv for (v)
   if(argc == 3 && check_operationtype(argv[1])==e_view)
   {
      V_MP3INFO vinfo;
        if(read_and_validate_args(argv, &vinfo)==e_failure)
        {
            printf("\n\t*** Invalid Input ***\n");
            printf("To vinfo : \t./a.out  -v  filename.mp3\n");
            printf("To help menu : \t./a.out  --help\n\n");
            return 0;
        }
        view_operation(&vinfo);
   }
   // check argv for (e)
   else if(argc == 5 && check_operationtype(argv[1])==e_edit)
   {
          E_MP3INFO einfo;
          if(read_and_validate_edit_args(argv,&einfo)==e_failure)
          {
               printf("\n\t--- Invalid input ---\n");
               printf("To Edit : \t./a.out  -e  -t/-a/-A/-m/-y/-c  'Data to be edited'  filename.mp3\n");
               printf("To help menu : \t./a.out  --help\n\n");
               return 0;    
          }
          do_edit(&einfo);
   }
   // check argv for (h)
   else if(check_operationtype(argv[1])==e_help)
   {
        printf("\n1.  -v  -->   to view mp3 file contents\n");
        printf("2.  -e  -->  to edit mp3 file contents\n");
        printf("\t Tags to be edited\n");
        printf("\t2.1  -t  -->  to edit song title\n");
        printf("\t2.2  -a  -->  to edit artist name\n");
        printf("\t2.3  -A  -->  to edit album name\n");
        printf("\t2.4  -y  -->  to edit year\n");
        printf("\t2.5  -m  -->  to edit Content type / Genre\n");
        printf("\t2.6  -c  -->  to edit Comment\n\n");
   }
   else 
   {
        printf("\n\t*** Invalid Input ***\n");
        printf("To vinfo : \t./a.out  -v  filename.mp3\n");
        printf("To Edit : \t./a.out  -e  -t/-a/-A/-m/-y/-c 'Data to be edited'  filename.mp3\n");
        printf("To help menu : \t./a.out  --help\n\n");
   }
   return 0;
}


// check operation type (v/e/h)
OperationType check_operationtype(char *opt)
{
    if(opt[1] == 'v')
    {
        return e_view;
    }
    else if(strcmp(opt,"--help")==0)
    {
        return e_help;
    }
    else if(opt[1] == 'e')
    {
        return e_edit;
    }
    return e_unsupported;
}
