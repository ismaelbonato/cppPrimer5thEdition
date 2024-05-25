#include <deque>
#include <stack>
#include <iostream>

int main ()
{
    const std::string expression{"A (B) ((C (D) ) E) F (G)"}; 
    std::stack<char> s;
    int timeSeen = 0;

    for (auto c : expression) {
        s.push(c);
        if (c == '(') ++timeSeen;
        if (timeSeen && (c == ')')) {
            while(s.top() != '(') { 
                    s.pop();
            }
            s.pop();
            s.push('@');
        }
    }

    std::cout << "times seen (: " << timeSeen << std::endl;
    std::string out;
    while (!s.empty()) {
        out.insert(out.begin(),s.top());
        s.pop();
    }

    std::cout << out << std::endl;
    
    return 0;
}