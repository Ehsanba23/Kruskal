#include<iostream>
#include<conio.h>
using namespace std;

int parent[10];
int a,b,u,v,i,j,n;
int minimum,cost[10][10];
int nedge=1;
int minimumcost=0;

void kruskal(int cost[][10],int n)
{
	cout << "\n\nThe Minimum Cost Edges Are:\n";

    while(nedge<n)
    {
    	minimum=999;
    	for(int i=1;i<=n;i++)
       		for(int j=1;j<=n;j++)
          		if(cost[i][j]<minimum)
           		{
                	minimum=cost[i][j];
                	a=u=i;
                	b=v=j;
                }
        while(parent[u])
            u=parent[u];
        while(parent[v])
        	v=parent[v];
        if(u!=v)
        {
        	nedge++;
        	cout << "\n(" << a << " -> " << b << ") = " << minimum;
        	minimumcost += minimum;
        	parent[v]=u;
        }
        cost[a][b]=cost[b][a]=999;
    }
    cout << "\n\nMinimum Cost = " << minimumcost;
}
void readData()
{
    cout << "Please Enter the Number of Vertix: ";
    cin >> n;
    cout << "Please Enter the Adjacency Matrix:\n";

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
			cin >> cost[i][j];
            if(cost[i][j]==0)
            	cost[i][j]=999;
        }
    kruskal(cost,n);
}

int main()
{
    readData();

    getch();
    return 0;
}
