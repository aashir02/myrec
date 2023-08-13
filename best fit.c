#include<stdio.h>
int p,b,i,j;
int blk_size[20],pro_size[20];
void blocksize(){
    printf("Enter the number of blocks ");
    scanf("%d",&b);
    for(i=0;i<b;i++){
        printf("Enter block %d size ",i+1);
        scanf("%d",&blk_size[i]);
    }
}
void processsize(){
    printf("Enter the number of process ");
    scanf("%d",&p);
    for(i=0;i<p;i++){
        printf("Enter process %d size ",i+1);
        scanf("%d",&pro_size[i]);
    }
}
void firstfit(int pro_size[],int blk_size[]){
    int allocation[p];
    for(i=0;i<p;i++)
        allocation[i]=-1;
    for(i=0;i<p;i++){
        int indexplaced=-1;
        for(j=0;j<b;j++){
            if(pro_size[i]<=blk_size[j]){
                if(indexplaced==-1)
                    indexplaced=j;
                else if(blk_size[j]<blk_size[indexplaced])
                    indexplaced=j;
                }
            }
        if(indexplaced!=-1)
            allocation[i]=indexplaced;
            blk_size[indexplaced]-=pro_size[i];
        }
    printf("Process no.\t Process size\t Block no");
    for(i=0;i<p;i++){
        printf("\n%d\t\t",i+1);
        printf("\t\t%d\t\t",pro_size[i]);
        if(allocation[i]!=-1)
            printf("\t\t%d",allocation[i]+1);
        else
            printf("Not allocated");
    }
}

int main(){
    blocksize();
    processsize();
    firstfit(pro_size,blk_size);
    return 0;
}
