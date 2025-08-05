class Solution {
  public:
    bool isPalinSent(string &s) {
    string b = "";
    
    for (char a : s) {
        if (isalpha(a)) {
            b += tolower(a);  // convert to lowercase for uniformity
        }
        if(isdigit(a)) b+=a;
    }

    //cout << b << " ";

    int i = 0, j = b.size() - 1;
    while (i < j) {
        if (b[i] != b[j]) return false;
        i++; j--;
    }

    return true;
}

};