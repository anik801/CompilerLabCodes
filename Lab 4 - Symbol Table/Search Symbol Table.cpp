#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define size 50

char temp[50];
char inp[100][100];

FILE *fp;


int checkMatch(char str1[],int n1,char str2[],int n2){
    if(n1==n2){
        if(!strcmp(str1,str2)){
            return 1;
        }
    }
    return 0;
}



main(){
    int i=0;
    char c1;

    printf("Enter a string: ");
    gets(temp);
    int len=strlen(temp);


    int line=1,flag=0;

    fp=fopen("symout.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%s",inp[i]);
        int tempLen=strlen(inp[i]);

        if(checkMatch(inp[i],tempLen,temp,len)){
            flag=1;
            break;
        }

        i++;
    }
    if(flag==0){
        printf("Not found.");
    }else{
        printf("Match found.\n\n");
        fscanf(fp,"%s",inp[i+1]);
        fscanf(fp,"%s",inp[i+2]);
        fscanf(fp,"%s",inp[i+3]);
        printf("%s\t%s\t%s\t%s\t%s\n\n",inp[i-1],inp[i],inp[i+1],inp[i+2],inp[i+3]);
    }

}
