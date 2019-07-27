#include<stdio.h>
#define M 999

void dijkstra(int v,int g[v][v],int src)
{
	int c[v][v],label[v],plabel[v],i,j,nn,min;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(g[i][j]==0)
				c[i][j]=M;
			else
				c[i][j]=g[i][j];
			}
    }	
	for(i=0;i<v;i++)
	{
		label[i]=c[src][i];
		plabel[i]=0;
	}
	label[src]=0;
	plabel[src]=1;
	for(j=0;j<v-1;j++)
	{
	     min=M;
		for(i=0;i<v;i++)
		{
			if(label[i]<min && plabel[i]!=1)
			{
				min=label[i];
				nn=i;
			}
	     }
	     
		plabel[nn]=1;
		for(i=0;i<v;i++)
		 {
		
		if(plabel[i]!=1)
	       	{
			if(label[i]>min+c[nn][i])
			label[i]=min+c[nn][i];
		    }
	     }
    }
   
   for(i=0;i<v;i++)
   printf("%d--->%d = %d\n",src,i,label[i]);
}
int main()
{
	int vertex,source,i,j;
	printf("Enter the number of vertices\n");
	scanf("%d",&vertex);
	int graph[vertex][vertex];
	printf("Enter the distance between each vertex\n");
	for(i=0;i<vertex;i++)
	{
		for(j=0;j<vertex;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	printf("Enter the source vertex\n");
	scanf("%d",&source);
	dijkstra(vertex,graph,source);
}
