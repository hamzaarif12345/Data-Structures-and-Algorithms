class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int i=0;
        int j=searchWord.size();
        string temp;
        for(auto a: sentence){
            if(isalpha(a)){
                temp+=a;
                //ptemp+=a;
            }
            else {
                if(temp.size()!=0) i++;
                if (temp.find(searchWord) != std::string::npos && temp.substr(0,j)==searchWord) {
                        return i; // Replace this with desired logic for found case
                }
                //ptemp=temp;
                temp="";
            }
        }
        if (temp.find(searchWord) != std::string::npos && temp.substr(0,j)==searchWord ) {
                        return ++i; // Replace this with desired logic for found case
                }
        return -1;
    }
};