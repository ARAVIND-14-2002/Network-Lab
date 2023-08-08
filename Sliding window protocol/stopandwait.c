#include<stdio.h>
#include<stdlib.h>

int ack(){
    int k;
    k=rand();
    if(k%2==0)
    return 1;
    else
    return 0;
}

void main(){
    int n,i,test;
    printf("Enter the no of packets you want to stimulate:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        x:test=ack();
        printf("%d\n",test);
        if(test==1){
            printf("Success ack received for packet -%d- Sending next packet \n",i);
        }
        else{
            printf("Failed ack received for packet -%d- Sending packet again \n",i);
            goto x;
        }
    }
}