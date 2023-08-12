#include<stdio.h>
void main(){
    int pno,rno,i,j,k,count=0,check=0;
    int alloc[10][10],max[10][10],avail[10],need[10][10],comp[10];
    
    printf("Enter the number of proceses ");
    scanf("%d",&pno);
    printf("Enter the number of resources");
    scanf("%d",&rno);
    
    printf("Enter allocation matrix \n");
    for(i=0;i<pno;i++){
        for(j=0;j<rno;j++){
            printf("Enter value %d%d",i,j);
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter max matrix \n");
    for(i=0;i<pno;i++){
        for(j=0;j<rno;j++){
            printf("Enter value %d%d",i,j);
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter Avail matrix \n");
    for(i=0;i<rno;i++){
        printf("Enter value %d",i+1);
        scanf("%d",&avail[i]);
    }
    for(i=0;i<pno;i++){
        for(j=0;j<rno;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printf("\nallocation matrix\n");
    for(i=0;i<pno;i++){
        for(j=0;j<rno;j++){
            printf(" %d ",alloc[i][j]);
        }
        printf("\n");
    }
    printf("\nmax matrix\n");
    for(i=0;i<pno;i++){
        for(j=0;j<rno;j++){
            printf(" %d ",max[i][j]);
        }
        printf("\n");
    }
     printf("\nneed matrix\n");
    for(i=0;i<pno;i++){
        for(j=0;j<rno;j++){
            printf(" %d ",need[i][j]);
        }
        printf("\n");
    }
    printf("\navailable\n");
    for(i=0;i<rno;i++)
        printf("%d",avail[i]);
    printf("\n");
    
    while(count<pno){
        for(i=0;i<pno;i++){
            int flag=0;
           for(j=0;j<rno;j++){
               if(need[i][j]>avail[i][j])
                    flag=1;
           } 
           if(flag==1 && comp[i]!=1){
               comp[i]=1;
               for(k=0;k<rno;k++){
                   avail[i][k]+=alloc[i][k];
                   printf("%d",&avail[i][k]);
               }
               printf("\n");
           }
        }
        count++;
    }
    for(i=0;i<rno;i++){
        if(comp[i]!=1)
            check=1;
    }
    if(check==0)
        printf("system is not safe\n");
    else
        printf("Systtem is safe");
}
