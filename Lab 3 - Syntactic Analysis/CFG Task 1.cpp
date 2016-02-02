#include<stdio.h>
#include<string.h>
#include<conio.h>

char string[10];
int i=0;
int length=0;
int count=0;
int flag;

void E();
void s1();
void s2();

void E(){
    return;
}

void s1(){
    if(string[count]=='0'){
        i++;
        count++;
        s1();
    }else if(string[count]=='1'){
        i--;
        count++;
        if(flag>0){
            flag*=-1;
            s2();
        }
    }else if(string[count]=='\n'){
        E();
    }
}

void s2(){
    if(string[count]=='1'){
        i--;
        count++;
        s2();
    }else if(string[count]=='0'){
        i++;
        count++;
        if(flag>0){
            flag*=-1;
            s1();
        }
    }else if(string[count]=='\n'){
        E();
    }
}



int main() {
	printf("Context Free Grammar(CFG):\n");
	printf("\n\nProduction is:\n");
	printf("\n\ts->s1 | s2\n\ts1->0 s1 1|E\n\ts2->1 s2 0|E\n");

	printf("\nEnter string: ");
	gets(string);

	length = strlen(string);

    flag=-1;
	if (string[count] == '0') {
		i++;
		count++;
		flag=1;
		s1();
	}else if(string[count] == '1'){
        i--;
        count++;
        flag=2;
        s2();
	}else if(string[count] == '\n'){
        E();
	}

	if(i==0 && length==count && flag<0)
		printf("\nValid String\n");
	else
		printf("\nInvalid String\n");

    //printf("\n%d\t%d\t%d\n\n",length,i,count);


	getch();
	return 0;
}


