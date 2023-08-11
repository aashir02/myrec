#include<stdio.h>
void main(){
    int n,i,tot_wait=0,tot_turn=0;
    int pro_arr[20],burr_arr[20],wait_time[20],turn_time[20];
    printf("Enter number of processes");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter process name");
        scanf("%d",&pro_arr[i]);
        
        printf("Enter burst time");
        scanf("%d",&burr_arr[i]);
    }
    printf("\nProcess");
    for(i=0;i<n;i++)
        printf("P%d",pro_arr[i]);
    printf("\nBurst time");
    for(i=0;i<n;i++)
        printf("%d",burr_arr[i]);
    
    wait_time[0]=0;
    for(i=1;i<n;i++){
        wait_time[i]=wait_time[i-1]+burr_arr[i-1];
        tot_wait+=wait_time[i];
    }
    turn_time[0]=burr_arr[0];
    tot_turn=burr_arr[0];
    for(i=1;i<n;i++){
        turn_time[i]=turn_time[i-1]+burr_arr[i];
        tot_turn+=turn_time[i];
    }
    printf("\nWaiting times");
    for(i=0;i<n;i++)
        printf("%d",wait_time[i]);
    printf("Turn around time");
    for(i=0;i<n;i++)
        printf("%d",turn_time[i]);
    printf("\n");
    printf("Total waiting time = %d",tot_wait);
    printf("Average waiting time = %d",(tot_wait)/n);
    printf("total turn around time = %d",tot_turn);
    printf("Average turn around time = %d",(tot_turn)/n);
    
}
