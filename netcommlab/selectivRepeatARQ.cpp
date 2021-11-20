#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int main(){
    int number_of_frames, window_size;
    int number_of_transmissions = 0;
    printf("Enter the number of frames to be transmitted: ");
    scanf("%d", &number_of_frames);
    printf("Enter the window size: ");
    scanf("%d", &window_size);
    int i=1;
    srand(time(NULL));
    while(i<=number_of_frames){
        int x = 0;
        for(int j=i; j<i+window_size && j<=number_of_frames; j++) {
            printf("Sent Frame: %d\n", j);
            number_of_transmissions++;
        }
        for(int j=i; j<i+window_size && j<=number_of_frames; j++) {
            int flag = rand() % 2;
            int flag1 = 1;
            if(!flag) {
                printf("Acknowledgment of frame : %d\n", j);
                x++;
            }
            else {
                while(flag1) {
                    printf("Negative Acknowledgment of frame: %d\n", j);
                    printf("Frame %d retransmitted", j);
                    number_of_transmissions++;
                    flag1 = rand() % 2;
                }
                x++;
            }
        }
        printf("\n");
        i+=x;
    }
    printf("Total number of transmissions: %d", number_of_transmissions);
}