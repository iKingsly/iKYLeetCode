//
//  main.cpp
//  8.6 二叉搜索树
//
//  Created by 郑钦洪 on 16/7/9.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
typedef int Status;
#define OK 1
#define Error -1
#define True 1
#define False 0
typedef struct BitNode {
    int data;
    struct BitNode *lChild, *rChild;
}BitNode, *BiTree;

Status SearchBST (BiTree T, int key, BiTree f, BiTree *p) {
    if (T == NULL) {
        *p = f;
        return false;
    } else if (key == T->data) {
        *p = T;
        return true;
    } else if (key < T->data) {
        return SearchBST(T->lChild, key, T, p);
    } else {
        return SearchBST(T->rChild, key, T, p);
    }
}

Status InsertBST (BiTree *T, int Key) {
    BiTree p, s;
    if (!SearchBST(*T, Key, NULL, &p)) {
        s = (BitNode *) malloc(sizeof(BitNode));
        s->data = Key;
        s->lChild = NULL;
        s->rChild = NULL;
        
        if (!p) { // 第一个节点
            *T = s;
        } else if(Key < p->data) {
            p->lChild = s;
        } else if (Key > p->data) {
            p->rChild = s;
        }
        return true;
    }
    return false;
}

BiTree * initBST(int numbers[], int n) {
    BiTree *T = NULL;
    for (int i = 0; i< n; i++) {
        InsertBST(T, numbers[i]);
    }
    return T;
}

// 从二叉排序树中删除节点p 并重新连接它的左右节点
Status DeleteNode (BiTree *p) {
    BiTree q, s;
    if ((*p)->rChild == NULL) {
        q = *p;
        *p = (*p)->lChild;
        free(q);
    } else if ((*p)->lChild == NULL) {
        q = (*p);
        *p = (*p)->rChild;
        free(q);
    } else {
        q = *p; s = (*p)->lChild;
        while (s->rChild) {
            q = s;
            s = s->rChild;
        }
        
        (*p)->data = s->data;
        if (q != *p) {
            q -> rChild = s->lChild;
        } else {
            q->lChild = s->lChild;
        }
        free(s);
    }
    return True;
}

Status DeleteTree (BiTree *T, int key) {
    if (!T) {
        return false;
    } else {
        if (key == (*T)->data) {
            return DeleteNode(T);
        } else if (key < (*T)->data) {
            DeleteTree(&(*T)->lChild,key);
        } else {
            DeleteTree(&(*T)->rChild, key);
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
