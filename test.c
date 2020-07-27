#include <stdio.h>

int main(void)
{
    int rank = 0; 
    int start, end;
    int p = 4;
    for(rank; rank < p; rank++)
    {
        printf("--");
        if(rank == 0)
        {
            start = 1;
            end = (int)65535/p + (65535 % p);
        }
        else
        {
            start = ((int)65535/p) * rank + (65535 % p) + 1;
            end = ((int)65535/p) * (rank + 1) + (65535 % p);
        }
        printf("Start: %d End: %d\n", start, end);
    }
}