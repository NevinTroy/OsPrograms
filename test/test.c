#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[]){
    FILE *fp=fopen("test.txt","r+");
    fprintf(fp,"Omae wa mo shindeiru\n");
    char ch;
    while(fgetc(fp)!=EOF){
        printf("%c",fgetc(fp));
    }
    fclose(fp);
    
    return 0;
}