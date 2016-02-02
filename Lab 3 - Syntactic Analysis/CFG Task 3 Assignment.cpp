#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void state_ment();
void assign_state();
void expression();
void relop();
void dprime();

int inp[100];
int cnt=-1;
int t;

int main()
{
    int i=-1;
    char c;
    FILE *fp;
    fp=fopen("input.txt","r");
    while((c=fgetc(fp))!=EOF)
    {
        inp[i++]=c;
    }
    inp[i]=EOF;
    state_ment();
    printf("\n\n");
    //getch();
    //return 0;
}
void state_ment()
{
    t=inp[cnt++];
    if(t=='\n')
        t=inp[cnt++];
    //Decision Statement
    if(t=='i')
    {
        if((t=inp[cnt++])=='f')
        {
            printf("Decision Statement");
            if((t=inp[cnt++])=='(')
            {
                expression();
                if((t=inp[cnt++])==')')
                {
                    state_ment();
                    dprime();
                }
            }
            else
                printf("\nError");
        }
    }
    //looping Statement
    else if(t=='f')
    {
        if((t=inp[cnt++])=='o')
        {
            if((t=inp[cnt++])=='r')
            {
                printf("\n\nLooping Statement");
                if((t=inp[cnt++])=='(')
                {
                    assign_state();
                    if((t=inp[cnt++])==';')
                    {
                        expression();
                        if((t=inp[cnt++])==';')
                        {
                            assign_state();
                            if((t=inp[cnt++])==')')
                            {
                                state_ment();
                            }
                            else
                                printf("\nError");
                        }
                        else
                            printf("\nError");
                    }
                    else
                        printf("\nfError");
                }
                else
                    printf("\nError");
            }
        }
    }
    else if(t=='w')
    {
        if((t=inp[cnt++])=='h')
        {
            if((t=inp[cnt++])=='i')
            {
                if((t=inp[cnt++])=='l')
                {
                    if((t=inp[cnt++])=='e')
                    {
                        printf("\n\nLooping Statement");
                        if((t=inp[cnt++])=='(')
                        {
                            expression();
                            if((t=inp[cnt++])==')')
                            {
                                state_ment();
                            }
                            else
                                printf("\nError");
                        }
                        else
                            printf("\nError");
                    }
                }
            }
        }
    }
    else
    {
        t=inp[cnt--];
        assign_state();
    }
}

void expression()
{
    t=inp[cnt++];
    if((t >=65 && t <=90) || (t >=97 && t <=122) || (t >=48 && t <=57))
    {
        if((t >=65 && t <=90) || (t >=97 && t <=122))
            printf("\nIdentifier\t%c",t);
        else if(t >=48 && t <=57)
            printf("\nConstant\t%c",t);
        relop();
    }
    else
    {
        printf("\nError");
    }
}

void relop()
{
    int t1;
    t=inp[cnt++];
    t1=t;
    if((t=='=')||(t=='!')||(t=='<')||(t=='>')||(t=='+')||(t=='-')||(t=='*')||(t=='/'))
    {
        if(((t=inp[cnt++])=='=')&&((t1=='=')||(t1=='!')||(t1=='<')||(t1=='>')))
        {
            printf("\nOperator\t%c%c",t1,t);
            t=inp[cnt++];
            if((t >=65 && t <=90) || (t >=97 && t <=122) || (t >=48 && t <=57))
            {
                if((t >=65 && t <=90) || (t >=97 && t <=122))
                    printf("\nIdentifier\t%c",t);
                else if(t >=48 && t <=57)
                    printf("\nConstant\t%c",t);
            }
            else
            {
                printf("\nError");
            }
        }
        else if(((t>=65 && t <=90) || (t >=97 && t <=122) || (t >=48 && t <=57))&&((t1=='=')||(t1=='+')||(t1=='-')||(t1=='*')||(t1=='/')))
        {
            printf("\nOperator %c",t1);
            if((t >=65 && t <=90) || (t >=97 && t <=122))
                printf("\nIdentifier\t%c",t);
            else if(t >=48 && t <=57)
                printf("\nConstant\t%c",t);
        }
        else
        {
            printf("\nError");
        }
    }
    else
    {
        t=inp[cnt--];
    }
}

void dprime()
{
    t=inp[cnt++];
    if(t=='e')
    {
        if((t=inp[cnt++])=='l')
        {
            if((t=inp[cnt++])=='s')
            {
                if((t=inp[cnt++])=='e')
                {
                    state_ment();
                }
                else
                    return;
            }
            else
                return;
        }
        else
            return;
    }
    else
        return;
}

void assign_state()
{
    t=inp[cnt++];
    if((t >=65 && t <=90) || (t >=97 && t <=122))
    {
        printf("\nIdentifier\t%c",t);
        if((t=inp[cnt++])=='=')
        {
            printf("\nOperator\t%c",t);
            expression();
        }
        else
            printf("\nError");
    }
    else
        printf("\nError");
}
