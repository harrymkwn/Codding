#include <bits/stdc++.h>
using namespace std;

string longestPalindromicSubstring(string str)
{
    int j = 0;
    int max = 0;
    int start = 0, end = 0;
    for (int i = 0; i < str.size(); i++)
    {
        j = 0;
        while (i + j < str.size() && i - j >= 0 && str[i + j] == str[i - j])
        {
            j++;
        }
        if (max < j * 2 + 1)
        {
            max = 2 * j + 1;
            start = i-j+1;
            end = i+j-1;
        }
        if (str[i] == str[i + 1])
        {
            j = 0;
            while (i + j + 1 < str.size() && i - j >= 0 && str[i + 1 + j] == str[i - j])
            {
                j++;
            }
            if (max < j * 2 + 2){
                max = 2 * j + 2;
                start = i-j+1;
                end = i+j + 1;
            }
        }
    }
    return str.substr(start,max-2);
} /* O(n^2) time | O(1) space */


int main(){
    string str = "abcbaxyzyxabc";
    cout<<longestPalindromicSubstring(str)<<"\n";

    return 0;
}