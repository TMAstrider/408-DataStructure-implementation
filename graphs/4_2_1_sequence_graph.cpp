#include <stdio.h>
#include <stdlib.h>



// Sequence Graphs
#define maxVertexNum 100

typedef char VertexType;
typedef int EdgeType;

typedef struct {
    VertexType vex[maxVertexNum];
    EdgeType edge[maxVertexNum][maxVertexNum];
    int vexNum, edgeNum;
}MGraph;



// Linked Graphs
#define N 8		//图中顶点数目的最大值，根据题目要求自己定义
typedef struct ArcNode{			//弧结点
	int vexIndex;				//该弧所指向的顶点编号
    int weight;                //该弧的权值
	struct ArcNode *next;		//指向下一个弧结点
}ArcNode; 

typedef struct VertexNode{	//顶点结点
	char data; 			//顶点信息，每个顶点存储一个char字符，可根据题目要求将char改为其他类型
	ArcNode *first; 	//指向第一条依附该顶点的弧的指针
}VertexNode;

typedef struct{
	VertexNode vex[N];    		//N个顶点
	int vexnum,arcnum; 		//图的顶点数和弧数
} ALGraph; 					//ALGraph是以邻接表存储的图类型
