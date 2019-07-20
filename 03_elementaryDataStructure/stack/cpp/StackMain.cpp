#include <iostream>
#include <sstream>
#include "Stack.h"

/** compile-time logging functions for convenient **/
template<typename Arg>
constexpr void LOG(Arg && arg) {
    std::cout << arg << "\n";
}

template<typename Arg1, typename Arg2>
constexpr void LOG2(Arg1 && arg1, Arg2 && arg2) {
    std::cout << arg1 << arg2 << "\n";
}

template<typename Arg1, typename Arg2, typename Arg3>
constexpr void LOG3(Arg1 && arg1, Arg2 && arg2, Arg3 && arg3) {
    std::cout << arg1 << arg2 << arg3 << "\n";
}
/** end of logging functions **/

struct Data {
    int val;

    inline friend std::ostream& operator <<(std::ostream& out, const Data& d) {
        out << "val: " << d.val;
        return out;
    }
};

/**
 * Convert fully parenthesized infix expression to postfix expression.
 */
std::string ConvertToPostfix(const std::string& infix) {
    std::stringstream ss;
    Stack<char> ts;

    for (auto it = infix.begin(); it != infix.end(); ++it) {
        char c = *it;

        if (c == '+' ||
            c == '-' ||
            c == '*') {
           ts.Push(c); 
        } 
        else if (c >= '0' && c <= '9') {
            ss << c << " ";
        }
        else if (c == ')') {
            ss << ts.Pop() << " ";

            // if it's the last element
            if (it == infix.end() - 1) {
                while (!ts.IsEmpty()) {
                    ss << ts.Pop();
                }
            }
        }
    }

    // usually if you check pointer address of ss.str() via std::addressof()
    // and with normal compilation flags of gcc, it will be the same externally
    // at the call site. This is because of RVO (return value optimization).
    // We can disable it via -fno-elide-constructors
    return ss.str();
}

/**
 * Compute result from value from postfix expression.
 */
int ComputePostfix(const std::string& postfix) {
    Stack<int> ts;

    for (const char c : postfix) {
        if (c >= '0' && c <= '9') {
            ts.Push(static_cast<int>(c-'0'));
        }
        else if (c == '+') {
            ts.Push((ts.Pop() + ts.Pop()));
        }
        else if (c == '-') {
            ts.Push((ts.Pop() - ts.Pop()));
        }
        else if (c == '*') {
            ts.Push((ts.Pop() * ts.Pop()));
        }
    }

    return ts.Pop();
}


int main() {
    /** Testing section **/
    Stack<int> s;
    s.Push(1);
    s.Push(2);

    LOG(s.Pop());
    LOG2(std::boolalpha, s.IsEmpty());
    LOG(s.Pop());
    LOG2(std::boolalpha, s.IsEmpty());

    Stack<Data> s2;
    s2.Push(Data {100});
    s2.Push(Data {200});

    LOG(s2.Pop());
    LOG2(std::boolalpha, s.IsEmpty());
    LOG(s2.Pop());
    LOG2(std::boolalpha, s.IsEmpty());

    std::cout << "\n";

    /** Infix/Postfix and its calculation **/
    const std::string infix ( "5 * (((9+8) * (4*6)) + 7)" );
    const std::string postfix = ConvertToPostfix(infix);
    
    LOG2("Postfix: ", postfix);

    int result = ComputePostfix(postfix);
    LOG2("Result: ", result);

    std::cout << std::endl;

    return 0;
}
