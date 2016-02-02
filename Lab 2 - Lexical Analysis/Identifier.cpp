#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define len 10

main(){

    //freopen("input.txt","r",stdin);

    int i,j,flag=1;
    char str[len],temp[len];
    gets(str);
    if(str[0]=='\0' || (!(str[0]=='_' || isalpha(str[0])))){
        //printf("Invlaid Input.1");
        flag=0;
    }else{
        i=0;
        while(str[i]!='\0'){
            if(!(isalnum(str[i]) || str[i]=='_')){
                //printf("Invalid input.2");
                flag=0;
                break;
            }
            i++;
        }
    }

    if(flag){
        printf("Valid Input.");
    }else{
        printf("Invalid Input");
    }

    //fclose(stdin);
}
