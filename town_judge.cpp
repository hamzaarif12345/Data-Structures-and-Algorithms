/*
In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

 

Example 1:

Input: n = 2, trust = [[1,2]]
Output: 2
know  we are
Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
*/
class Solution {
public:
    int count(vector<int> b, int a){int c1=0;
        for( auto c: b){ if (c==a) c1++;}
        return c1;
    }
    int findJudge(int n, vector<vector<int>>& trust) {
        //int ans=-1;
        if(n==1 && trust.size()==0) return 1;
        vector<int> a;
        vector<int> b;
        for(int i=0;i<trust.size();i++){
            a.push_back(trust[i][0]);
            b.push_back(trust[i][1]);
        }
        for(int i=0;i<b.size();i++){
            if(find(a.begin(),a.end(),b[i])==a.end()  && count(b,b[i])==n-1) return b[i];
            

        }
        return -1;
        
    }
};