#include <stdio.h>
#include <stdlib.h>
#define H 20
#define L 20
char a[H][L];
int main()
{
    int i,j,x,y;
    FILE *fp;
    fp=fopen("migong.txt","r");
    if (fp==NULL)
    {
        printf("无法打开文件\n");
        exit(0);
    }
    printf("迷宫\n");
    for (i=0;i<H;i++)
    {
        for (j=0;j<L;j++)
        {
            fscanf(fp,"%c",&a[i][j]);
            if(a[i][j]=='S')
            {
                x=i;
                y=j;
            }
            printf("%c",a[i][j]);
        }
    }
    dfs(x,y);
    printf("路径如下\n");
    for (i=0;j<H;i++)
    {
        for (j=0;j<L;j++)
        {
            printf("%c",a[i][j]);
        }
    }
    return 0;
}

void dfs(int x,int y)
{
    if(a[x][y]!='E')
    {
        if(x+1<H)
        {
            if(a[x+1][y]='.')
               {
                   a[x+1][y]='>';
                   dfs(x+1,y);
               }
        }
        if(x-1>=0)
        {
             if(a[x-1][y]='.')
                {
                   a[x-1][y]='>';
                   dfs(x-1,y);
                 }
        }
       if(y+1<L)
       {
           if(a[x][y+1]='.')
                  {
                       a[x][y+1]='>';
                       dfs(x,y+1);
                   }
       }
        if(y-1>=0)
        {
             if(a[x][y-1]='.')
                  {
                      a[x][y-1]='>';
                      dfs(x,y-1);
                  }
        }

    }
}

