#include<stdio.h>
int i,blksize[20],b,p,pro_size[20],j;
void blocksize(){
    printf("Enter the number of blocks ");
    scanf("%d",&b);
    for(i=0;i<b;i++){
        printf("Enter the size of block %d ",i);
        scanf("%d",&blksize[i]);
    }
}
void processsize(){
    printf("Enter the number of processes ");
    scanf("%d",&p);
    for(i=0;i<p;i++){
        printf("Enter the size of process %d ",i);
        scanf("%d",&pro_size[i]);
    }
}
void firstfit(int processsize[],int blocksize[]){
    int allocation[p];
    for(i=0;i<p;i++){
        allocation[i]=-1;
    }
    for(i=0;i<p;i++){
        for(j=0;j<b;j++){
            if(pro_size[i]<=blksize[j]){
                allocation[i]=j;
                blksize[j]=blksize[j]-pro_size[i];
                break;
            }
                
        }
    }
     printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < p; i++)
    {
        printf(" %d\t\t\t", i+1);
        printf("%d\t\t\t\t", pro_size[i]);
        if (allocation[i] != -1)
            printf("%i", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}
int main(){
    
    blocksize();
    processsize();
    firstfit(processsize,blocksize);
    return 0;
}