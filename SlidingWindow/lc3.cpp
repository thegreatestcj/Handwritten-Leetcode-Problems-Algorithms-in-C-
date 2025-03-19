#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

string longestSubstring(string str)
{
    size_t n = str.size();
    string res = "";
    size_t maxLength = 0;

    if (n == 0) {
        return res;
    }

    size_t left = 0;
    size_t start = 0;
    map<char,int> mp;

    for (size_t right = 0; right < n; right++) {
        char ch = str[right];
        if (mp.count(ch) && mp[ch] >= left)
        {
            left = mp[ch] + 1;
        }

        mp[ch] = right;
        // The map should record the nearest duplicate
        // to the current index.
        if (right - left + 1 > maxLength) {
            maxLength = right - left + 1;
            start = left;
        }

    }

    res = str.substr(start, maxLength);

    return res;
}

void test() {
    string s0 = "";
    cout << "Edge case: empty string, Result: ";
    cout << s0 << endl;

    string s1 = "a";
    cout << "Edge case: single char, Result: ";
    cout << s1 << endl;

    vector<string> vec;
    vec.emplace_back("abcdefg");
    vec.emplace_back("rhsyjskkkk");
    vec.emplace_back("ooooooooo");
    vec.emplace_back("ggggglsadrew");

    for (const auto& s : vec)
    {
        string res = longestSubstring(s);
        cout << "Case: " << s << ", Result: " << res << endl;
    }
}

int main() {
    test();
    return 0;
}