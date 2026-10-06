#ifndef PRINT_H
#define PRINT_H

void print_line()
{
    for(int i=0;i<88;i++)
    printf("-");
    printf("\n");
}

void print_space()
{
    for(int i=0;i<27;i++)
        printf(" ");
}

void print_start_format()
{
    print_space();
    printf("<----------Started View---------->\n");

    print_line();

    printf("SI.no\t|\tTAG\t|\tContent\n");
    
    print_line();
}

void print_end_format(){
    print_line();
    print_space();
    printf("<----------End of view---------->\n");
}



#endif 