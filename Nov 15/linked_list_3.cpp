#include<iostream>
using namespace std;

class node
{
    public :
        int data;
        node *next;

        // constructor 1st way
        node(int d)
        {
            data = d;
            next = NULL;
        }

        // constructor 2nd way
        // node(int d) : data(d), next(NULL)
        // {
        //     /
        // }
};

int length(node* head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head -> next;
    }
    return cnt;
}

int length_recursive(node* head)
{
    // base case
    if (head == NULL)
    {
        return 0;
    }

    // recursive case
    return 1 + length_recursive(head -> next);
}

void insert_at_front(node* &head, node* &tail, int data)
{
    node *n = new node(data);   // constructor call hoga 

    // if is for when head and tail point to NULL
    if (head == NULL)   // agar abhi tak linked list bana hi nhi
    {
        head = n;
        tail =n;
    }
    else
    {
        n -> next = head;
        head = n;
    }
}

void insert_at_end(node* &head, node* &tail, int data)
{
    node *n = new node(data);   // constructor call hoga 

    if (head == NULL)   
    {
        head = n;
        tail = n;
    }
    else
    {
        tail -> next = n;
        tail = n;
    }
}

void insert_at_any_position(node* &head, node* &tail, int data, int position)
{
    if (position == 0)
    {
        insert_at_front(head, tail, data);
    }
    else if (position >= length(head))
    {
        insert_at_end(head, tail, data);
    }
    else
    {
        node* temp = head;
        node *n = new node(data);
        for (int i = 1; i <= position-1; i++)   // if position 3, i chalega for 1 & 2
        {
            temp = temp -> next;
        }
        n -> next = temp -> next;
        temp -> next = n;
    }
    
}

void delete_at_front(node* &head, node* &tail)
{
    if (head == NULL)   // if linked list is empty
    {
        return;
    }
    else if (head -> next == NULL)  // if we have only one node in linked list
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        node *n = head;
        head = head->next;
        delete n;
    }
    
}

void delete_at_end(node* &head, node* &tail)
{
    if (head == NULL)   // if linked list is empty
    {
        return;
    }
    else if (head -> next == NULL)  // if we have only one node in linked list
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        node *temp = head;
        while (temp -> next != tail)
        {
            temp = temp -> next;
        }
        delete tail;
        tail = temp;
        tail -> next = NULL;    // temp -> next = NULL;
    }
}

void delete_at_any_position(node* &head, node* &tail, int position)
{
    if (position == 0)   // if linked list is empty
    {
        delete_at_front(head, tail);
    }
    else if (position >= (length(head) - 1))  // if we have only one node in linked list
    {
        delete_at_end(head, tail);
    }
    else
    {
        node *temp = head;
        for (int i = 1; i <= position-1; i++)
        {
            temp = temp -> next; 
        }
        node *n = temp -> next;
        temp -> next = n -> next;
        delete n;
    }
}

node *search_iteratively(node *head, node *tail, int key)
{
    while (head != NULL)
    {
        if (head -> data == key)
        {
            return head;
        }
        head = head -> next;
    }
    return NULL;
}

node *search_recursively(node *head, node *tail, int key)
{
    // base case
    if (head == NULL)
    {
        return NULL;
    }
    if (head -> data == key)
    {
        return head;
    }
    
    // recursive case
    return search_recursively(head -> next, tail, key);
}

node *mid(node *head)       // mid point runner technique
{
    if (head == NULL)
    {
        return NULL;    // or return head as it is NULL
    }
    node *fast = head -> next;
    node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

void reverse_linked_list(node* &head)
{
    node *c = head;
    node *prev = NULL;
    node *n = NULL;
    while (c != NULL)       // or while(c)
    {
        n = c -> next;
        c -> next = prev;
        prev = c;
        c = n;
    }
    head = prev;
}

void print_linked_list(node *head)
{
    while (head != NULL)  // or head != tail->next   or head -> != NULL
    {
        cout<<head -> data<<" -> ";
        head = head -> next;
    }
}

node *merge(node *a, node*b)      // a --> 1 3 5      b --> 2 4 6 7
{
    // base case
    if (a == NULL)
    {
        return b;
    }
    else if (b == NULL)
    {
        return a;
    }

    // recursive case
    node *newHead;
    if (a->data < b->data)
    {
        newHead = a;
        node *c = merge(a->next, b);    
        newHead -> next = c;
    }
    else
    {
        newHead = b;
        node *d = merge(a, b->next);    
        newHead -> next = d;
    }
    return newHead;     // newHead me nyi linked list ka head hoga
}

node *mergeSort(node *head)
{
    // base case
    if (head == NULL || head -> next == NULL)
    {
        return head;
    }
    
    // recursive case
    // 1. divide
    node *m = mid(head);
    node *b = head;
    node *c = m -> next;
    m -> next = NULL;

    // 2. sort
    b = mergeSort(b);
    c = mergeSort(c);

    // 3. merge 
    node *fHead = merge(b,c);
    return fHead;
}

bool isCyclic(node *head)   // to check if linked list is cyclic or not
{
    node *fast = head;
    node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
        if (fast == slow)   // linked list is cyclic
        {
            return true;
        }
    }
    return false;
}

void createCycle(node *head)
{
    node *temp = head;
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = head -> next -> next;
}

// or

// void createCycle(node* head, node* &tail)
// {
//     tail -> next = head -> next -> next;
// }

void breakCycle(node *head)     // Floyd Cycle Algorithm
{
    node *fast = head;
    node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
        if (fast == slow)   
        {
            break;
        }
    }

    // take one of the pointers out of slow and fast to head back
    node *prev = head;
    while (prev -> next != fast)
    {
        prev = prev -> next;
    }
    slow = head;
    while (fast != slow)
    {
        prev = fast;
        slow = slow -> next;
        fast = fast -> next;
    }
    prev -> next = NULL;
}

int main()
{
    // // node n1(3);
    // // node n2(4);
    // // n1.next = &n2;
    // // cout<<n1.data<<" "<<(*n1.next).data<<endl;
    // // or 
    // // cout<<n1.data<<" "<<n1.next -> data<<endl;

    // node *head = NULL, *tail = NULL;
    // // INSERTION
    // // insert_at_front(head, tail, data);
    // insert_at_front(head, tail, 1);     // 1
    // insert_at_front(head, tail, 2);     // 2->1
    // insert_at_front(head, tail, 3);     // 3->2->1
    // insert_at_front(head, tail, 4);     // 4->3->2->1
    // insert_at_front(head, tail, 5);     // 5->4->3->2->1
    // print_linked_list(head);

    // cout<<endl;
    // insert_at_end(head, tail, 6);       // 5->4->3->2->1->6
    // insert_at_end(head, tail, 7);       // 5->4->3->2->1->6->7
    // insert_at_end(head, tail, 8);       // 5->4->3->2->1->6->7->8
    // print_linked_list(head);

    // cout<<endl<<"Length of linked list is "<<length(head)<<endl<<endl;
    // insert_at_any_position(head, tail, 70, 2);
    // print_linked_list(head);
    // cout<<endl<<"Length of linked list is "<<length_recursive(head)<<endl<<endl;
    
    // // DELETION
    // delete_at_front(head, tail);
    // cout<<"After deleting at front :-"<<endl;
    // print_linked_list(head);
    // cout<<endl<<endl;

    // delete_at_end(head, tail);
    // cout<<"After deleting at end :-"<<endl;
    // print_linked_list(head);
    // cout<<endl<<endl;

    // delete_at_any_position(head, tail, 4);
    // cout<<"After deleting at position 4 :-"<<endl;
    // print_linked_list(head);
    // cout<<endl<<endl;

    // // SEARCHING    <- two ways - recursively and iteratively
    // node *x = search_iteratively(head, tail, 14);
    // if (x == NULL)
    // {
    //     cout<<"Key not found";
    // }
    // else
    // {
    //     cout<<"Value of node is "<<x->data;
    // }
    // cout<<endl<<endl;

    // node *y = search_recursively(head, tail, 6);
    // if (y == NULL)
    // {
    //     cout<<"Key not found";
    // }
    // else
    // {
    //     cout<<"Value of node is "<<y->data;
    // }
    // cout<<endl<<endl;

    // // MID
    // print_linked_list(head);
    // cout<<endl;
    // node *m = mid(head);
    // if (m == NULL)
    // {
    //     cout<<"Mid not present";
    // }
    // else
    // {
    //     cout<<"Value of node at mid is "<<m->data;
    // }
    // cout<<endl<<endl;

    // // REVERSING
    // reverse_linked_list(head);
    // cout<<"Linked list after reverse is :-"<<endl;
    // print_linked_list(head);

    node *head1 = NULL, *tail1 = NULL;
    insert_at_front(head1, tail1, 6);
    insert_at_front(head1, tail1, 5);
    insert_at_front(head1, tail1, 4);
    insert_at_front(head1, tail1, 3);
    insert_at_front(head1, tail1, 2);
    insert_at_front(head1, tail1, 1);
    print_linked_list(head1);

    cout<<endl;

    node *head2 = NULL, *tail2 = NULL;
    insert_at_front(head2, tail2, 15);
    insert_at_front(head2, tail2, 9);
    insert_at_front(head2, tail2, 8);
    print_linked_list(head2);

    cout<<endl;

    node *finalHead = merge(head1, head2);
    print_linked_list(finalHead);

    cout<<endl<<endl;

    node *head3 = NULL, *tail3 = NULL;
    insert_at_front(head3, tail3, 5);
    insert_at_front(head3, tail3, 42);
    insert_at_front(head3, tail3, 90);
    insert_at_front(head3, tail3, 12);
    insert_at_front(head3, tail3, 75);
    print_linked_list(head3);

    cout<<endl<<"After merge sort :-"<<endl;
    head3 = mergeSort(head3);
    print_linked_list(head3);

    cout<<endl;

    if (isCyclic(head3))
    {
        cout<<"This is cyclic linked list"<<endl;
    }
    else
    {
        cout<<"This is linear (not cyclic) linked list"<<endl;
    }
    
    createCycle(head3);
    cout<<endl;
    if (isCyclic(head3))
    {
        cout<<"This is cyclic linked list"<<endl;
    }
    else
    {
        cout<<"This is linear (not cyclic) linked list"<<endl;
    }

    breakCycle(head3);
    cout<<endl;
    if (isCyclic(head3))
    {
        cout<<"This is cyclic linked list"<<endl;
    }
    else
    {
        cout<<"This is linear (not cyclic) linked list"<<endl;
    }
    print_linked_list(head3);

    return 0;
}
// position will start from index 0