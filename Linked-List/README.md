# Linked List

### Why Linked List?
**Problems with Array:**
 Array is fixed size, and when we initial arrays we cannot increse or decrese its size. and **This is a problem** because we may build project for normal users and we can not expect how much data exactaly they will mipulate with. 
So **if we don't know how many elements will be stored** it means that we need linked list.

### What is Linked List and Node?
 Linked list is a collection of Nodes and each **Node** contains a data and pointer to next Node

| Data | Next |
| :-----: |:----:|
| Data will be stored | Pointer to next Node |

### How to define Node and add data - in pseudo code:
* We have to define two things 
    * Data "It will be any type"
    * Pointer "It will be a nood type"
* To define node in C language `struct Node`
```
struct Node {
    int data;                // Can be used any type
    struct Node *next;       // It have Node Type "Self Referencal structure"
}
```
* Node creates in the Heap so we need a pointer in the stack
```
struct Node *pointer;
```
* Create Node in the Heap wit malloc function
```
pointer = (struct Node *)malloc(sizeof(struct Node));
// now we created node in the heap and pointer points to that
```
* Store Data to the Node
```
pointer->data = 14;
pointer->next = 0;
```

### How to access data - in pseudo code:
* If need to access next node
```
element = pointer;
element = pointer->next;
```
* Making first node `NULL` will make you easly know that is the linked list have node's or not.
```
struct Node *pointer = Null;
// We can check if the list have node's or not easly now
if (pointer == NULL)
```
* To know That you reached the last node on the list, you can be sure that the next of the last node is `NULL` or `0`
```
// To check if the last element
if (pointer->next == NULL)
```
* To display all data, use `while` loop because you don't know how many nodes there so you need loop until the last command becomes true
```
struct Node *pointer = first;
while (pointer != 0)
{
    printf("%d", pointer->data);
    pointer = pointer->next;
}
```
