#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
    char sender[50],reciever[50];
    int i, winsize;
    printf("Enter the window size: ");
    scanf("%d",&winsize);
    printf("\nSender window is expanded to store msg\n");
    printf("Enter the Data to be send: ");
    fflush(stdin);
    scanf("%d",sender);
    for (i = 0; i < winsize; i++)
    reciever[i] = sender[i];
    reciever[i] = NULL;
    printf("\nWindow size of reciever is expanded \n");
    printf("\n Acknowledgement from reciever\n");
    for ( i = 0; i < winsize; i++)
    printf("\nack :%d",i);
    printf("\nMessage received by reciever is :%s\n ",reciever);
    printf("\nWindow size of reciever shrinked \n")
}