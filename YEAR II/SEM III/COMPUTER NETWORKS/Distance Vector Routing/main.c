#include<stdio.h>
#define MAX 20

struct router
{
    unsigned dist[MAX];
    unsigned from[MAX];
};

struct router rt[10];

int main()
{
    printf("\n======== DISTANcE VECTOR ROUTING ========\n");
    int costmat[MAX][MAX];
    int nodes, i, j, k, count=0;

    printf("\nEnter the number of nodes: ");
    scanf("%d", &nodes);

    printf("\nEnter the cost matrix:\n");
    for(i=0; i<nodes; i++)
    {
        for(j=0; j<nodes; j++)
        {
            scanf("%d", &costmat[i][j]);
            costmat[i][i] = 0;
            //initialise the distance equal to cost matrix
            rt[i].dist[j] = costmat[i][j];
            rt[i].from[j] = j;
        }
    }

    do
    {
        count = 0;
        for(i=0; i<nodes; i++)
        //We choose arbitary vertex k and we calculate the direct distance
        //from the node i to k using the cost matrix
        //and add the distance from k to node j
        for(j=0; j<nodes; j++)
            for(k=0; k<nodes; k++)
                if(rt[i].dist[j] > costmat[i][k] + rt[k].dist[j])
                {
                    //We calculate the minimum distance
                    rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                    rt[i].from[j] = k;
                    count++;
                }
    }while(count != 0);

    for(i=0; i<nodes; i++)
    {
        printf("\n\nFor Router %d:\n=============", i+1);
        for(j=0; j<nodes; j++)
        {
            printf("\t\nRouter %d via %d Distance: %d ", j+1, rt[i].from[j]+1, rt[i].dist[j]);
        }
    }
    printf("\n\n");
    getchar();
}