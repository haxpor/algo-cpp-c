#ifndef __STACK_H__
#define __STACK_H__

#include <type_traits>
#include <algorithm>

/*
====================
Stack with no boundary checking.
====================
*/
template<typename ItemType>
class Stack {
public:
                            Stack(int max=100);
                            ~Stack();

    /**
     * Push an input item into the stack by copying.
     */
    void                    Push(const ItemType& item);

    /**
     * Pop from statck.
     * This return a reference to the popped element.
     */
    ItemType&               Pop(void);

    /**
     * Get whether the stack is empty.
     */
    bool                    IsEmpty(void) const;

    template<typename T>
    friend std::ostream&    operator<<(std::ostream& out, const Stack<T>& s);

private:
    /**
     * Indexed pointer to head of stack.
     */
    int             p;

    /**
     * Data elements of stack.
     */
    ItemType        *stack;
};

template<typename ItemType>
inline Stack<ItemType>::Stack(int max) {
    stack = new ItemType[max];
    p = 0;
}

template<typename ItemType>
inline Stack<ItemType>::~Stack() {
   delete[] stack; 
}

/* Following two functions provided for convenient in users' use case
 * Might be not all the time users will need move semantics?
 * So the first one below here is provided
 */
template<typename ItemType>
inline void Stack<ItemType>::Push(const ItemType& item) {
    // if it's a class type then we construct a new copy of such object before pushing
    if (std::is_class<ItemType>::value) {
        stack[p++] = ItemType(item);
    } else {    // by value
        stack[p++] = item;
    }
}


template<typename ItemType>
inline ItemType& Stack<ItemType>::Pop(void) {
    return stack[--p];
}

template<typename ItemType>
inline bool Stack<ItemType>::IsEmpty(void) const {
    return !p;
}

template<typename ItemType>
inline std::ostream& operator<<(std::ostream& out, const Stack<ItemType>& s) {
    if (!s.IsEmpty()) {
        for (int i=0; i<s.p; ++i) {
            out << s.stack[i] << ", ";
        } 
    }
    return out;
}

#endif /* __STACK_H__ */
