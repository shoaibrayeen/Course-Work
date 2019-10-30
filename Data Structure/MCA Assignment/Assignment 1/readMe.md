### Q1 (STACK): On a given machine, how do you check whether the stack grows up or down?
Hint: Use address of variables

### Q2 (QUEUE): Given a stack of integers, how do you check whether each successive pair of
### numbers in the stack is consecutive or not. The pairs can be increasing or decreasing, and if
### the stack has an odd number of elements, the element at the top is left out of a pair. For
### example , if the stack of elements are [ 4,5,-2,-3,11,10,5,6,20] , then the output should be
### true because each of the pairs (4,5), (-2,-3),(11,10) and (5,6) consist of consecutive numbers.
Hint: Use STL stack and STL queue

### Q3 (LINKEDLIST): Reverse the linked list in pairs. For example a linked list 1-> 2-> 3 -> 4 -> 5,
### then after the function has been called the linked list must be 2-> 1->4 -> 3 -> 5.
Note: Write either a recursive or a iterative function

### Q4 (LINKEDLIST): Split a circular linked list into two equal parts circular linked lists. If the
### number of nodes in the list are odd then make first list with one extra node than second list.
Hint: Use the Floyd cycle finding algorithm

### Q5(LINKEDLIST): N people have decided to elect a leader by arranging themselves in a circle
### and eliminating every Mth person around the circle, closing the ranks as each person drops
### out. Find which person will be the last one remaining (with rank 1).
Hint: N people form a circular linked list of N nodes

### Q6 (BINARYTREE): Given a binary tree, print out all its root –to –leaf paths.
Hint: Using array to store path
### Or

### Given a binary tree, give an algorithm for checking the existence of path with given sum.
### That means, given a sum check whether there exists a path from root to any of the nodes.
Hint: Subtract the node value from the sum before calling its children
