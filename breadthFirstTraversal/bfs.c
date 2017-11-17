#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

int **adjMat; //adjecency matrix
int verticesMax, edgesMax;
int *queue, front, rear;
int *result;
int i, j;

struct Vertex
{
	char label;
	int visited;
};

struct Vertex *vertices;

void getVertices()
{
	char c;
	printf("\nEnter number of vertices to add: ");
	scanf("%d", &verticesMax);
	vertices = (struct Vertex *)malloc(sizeof(struct Vertex)*verticesMax);

	printf("\nEnter name of each vertex:\n");
	for (i = 0; i < verticesMax; i++)
	{
		printf("%d: ", i + 1);
		scanf("%s", &vertices[i].label);
		vertices[i].visited = 0;
	}
}

void getEdges()
{
	printf("\nEnter number of edges to add: ");
	scanf("%d", &edgesMax);
}

void createAdjMatrix()
{
	adjMat = (int **)malloc(sizeof(int *)*verticesMax);

	for (i = 0; i < verticesMax; i++)
	{
		adjMat[i] = (int *)malloc(sizeof(int)*edgesMax);
	}
	for (i = 0; i < verticesMax; i++)
	{
		for (j = 0; j < edgesMax; j++)
		{
			adjMat[i][j] = 0;
		}
	}
}

void inputEdges()
{
	int first, second;
	for (i = 0; i < edgesMax; i++)
	{
		system("cls");
		for (j = 0; j < verticesMax; j++)
		{
			printf("%d\t", j);
		}
		printf("\n");
		for (j = 0; j < verticesMax; j++)
		{
			printf("%c\t", vertices[j].label);
		}

		printf("\n\nEnter two vertices between you want to add edge");
		printf("\nFirst: ");
		scanf("%d", &first);
		printf("Second: ");
		scanf("%d", &second);

		adjMat[first][i] = 1;
		adjMat[second][i] = 1;
	}
}

void createQueue()
{
	queue = (int *)malloc(sizeof(int)*verticesMax - 1);
	front = -1;
	rear = 0;
}

void printQueue()
{
	if (front != -1)
	{
		for (i = 0; i <= rear; i++)
		{
			//printf("%d", queue[i]);
		}
	}
	//getch();
}

void push(int data)
{
	if (front != -1)
	{
		rear++;
	}
	else
	{
		front++;
		rear = 0;
	}
	queue[rear] = data;
	printQueue();
}

int pop()
{
	int d;
	if (front != -1)
	{
		d = queue[front];
		front++;
		if (front > rear)
		{
			front = -1;
			rear = 0;
		}
		printQueue();
		return d;
	}
	else
	{
		printQueue();
		return -1;
	}
}

void bfs()
{
	int edge = 0, vertex = 0, checkVertex = 0;
	int completed = 0;
	result = (int *)malloc(sizeof(int)*verticesMax);
	push(0);

	while (1)
	{
		checkVertex = pop();
		if (checkVertex != -1)
		{
			result[completed] = checkVertex;
			completed++;
			for (edge = 0; edge < edgesMax; edge++)
			{
				if (adjMat[checkVertex][edge] == 1)
				{
					for (vertex = 0; vertex < verticesMax; vertex++)
					{
						if (vertex == checkVertex)
						{
							continue;
						}
						if ((adjMat[vertex][edge] == 1) && vertices[vertex].visited==0)
						{
							vertices[vertex].visited = 1;
							/*completed++;
							result[completed] = vertex;*/
							push(vertex);
							break;
						}
					}
				}
			}
		}
		vertices[checkVertex].visited = 1;
		if (checkVertex == -1)
		{
			break;
		}
	}

	printf("\n\nAns is: ");
	for (i = 0; i < verticesMax; i++)
	{
		printf("%c\t", vertices[result[i]].label);
	}
	printf("\n");
}

void main()
{
	getVertices();
	getEdges();
	createAdjMatrix();
	inputEdges();
	createQueue();
	bfs();
	getch();
}