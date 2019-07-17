#include <iostream>
#include "Stack.h"

struct Data {
    int val;

    inline friend std::ostream& operator <<(std::ostream& out, const Data& d) {
        out << "val: " << d.val;
        return out;
    }
};


int main() {
    Stack<int> s;
    s.Push(1);
    s.Push(2);
    std::cout << s.Pop() << std::endl;
    std::cout << std::boolalpha << s.IsEmpty() << std::endl;
    std::cout << s.Pop() << std::endl;
    std::cout << std::boolalpha << s.IsEmpty() << std::endl;

    Stack<Data> s2;
    s2.Push(Data {100});
    s2.Push(Data {200});
    std::cout << s2.Pop() << std::endl;
    std::cout << std::boolalpha << s.IsEmpty() << std::endl;
    std::cout << s2.Pop() << std::endl;
    std::cout << std::boolalpha << s.IsEmpty() << std::endl;

    return 0;
}
