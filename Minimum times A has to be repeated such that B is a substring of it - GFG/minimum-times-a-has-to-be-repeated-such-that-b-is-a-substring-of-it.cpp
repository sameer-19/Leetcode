// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
    unordered_map<char,bool> p;
        for(int i=0;i<B.length();i++){
            p[B[i]] = true;
        }
        for(int i=0;i<A.length();i++){
            p[A[i]] = false;
        }
        for(auto h : p){
            if(h.second==true){
                return -1;
            }
        }
        
        int count=1;
        string dum = A;
        int tmp = B.length()/A.length();
        for(int i=1; i<=tmp+2; i++){
            if (A.find(B) != string::npos) return count;
            else{
                A += dum;
                count++;
            }
        }
        return -1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends