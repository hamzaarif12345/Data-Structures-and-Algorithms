#include<iostream>
#include<bits/stdc++.h>
using namespace std;
char arr[100],arr1[100],b[100][100];
int c[100][100]={0};

/*void print(char b1[][100],char a[],int i,int j ){
    
    if(i==0 & j==0){
        return ;
    }
    if(b1[i][j]=='d'){
        print(b1,a,i-1,j-1);
        cout<<a[i];
    }
    else if(b1[i][j]=='u'){
        print(b1,a,i-1,j);
    }
    else{
        print(b1,a,i,j-1);
    }
}*/
int main(){
    
    cout<<"Enter the size of array 1: ";
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        cout<<"Enter the element ";
        cin>>arr[i];
    }
    
    cout<<"Enter the size of array 2: ";
    int a1;
    cin>>a1;
    for(int i=0;i<a1;i++){
        cout<<"Enter the element ";
        cin>>arr1[i];
    }
    int m=a;
    int n=a1;
    for(int i=0;i< m;i++){
        c[i][0]=0;
        }
    for(int j=0;j<n;j++){
        c[0][j]=0;
    }
    for(int i =0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i]==arr1[j]){
                c[i][j]=c[i-1][j-1] + 1;
                b[i][j]='d';
            }
            else if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]='u';
            }
            else{
                c[i][j]=c[i][j-1];
                b[i][j]='l';
            }
        }
    }
    cout<<"Printing the array c:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<" "<<c[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"Printing the array b:\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<" "<<b[i][j]<<" ";
        }
        cout<<"\n";
    }
    int index = c[m][n];
    char lcsAlgo[index + 1];
    lcsAlgo[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (arr[i - 1] == arr1[j - 1]) {
            lcsAlgo[index - 1] = arr[i - 1];
            i--;
            j--;
            index--;
    }

    else if (c[i - 1][j] > c[i][j - 1])
      i--;
    else
      j--;
  }
  
    // Printing the sub sequences
    cout << "S1 : " << arr << "\nS2 : " << arr1 << "\nLCS: " << lcsAlgo << "\n";
    
    //cout<<"\nThe common same sequence: ";
    //print(b,arr,0,m);

    /*cout<<"\nThe required string is:";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(b[i][j]=='d'){
                cout<<arr[i];
            }
        }
        
    }*/

    return 0;
}