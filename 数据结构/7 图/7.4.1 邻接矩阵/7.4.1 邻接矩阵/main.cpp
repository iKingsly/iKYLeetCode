//
//  main.cpp
//  7.4.1 邻接矩阵
//
//  Created by 郑钦洪 on 16/7/7.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535
typedef int Boolean;

Boolean visited[MAXVEX];
typedef struct {
    // 顶点表
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    // 顶点数和边数
    int numVertexes, numEdges;
}MGraph;

void CreateMGraph (MGraph *G) {
    int i,j,k,w;
    printf("输入顶点数和边数 :\n");
    scanf("%d,%d",&G->numVertexes, &G->numEdges);
    
    // 输入顶点信息 建立顶点表
    for (i = 0; i < G->numVertexes; i++) {
        scanf("%c",&G->vexs[i]);
    }
    
    // 初始化为无限大
    for (i = 0; i < G->numVertexes; i++) {
        for (j = 0 ; j < G->numVertexes; j++) {
            G->arc[i][j] = INFINITY;
        }
    }
    
    // 输入边表
    for (i = 0 ; i < G->numEdges; i++) {
        printf("输入边的上标下标和权值");
        scanf("%d,%d,%d",&i,&j,&w);
        G->arc[i][j] = w;
        G->arc[j][i] = w;
    }
}

void DFS(MGraph G, int i) {
    int j ;
    visited[i] = true;
    // 在这里可以做其他的操作，比如说找到一个点然后返回
    printf("%c ",G.vexs[i]);
    for (j = 0; j < G.numVertexes; j++) {
        if (G.arc[i][j] == 1 && !visited[j]) {
            DFS(G, j);
        }
    }
}

void DFSTraverse (MGraph G) {
    int i;
    for (i = 0; i < G.numVertexes; i++) {
        visited[i] = false;
    }
    for (i = 0; i < G.numVertexes; i++) {
        if (!visited[i]) {
            DFS(G, i);
        }
    }
}

// Prim算法生成的最小生成树
void MiniSpanTree_Prim (MGraph G) {
    int min, i, j, k;
    int adjvex[MAXVEX];
    int lowcost[MAXVEX];
    // 用来记录权值
    lowcost[0] = 0;
    
    // 初始化下标为0的顶点已经被标记过
    adjvex[0] = 0;
    
    // 初始化初0下标以外的全部顶点
    for (i = 1; i < G.numVertexes; i++) {
        lowcost[i] = G.arc[0][1];
        adjvex[i] = 0;
    }
    
    for (i = 1; i < G.numVertexes; i++) {
        // 初始化min为无限大
        min = INFINITY;
        
        j = 1; k = 0;
        
        while (j < G.numVertexes) {
            if (lowcost[j] != 0 && lowcost[j] < min) {
                min = lowcost[j];
                // 将当前权值最小的下标存入k中
                k = j;
            }
            j ++;
        }
        
        printf("(%d , %d)",adjvex[k],k);
        // 将lowcost的权值设置为0 表示此顶点已经完成任务
        lowcost[k] = 0;
        
        for (j = 1; j < G.numVertexes; j++) {
            if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j]) {
                lowcost[j] = G.arc[k][j];
                adjvex[j] = k;
            }
        }
        
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
