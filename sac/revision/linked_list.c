#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};
typedef struct node Node;

struct linkedList
{
    Node *head;
    Node *tail;
};
typedef struct linkedList LinkedList;

Node *new_node(int val);
void print_ll(LinkedList *ll);
void insert_sorted(LinkedList *ll, int value);

int main()
{
    // new ll
    LinkedList *ll = malloc(sizeof(LinkedList));

    // initializing linked list
    ll->head = new_node(0);
    int i = 1;
    Node *curr = ll->head;
    while (i < 5)
    {
        Node *n = new_node(i * 10);
        curr->next = n;
        curr = curr->next;
        i++;
    }

    // normal operation
    printf("sorted ll\n");
    print_ll(ll);

    printf("insert 15 to middle\n");
    insert_sorted(ll, 15);
    print_ll(ll);

    // empty list
    printf("\ninsert empty list\n");
    LinkedList *el = malloc(sizeof(LinkedList));
    insert_sorted(el, 10);
    print_ll(el);

    // new smallest
    printf("\ninert new smallest\n");
    insert_sorted(el, 3);
    print_ll(el);

    // new largest
    printf("\ninert new largest\n");
    insert_sorted(el, 20);
    print_ll(el);

    // free linked list
    return 0;
}

// init new node
Node *new_node(int val)
{
    Node *n = malloc(sizeof(Node));
    n->val = val;
    n->next = NULL;
    return n;
}

// print ll
void print_ll(LinkedList *ll)
{
    Node *c = ll->head;
    while (c != NULL)
    {
        printf("%d -> ", c->val);
        c = c->next;
    }
    printf("NULL\n");
}

// insert a node inorder in a sorted linked list
void insert_sorted(LinkedList *ll, int value)
{
    Node *insert_this = new_node(value);
    Node *curr = ll->head;

    // handle empty list
    if (curr == NULL)
    {
        ll->head = insert_this;
    }

    // normal operation
    while (curr != NULL)
    {
        // new smallest
        if (curr->val > value)
        {
            ll->head = insert_this;
            insert_this->next = curr;
            return;
        }

        // new largest
        if (curr->next == NULL && value > curr->val)
        {
            ll->tail = insert_this;
            curr->next = insert_this;
            return;
        }

        // normal transpose
        if (curr->val < value && value <= curr->next->val)
        {
            printf("%d\n", curr->next->val);
            insert_this->next = curr->next;
            curr->next = insert_this;
            return;
        }

        curr = curr->next;
    }
}