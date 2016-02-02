#include <stdio.h>

void readOutput()
{
    FILE *fp;
    int c;
    fp = fopen("output.c", "r");

    while((c = fgetc(fp)) != EOF)
    {
        printf("%c",c);
    }
    fclose(fp);
}

main()
{
    FILE *fp,*fp2;
    int c1,c2,c3,c4,i,j,temp=0;

    //Source
    fp = fopen("temp.c", "r");
    fp2 = fopen("output.c", "w");

    //Input
    while((c1 = fgetc(fp)) != EOF)
    {
        if(c1 == '/')
        {
             c2=fgetc(fp);
             if(c2 == '/')
             {
                 while((c2 = fgetc(fp)) != EOF)
                 {
                     if(c2=='\n')
                     {
                        break;
                     }
                 }
             }
             else if(c2 == '*')
             {
                 while((c3 = fgetc(fp)) != EOF)
                 {
                     if(c3=='*')
                     {
                         c3=fgetc(fp);
                         if(c3=='/')
                            break;
                     }
                 }
             }
             else
             {
                 //printf("%c",c1);
                 if(c1!=' ')
                    putc(c1, fp2);
             }

        }
        else
        {
            //printf("%c",c1);
            if(c1!=' ')
                putc(c1, fp2);
        }

    }
    fclose(fp);
    fclose(fp2);

    readOutput();
}
