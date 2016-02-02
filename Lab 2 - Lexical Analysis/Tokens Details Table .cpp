#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define len 30

void checkAllInformation();

//total 32 keywords
char *keywords[]= {"auto","break","case","char","const","continue","default","do","double","else","enum","extern",
"float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch",
"typedef","union","unsigned","void","volatile","while"};

char word[len];

void checkAllInformation(){

    //Checking keywords array.
    for(int i=0;i<32;i++)
        puts(keywords[i]);
    //Checking ASCII value of double quotation(")
    char c1='"';
    printf("Value of double quotation: %d",c1);

    //checking ASCII value of single quotation(')
    printf("\nValue of single quotation: ");
    char a[]="'";
    for(int i=0;i<1;i++)
        printf("%d ",a[i]);
    printf("\n");

}

void cleanArray(int x, int y){
    for(int i=x;i<y;i++){
        word[i]=' ';
    }
}

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

void removeComments(char str[])
{
    FILE *fp,*fp2;
    int c1,c2,c3,c4,i,j,temp=0;

    //Source
    fp = fopen(str, "r");
    fp2 = fopen("commentLess.cpp", "w");

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
                        putc('\n',fp2);
                        break;
                     }
                 }
             }
             else if(c2 == '*')
             {
                 while((c3 = fgetc(fp)) != EOF)
                 {
                     if(c3=='\n')
                        putc('\n',fp2);
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
                 //if(c1!=' ')
                    putc(c1, fp2);
             }
        }
        else
        {
            //printf("%c",c1);
            //if(c1!=' ')
                putc(c1, fp2);
        }
    }
    fclose(fp);
    fclose(fp2);
}

main(){
    removeComments("temp.cpp");
    FILE *fp;
    fp = fopen("commentLess.cpp", "r");
    int c1,c2,i,j,letterFlag=0,line=1,letterCount=0,doubleInputFlag,spaceFlag=0;
    char temp;

    //checkAllInformation();
    while((c1 = fgetc(fp)) != EOF){

    doubleInputFlag=1;
    while(doubleInputFlag)
    {
        doubleInputFlag=0;

        //Checking for preprocessor directive and constant declaration
        if(c1=='#'){
            //Cleaning word array of garbage.
            cleanArray(0,len);
            letterCount=0;
            letterFlag=0;
            while(c1!='\n'){
                if(c1!='#' && c1!=' ' && letterFlag==0){
                    temp=c1;
                    letterFlag=1;
                }
                word[letterCount]=c1;
                letterCount++;
                c1=fgetc(fp);
            }
            if(temp=='i'){
                printf("Line %d\tPreprocessor directive\t\t",line);
            }else{
                printf("Line %d\tConstant declaration\t\t",line);
            }
            puts(word);
            //line++;
            //doubleInputFlag=1;
        }
        //checking for double quotation constant

        else if(c1==34){
            cleanArray(0,len);
            letterCount=0;
            letterFlag=0;

            word[letterCount]=c1;
            letterCount++;
            c1=fgetc(fp);
            while(c1!=34){
                word[letterCount]=c1;
                letterCount++;
                c1=fgetc(fp);
            }
            word[letterCount]=c1;
            letterCount++;
            printf("Line %d\tString Constant\t\t\t",line);
            puts(word);
            c1=fgetc(fp);
            doubleInputFlag=1;
        }

        //Checking for single quotation constant
        else if(c1==39){
            cleanArray(0,len);
            letterCount=0;
            letterFlag=0;

            word[letterCount]=c1;
            letterCount++;
            c1=fgetc(fp);

            while(c1!=39){
                word[letterCount]=c1;
                letterCount++;
                c1=fgetc(fp);
            }
            word[letterCount]=c1;
            letterCount++;
            printf("Line %d\tCharacter Constant\t\t",line);
            puts(word);
            c1=fgetc(fp);
            doubleInputFlag=1;
        }

        //Checking for identifiers and keywords
        else if(isalpha(c1) || c1=='_'){
            cleanArray(0,len);
            letterCount=0;
            letterFlag=0;
            while(c1!=' '){
                if(!(isalnum(c1) || c1=='_'))
                    break;
                word[letterCount]=c1;
                letterCount++;
                c1=fgetc(fp);
            }
            if(checkKeyword(word,letterCount)){
                printf("Line %d\tKeyword\t\t\t\t",line);
            }else{
                printf("Line %d\tIdentifier\t\t\t",line);
            }
            puts(word);
            doubleInputFlag=1;
        }

        //Checking numeric constant
        else if(isdigit(c1)){
            cleanArray(0,len);
            letterCount=0;
            letterFlag=0;
            while(isdigit(c1)){
                word[letterCount]=c1;
                letterCount++;
                c1=fgetc(fp);
            }
            printf("Line %d\tNumeric Constant\t\t",line);
            puts(word);
            doubleInputFlag=1;
        }

        //Checking for special symbols
        else if(c1==','){
            printf("Line %d\tComma\t\t\t%c\n",line,c1);
        }
        else if(c1==';'){
            printf("Line %d\tSemicolon\t\t\t%c\n",line,c1);
        }
        //Checking for brackets
        else if(c1=='[' || c1==']' || c1=='{' || c1=='}' || c1=='(' || c1==')'){
            printf("Line %d\tBracket\t\t\t\t%c\n",line,c1);
        }
        //Checking for operators
        else if(c1=='<'){
            c2=fgetc(fp);
            if(c2=='=' || c2=='>'){
                printf("Line %d\tOperator\t\t\t%c%c\n",line,c1,c2);
            }else{
                printf("Line %d\tOperator\t\t\t\t%c\n",line,c1);
            }
            c1=c2;
            doubleInputFlag=1;
        }
        else if(c1=='>'){
            c2=fgetc(fp);
            if(c2=='='){
                printf("Line %d\tOperator\t\t\t%c%c\n",line,c1,c2);
            }else{
                printf("Line %d\tOperator\t\t\t\t%c\n",line,c1);
            }
            c1=c2;
            doubleInputFlag=1;
        }
        else if(c1=='='){
            c2=fgetc(fp);
            if(c2=='='){
                printf("Line %d\tOperator\t\t\t%c%c\n",line,c1,c2);
            }else{
                printf("Line %d\tOperator\t\t\t%c\n",line,c1);
            }
            c1=c2;
            doubleInputFlag=1;
        }
        else if(c1=='!'){
            c2=fgetc(fp);
            if(c2=='='){
                printf("Line %d\tOperator\t\t\t%c%c\n",line,c1,c2);
            }else{
                printf("Line %d\tOperator\t\t\t%c%c\n",line,c1);
            }
            c1=c2;
            doubleInputFlag=1;
        }
        else if(c1=='+' || c1=='-'){
            c2=fgetc(fp);
            if((c1=='+' && c2=='+')||(c1=='-' && c2=='-')){
                printf("Line %d\tOperator\t\t\t%c%c\n",line,c1,c2);
            }else{
                printf("Line %d\tOperator\t\t\t%c%c\n",line,c1);
            }
            c1=c2;
            doubleInputFlag=1;
        }
        else if(c1=='*' || c1=='/' || c1=='%'){
            printf("Line %d\tOperator\t\t\t%c\n",line,c1);
        }
        //Checking for separators
        else if(c1==' '){
            //For removing extra spaces
            if(spaceFlag==0)
            {
                printf("Line %d\tSeparator (Space)\n",line);
                spaceFlag=1;
            }
        }

        if(c1!=' ')
            spaceFlag=0;


        if(c1=='\n'){
            printf("Line %d\tSeparator (New Line)\n",line);
            line++;
        }

    }//Inner while loop ends

    }//Outer while loop ends

    fclose(fp);
}
