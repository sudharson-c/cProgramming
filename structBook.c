
#include <stdio.h>
#include <string.h>

struct dop
{
    int date;
    int mon;
    int year;
};
struct book
{
    double bid;
    char bName[30];
    char bAuthor[30];
    char bPublisher[30];
    float bCost;
    int bQuan;
    struct dop bDOP;
};

void getBook(struct book[]);
void displayBook(struct book[]);
void displayAuthor(struct book[]);
void costlyBook(struct book b[]);
void displayTitle(struct book b[]);
void displayPublisher(struct book b[]);
void displaySameYear(struct book b[]);

int main()
{
    struct book b[10];
    int u_choice;
    getBook(b);
    printf("1.Display all Books");
    printf("\n2.Search by Author\n");
    printf("3.Costliest book index\n");
    printf("4.Search by Title\n");
    printf("5.Search by Publisher\n");
    printf("6.Display book of same publishing year:\n");
    printf("7.Exit\nEnter Choice: ");
    scanf("%d", &u_choice);
    do{
        switch (u_choice)
        {
        case 1:
            displayBook(b);
            break;
        case 2:
            displayAuthor(b);
            break;
        case 3:
            costlyBook(b);
            break;
        case 4:
            displayTitle(b);
            break;
        case 5:
            displayPublisher(b);
            break;
        case 6:
            displaySameYear(b);
            break;
        default:
            printf("Enter proper choice");
            break;
        }
    while(u_choice!=7);

    return 0;
}
void getBook(struct book b[])
{
    int i;

    for (i = 0; i < 2; i++)
    {
        printf("Enter book name : ");
        scanf("%s", b[i].bName);
        printf("Enter book ID : ");
        scanf("%lf", &b[i].bid);
        printf("Enter book author : ");
        scanf("%s", b[i].bAuthor);
        printf("Enter book publisher : ");
        scanf("%s", b[i].bPublisher);
        printf("Enter book cost : ");
        scanf("%f", &b[i].bCost);
        printf("Enter book quantity : ");
        scanf("%d", &b[i].bQuan);
        printf("Enter book's date of publishing (DD MM YYYY) : ");
        scanf("%d %d %d", &b[i].bDOP.date, &b[i].bDOP.mon, &b[i].bDOP.year);
        printf("\n\n");
    }
}
void displayBook(struct book b[])
{
    int i;
    for (i = 0; i < 2; i++)
    {
        printf("Book id : %.0f\n", b[i].bid);
        printf("Book name: %s\n", b[i].bName);
        printf("Book Author:%s\n", b[i].bAuthor);
        printf("Book Publisher:%s", b[i].bPublisher);
        printf("\nBook Cost: %.2f", b[i].bCost);
        printf("\nBook Quantity: %d", b[i].bQuan);
        printf("\nBook DOP : %d %d %d", b[i].bDOP.date, b[i].bDOP.mon, b[i].bDOP.year);
        printf("\n\n");
    }
}
void displayAuthor(struct book b[])
{
    int i;
    char uAuthor[30];
    printf("Enter Author name to search: ");
    scanf("%s", uAuthor);
    for (i = 0; i < 2; i++)
    {
        if (strcmp(b[i].bAuthor, uAuthor) == 0)
        {
            printf("Book id : %.0f\n", b[i].bid);
            printf("Book name: %s\n", b[i].bName);
            printf("Book Author:%s", b[i].bAuthor);
            printf("Book Publisher:%s", b[i].bPublisher);
            printf("\nBook Cost: %.2f", b[i].bCost);
            printf("\nBook Quantity: %d", b[i].bQuan);
            printf("\nBook DOP : %d %d %d", b[i].bDOP.date, b[i].bDOP.mon, b[i].bDOP.year);
            printf("\n\n");
        }
    }
}
void costlyBook(struct book b[])
{
    int i, index;
    for (i = 0; i < 2; i++)
    {
        if (b[i].bCost > b[i + 1].bCost)
        {
            index = i;
        }
    }
    printf("Costliest book at index %d in position %d", index, index + 1);
}
void displayPublisher(struct book b[])
{
    int i;
    char uPublisher[30];
    printf("Enter Publisher name to search: ");
    scanf("%s", uPublisher);
    for (i = 0; i < 2; i++)
    {
        if (strcmp(b[i].bPublisher, uPublisher) == 0)
        {
            printf("Book id : %.0f\n", b[i].bid);
            printf("Book name: %s\n", b[i].bName);
            printf("Book Author:%s\n", b[i].bAuthor);
            printf("Book Publisher:%s", b[i].bPublisher);
            printf("\nBook Cost: %.2f", b[i].bCost);
            printf("\nBook Quantity: %d", b[i].bQuan);
            printf("\nBook DOP : %d %d %d", b[i].bDOP.date, b[i].bDOP.mon, b[i].bDOP.year);
            printf("\n\n");
        }
    }
}
void displayTitle(struct book b[])
{
    int i;
    char uTitle[30];
    printf("Enter Title to search: ");
    scanf("%s", uTitle);
    for (i = 0; i < 2; i++)
    {
        if (strcmp(b[i].bName, uTitle) == 0)
        {
            printf("Book id : %.0f\n", b[i].bid);
            printf("Book name: %s\n", b[i].bName);
            printf("Book Author:%s\n", b[i].bAuthor);
            printf("Book Publisher:%s", b[i].bPublisher);
            printf("\nBook Cost: %.2f", b[i].bCost);
            printf("\nBook Quantity: %d", b[i].bQuan);
            printf("\nBook DOP : %d %d %d", b[i].bDOP.date, b[i].bDOP.mon, b[i].bDOP.year);
            printf("\n\n");
        }
    }
}
void displaySameYear(struct book b[])
{
    int i;
    int uYear;
    printf("Enter Publishing year to search: ");
    scanf("%d", &uYear);
    printf("\n");
    for (i = 0; i < 2; i++)
    {
        if (b[i].bDOP.year == uYear)
        {
            printf("Book id : %.0f\n", b[i].bid);
            printf("Book name: %s\n", b[i].bName);
            printf("Book Author:%s\n", b[i].bAuthor);
            printf("Book Publisher:%s", b[i].bPublisher);
            printf("\nBook Cost: %.2f", b[i].bCost);
            printf("\nBook Quantity: %d", b[i].bQuan);
            printf("\nBook DOP : %d %d %d", b[i].bDOP.date, b[i].bDOP.mon, b[i].bDOP.year);
            printf("\n\n");
        }
    }
}
