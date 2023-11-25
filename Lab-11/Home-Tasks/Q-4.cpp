#include <iostream>
#include <string>

using namespace std;


class HashTable 
{
    public:
        int arr[26];

        HashTable() 
        {
            for(int i = 0; i < 26; i++)
            {
                arr[i] = 0;
            }
        }

        int count(char key)
        {
            return arr[key - 'A'];
        }
};

string Q4(string s, string t)
{
    if(s.length() < t.length())
    {
        return "";
    }

    HashTable T;
    HashTable S;

    for(int i = 0; i < t.length(); i++)
    {
        T.arr[t[i] - 'A']++;
    }

    int min = 100000, count = t.length(), a = 0, b = 0, temp = 0;

    while(b < s.length())
    {
        S.arr[s[b] - 'A']++;

        if(T.count(s[b]) > 0 && S.count(s[b]) <= T.count(s[b]))
        {
            count--;
        }
        b += 1;

        while(count == 0)
        {
            S.arr[s[a] - 'A']--;
            
            if(min > b - a)
            {
                min = b -a;
                
                temp = a; 
            }

            if (T.count(s[a]) > 0 && S.count(s[a]) < T.count(s[a]))
            {
                count++;
            }
            a += 1;
        }
    }

    if(min == 100000)
    {
        return "";
    }

    string ans = "";

    for(int i = 0; i < min; i++)
    {
        ans += s[temp];
        temp++;
    }

    return ans;
}
int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << Q4(s, t) << endl;
}

