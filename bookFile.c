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
    printf("1. Display all Books\n");
    printf("2. Search by Author\n");
    printf("3. Costliest book index\n");
    printf("4. Search by Title\n");
    printf("5. Search by Publisher\n");
    printf("6. Display book of same publishing year\n");
    scanf("%d", &u_choice);
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
            printf("Enter proper choice\n");
            break;
    }

    return 0;
}

void getBook(struct book b[])
{
    FILE *fp;
    int i;

    fp = fopen("books.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    for (i = 0; i < 2; i++)
    {
        printf("Enter book name: ");
        scanf("%s", b[i].bName);
        printf("Enter book ID: ");
        scanf("%lf", &b[i].bid);
        printf("Enter book author: ");
        scanf("%s", b[i].bAuthor);
        printf("Enter book publisher: ");
        scanf("%s", b[i].bPublisher);
        printf("Enter book cost: ");
        scanf("%f", &b[i].bCost);
        printf("Enter book quantity: ");
        scanf("%d", &b[i].bQuan);
        printf("Enter book's date of publishing (DD MM YYYY): ");
        scanf("%d %d %d", &b[i].bDOP.date, &b[i].bDOP.mon, &b[i].bDOP.year);
        printf("\n\n");

        fprintf(fp, "%.0f %s %s %s %.2f %d %d %d %d\n", b[i].bid, b[i].bName, b[i].bAuthor, b[i].bPublisher, b[i].bCost, b[i].bQuan, b[i].bDOP.date, b[i].bDOP.mon, b[i].bDOP.year);
    }

    fclose(fp);
}

void displayBook(struct book b[])
{
    FILE *fp;
    int i;

    fp = fopen("books.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    while (fscanf(fp, "%lf %s %s %s %f %d %d %d %d", &b[i].bid, b[i].bName, b[i].bAuthor, b[i].bPublisher, &b[i].bCost, &b[i].bQuan, &b[i].bDOP.date, &b[i].bDOP.mon, &b[i].bDOP.year) != EOF)
    {
        printf("Book id: %.0f\n", b[i].bid);
        printf("Book name: %s\n", b[i].bName);
        printf("Book Author: %s\n", b[i].bAuthor);
        printf("Book Publisher: %s\n", b[i].bPublisher);
        printf("Book Cost: %.2f\n", b[i].bCost);
        printf("Book Quantity: %d\n", b[i].bQuan);
        printf("Book DOP: %d %d %d\n\n", b[i].bDOP.date, b[i].bDOP.mon, b[i].bDOP.year);
        i++;
    }

    fclose(fp);
}

void displayAuthor(struct book b[])
{
    FILE *fp;
    int i;
    char uAuthor[30];

    printf("Enter Author name to search: ");
    scanf("%s", uAuthor);

    fp = fopen("books.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    while (fscanf(fp, "%lf %s %s %s %f %d %d %d %d", &b[i].bid, b[i].bName, b[i].bAuthor, b[i].bPublisher, &b[i].bCost, &b[i].bQuan, &b[i].bDOP.date, &b[i].bDOP.mon, &b[i].bDOP.year) != EOF)
    {
        if (strcmp(b[i].bAuthor, uAuthor) == 0)
        {
            printf("Book id: %.0f\n", b[i].bid);
            printf("Book name: %s\n", b[i].bName);
            printf("Book Author: %s\n", b[i].bAuthor);
            printf("Book Publisher: %s\n", b[i].bPublisher);
            printf("Book Cost: %.2f\n", b[i].bCost);
            printf("Book Quantity: %d\n", b[i].bQuan);
            printf("Book DOP: %d %d %d\n\n", b[i].bDOP.date, b[i].bDOP.mon, b[i].bDOP.year);
        }
        i++;
    }

    fclose(fp);
}

void costlyBook(struct book b[])
{
    FILE *fp;
    int i, index = 0, maxIndex = 0;
    float maxCost = 0.0;

    fp = fopen("books.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    while (fscanf(fp, "%lf %s %s %s %f %d %d %d %d", &b[i].bid, b[i].bName, b[i].bAuthor, b[i].bPublisher, &b[i].bCost, &b[i].bQuan, &b[i].bDOP.date, &b[i].bDOP.mon, &b[i].bDOP.year) != EOF)
    {
        if (b[i].bCost > maxCost)
        {
            maxCost = b[i].bCost;
            maxIndex = index;
        }
        i++;
        index++;
    }

    printf("Costliest book at index %d in position %d\n", maxIndex, maxIndex + 1);

    fclose(fp);
}

void displayPublisher(struct book b[])
{
    FILE *fp;
    int i;
    char uPublisher[30];

    printf("Enter Publisher name to search: ");
    scanf("%s", uPublisher);

    fp = fopen("books.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    while (fscanf(fp, "%lf %s %s %s %f %d %d %d %d", &b[i].bid, b[i].bName, b[i].bAuthor, b[i].bPublisher, &b[i].bCost, &b[i].bQuan, &b[i].bDOP.date, &b[i].bDOP.mon, &b[i].bDOP.year) != EOF)
    {
        if (strcmp(b[i].bPublisher, uPublisher) == 0)
        {
            printf("Book id: %.0f\n", b[i].bid);
            printf("Book name: %s\n", b[i].bName);
            printf("Book Author: %s\n", b[i].bAuthor);
            printf("Book Publisher: %s\n", b[i].bPublisher);
            printf("Book Cost: %.2f\n", b[i].bCost);
            printf("Book Quantity: %d\n", b[i].bQuan);
            printf("Book DOP: %d %d %d\n\n", b[i].bDOP.date, b[i].bDOP.mon, b[i].bDOP.year);
        }
        i++;
    }

    fclose(fp);
}

void displayTitle(struct book b[])
{
    FILE *fp;
    int i;
    char uTitle[30];

    printf("Enter Title to search: ");
    scanf("%s", uTitle);

    fp = fopen("books.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    while (fscanf(fp, "%lf %s %s %s %f %d %d %d %d", &b[i].bid, b[i].bName, b[i].bAuthor, b[i].bPublisher, &b[i].bCost, &b[i].bQuan, &b[i].bDOP.date, &b[i].bDOP.mon, &b[i].bDOP.year) != EOF)
    {
        if (strcmp(b[i].bName, uTitle) == 0)
        {
            printf("Book id: %.0f\n", b[i].bid);
            printf("Book name: %s\n", b[i].bName);
            printf("Book Author: %s\n", b[i].bAuthor);
            printf("Book Publisher: %s\n", b[i].bPublisher);
            printf("Book Cost: %.2f\n", b[i].bCost);
            printf("Book Quantity: %d\n", b[i].bQuan);
            printf("Book DOP: %d %d %d\n\n", b[i].bDOP.date, b[i].bDOP.mon, b[i].bDOP.year);
        }
        i++;
    }

    fclose(fp);
}

void displaySameYear(struct book b[])
{
    FILE *fp;
    int i;
    int uYear;

    printf("Enter Publishing year to search: ");
    scanf("%d", &uYear);

    fp = fopen("books.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    while (fscanf(fp, "%lf %s %s %s %f %d %d %d %d", &b[i].bid, b[i].bName, b[i].bAuthor, b[i].bPublisher, &b[i].bCost, &b[i].bQuan, &b[i].bDOP.date, &b[i].bDOP.mon, &b[i].bDOP.year) != EOF)
    {
        if (b[i].bDOP.year == uYear)
        {
            printf("Book id: %.0f\n", b[i].bid);
            printf("Book name: %s\n", b[i].bName);
            printf("Book Author: %s\n", b[i].bAuthor);
            printf("Book Publisher: %s\n", b[i].bPublisher);
            printf("Book Cost: %.2f\n", b[i].bCost);
            printf("Book Quantity: %d\n", b[i].bQuan);
            printf("Book DOP: %d %d %d\n\n", b[i].bDOP.date, b[i].bDOP.mon, b[i].bDOP.year);
        }
        i++;
    }

    fclose(fp);
}
