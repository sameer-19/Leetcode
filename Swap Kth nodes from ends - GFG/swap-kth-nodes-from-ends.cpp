// { Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node* head, int num, int K)
{
    if(num<K)
        return head;
    //step - 1
    Node *dummy=new Node(0),*p1,*p2,*prev1,*prev2;
    dummy->next=head;
    p1=p2=prev1=dummy;
    int a=K;
    while(a>0 &&  a--)
    {
        prev1=p1;
        p1=p1->next;
    }
    a=num-K+1;
    while(a--)
    {
        prev2=p2;
        p2=p2->next;
    }
    //step-2
    if(prev2==p1)	//case (i)
    {
        prev1->next=p2;
        p1->next=p2->next;
        p2->next=p1;
    }
    else    		//case (ii)
    {
        Node *temp=p1->next;
        prev1->next=p2;
        prev2->next=p1;
        p1->next=p2->next;
        prev2->next=p1;
        p2->next=temp;
    }
    return dummy->next;
}
