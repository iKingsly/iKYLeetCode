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
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
