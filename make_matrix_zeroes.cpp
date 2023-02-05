#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//Also do optimizing
void sol(vector<vector<int>> matrix){
    int i=matrix.size();
    int j=matrix[0].size();
    for(int a=0;a<i;a++)
        for(int b=0;b<j;b++){
            if(matrix[a][b]==0){
                for(int i1=0;i1<a;i1++)
                    matrix[a][i1]=0;
                for(int i11=0;i11<a;i11++)
                    matrix[i11][b]=0;
            }
        }
    for(int a1=0;a1<i;a1++){
        for(int b1=0;b1<j;b1++){
            cout<<matrix[a1][b1]<<" ";
        }
        cout<<"\n";}
    }


void input(){
    int matrix[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<"\nEnter the value: ";
            cin>>matrix[i][j];
        }
            
    }
}
int main(){
    vector<vector<int>> vect
    {
        {1, 0, 3},
        {4, 5, 6},
        {0, 8, 9}
    };
    //input();
    sol(vect);
    return 0;

}
