#include<stdio.h>
#include<conio.h>
#include<string.h>

int i=0,j=0,tmpch=90;
char str[100],left[15],right[15];
char inp[100],temp[100];
int count=0;
char countChar='A';

void findOperator();
void explore();
void fleft(int);
void fright(int);
void checkParenthesis();
void clearData();

struct exp{
	int pos;
	char op;
}k[15];

int main(){

	printf("\t\tINTERMEDIATE CODE GENERATION\n\n");
	printf("Enter the Expression :");

	freopen("input.txt","r",stdin);
	scanf("%s",inp);


	clearData();
	printf("\n%s\n",inp);
	//printf("\nThe intermediate code:\tExpression\n");
	printf("\nOUTPUT\n");
    checkParenthesis();

	clearData();
	strcpy(str,inp);
    printf("\n%s\n",str);

	findOperator();
	explore();

	return 0;
	fclose(stdin);
}
void clearData(){
    for(int i=0;i<100;i++){
        str[i]='\0';
        temp[i]='\0';
    }
    j=0; //Global variable for findOperator and explore function.
}
int createTemp(int x){
    int j=0;
    for(int i=x-1;i>=0;i--){
        if(inp[i]=='('){
            break;
        }
        str[j]=inp[i];
        j++;
    }
    sprintf(str, "%s", strrev(str));
    sprintf(temp, "%c=%s",countChar,str);
    strcpy(str,temp);
    puts(str);
    //printf("\n%s\t%d\t%d\n",str,x,j);

    int i=x-j-1;
    inp[i]=countChar;
    i++;
    countChar++;

    int k=x+1;
    for(;i<strlen(inp);i++){
        inp[i]=inp[k];
        k++;
    }
    for(;i<100;i++){
        inp[i]='\0';
    }


    findOperator();
	explore();

    //puts(inp);
    //printf("\n\n%s\n\n",inp);
    printf("\n\n");
    return j;
}
void checkParenthesis(){
    int i=0,j=0,len=strlen(inp);
    int flag=0;
    while(i<len){
        if(inp[i]==')'){
            clearData();
            i=createTemp(i);
        }
        i++;
    }
}

void findOperator(){

	for(i=0;str[i]!='\0';i++)
		if(str[i]=='='){
			k[j].pos=i;
			k[j].op='=';
			j++;
			break;
		}
    for(i=0;str[i]!='\0';i++)
		if(str[i]=='^'){
			k[j].pos=i;
			k[j].op='^';
			j++;
		}
	for(i=0;str[i]!='\0';i++)
		if(str[i]=='/'){
			k[j].pos=i;
			k[j].op='/';
			j++;
		}

	for(i=0;str[i]!='\0';i++)
		if(str[i]=='*'){
			k[j].pos=i;
			k[j].op='*';
			j++;
		}

	for(i=0;str[i]!='\0';i++)
		if(str[i]=='+'){
			k[j].pos=i;
			k[j].op='+';
			j++;
		}

	for(i=0;str[i]!='\0';i++)
		if(str[i]=='-'){
			k[j].pos=i;
			k[j].op='-';
			j++;
		}
}


void explore(){

	i=1;
	while(k[i].op!='\0'){

		fleft(k[i].pos);
		fright(k[i].pos);
		str[k[i].pos]=tmpch--;

		printf("\t%c = %s%c%s\t\t",str[k[i].pos],left,k[i].op,right);

	for(j=0;j <strlen(str);j++){
		if(str[j]!='$')
			printf("%c",str[j]);
    }
	printf("\n");
	i++;
	}

	fright(-1);
	printf("\t%s = %c",right,str[k[--i].pos]);

}

void fleft(int x){

	int w=0,flag=0;
	x--;
	while(x!= -1 && str[x]!= '+' && str[x]!='*' && str[x]!='=' && str[x]!='\0' && str[x]!='-' && str[x]!='/' && str[x]!='^'){
		if(str[x]!='$' && flag==0){
			left[w]=str[x];
			w++;
			left[w]='\0';
			str[x]='$';
			flag=1;
		}
	x--;
	}
}

void fright(int x){

	int w=0,flag=0;
	x++;
	while(x!= -1 && str[x]!= '+' && str[x]!='*' && str[x]!='\0' && str[x]!='=' && str[x]!='-' && str[x]!='/' && str[x]!='^'){
		if(str[x]!='$' && flag==0){
			right[w]=str[x];
			w++;
			right[w]='\0';
			str[x]='$';
			flag=1;
		}
	x++;
	}
}
