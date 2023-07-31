
    // NUMBER PATTERN

    // n = 2
    //  00 01 02     2 2 2
    //  10 11 12     2 1 2 
    //  20 21 22     2 2 2   

    //  n= 3
    //  00 01 02 03 04      3 3 3 3 3
    //  10 11 12 13 14      3 2 2 2 3 
    //  20 21 22 23 24      3 2 1 2 3
    //  30 31 32 33 34      3 2 2 2 3
    //  40 41 42 43 44      3 3 3 3 3


#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d",&n);
    int size = 2*n-1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int distanceToCenter;
            if(abs(i - size / 2) > abs(j - size / 2))
                distanceToCenter= abs(i - size / 2);
            else
                distanceToCenter= abs(j - size / 2);
            
            int value = distanceToCenter + 1;
            
            printf("%d ", value);
        }
        printf("\n");
    }

    return 0;
}
