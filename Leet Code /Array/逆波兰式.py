class Stack:
    def __init__(self):
        self.items = []
         
    def isEmpty(self):
        return len(self.items)==0
     
    def push(self, item):
        self.items.append(item)
     
    def pop(self):
        return self.items.pop() 
     
    def peek(self):
        if not self.isEmpty():
            return self.items[len(self.items)-1]
         
    def size(self):
        return len(self.items) 
        
def infixToPostfix(infixexpr):
    prec = {}
    prec["*"] = 3
    prec["/"] = 3
    prec["+"] = 2
    prec["-"] = 2
    prec["("] = 1
    opStack = Stack()
    postfixList = []
    tokenList = infixexpr.split()
    for token in tokenList:
        if token in "ABCDEFGHIJKLMNOPQRSTUVWXYZ" or token in "0123456789":
            postfixList.append(token)
        elif token == '(':
            opStack.push(token)
        elif token == ')':
            topToken = opStack.pop()
            while topToken != '(':
                postfixList.append(topToken)
                topToken = opStack.pop()
        else:
            while (not opStack.isEmpty()) and \
               (prec[opStack.peek()] >= prec[token]):
                  postfixList.append(opStack.pop())
            opStack.push(token)

    while not opStack.isEmpty():
        postfixList.append(opStack.pop())
    return " ".join(postfixList)

n = raw_input()
resultN = int(n) + int(n) - 1
strn = raw_input()
strn = strn[0:resultN]
print(infixToPostfix(strn)) 