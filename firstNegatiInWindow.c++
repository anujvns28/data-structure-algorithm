// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void fristNegativeInWindow(int arr[7],int size,int k,vector<int>&ans){
    deque<int>dq;
    for(int i=0;i<size;i++){
        // push nagative index in back side of que
        if(arr[i]<0){
            dq.push_back(i);
        }
        
        // check top element of que is under window or not
        while(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }
        
        // if window is complet then push element in ans
        if(i>=k-1){
            if(!dq.empty()){
                ans.push_back(arr[dq.front()]);
            }else{
                ans.push_back(0);
            }
        }
       
    }
}

int main() {
    int arr[7] = {2,5,4,-1,-2,0,5};
    int size = 7;
    int k = 3;
    vector<int>ans;
    
    fristNegativeInWindow(arr,size,k,ans);
    
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " " ;
    }
    
    
    return 0;
}