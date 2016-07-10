//
//  main.cpp
//  8.7 二叉平衡树
//
//  Created by 郑钦洪 on 16/7/10.
//  Copyright © 2016年 iKingsly. All rights reserved.
//

#include <iostream>
// 左边高1
#define LH +1
// 等高
#define EH 0
// 右边高1
#define RH -1

typedef struct BiTNode {
    int data;
    int bf;
    struct BiTNode *lChild,*rChild;
}BiTNode,*BiTree;

void R_Rotate (BiTree *p) {
    BiTree L;
    L = (*p)->lChild;
    (*p)->lChild = L->rChild;
    L->rChild = (*p);
    *p = L;
}

void L_Rotate (BiTree *p) {
    BiTree L;
    L = (*p)->rChild;
    (*p)->rChild = L->lChild;
    L->lChild = (*p);
    *p = L;
}

void LeftBalance(BiTree *T) {
    BiTree L,Lr;
    L = (*T)->lChild;
    
    switch (L->bf) {
        case LH:
            (*T)->bf = L->bf = EH;
            R_Rotate(T);
            break;
        case RH:
            Lr = L->rChild;
            switch (Lr->bf) {
                case LH:
                    (*T)->bf = RH;
                    L->bf = EH;
                    break;
                case EH:
                    (*T)->bf = L->bf = EH;
                    break;
                case RH:
                    (*T)->bf = EH;
                    L->bf = LH;
                    break;
                default:
                    break;
            }
            Lr->bf = EH;
            L_Rotate(&(*T)->lChild);
            R_Rotate(T);
        default:
            break;
    }
}

void RightBalance(BiTree *T) {
    BiTree L,Lr;
    L = (*T)->rChild;
    
    switch (L->bf) {
        case LH:
            (*T)->bf = L->bf = EH;
            R_Rotate(T);
            break;
        case RH:
            Lr = L->rChild;
            switch (Lr->bf) {
                case LH:
                    (*T)->bf = RH;
                    L->bf = EH;
                    break;
                case EH:
                    (*T)->bf = L->bf = EH;
                    break;
                case RH:
                    (*T)->bf = EH;
                    L->bf = LH;
                    break;
                default:
                    break;
            }
            Lr->bf = EH;
            L_Rotate(&(*T)->lChild);
            R_Rotate(T);
        default:
            break;
    }
}


bool InsertAVL (BiTree *T, int e, bool *taller) {
    if (!*T) {
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = e;
        (*T)->bf = EH;
        *taller = true;
    } else {
        if (e == (*T)->data) {
            *taller = false;
            return false;
        }
        if (e < (*T)->data) {
            if (!InsertAVL(&(*T)->lChild,e,taller)) {
                return false;
            }
            if (*taller) {
                switch ((*T)->bf) {
                    case LH: // 原来左子树不平衡 现在左子树更不平衡
                        LeftBalance(T);
                        *taller = true;
                        break;
                    case EH: // 原来平衡 现在左子树不平衡
                        (*T)->bf = LH;
                        *taller = true;
                        break;
                    case RH: // 原来右子树高 现在平衡了
                        (*T)->bf = EH;
                        *taller = false;
                    default:
                        break;
                }
            }
        }
        if (e > (*T)->data) {
            if (!InsertAVL(&(*T)->rChild,e,taller)) {
                return false;
            }
            if (*taller) {
                switch ((*T)->bf) {
                    case LH: // 原本左子树高 现在插入后平衡
                        (*T)->bf = EH;
                        *taller = false;
                        break;
                    case EH:
                        (*T)->bf = RH;
                        *taller = true;
                    case RH:
                        RightBalance(T);
                        *taller = false;
                        break;
                    default:
                        break;
                }
            }
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
