#include <stdio.h>

void main(){
    int n,i,j,k,source,min;
    printf("Enter the number of routers: ");
    scanf("%d",&n);
    int costmatrix[n][n],flag[n],last[n],dist[n];
    printf("Enter the cost matrix:\n");
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            scanf("%d",&costmatrix[i][j]);
        
    printf("Enter the source router: ");
    scanf("%d",&source);
    for (i=0;i<n;i++)
    {
        flag[i]=0; //flag is initialized to 0, indicating all routers are unvisited initially.
        last[i]=source; //last is initialized to the source router.
        dist[i]=costmatrix[source][i]; //dist is initialized to the cost from the source router to each other router.
    }
    flag[source]=1; //The source router is marked as visited by setting flag[source] to 1.
    for (i=0;i<n;i++)
    {
        min = 1000;
        for (j=0;j<n;j++)
            if (!flag[j])
                if(dist[j]<min)
                {
                    k=j;
                    min = dist[j];
                }

        flag[j]=1;
        for(j=0;j<n;j++)
            if(!flag[j])
                if(min+costmatrix[k][j]<dist[j])
                {
                    dist[j]=min+costmatrix[k][j];
                    last[j]=k;
                }
    }
    for(i=0;i<n;i++)
    {
        printf("%d==>%d:Path taken:%d",source,i,i);
        j=i;
        while(j!=source)
        {
            printf("<--%d",last[j]);
            j=last[j];
        }
        printf("\nShortest Distance : %d\n",dist[i]);
    }
    
}