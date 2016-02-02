#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>

#define DONE 260
#define NUM 257
#define ID 259

void E();
void T();
void F();
void parser();
int lexer();
void match(int);
void parsex();

int i=0,flag=9,lkahd;
char inp[175];
int cnt=-1;

int main(void)
{
    int i=-1;
    char c;
    FILE *fp;
    fp=fopen("ep1.txt","r");
    while((c=fgetc(fp))!=EOF) {
        inp[i++]=c;
    }
    inp[i]=EOF;
    parser();
    getch();
    return 0;
}

int lexer(){
    int t;
    while(1) {
        t=inp[cnt++];
        if(t==' '||t=='\t'||t=='\n');
        else if(t=='+'||t=='-'||t=='*'||t=='/'){
            printf("Arithmetic Operator\t%c\n",t);
            return t;
        }
        else if(isdigit(t)){
            if(isdigit(inp[cnt]))
            {
                printf("\nNumber:\t%c",t);
                while(isdigit(inp[cnt])){
                    printf("%c",inp[cnt]);
                    t=inp[cnt++];
                }
                printf("\n");
            }
            else
            printf("\nNumber:\t%c\n",t);
            return NUM;
        }
        else if(isalpha(t)){
            if(isalnum(inp[cnt]))
            {
                printf("\nIdentifier:\t%c",t);
                while(isalnum(inp[cnt])){
                    printf("%c",inp[cnt]);
                    t=inp[cnt++];
                }
                printf("\n");
            }
            else
            printf("\nIdentifier:\t%c\n",t);
            return ID;
        }
        else if(t==EOF)
        return DONE;
        else
        return t;
    }
}

void parser() {
    lkahd=lexer();
    while(lkahd!=DONE){
        E();
        match(';');
    }
    if(lkahd==DONE)
        parsex();
}

void match(int t){
    if(lkahd==t)
        lkahd=lexer();
    else
        return;
}

void F(){
    switch(lkahd){
        case '(':
            match('(');
            E();
            match(')');
            break;
        case NUM:
            match(NUM);
            break;
            case ID:
            match(ID);
            break;
        case '-':
            match('-');
            F();
            break;
        default:{
            printf("\nSyntax Error !!!!");
            flag=7;
        }
    }
}

void T(){
    int t;
    F();
    while(1){
        switch(lkahd){
            case '*':
                t=lkahd;
                match(lkahd);
                F();
                break;
            case '/':
                t=lkahd;
                match(lkahd);
                F();
                break;
            default:
                return;
        }
    }
}

void E(){
    int t;
    T();
    while(1){
        switch(lkahd){
            case '+':
                t=lkahd;
                match(lkahd);
                T();
                break;
            case '-':
                t=lkahd;
                match(lkahd);
                T();
                break;
            default:
                return;
        }
    }
}

void parsex(){
    if(flag!=7)
        printf("\n\nSuccessful\n");
    else
        printf("\n\nErrors found\n");
}
