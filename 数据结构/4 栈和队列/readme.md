#栈和队列
##1.栈
栈是限定在表位进行插入和删除操作的线性表
###1.1 栈的条件
栈满的条件 `S->top == MAXSIZE - 1`

栈为空的条件 `S->top == -1`
##2.队列
队列是只允许在一段进行插入操作，而在另外一端进行删除操作的线性表
###2.1 队列的条件
队列满的条件 `(Q.rear + 1) % MAXSIZE == Q.front`
队列空的条件 `Q.rear == Q.front`

如果是链式队列, 需要注意在出队列的时候，如果队列中只有一个元素，需要把队列的尾指针也指向头指针
链式队列的结构


	// 结点结构
	typedef struct QNode {
    	QElemType data;
    	struct QNode *next;
	}QNode, *QueuePtr;

	// 队列的链表结构
	typedef struct {
    	// 队头 队尾指针
    	QueuePtr front, rear;
	} LinkQueue;`