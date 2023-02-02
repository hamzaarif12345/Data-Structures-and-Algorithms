#include<bits/stdc++.h>
using namespace std;

int merge(int arr[10],int l,int mid, int h){
    int n1=mid-l+1;
    int n2=h-mid;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++){
        left[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++){
        right[j]=arr[mid+1+j];
    }
    int i=0,j=0;
    int k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }
        else {
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=right[j];
        j++;
        k++;
    }
}

int  merges(int arr[10],int l,int h){
    if(l<h){
        int mid =(l+h)/2;
        merges(arr,l,mid);
        merges(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
    return arr[10];
}

int main(){
    int arr[]={20,30,40,10,50,1,2,3,4,5};
    int k1=sizeof(arr)/sizeof(arr[0]);
    cout<<k1<<"\n\n\n";
    arr[k1]=merges(arr,0,9);
    for(int i=0;i<k1;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}