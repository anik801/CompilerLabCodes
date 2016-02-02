#include<stdio.h>
main(){

    FILE *fp;
    fp = fopen("temp.cpp", "r");

    int c1,i,j,line=1;

    while((c1 = fgetc(fp)) != EOF){
        if(c1=='\n'){
            line++;
        }else if(c1=='<'){
            c1=fgetc(fp);
            if(c1=='='){
                printf("%d\tLE\n",line);
            }else if(c1=='>'){
                printf("%d\tNE\n",line);
            }else{
                printf("%d\tLT\n",line);
            }
        }else if(c1=='<'){
            c1=fgetc(fp);
            if(c1=='='){
                printf("%d\tGE\n",line);
            }else{
                printf("%d\tGT\n",line);
            }
        }else if(c1=='='){
            printf("%d\tEQ\n",line);
        }
    }


    fclose(fp);
}
