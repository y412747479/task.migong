#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp=fopen("migong.txt","r");
    if (fp==NULL)
    {
        printf("");
        exit(0);
    }

    return 0;
}
