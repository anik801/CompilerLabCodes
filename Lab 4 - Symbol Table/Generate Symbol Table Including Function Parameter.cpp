#include "stdio.h"
#include "string.h"
#define size 20
FILE *fp,*fp1;
char inp[50][20];
char temp[20];

char *keywords[]= {"const","int","float","char","double"};
int keywordCount=5;
struct node{
    char what[size];
    char name[size];
    char type[size];
    char isStatic[size];
    char scope[size];

};
node nodes[size],tempNode;
int nodeIndex=0;
//char current[size];

int matchKeywords(char x[]){
    for(int i=0;i<keywordCount;i++){
        if(strcmp(x,keywords[i])==0){
            //strcpy(current,keywords[i]);
            return 1;
        }
    }
    return 0;
}

void printNodes(){
    for(int i=0;i<nodeIndex;i++){
        printf("%s\t%s\t%s\t%s\t%s\n",nodes[i].what,nodes[i].name,nodes[i].type,nodes[i].isStatic,nodes[i].scope);
        fprintf(fp1,"%s\t%s\t%s\t%s\t%s\n",nodes[i].what,nodes[i].name,nodes[i].type,nodes[i].isStatic,nodes[i].scope);
    }
}
void cleanifyTemp(){
    for(int i=0;i<size;i++){
        if(temp[i]==';')
            temp[i]='\0';
    }
}
int checkDuplicate(){
    for(int i=0;i<nodeIndex;i++){
        if(nodes[i].name==tempNode.name && nodes[i].scope==tempNode.scope)
            return 1;
    }
    return 0;
}
main(){
    fp=fopen("input.c","r");
    fp1=fopen("output.txt","w");
    char thisScope[]="Global";
    int len;
    int i=1;
    while(!feof(fp))
    {
        fscanf(fp,"%s",temp);
      //  printf("%d\t%s\n",i++,temp);

        if(strcmp(temp,"main")==0)
        {
            strcmp(thisScope,"Local");
        }
        if(matchKeywords(temp))
        {
            //puts(temp);

            if(strcmp(temp,"const")==0){
                strcpy(tempNode.what,"Constant");

                fscanf(fp,"%s",temp);
                strcpy(tempNode.type,temp);

                fscanf(fp,"%s",temp);
                cleanifyTemp();
                strcpy(tempNode.name,temp);

                if(temp[0]=='*'){
                    strcpy(tempNode.isStatic,"Dynamic");
                }else{
                    strcpy(tempNode.isStatic,"Static");
                }

                strcpy(tempNode.scope,thisScope);

            }else{
                strcpy(tempNode.what,"Identifier ");
                strcpy(tempNode.type,temp);

                fscanf(fp,"%s",temp);
                cleanifyTemp();

                strcpy(tempNode.name,temp);

                if(temp[0]=='*'){
                    strcpy(tempNode.isStatic,"Dynamic");
                }else{
                    strcpy(tempNode.isStatic,"Static");
                }

                strcpy(tempNode.scope,thisScope);
            }
            //fscanf();
            //printf("%c",temp[len-1]);

            //printf("%s\t%s\t%s\t%s\t%s\n",nodes[nodeIndex].what,nodes[nodeIndex].name,nodes[nodeIndex].type,nodes[nodeIndex].isStatic,nodes[nodeIndex].scope);
            if(checkDuplicate()){
                continue;
            }else{
                strcpy(nodes[nodeIndex].name,tempNode.name);
                strcpy(nodes[nodeIndex].type,tempNode.type);
                strcpy(nodes[nodeIndex].what,tempNode.what);
                strcpy(nodes[nodeIndex].isStatic,tempNode.isStatic);
                strcpy(nodes[nodeIndex].scope,tempNode.scope);
                nodeIndex++;
            }

        }



    }
    printNodes();

    fclose(fp);
    fclose(fp1);
}
