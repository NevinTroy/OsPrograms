#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int main(int argc,char* argv[]){
    int p1[2];  //c->p
    int p2[2];  //p->c
    if(pipe(p1)==-1){
        return 1;
    }
    if(pipe(p2)==-1){
        return 1;
    }
    int id=fork();
    if(id==0){
        close(p1[0]);
        close(p2[1]);
        int x;
        read(p2[0],&x,sizeof(x));
        printf("Read %d successfully\n",x);
        x*=4;
        write(p1[1],&x,sizeof(x));
        printf("Wrote %d successfully\n",x);
        close(p1[1]);
        close(p2[0]);

    }
    else{
        close(p1[1]);
        close(p2[0]);
        srand(time(NULL));
        int y=rand()%10;
        write(p2[1],&y,sizeof(y));
        printf("Wrote %d successfully\n",y);
        read(p1[0],&y,sizeof(y));
        printf("Read %d successfully\n",y);
        close(p1[0]);
        close(p2[1]);
    }
    return 0;
}
