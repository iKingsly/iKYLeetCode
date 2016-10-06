#80 Remove Duplicates from Sorted Array II
这是Remove Duplicates from Sorted Array I的改版，允许同时存在同一个数2次，由于数组是排序好的，且如果数组大小小于3的话，可以直接返回数据，不需要做处理，这里我们用两个指针，一个是head用来指向需要移除的元素的位置，一个是i，用来进行遍历，当nums[head-2]不等于nums[i]的时候，就是说明需要进行替换，将下标为head的值换成i的值，如果两者相等，说明i还要继续往下走直到找到一个不相等的值来进行替换



