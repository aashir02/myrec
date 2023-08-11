#include<stdio.h>
int mutex=1,full=0,empty=2,x=0;
void producer(){
    mutex--;
    full++;
    empty--;
    x++;
    mutex++;
}
void consumer(){
    mutex--;
    empty++;
    full--;
    x--;
    mutex++;
}
void main(){
    int ch=0;
    while(ch!=3){
        printf("\n1.Produce\n2.Consume\n3.Exit\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:if(mutex==1 && empty!=0)
                    producer();
                    else
                    printf("buffer full");
                    break;
            case 2:if(mutex==1 && full!=0)
                    consumer();
                    else
                    printf("buffer empty");
                    break;
            case 3:printf("Exiting...");
        }
    }
}