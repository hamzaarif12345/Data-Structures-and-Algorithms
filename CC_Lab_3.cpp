#include <iostream>
#include <fstream>
#include <regex>
#include<string>

using namespace std;

int main() {
    string filename;
    cout << "Enter file name: ";
    getline(cin, filename);

    ifstream file(filename);
    string line;
    int token_count = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find("#include") != string::npos) {
                continue;
            }
            if (line[0] == '#') {
                continue;
            }
            if(line.find("//") != string::npos){
                continue;
            }
            if(line.find("/*") != string::npos){
                continue;
            }
            if(line.find("*/") != string::npos){
                continue;
            }
            if(line.find("::") != string::npos){
                token_count--;
            }
            if(line.find(">>") != string::npos){
                token_count--;
            }
            if(line.find("<<") != string::npos){
                token_count--;
            }
            if(line.find("->") != string::npos){
                token_count--;
            }
            if(line.find("++") != string::npos){
                token_count--;
            }
            if(line.find("--") != string::npos){
                token_count--;
            }
            if(line.find("==") != string::npos){
                token_count--;
            }
            if(line.find("!=") != string::npos){
                token_count--;
            }
            if(line.find("<=") != string::npos){
                token_count--;
            }
            if(line.find(">=") != string::npos){
                token_count--;
            }
            if(line.find("&&") != string::npos){
                token_count--;
            }
            if(line.find("||") != string::npos){
                token_count--;
            }
            if(line.find("+=") != string::npos){
                token_count--;
            }
            if(line.find("-=") != string::npos){
                token_count--;
            }
            if(line.find("*=") != string::npos){
                token_count--;
            }
            if(line.find("/=") != string::npos){
                token_count--;
            }
            if(line.find("%=") != string::npos){
                token_count--;
            }
            if(line.find("&=") != string::npos){
                token_count--;
            }
            if(line.find("|=") != string::npos){
                token_count--;
            }
            if(line.find("^=") != string::npos){
                token_count--;
            }
            if(line.find("<<=") != string::npos){
                token_count--;
            }
            if(line.find(">>=") != string::npos){
                token_count--;
            }
            
            #include <iostream>
#include <fstream>
#include <regex>

using namespace std;

int main() {
    string filename;
    cout << "Enter file name: ";
    getline(cin, filename);

    ifstream file(filename);
    string line;
    int token_count = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find("#include") != string::npos) {
                continue;
            }
            if (line[0] == '#') {
                continue;
            }
            if(line.find("//") != string::npos){
                continue;
            }
            if(line.find("/*") != string::npos){
                continue;
            }
            if(line.find("*/") != string::npos){
                continue;
            }
            if(line.find("::") != string::npos){
                token_count--;
            }
            if(line.find(">>") != string::npos){
                token_count--;
            }
            if(line.find("<<") != string::npos){
                token_count--;
            }
            if(line.find("->") != string::npos){
                token_count--;
            }
            if(line.find("++") != string::npos){
                token_count--;
            }
            if(line.find("--") != string::npos){
                token_count--;
            }
            if(line.find("==") != string::npos){
                token_count--;
            }
            if(line.find("!=") != string::npos){
                token_count--;
            }
            if(line.find("<=") != string::npos){
                token_count--;
            }
            if(line.find(">=") != string::npos){
                token_count--;
            }
            if(line.find("&&") != string::npos){
                token_count--;
            }
            if(line.find("||") != string::npos){
                token_count--;
            }
            if(line.find("+=") != string::npos){
                token_count--;
            }
            if(line.find("-=") != string::npos){
                token_count--;
            }
            if(line.find("*=") != string::npos){
                token_count--;
            }
            if(line.find("/=") != string::npos){
                token_count--;
            }
            if(line.find("%=") != string::npos){
                token_count--;
            }
            if(line.find("&=") != string::npos){
                token_count--;
            }
            if(line.find("|=") != string::npos){
                token_count--;
            }
            if(line.find("^=") != string::npos){
                token_count--;
            }
            if(line.find("<<=") != string::npos){
                token_count--;
            }
            if(line.find(">>=") != string::npos){
                token_count--;
            }
            
            regex token_regex("[a-zA-Z_][a-zA-Z_0-9]*|[0-9]+|[(){};,::]|[+\\-*/=<>]|[^ \t\r\n]]");
            sregex_iterator iter(line.begin(), line.end(), token_regex);
            sregex_iterator end;
            for (; iter != end; ++iter) {
                string token = iter->str();
                token_count ++;
            }
        }
        file.close();
        cout << "Number of tokens: " << token_count << endl;
    } 
    else {
        cout << "Unable to open file" << endl;
    }
    return 0;
}

        }
        file.close();
        cout << "Number of tokens: " << token_count << endl;
    } 
    else {
        cout << "Unable to open file" << endl;
    }
    return 0;
}
