#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int code[64];

int hamming(int pos, int code_len){
    int count = 0, i, j;
    i = pos - 1;
    while (i < code_len){
        for (j = i; j < i + pos; j++){
            if (code[j] == 1)
                count++;
        }
        i = i + 2 * pos;
    }
    if (count % 2 == 0)
        return 1;
    else
        return 0;
}

void sender(int data[], int m){
    int r, code_len, i, j, k, pos, parity_bit;
    r = 0;
    while (m >= (int)pow(2, r) - (r + 1)){
        r = r + 1;
    }
    code_len = r + m;
    printf("\nCODE LENGTH: %d",code_len);
    j = k = 0;
    for (i = 0; i < code_len; i++){
        if (i == ((int)pow(2, k) - 1)){
            code[i] = 0;
            k++;
        }
        else{
            code[i] = data[j];
            j++;
        }
    }
    printf("\nNo of parity bits: %d", r);
    for (i = 0; i < r; i++){
        pos = (int)pow(2, i);
        parity_bit = hamming(pos, code_len);
        code[pos - 1] = parity_bit;
    }
    printf("\nThe generated Code Word is: ");
    for (i = code_len-1 ; i >= 0; i--){
        printf("%d ", code[i]);
    }
}

void receiver(int m){
    int r, code_len,pos,i,flag=0;
    r = 0;
    while (m >= (int)pow(2, r) - (r + 1)){
        r = r + 1;
    }
    code_len = r + m;
    int syndrome[r];
    for (i = 0; i < r; i++){
        pos = (int)pow(2, i);
        syndrome[i] = hamming(pos, code_len);
        if(syndrome[i]==1)
            flag=1;
        printf("\nSyndrome Bit, S%d is %d ",i,syndrome[i]);
    }
    if(flag == 0)
        printf("\nNo error in transmission of Codeword.");
    else{
        printf("\nThere is error in transmission of Codeword.");
    }    
}

int main(int argc,char* argv[]){
    int i, m, data[50];
    int opt;
    int c;
    printf("\nEnter the length of data word: ");
    scanf("%d", &m);
    printf("Enter the data word: ");
    for (i = m-1; i >= 0; i--)
        scanf("%d", &data[i]);
    while(1){
        printf("\n\nMENU\n");
        printf("1. Sender Side\n");
        printf("2. Reciever Side\n");
        printf("Enter your choice: ");
        scanf("%d",&opt);
        switch(opt){
            case 1: printf("\n   SENDERS SIDE  ");
                    sender(data, m);
                    break;
            case 2: printf("\n   RECEIVERS SIDE  ");
                    receiver(m);
                    break;
            default: printf("Error: Wrong option\n");
        }
        printf("\n Click 1 to continue and 0 to exit\n");
        scanf("%d",&c);
        if(c=='0'){
            return 1;
        }
    }
    return 0; 
}