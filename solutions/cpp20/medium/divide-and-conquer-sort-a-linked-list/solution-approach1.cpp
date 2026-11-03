// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/divide-and-conquer-sort-a-linked-list/problem?isFullScreen=true
// Problem     Divide and Conquer - Sort a Linked List
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 08:05 a.m.
// ──────────────────────────────────────────────────



#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* mergeLists(Node* a, Node* b)
{
    if (a == NULL)
        return b;

    if (b == NULL)
        return a;

    if (a->data <= b->data)
    {
        a->next = mergeLists(a->next, b);
        return a;
    }
    else
    {
        b->next = mergeLists(a, b->next);
        return b;
    }
}

Node* mergeSort(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* second = slow->next;
    slow->next = NULL;

    Node* first = mergeSort(head);
    second = mergeSort(second);

    return mergeLists(first, second);
}

int main()
{
    int n;
    cin >> n;

    if (n == 0)
    {
        cout << "Empty";
        return 0;
    }

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = mergeSort(head);

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
