#include<stdio.h>
#include<stdlib.h>
/////이것은 기본///// 
typedef struct edge{
	int origin;
	int destination;
	int weight;
}Edge;

typedef struct vertex{
	int name;
	int weight;
}Vertex;

typedef struct graph{
	Edge *edges;
	Vertex *vertex;
}Graph;

Graph *G;
int n,m,s;

void Bellman(){
	
	Vertex temp;
	int i,j,destination,origin,weight;	
	
	/*if(s!=1)
   	{
   		temp=G->vertex[s];
   		G->vertex[s]=G->vertex[1];
   		G->vertex[1]=temp;
   	}*/
   	G->vertex[1].weight=0;
	
	for(i=1;i<=n;i++)
	{
		for(j=0;j<m;j++)
	 	{
	 		if(G->edges[j].origin == G->vertex[i].name)
		 	{
			 	origin=G->edges[j].origin;
	 			destination=G->edges[j].destination;
	 			
	 			if( G->vertex[destination].weight < G->vertex[origin].weight + G->edges[j].weight)
	 			 		G->vertex[destination].weight=G->vertex[destination].weight;
	 			else
				 	G->vertex[destination].weight= G->vertex[origin].weight+G->edges[j].weight;			
			}
		}
	}
}

int main()
{
	int i,weight,origin,destination;
	
	scanf("%d %d %d",&n,&m,&s);
	G=(Graph*)malloc(sizeof(Graph));
	G->edges=(Edge*)malloc(sizeof(Edge)*m);
	G->vertex=(Vertex*)malloc(sizeof(Vertex)*(n+1));
	
	for(i=1;i<=n;i++)
	{
		G->vertex[i].name=i;
		G->vertex[i].weight=1000;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&origin,&destination,&weight);
		G->edges[i].origin=origin;
		G->edges[i].destination=destination;
		G->edges[i].weight=weight;
	}
	
	Bellman();
	
	for(i=1;i<=n;i++)
	{
		if(i==s || G->vertex[i].weight==1000) continue;
		else
		printf("%d %d\n",i,G->vertex[i].weight);
	}
}
