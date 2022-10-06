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

int main()
{
	int len;
	int a[6] = {14, 15, 16, 17, 18, 19};

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
	len = recursive_counter(first);
	printf("%d\n", len);

	return(0);
}
