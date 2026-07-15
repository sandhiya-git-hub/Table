#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50

void printBorder(int size)
{
    int i;
    printf("   ");
    for(i = 0; i < size; i++)
        printf("+-----");
    printf("+\n");
}
void printTable(int arr[MAX][MAX], int size)
{
    int i, j;
    printf("\nGenerated 2D array:\n\n");
    printf("     ");
    for(i = 0; i < size; i++)
        printf("%02d    ", i);
    printf("\n");
    printBorder(size);
    for(i = 0; i < size; i++)
    {
        printf("%02d ", i);
        for(j = 0; j < size; j++)
            printf("| %2d ", arr[i][j]);
        printf("|\n");
        printBorder(size);
    }
}
int printHighlightedTable(int arr[MAX][MAX], int size, int highlight)
{
    int i, j;
    int count = 0;
    printf("\nArray with %d highlighted:\n\n", highlight);
    printf("     ");
    for(i = 0; i < size; i++)
        printf("%02d    ", i);
    printf("\n");
    printBorder(size);
    for(i = 0; i < size; i++)
    {
        printf("%02d ", i);
        for(j = 0; j < size; j++)
        {
            if(arr[i][j] == highlight)
            {
                printf("|[%2d]", arr[i][j]);
                count++;
            }
            else
            {
                printf("| %2d ", arr[i][j]);
            }
        }
        printf("|\n");
        printBorder(size);
    }
    return count;
}
int main()
{
    int arr[MAX][MAX];
    int size;
    int highlight;
    int i, j;
    int count;
    char ch;
    srand(time(NULL));
    // Read array size
    while(1)
    {
        printf("Enter array size (for PxP array): ");
        if(scanf("%d", &size) != 1)
        {
            printf("Invalid input.\n");
            while((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }
        if(size <= 0 || size > MAX)
        {
            printf("Please enter a value between 1 and %d.\n", MAX);
            continue;
        }
        break;
    }
    // Generate random even numbers
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            arr[i][j] = (rand() % 8 + 1) * 2;
        }
    }
    // Display generated table
    printTable(arr, size);
    // Read highlight number
    while(1)
    {
        printf("\nEnter a number to highlight (even number 2-16): ");

        if(scanf("%d", &highlight) != 1)
        {
            printf("Invalid input.\n");
            while((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }
        if(highlight < 2 || highlight > 16 || highlight % 2 != 0)
        {
            printf("Please enter an even number between 2 and 16.\n");
            continue;
        }
        break;
    }
    // Display highlighted table
    count = printHighlightedTable(arr, size, highlight);
    printf("\nNumber %d appeared %d time(s)\n", highlight, count);
    return 0;
}
