#include <stdio.h>
#include <stdlib.h>

char Map[30][30]= {0}, VisitMap[30][30]= {0};
int m, n;
int KeySum[1000], KeyCount[1000];       //钥匙总数，当前找到的钥匙数量
int main()
{
    while(scanf("%d %d",&m, &n)!=EOF)
    {
        inputMap();
        computeItemSum();
        copyMap();
        printf("end! answer:%d\n", dfs(1, 1));
    }
    return 0;
}
void inputMap()
{
    int i,j;
    for(i=0; i<25; i++)     //先全部初始化为0
    {
        for(j=0; j<25; j++)
        {
            Map[i][j]=0;
        }
    }
    for(i=0; i<n+2; i++)        //将图的上下边界设置为X
    {
        Map[0][i]='X';
        Map[m+1][i]='X';
    }
    for(i=1; i<m+1; i++)        //输入，并设置左右边界X
    {
        Map[i][0]='X';
        scanf("%s", Map[i]+1);
        Map[i][n+1]='X';
    }
}
void computeItemSum()       //计算图中钥匙的总数量
{
    int i, j;
    for(int i='a'; i<='e'; i++)        //初始化为0
    {
        KeyCount[i]=0;
        KeySum[i]=0;
    }
    for(int i=1; i<=m; i++)         //逐个统计
    {
        for(int j=1; j<=n; j++)
        {
            KeySum[Map[i][j]]++;
        }
    }
}
void copyMap()          //因为搜索过程中会对图进行修改，所以复制出来，不改动原图
{
    int i, j;
    for(i=0; i<=m+1; i++)
    {
        for(j=0; j<=n+1; j++)
        {
            VisitMap[i][j]=Map[i][j];
        }
    }
}
void show()         //显示钥匙和图当前遍历的状态
{
    int i, j;
    printf("\nVisitMap:\n");
    for(i=0; i<m+2; i++)
    {
        for(j=0; j<n+2; j++)
            printf("%c", VisitMap[i][j]);
        printf("\n");
    }
    printf("KeySum:\n");
    for(i='a'; i<='e'; i++)
    {
        printf("%d ", KeySum[i]);
    }
    printf("\nKeyCount:\n");
    for(i='a'; i<='e'; i++)
    {
        printf("%d ", KeyCount[i]);
    }
    printf("\n");
    getchar();
}
int dfs(int x, int y)       //深度优先遍历
{
    printf("\nposition:%d %d\n", x, y);
    show();
    if(VisitMap[x][y]=='G') return 1;          //根据当前节点的不同符号，分别做出相应的处理
    if(VisitMap[x][y]=='X') return 0;
    if(VisitMap[x][y]=='.') VisitMap[x][y]='X';
    if('a'<=VisitMap[x][y]&&VisitMap[x][y]<='e')
    {
        KeyCount[VisitMap[x][y]]++;
        VisitMap[x][y]='X';
    }
    if('A'<=VisitMap[x][y]&&VisitMap[x][y]<='E')
    {
        if(KeyCount[VisitMap[x][y]+32]==KeySum[VisitMap[x][y]+32])
        {
            VisitMap[x][y]='X';
        }
        else
        {
            return 0;
        }
    }
    return dfs(x-1,y)||dfs(x, y+1)||dfs(x+1, y)||dfs(x, y-1);   //当前节点可以到达的话，就依次尝试向当前节点的上右下左方向继续遍历
}
