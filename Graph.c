#include<stdio.h>
#include<stdlib.h>

struct Graph
{
	int V;
	int E;
	int **Adj;	//Adjacency Matrix
	int weight;	//0 means unweighted
	int directed;//0 means undirected
};


struct Graph * createGraph()
{
	struct Graph *G=malloc(sizeof(struct Graph));
	printf("Enter the number of vertices and edges : ");
	scanf("%d%d",&G->V,&G->E);
	printf("Input 0 for unweighted and 1 for weighted");
	scanf("%d",&G->weight);
	printf("Input 0 for undirected and 1 for directed");
	scanf("%d",&G->weight);

	G->Adj=malloc(sizeof(int *)*G->V);
	int i;
	for(i=0;i<G->V;i++){
		G->Adj[i]=calloc(sizeof(int),G->V);	//Initialize with 0s
	}
	int u,v;
	for(i=0;i<G->E;i++)
	{
		printf("Enter the source and destination of %d edge: ",i+1);
		scanf("%d%d",&u,&v);
		if(G->weight){
			printf("Enter the weight : \n");
			scanf("%d",&G->Adj[u][v]);
		}else{
			G->Adj[u][v]=1;
		}
		if(G->directed){
			G->Adj[v][u]=G->Adj[u][v];
		}
	}
	return G;
}


int main()
{
	struct Graph *G=createGraph();
	int i,j;
	for(i=0;i<G->V;i++)
	{
		for(j=0;j<G->V;j++)
		{
			printf("%d\t",G->Adj[i][j]);
		}
		printf("\n");
	}
}