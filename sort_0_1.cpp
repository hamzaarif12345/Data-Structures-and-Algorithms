#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

vector<int> sol(){
    vector<int> arr={2,0,1,0,2,1,0,1,2,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    int lo=0;
    int mid=0;
    int hi=arr.size()-1;
    while (mid <= hi) { 
            switch (arr[mid]) { 

            // If the element is 0 
            case 0: 
                swap(arr[lo++], arr[mid++]); 
                break; 

            // If the element is 1 . 
            case 1: 
                mid++; 
                break; 

            // If the element is 2 
            case 2: 
                swap(arr[mid], arr[hi--]); 
                break; 
            }
        }

    for(int j=0;j<10;j++){
        cout<<arr[j]<<" ";}
    return arr;
}
int main(){
    //vector<int> arr={2,0,1,0,2,1,0,1,2,0};
    
    sol();
    
    return 0;
}