/* In the project i am using the electricity usage of an individual to calculate and store the amount 
he/she has to pay every month. the project also gives warning to the user if he/she exceeds the monthly usage of power limit. lets the user decide to store, delete or display the details. it also gives recommendation based on average unit consumption
 */






#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int mon;
    int uni;
    int yea;
    float charg;
    float ta;
    float tota;
    struct node* link;
}N;

N* ptr=NULL;
N* ptrr=NULL;

void calculate();
N* display();
float cal();
float avg();
void recomend();
N* del();

int main()
{   int choice,choice1;

    printf("Welcome to Electricity Bill calculator\n\n");

    N* head=NULL;

    while(true)
    {
        printf("1:To calculate the monthy bill\n2:To display the monthly bill details:\n3:Check if you are exceeding your average Units consumption\n4:To Delete the billing History\n5:To check Average Units consumption\n6:Exit\nenter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                calculate(&head);
                break;
            case 2:
                if(head==NULL)
                {
                    printf("\nNo History to display\n\n");
                }
                else
                {
                    display(&head);
                }
                break;
            case 3:
                recomend(&head);
                break;
            case 4:
                if(head==NULL)
                {
                    printf("\nNo History to delete\n\n");
                }
                else
                {
                    printf("\n\nDo you really want to delete your history??\n1:Proceed\n2:Don't proceed\nEnter your choice:");
                    scanf("%d",&choice1);
                    printf("\n\n\n");
                    switch(choice1)
                    {
                        case 1:
                            del(&head);
                            break;
                        case 2:
                            break;
                        default:
                            printf("Invalid input");
                            break;
                    }
                }
                break;
            case 5:
                if(head==NULL)
                {
                    printf("\n\nNo history to calculate the average units consumed!!\n\n\n");
                }
                else{
                    printf("\n\nYour average unit consumption is:%.3f\n\n\n",cal(head));
                }
                break;
            case 6:
                printf("Exiting the program!!!\n");
                return 0;
            default:
                printf("\n\nInvalid input\n\n\n");
                break;
        }
    }
}

void calculate(N** head)
{
    int units, result,year,month,choice2;
    float charge, tax, total;

    printf("\n\nEnter the month in number:");
    scanf("%d",&month);
    if(month<=0||month>=13)
    {
        printf("Invalid input!!\n\n");
        exit(1);
    }

    printf("\n\nEnter the year in number:");
    scanf("%d",&year);
    if(year<=1950||month>=2100)
    {
        printf("Invalid input!!\n\n");
        exit(1);
    }
    

    printf("Enter the units consumed:");
    scanf("%d", &units);

    if(units <= 100) {
        charge = units * 0.50;
    } else if(units <= 300) {
        charge = 100 * 0.50 + (units - 100) * 0.75;
    } else if(units <= 500) {
        charge = 100 * 0.50 + 200 * 0.75 + (units - 300) * 1.20;
    } else {
        charge = 100 * 0.50 + 200 * 0.75 + 200 * 1.20 + (units - 500) * 1.50;
    }

    tax = charge * 0.18;
    total = charge + tax;

    printf("\nThe charge for the units consumed is: %.2f", charge);
    printf("\nThe tax amount for the charge is: %.2f\n", tax);
    printf("The total amount payable is: %.2f\n\n\n", total);
    printf("1:To save your Electricity Bill details\n2:To not save your history\nEnter your choice:");
    scanf("%d",&choice2);

    switch (choice2)
    {
    case 1:
        if(*head==NULL)
        {
            *head=(N*)malloc(sizeof(N));
            (*head)->uni=units;
            (*head)->mon=month;
            (*head)->yea=year;
            (*head)->charg=charge;
            (*head)->ta=tax;
            (*head)->tota=total;
            (*head)->link=NULL;
        }
        else if(((*head)->link==NULL))
        {
            ptr=(N*)malloc(sizeof(N));
            ptr->uni=units;
            ptr->mon=month;
            ptr->yea=year;
            ptr->charg=charge;
            ptr->ta=tax;
            ptr->tota=total;
            ptr->link=NULL;
            (*head)->link=ptr;

        }
        else
        {
            ptrr=(N*)malloc(sizeof(N));
            ptrr->uni=units;
            ptrr->mon=month;
            ptrr->yea=year;
            ptrr->charg=charge;
            ptrr->ta=tax;
            ptrr->tota=total;
            ptrr->link=NULL;
            ptr->link=ptrr;
            ptrr=NULL;
            ptr=ptr->link;
        }
        printf("\n\n\n");
        break;
    case 2:
        printf("\n\n\n");
        break;
    default:
        break;
    }
}

N* display(N** head)
{
    // int m=1;
    N* dis=NULL;
    dis=*head;
    while(dis!=NULL)
    {
        printf("\nMonth:%d || Year:%d\n",dis->mon,dis->yea);
        printf("Total units consumed in this month:%d\n",dis->uni);
        printf("Electricity charge of the month:%.2f\n",dis->charg);
        printf("Tax for this month:%.2f\n",dis->ta);
        printf("Total payable month this month:%.2f\n\n\n",dis->tota);
        dis=dis->link;
    }
}

N* del(N** head) {
    while (*head != NULL) {
        N* temp = *head;
        *head = (*head)->link;
        free(temp);
    }
}

void recomend(N** hea)
{
    if(*hea==NULL)
    {
        printf("\n\nNO History to show average Units consumption!!!\n\n\n");
    }
    else
    {
        float a;
        a=cal(*hea);
        if(a>=300)
        {
            printf("\n\nYou are exceeding your average units consumption.....\n\n\nTips to save money on electricity!!!:\n\nBuy Electrical Appliances with a 5-Star BEE Rating Only. ...\nSwitch to LED Lights. ...\nSwitch to Smart Appliances for Remote Control and Optimal Usage. ...\nSwitch to BLDC Fans. ...\nHarness Solar Energy with Solar Panels. ...\nOperate the AC at 24 degrees Celsius.\n\n\n\n"); 
        }
        else
        {
            printf("\n\nHurray!! you still didnt exceeding your average units comsumptions but still here are some recommendations for you!!!!\n\nTips to save money on electricity!!!:\n\nBuy Electrical Appliances with a 5-Star BEE Rating Only. ...\nSwitch to LED Lights. ...\nSwitch to Smart Appliances for Remote Control and Optimal Usage. ...\nSwitch to BLDC Fans. ...\nHarness Solar Energy with Solar Panels. ...\nOperate the AC at 24 degrees Celsius.\n\n\n\n");
        }
    }
}

float cal(N* head)
{
    float c=0,t=0;
    N* cal=NULL;
    cal=head;
    while(cal!=NULL)
    {
        t=t+cal->uni;
        c++;
        cal=cal->link;
    }
    return t/c;
}
