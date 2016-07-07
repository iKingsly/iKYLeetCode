//
//  main.cpp
//  7.4.2 邻接表
//
//  Created by 郑钦洪 on 16/7/7.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535

// 边表节点
typedef struct EdgeNode {
    int adjvex;
    EdgeType weight;
    struct EdgeNode *next;
}EdgeNode;

// 顶点表节点
typedef struct VertexNode{
    VertexType data;
    EdgeNode *firstEdge;
} VertexNode, AdjList[MAXVEX];

typedef struct {
    AdjList adjList;
    // 当前顶点数和边数
    int numVertexes, numEdges;
}GraphAdjust;


void CreateALGraph (GraphAdjust *G) {
    int i, j, k;
    EdgeNode *e;
    printf("输入顶点数和边数:\n");
    scanf("%d %d",&G->numVertexes, &G->numEdges);
    for (i = 0; i < G->numVertexes; i++) {
        scanf("%s",&(G->adjList[i].data));
        G->adjList[i].firstEdge = NULL;
    }
    
    // 建立边表
    for (k = 0; k < G->numEdges; k++) {
        scanf("%d,%d",&i,&j);
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = j;
        e->next = G->adjList[i].firstEdge;
        G->adjList[i].firstEdge = e;
        
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i;
        e->next = G->adjList[j].firstEdge;
        G->adjList[j].firstEdge = e;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
