//Program to read 5 different hours and print it after that.
//For that, you need to type the hour, minute and second five times.
#include <stdio.h>

struct hours{
    int hour;
    int minutes;
    int seconds;
};

void GetHours(struct hours list[5]);
void PrintHours(struct hours list[5]);

int main(){

    //creating vector
    struct hours listhours[5];

    GetHours(listhours);
    PrintHours(listhours);
     
    return 0;
}

void GetHours(struct hours list[5]){
    int i = 1;

    for (i = 0; i < 5; i++)
    {
        printf("Type the hour of the %d value: \n",i + 1);
        scanf("%d",&list[i].hour);

        printf("Type the minutes of the %d value: \n",i + 1);
        scanf("%d",&list[i].minutes);

        printf("Type the seconds of the %d value: \n",i + 1);
        scanf("%d",&list[i].seconds);       
    }  
}

void PrintHours(struct hours list[5]){
    int i = 1;

    for (i = 0; i < 5; i++)
    {
        printf("%d : %d : %d\n",list[i].hour,list[i].minutes,list[i].seconds);
    }
}