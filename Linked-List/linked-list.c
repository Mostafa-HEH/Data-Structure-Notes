#include <stdio.h>
#include <stdlib.h>

// Define Node && Creates first pointer
struct Node {
	int data;
	struct Node *next;
}*first = NULL;

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

int main()
{
	int len, sum, max;
	int a[6] = {14, 15, 26, 17, 18, 19};

	// Create Linked List
	create(a, 6);

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
        max = recursive_max(first);
        printf("%d\n", max);

	return(0);
}
