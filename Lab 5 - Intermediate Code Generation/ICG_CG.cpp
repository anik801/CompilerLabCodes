#include<stdio.h>
#include<conio.h>
#include<string.h>

int i=0,j=0,tmpch=90;
char str[100],left[15],right[15];
FILE *fp2;

void findOperator();
void explore();
void fleft(int);
void fright(int);
void readOutput();
void generateMachineCode();

struct exp{
	int pos;
	char op;
}k[15];

int main(){

    fp2 = fopen("intermidiate.txt", "w");

	//printf("\t\tINTERMEDIATE CODE GENERATION\n\n");
	//printf("Enter the Expression :");

	//scanf("%s",str);
	freopen("input.c","r",stdin);
	scanf("%s",str);

	//printf("The intermediate code:\tExpression\n");

	findOperator();

	explore();

    fclose(stdin);
	fclose(fp2);


    generateMachineCode();
    readOutput();



	return 0;
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

		fprintf(fp2,"%c=%s%c%s",str[k[i].pos],left,k[i].op,right);

	for(j=0;j <strlen(str);j++){
		if(str[j]!='$');
			//printf("%c",str[j]);
    }
	fprintf(fp2,"\n");
	i++;
	}

	fright(-1);
	fprintf(fp2,"%s=%c",right,str[k[--i].pos]);
	//getch();

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

void readOutput()
{
    FILE *fp;
    int c;
    fp = fopen("output.asm", "r");

    while((c = fgetc(fp)) != EOF)
    {
        printf("%c",c);
    }
    fclose(fp);
}

void generateMachineCode(){

	int i=2,j=0;
	char ip[100];
	char kk[]="intermidiate.txt";
	FILE *fp,*fp3;

	fp=fopen(kk,"r");
	fp3=fopen("output.asm","w");
	/*
	printf("\nThe Contents of the file %s \n\n",kk);
	if(fp==NULL){
		printf("\nError in Opening the file");
		getch();
	}

	while(!feof(fp)){
		fscanf(fp,"%s\n",ip);
		printf("\t\t%s\n",ip);
	}

	//rewind(fp); //move file pointer to the beginning of the file.

	printf("\n------------------------------\n");
	printf("\tStatement \t Target Code\n");
	printf("\n------------------------------\n");
    */
	while(!feof(fp)){

		fscanf(fp,"%s",ip);
		//printf("\t%s",ip);
		fprintf(fp3,"MOV R%d,%c\n",j,ip[i]);

        if(ip[i+1]=='*')
            fprintf(fp3,"MUL ");
        else if(ip[i+1]=='/')
            fprintf(fp3,"DIV ");
		else if(ip[i+1]=='+')
			fprintf(fp3,"ADD ");
	  	else
	    	fprintf(fp3,"SUB ");


			fprintf(fp3,"R%d,%c\n\n",j,ip[i+2]);

			//printf("\t\t\tThe Result of %c is stored in R%d\n\n",ip[i-2],j);

		j++;
	}

	//printf("\n-------------------------------\n");

	fclose(fp);
	fclose(fp3);
}
