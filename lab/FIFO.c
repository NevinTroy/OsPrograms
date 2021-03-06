#include <stdio.h>

int n, nf;
int in[100];
int p[50];
int hit = 0;
int i, j, k;
int pgfaultcnt = 0;

void initialize(){
    pgfaultcnt = 0;
    for (i = 0; i < nf; i++)
        p[i] = 9999;
}

int isHit(int data){
    hit = 0;
    for (j = 0; j < nf; j++)
    {
        if (p[j] == data)
        {
            hit = 1;
            break;
        }
    }

    return hit;
}

int getHitIndex(int data){
    int hitind;
    for (k = 0; k < nf; k++)
    {
        if (p[k] == data)
        {
            hitind = k;
            break;
        }
    }
    return hitind;
}

void dispPages(){
    for (k = 0; k < nf; k++)
    {
        if (p[k] != 9999)
            printf(" %d", p[k]);
    }
}

void fifo(){
    initialize();
    for (i = 0; i < n; i++)
    {
        printf("\nFor %d :", in[i]);

        if (isHit(in[i]) == 0)
        {

            for (k = 0; k < nf - 1; k++)
                p[k] = p[k + 1];

            p[k] = in[i];
            pgfaultcnt++;
            dispPages();
        }
        else
            printf("No page fault");
    }
    printf("\nTotal no of page faults:%d", pgfaultcnt);
}

int main(int argc,char* argv[]){
    printf("\nEnter length of page reference sequence:");
    scanf("%d", &n);
    printf("\nEnter the page reference sequence:");
    for (i = 0; i < n; i++)
        scanf("%d", &in[i]);
    printf("\nEnter no of frames:");
    scanf("%d", &nf);
    fifo();
}
