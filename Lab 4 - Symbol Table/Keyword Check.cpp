#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define size 50

char temp[50];


//total 32 keywords
char *keywords[]= {"auto","break","case","char","const","continue","default","do","double","else","enum","extern",
"float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch",
"typedef","union","unsigned","void","volatile","while"};

int checkKeyword(char str[],int n){
    int i,j,flag;
    for(i=0;i<32;i++){
        flag=1;
        for(j=0;j<n;j++){
            if(str[j]!=keywords[i][j] || strlen(keywords[i])!=n){
                flag=0;
                break;
            }
        }
        if(flag==1){
            return flag;
        }
    }
    return flag;
}


main(){
    int i=0;

    printf("Enter a string: ");
    gets(temp);
    int len=strlen(temp);

    if(checkKeyword(temp,len)){
        printf("It is a keyword.");
    }else{
        printf("It is not a keyword.");
    }


}
