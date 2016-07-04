//
//  main.cpp
//  6.8 二叉链表
//
//  Created by 郑钦洪 on 16/7/4.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
typedef char TElemType;
typedef struct BiTNode {
    TElemType data;
    BiTNode *lChild, *rChild;
} BiTNode , *BiTree;

void PreOrderTraverse (BiTree T) {
    if (T == NULL) {
        return;
    }
    printf("%c", T->data);
    PreOrderTraverse(T->lChild);
    PreOrderTraverse(T->rChild);
}

void InOrderTraverse (BiTree T) {
    if (T == NULL) {
        return;
    }
    InOrderTraverse(T->lChild);
    printf("%c", T->data);
    InOrderTraverse(T->rChild);
}

void PostOrderTraverse (BiTree T) {
    if (T == NULL) {
        return;
    }
    PostOrderTraverse(T->lChild);
    PostOrderTraverse(T->rChild);
    printf("%c", T->data);
}

void CreateBiTree (BiTree *T) {
    TElemType ch;
    scanf("%c", &ch);
    if (ch == '#') {
        *T = NULL;
    } else {
        *T = (BiTree) malloc(sizeof(BiTNode));
        if (!*T) {
            exit(EOVERFLOW);
        } else {
            (*T)->data = ch;
            CreateBiTree(&(*T)->lChild);
            CreateBiTree(&(*T)->rChild);
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
