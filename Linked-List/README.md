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
* We can display nodes by Recusive display as the example
```
void display(struct Node *pointer)
{
	if (pointer != 0)
	{
		printf("%d", pointer->data);
		display(pointer->next);
	}
}
```
This will print element in normal order, *But* if we call function before print it will prit as order as function calls on the stack recursonly, it will be reversed order as the example
```
void display(struct Node *pointer)
{
        if (pointer != 0)
        {
                display(pointer->next);
		printf("%d", pointer->data);
        }
}
```

### Count nodes in linked list:
it's good to loop in linked list and count nodes `WHILE` Node `!=` `NULL` or `0`
```
counter = 0;
while (pointer != null)
{
	counter++;
	pointer = pointer->next;
}
printf("%d", counter);
```
So on Recursive count function
```
int counter(struct Node *pointer)
{
        if (pointer == 0) {
                return (0);
        } else {
                return (counter(pointer->next) + 1);
        }
}
```
why  `return (counter(pointer->next) + 1);` not  `return (1 + counter(pointer->next));` ?
the addion sould be done after function return and if before it will be 1 + null


### Search in Linked List
* There are two typs of search (linear search and binary search), and with linked list we can only use linear search beacause we cannot reach the middle of the nodes.
* Search is looping to reach the last `NULL` value if the element is found `Return ture` else `Return false`.
* There are two ways to improve search in the linked list (Transposition - move to the Head).
> Move to the Head : by moveing the search element to the begin of the list and to do this process:
>> we need current Node and previous Node
>> to get previous node we need to create a pointer to follow the current pointer.


### Inserting elements in Linked list
* linked list are sorted as 1,2,3...etc index so i can insert element in any positions before first, after third , at last ...etc
* So we have two strtatigies (before certen node, after certen node).


### Creating Linked List using insert
we can create a linked list with iserting function too but we should be shure first we added the 0 index Node and add valied index

### Creating a Linked List by inserting at last Node
* Alway last Node have next of `NULL` so we can reach last by create new node and make last Node next ref to the new one
* Also create element saves last node will be good and help.

### Deleting from linked list
The common senarios for deleting (delete the firt node, delete a node at given position)* For first case -Delete first Node- :
> will change the pointer first to the next node, by this the first node cannot be reached any more but it will still located at the memory, so be sure you unlocate the Node.

### Delete duplcated elements
can delete the second duplcate element by compare the next elemnts and if need use sort function

### Reversing a linked list
we can reverse a linked list in two ways (reversing elemnts, reversing links).
> First -> Reversing elements by changes the first Node data to contain last Node data and last node containe first node data and so on.
and to Tod this:
>> create an array and copy elements to them, then copy it again to Nodes list. So it's not an effecient way because it needs extra space for the array
> Second on -> reversing links by make the next link to the previous.
**It's recommended the second way with linked list**
>> **Revesring using sliding** : by three pointers(follower, previous, pointer) with this same order. so pointer is current ellement and previous is the previous element to current element and at last follower is the previous for previous.
so we need pointer and previous to change lead from previous -> pointer into previous -> follower.
>> **Reversing by recusring** call function it selfe with current and previous function.

### Concating Linked Lists
Concating simply means to appened one list to other, for example we have two lists so we need to reach the last of the firt one and make it points to the first in the second list.
