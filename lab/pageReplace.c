#include <stdio.h>
#include <stdlib.h>
int n, nf;
int in[100];
int p[50];
int hit = 0;
int i, j, k;
int pgfaultcnt = 0;

int randomPage()
{
    int randompage;
    int upper = 9, lower = 0;
    randompage = (rand() % (upper - lower + 1)) + lower;
    return randompage;
}

int randomFrame()
{
    int randomnumber;
    int upper = 7, lower = 1;
    randomnumber = (rand() % (upper - lower + 1)) + lower;
    return randomnumber;
}
void data()
{
    printf("\nEnter the number of no. of pages: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        in[i] = randomPage();
    printf("\nThe random page reference sequence generated: ");
    for (i = 0; i < n; i++)
        printf("%d", in[i]);
    nf = randomFrame();
    printf("\nRandom frame no. : %d", nf);
}

void initialize()
{
    pgfaultcnt = 0;
    for (i = 0; i < nf; i++)
        p[i] = 9999;
}

int isHit(int data)
{
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

int getHitIndex(int data)
{
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

void dispPages()
{
    for (k = 0; k < nf; k++)
    {
        if (p[k] != 9999)
            printf(" %d", p[k]);
    }
}

void dispPgFaultCnt()
{
    printf("\nTotal no of page faults:%d\n", pgfaultcnt);
}

void fifo()
{
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
    dispPgFaultCnt();
}

void optimal()
{
    initialize();
    int near[50];
    for (i = 0; i < n; i++)
    {

        printf("\nFor %d :", in[i]);

        if (isHit(in[i]) == 0)
        {

            for (j = 0; j < nf; j++)
            {
                int pg = p[j];
                int found = 0;
                for (k = i; k < n; k++)
                {
                    if (pg == in[k])
                    {
                        near[j] = k;
                        found = 1;
                        break;
                    }
                    else
                        found = 0;
                }
                if (!found)
                    near[j] = 9999;
            }
            int max = -9999;
            int repindex;
            for (j = 0; j < nf; j++)
            {
                if (near[j] > max)
                {
                    max = near[j];
                    repindex = j;
                }
            }
            p[repindex] = in[i];
            pgfaultcnt++;

            dispPages();
        }
        else
            printf("No page fault");
    }
    dispPgFaultCnt();
}

void lru()
{
    initialize();

    int least[50];
    for (i = 0; i < n; i++)
    {

        printf("\nFor %d :", in[i]);

        if (isHit(in[i]) == 0)
        {

            for (j = 0; j < nf; j++)
            {
                int pg = p[j];
                int found = 0;
                for (k = i - 1; k >= 0; k--)
                {
                    if (pg == in[k])
                    {
                        least[j] = k;
                        found = 1;
                        break;
                    }
                    else
                        found = 0;
                }
                if (!found)
                    least[j] = -9999;
            }
            int min = 9999;
            int repindex;
            for (j = 0; j < nf; j++)
            {
                if (least[j] < min)
                {
                    min = least[j];
                    repindex = j;
                }
            }
            p[repindex] = in[i];
            pgfaultcnt++;

            dispPages();
        }
        else
            printf("No page fault!");
    }
    dispPgFaultCnt();
}

int main()
{
    printf("\nPage Replacement Algorithms");
    data();
    printf("\nFor FIFO algorithm");
    fifo();
    printf("\nFor OPT algorithm");
    optimal();
    printf("\nFor LRU algorithm");
    lru();
}

