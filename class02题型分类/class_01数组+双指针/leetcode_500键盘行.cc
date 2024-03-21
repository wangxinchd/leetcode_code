
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// 打印二维vector
void
print_vector_string(vector<string> words)
{
    cout << "打印字符串数组\n";
    for (auto word:words)
    {
            printf("%s, ", word.c_str());
    }
    printf("===end===\n");
    fflush(NULL);
}

void
print_uset_char(unordered_set <char> & uset)
{
    for (auto it : uset)
    {
        cout << it << ", ";
    }
    cout << endl;
}

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ret;
        unordered_set <char> line1;
        unordered_set <char> line2;
        unordered_set <char> line3;

        unordered_set <char> *tmp;

        string str1 = "qwertyuiop";
        string str2 = "asdfghjkl";
        string str3 = "zxcvbnm";

        for (int i = 0; i < (int) str1.length(); i++)
        {
            line1.insert(str1[i]);
            line1.insert(str1[i] - ('a' - 'A'));
        }
        for (int i = 0; i < ( int )str2.length(); i++)
        {
            line2.insert(str2[i]);
            line2.insert(str2[i] - ('a' - 'A'));
        }
        for (int i = 0; i < ( int )str3.length(); i++)
        {
            line3.insert(str3[i]);
            line3.insert(str3[i] - ('a' - 'A'));
        }

        for (int i = 0; i < ( int )words.size(); i++)
        {
            if (line1.find(words[i][0]) != line1.end())
            {
                tmp = &line1;
            }
            else if (line2.find(words[i][0]) != line2.end())
            {
                tmp = &line2;
            }
            else
            {
                tmp = &line3;
            }

            bool is_exist = true;
            for (int j = 0; j < ( int )words[i].size(); j++)
            {
                if (tmp->find(words[i][j]) == tmp->end())
                {
                    is_exist = false;
                    break;
                }
            }

            if (is_exist)
            {
                ret.push_back(words[i]);
            }
        }

        return ret;
    }
};


int
main(int argc, char **agrv)
{
    Solution solution;
    // vector<string> words = {"hello","alaska","dad","peace"};
    vector<string> words = {"Hello","Alaska","Dad","Peace"};
    print_vector_string(solution.findWords(words));

    return 0;
}