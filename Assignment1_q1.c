#include<stdio.h>

struct Date {
    int day;
    int month;
    int year;
};
void initDate(struct Date* ptrDate)
{
    ptrDate->day = 1;
    ptrDate->month = 1;
    ptrDate->year = 2000;
}

void printDateOnConsole(struct Date* ptrDate)
{
    printf("Date: %d/%d/%d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}
void acceptDateFromConsole(struct Date* ptrDate)
{
    printf("Enter Day : ");
    scanf("%d",&ptrDate->day);
    printf("Enter month : ");
    scanf("%d",&ptrDate->month);
    printf("Enter year : ");
    scanf("%d",&ptrDate->year);
}

int menulist(){
    int choice;
    printf("Menu List:\n");
    printf("1. initDate\n");
    printf("2. printDateOnConsole\n");
    printf("3. acceptDateFromConsole\n");
    printf("0. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    return choice;
}

int main(){
    int choice;
    struct Date d;
    do{
        choice = menulist();
       switch (choice)
       {
          case 1 : initDate(&d);
                   break;
          case 2 : printDateOnConsole(&d);
                   break;
          case 3 : acceptDateFromConsole(&d);
                   break;
       }
    }while (choice != 0);

    return 0;
}