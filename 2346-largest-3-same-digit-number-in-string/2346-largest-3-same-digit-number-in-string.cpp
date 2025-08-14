class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for (int i = 1; i < num.size() - 1; i++) {
            if (num[i - 1] == num[i] && num[i] == num[i + 1]) {
                string ans1 = num.substr(i - 1, 3);
                if (ans1 > ans)
                    ans = ans1;
            }
        }
        return ans;
    }
};
