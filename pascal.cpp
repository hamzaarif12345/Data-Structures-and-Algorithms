#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"\nEnter the value of n:  ";
    int a;
    cin>>a;
    int m[a][a];
    m[0][0]=1;
    for(int i=0;i<a;i++){  
        m[i][0]=m[i][i]=1; 
        
        for(int j=1;j<i;j++){
            
            //m[i][j]=m[i-1][j-1]+m[i-1][j];
            if(m[i-1][j-1] && m[i-1][j])
                m[i][j]=m[i-1][j-1]+m[i-1][j];
            else if(m[i-1][j])
                m[i][j]=m[i-1][j];
            else if(m[i-1][j-1])
                m[i][j]=m[i-1][j-1];
            else 
                m[i][j]=0;
            
            //cout<<m[i][j]<<" ";
        }
        //cout<<"\n";}
        
    }
    for(int i1=0;i1<=a;i1++){
        for(int j1=0;j1<=i1;j1++){
            cout<<m[i1][j1]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}