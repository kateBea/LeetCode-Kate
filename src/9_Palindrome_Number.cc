#include <stack>
using namespace std;

class Solution {
public:
    
    int howManyDigits(int x)
    {
        if (x%10 == x) return 1;
        else return 1+howManyDigits(x/10);
    }
    
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        bool isPal = true;
        stack<int> pila;
        int leng = howManyDigits(x);
        
        int i = 0;
        while (i < leng/2) {
            pila.push(x%10);
            x/=10;
            ++i;
        }
        if (leng%2 != 0) x/=10;
        while (i < leng and isPal and not pila.empty()) {
            if (pila.top() != x%10) isPal = false;
            pila.pop();
            x/=10;
            ++i;
        }
        return isPal;
    }
};
