// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    Node * greater = NULL, *greater_head = NULL ; 
    Node * smaller = NULL, *smaller_head = NULL ;
    Node * equal   = NULL, *equal_head   = NULL ; 
    while(head){
        if(head -> data > x)
            (greater) ? greater = greater -> next = head  : greater = greater_head = head ;
        else if(head -> data == x)
            (equal)   ? equal   = equal   -> next = head  : equal   = equal_head   = head ;
        else
            (smaller) ? smaller = smaller -> next = head  : smaller = smaller_head = head ;
        head = head -> next ; 
    }
    if(greater){
        greater -> next = NULL ;
    }
    if(equal){
        equal   -> next = greater_head ;
        greater_head    = equal_head  ;
    }
    if(smaller){
        smaller -> next = greater_head ;
        greater_head    = smaller_head ;
    }
    return greater_head;
}