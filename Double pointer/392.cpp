#include <string>
using namespace std;
class Solution {
    public:
        bool isSubsequence(string s, string t) {
            int m = 0;
            for(char i : t) {
                if(i == s[m]) {
                    m++;
                }
            }
            if(m == s.size()) {
                return true;
            }
            else {
                return false;
            }
        }
    };
//进阶挑战：如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？
//思路：将长字符串分解，构造一个26*长字符串长度的二维数组，每一列有26行，每行都记录了该行对应的字符要出现的下一个位置，如果为本行字母则为0,r
//如果以后都没有这个字符则设置为-1,遍历短字符串，从一个字符跳到下一个字符，直到字符遍历完成或遇到-1