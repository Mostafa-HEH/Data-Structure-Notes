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

int main()
{
	int a[6] = {14, 15, 16, 17, 18, 19};

	// Create Linked List
	create(a, 6);

	// Display data
	display(first);

	// Recursive Display
	recursive_display(first);

	return(0);
}
