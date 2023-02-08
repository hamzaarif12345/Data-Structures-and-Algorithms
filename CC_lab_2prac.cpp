#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
int c;
string states="q0";
int main()
{
    string expr;
    cout<<"Enter the expression: ";
    cin>>expr;
    string states="q0";
    for(int i=0;i<expr.length();i++){
        if(states=="q0"){
            if(expr[i]=='0'){
                states="q0";}
            else{
                states="q1";}
        }
        else if(states=="q1"){
            if(expr[i]=='0')
                states="q3";
            else
                states="q2";
        }
        else if(states=="q2"){
            if(expr[i]=='0')
                states="q3";
            else
                states="q2";
        }
        else if(states=="q3"){
            if(expr[i]=='0')
                states="q3";
            else
                states="q3";
        }
        else
            cout<<"Wrong expression";
        c++;
    }
    if(c==expr.length() && (states=="q2" || states=="q3")) {
        cout<<"\nString is accepted";} 
    else{    
        cout<<"\nString is rejected";}
    return 0;
}
