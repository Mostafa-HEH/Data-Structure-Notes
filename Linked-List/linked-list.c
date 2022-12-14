#include <stdio.h>
#include <stdlib.h>

// Define Node && Creates first pointer
struct Node {
	int data;
	struct Node *next;
}*first = NULL,*second = NULL , *last = NULL;

// Create Nodes
void create(int a[], int n)
{
	int i;
	struct Node *t, *last;
	first = (struct Node *)malloc(sizeof(struct Node));
	first->data = a[0];
	first->next = NULL;
	last = first;

	for (i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = a[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

// Display Nodes
void display(struct Node *p)
{
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

// Recursive Display Nodes
void recursive_display(struct Node *p)
{
	if (p != NULL)
	{
		// For normal order
		// printf("%d\n", p->data);
		// recursive_display(p->next);

		// For Reversed order
		recursive_display(p->next);
		printf("%d\n", p->data);
	}
}

// Nodes Counter
int counter(struct Node *pointer)
{
	int count = 0;
	while (pointer != NULL)
	{
		count++;
		pointer = pointer->next;
	}
	return (count);
}

// Recursive Counter
int recursive_counter(struct Node *pointer)
{
	if (pointer == 0) {
		return (0);
	} else {
		return (recursive_counter(pointer->next) + 1);
	}
}


// Sum all nodes
int sums(struct Node *pointer)
{
	int sum = 0;
	while (pointer != NULL)
	{
		sum = sum + pointer->data;
		pointer = pointer->next;
	}
	return sum;
}


// Recursive Sums
int recursive_sums(struct Node *pointer)
{
	if (pointer == NULL)
		return (0);

	return (recursive_sums(pointer->next) + pointer->data);
}

// Find Max
int get_max(struct Node *pointer)
{
	int max = -32768;
	while (pointer) {
		if (pointer->data > max)
			max = pointer->data;
		pointer = pointer->next;
	}
	return max;
}


// Recursive max
int recursive_max(struct Node *pointer)
{
	int max = -32768;

	if (pointer == 0) {
		return max;
	} else {
		max = recursive_max(pointer->next);
		if (max < pointer->data) {
			return pointer->data;
		} else {
			return max;
		}
	}

	pointer = pointer->next;
}


// Search element
int is_found(struct Node *pointer, int el)
{
	while (pointer != NULL){
		if (pointer->data == el)
			return 1;
		pointer = pointer->next;
	}
	return 0;
}

// Recursive search element
int recursive_is_found(struct Node *pointer, int el)
{
	if(pointer == NULL){
		return 0;
	} else if(pointer->data == el){
		return 1;
	}
	recursive_is_found(pointer->next, el);
}

// Improve search
int search_with_improve(struct Node *pointer, int el)
{
	struct Node *prev = pointer;

        while (pointer != NULL){
                if (pointer->data == el){
			prev->next = pointer->next;
			pointer->next = first;
			first = pointer;
                        return 1;
		}
		prev = pointer;
                pointer = pointer->next;
        }

        return 0;
}

// Iserting before first element
void insert_before_first(struct Node *pointer, int el)
{
	struct Node *new = (struct Node *)malloc(sizeof(struct Node));

	new->data = el;
	new->next = pointer;
	
	first = new;	
}


// Inserting after certen node position
void insert_after(struct Node *pointer, int el, int position)
{
	struct Node *new = (struct Node *)malloc(sizeof(struct Node));
	new->data = el;

	int counter = 0;
	while (pointer != NULL){
		if(counter == position){
			new->next = pointer->next;
			pointer->next = new;
			break;
		}
		counter++;
		pointer = pointer->next;
	}
}

// Create Linked List by inserting
void insert_create(int idx, int el, struct Node *pointer)
{
	struct Node *new = (struct Node *)malloc(sizeof(struct Node));
	new->data = el;

	int i;
	for (i = 0; i < idx - 1; i++) {
		pointer = pointer->next;
	}

	if (idx == 0) {
		new->next = pointer;
		first = new;
	} 
	
	if (idx > 0) {
		new->next = pointer->next;
		pointer->next = new;
	}
}


// Creating a Linked List  by inserting at last
void insert(int el)
{
	struct Node *new = (struct Node *)malloc(sizeof(struct Node));
	new->data = el;
	new->next = NULL;

	if (first == NULL) {
		first = new;
		last = new;
	}

	last->next = new;
	last = new;
}

void insert_sorted(struct Node *pointer, int el)
{
	struct Node *prev = NULL;
	struct Node *new = (struct Node *)malloc(sizeof(struct Node));

	new->data = el;
	new->next = NULL;

	if (first == NULL){
		first = new;
	} else {
		while (pointer && pointer->data < el) {
			prev = pointer;
			pointer = pointer->next;
		}
	
		if (pointer == first) {
			new->next = first;
			first = new;
		} else {
			new->next = prev->next;
			prev->next = new;
		}
	}
}

// Detete First Node
void delete_first()
{
	int arc;
	struct Node *pointer = first;
	first  = first->next;
	arc = first->data;
	free(pointer);
}

// Delete at spacific position
void delete_at(int p)
{
	struct Node *prev, *pointer = first;
	int counter = 1, arc;

	while (p != counter) {
		prev = pointer;
		pointer = pointer->next;
		counter++;
	}

	prev->next = pointer->next;
	arc = pointer->data;
	free(pointer);


}

// Check if the linked list is sorted
int is_sorted(struct Node *pointer)
{
	int x = -32768;

	while (pointer) {
		if (pointer->data < x)
                	return 0;

		x = pointer->data;
                pointer = pointer->next;
	}
	return 1;
}


// Remove duplcates from sorted list
void remove_duplcates(struct Node *pointer)
{
	struct Node *nxt = pointer->next;

	while (nxt != NULL){
		if (pointer->data != nxt->data)
		{
                        pointer = nxt;
                        nxt = nxt->next;
		} else {
                        pointer->next = nxt->next;
                        free(nxt);
                        nxt = pointer->next;
		}
	}
}

// Reverse by element
void reverse_element(struct Node *pointer)
{
	int *arr ,i = 0, counter = 0;
	
	while (pointer != NULL) {
		counter++;
		pointer = pointer->next;
	}

	pointer = first;

	arr = (int *)malloc(sizeof(int) * counter);

	while (pointer != NULL) {
		arr[i] = pointer->data;
		pointer = pointer->next;
		i++;
	}

	pointer = first;
	i--;

	while (pointer != NULL) {
		pointer->data = arr[i];
		pointer = pointer->next;
		i--;
	}
}

// Reverse Linked List by linking
void reverse(struct Node *pointer)
{
	struct Node *follower = NULL, *previous = NULL;

	while (pointer)
	{
		follower = previous;
		previous = pointer;
		pointer = pointer->next;
		previous->next = follower;
	}

	first = previous;
}

// Recusrion Reverse in linked list
void recursion_reverse(struct Node *prev, struct Node *pointer)
{
	if (pointer)
	{
		recursion_reverse(pointer, pointer->next);
		pointer->next = prev;
	} else {
		first = prev;
	}
}


// Concating two linked list
void concating(struct Node *fpointer, struct Node *spointer)
{
	while (fpointer->next != NULL)
		fpointer = fpointer->next;
	fpointer->next = spointer;
	spointer = NULL;
}


// chech if linear or loop
int is_loop(struct Node *pointer)
{
	struct Node *p = pointer, *q = pointer;
	
	do {
		p = p->next;
		q = q->next;
		
		if (q)
			q->next;
	} while (p && q);

	if (p == q) {
		return 1;
	} else {
		return 0;
	}
}


int main()
{
	int len, sum, max;
	int a[6] = {14, 15, 16, 17, 18, 19};

	// Create Linked List
	//create(a, 6);

	// Display data
	//display(first);

	// Recursive Display
	//recursive_display(first);

	// Count The Linked List
	//len = counter(first);
	//printf("%d\n", len);

	// Recursive Counter 
	//len = recursive_counter(first);
	//printf("%d\n", len);

	// Sum of all elements if intgers
	//sum = sums(first);
	//printf("%d\n", sum);

	// Recursive Sums
	//sum = recursive_sums(first);
	//printf("%d\n", sum);

	// Find Max if ingers
	//max = get_max(first);
	//printf("%d\n", max);
	
	// Find Max if ingers
        //max = recursive_max(first);
        //printf("%d\n", max);
	
	// Search element
	//printf("%d\n", is_found(first, 27));
	
	// Recursive search
	//printf("%d\n", recursive_is_found(first, 18));
	
	// Search with improve;
	//printf("is found: %d\n",search_with_improve(first, 17));
	//display(first);
	
	// Insert before first node
	//display(first);
	//insert_before_first(first, 5);
	//printf("---------------------------\n");
	//display(first);
	
        // Insert after certen node
        //display(first);
        //insert_after(first, 5, 3);
        //printf("---------------------------\n");
        //display(first);
	
	// Create by inserting
	//insert_create(0, 20, first);
	//insert_create(1, 21, first);
	//insert_create(2, 22, first);
	//insert_create(1, 23, first);
	//insert_create(3, 24, first);
	//insert_create(0, 25, first);
	//display(first);

	// Insert at last
	//insert(5);
        //insert(6);
        //insert(7);
	//insert(8);
        //insert(50);
        //display(first);
	
	// Insert at last
        //insert_sorted(first, 5);
        //insert_sorted(first, 10);
        //insert_sorted(first, 7);
        //insert_sorted(first, 555);
        //insert_sorted(first, 6);
        //insert_sorted(first, 4);
        //insert_sorted(first, 8);
        //display(first);
	
	// Deleting first node
	//display(first);
	//printf("--------------------------\n");
	//delete_first();
	//delete_first();
	//display(first);
	
	// Delete in spacific position
        //display(first);
        //printf("--------------------------\n");
        //delete_at(4);
	//display(first);
	
	// Is it the linked list sorted
	//printf("%d\n", is_sorted(first));
	
	// Remove duplcate from sorted linked list
	//display(first);
	//printf("--------------------------\n");
	//remove_duplcates(first);
	//printf("--------------------------\n");
	//display(first);

	// Reverse Linked list by element
	//display(first);
	//printf("--------------------------\n");
	//reverse_element(first);
	//display(first);
	
	// Reverse Linked list by links
        //display(first);
        //printf("--------------------------\n");
        //reverse(first);
        //display(first);
	
        // Reverse Linked list with recursion
        //display(first);
        //printf("--------------------------\n");
        //recursion_reverse(NULL, first);
        //display(first);
	
	// Conating two lists
	printf("First---------------\n");
	insert_sorted(first, 5);
	insert_sorted(first, 6);
	insert_sorted(first, 7);
	insert_sorted(first, 8);
	insert_sorted(first, 9);
	display(first);
	printf("Second---------------\n");
	second = (struct Node *)malloc(sizeof(struct Node));
	second->data = 15;
	second->next = NULL;
	display(second);
	printf("First with Second---------------\n");
	concating(first, second);
	display(first);
	printf("---------------\n");
	display(second);

	return(0);
}
