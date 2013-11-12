#include <stdio.h>                    //深度优先
#include <stdlib.h>
#define H 20
#define L 21
#include <conio.h>
#include <windows.h>
char a[H][L];
const int di[4] = {0,1,0,-1},
          dj[4] = {1,0,-1,0};
int main()
{
    void print(void);
    void dfs(int i,int j);
    int i,j,x,y;
    FILE *fp;
    fp=fopen("migong.txt","r");
    if (fp==NULL)
    {
        printf("无法打开文件\n");
        exit(0);
    }
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
        }
    }
    dfs(x,y);
   return 0;
}
void print(void)
{
    int i,j;
     for (i=0;i<H;i++)
    {
        for (j=0;j<L;j++)
        {
            printf("%c",a[i][j]);
        }
    }
}

void dfs(int x,int y)
{
    if(a[x][y]!='E')
    {
        int k;
	for (k = 0; k < 4; k++)
		if (x + di[k] >= 0 && y + di[k] < L
			&& x + dj[k] >= 0 && y + dj[k] < L
			&& a[x + di[k]][y + dj[k]] == '.')
       {
           a[x + di[k]][y + dj[k]] = '>';
           print();
           Sleep(100);
           system("cls");
           dfs(x+di[k],y+dj[k]);
        }
    }
}

