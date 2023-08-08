#include<stdio.h>
int costMatrix[20][20],n;

struct routers{
    int distance[20];
    int adjnode[20];
}node[20];

int readcostMatrix(){

int i,j;
printf("Enter cost matrix:\n");
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        scanf("%d",&costMatrix[i][j]);

        node[i].distance[j]=costMatrix[i][j];
        node[i].adjnode[j]=j;
        }
    }
}

int calcRoutingTable(){
    int i,j,k;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                if(node[i].distance[j]>costMatrix[i][j]+node[k].distance[j])
                {
                    node[i].distance[j]=costMatrix[i][j]+node[k].distance[j];
                    node[i].adjnode[j]=k;
                }                    
            }     
       }
    }
}

int displayRoutes(){
    int i,j;
    
    for(i=0;i<n;i++){
        printf("\nRoutes %d\n",i+1);
        for(j=0;j<n;j++){
            printf("Node %d via %d : Distance %d\n",j+1,node[i].adjnode[j],node[i].distance[j]);
        }
        printf("\n");
    }
}

int main(){
    // int i,j;
    printf("Number of Nodes:");
    scanf("%d",&n);
    readcostMatrix();
    calcRoutingTable();
    displayRoutes();

    return 0;
}