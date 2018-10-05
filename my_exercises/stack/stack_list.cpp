#include "stack_list.hpp"
#include <iostream>

stack_list::stack_list()    {
    // Empty stack
    ptr = 0;
    elem = 0; // could be any value, in fact.
}

int stack_list::top() const {
    if (ptr == 0) // No element in the stack
        std::cerr<<"No element in the stack"<<std::endl;
    else
        return ptr->elem;
}

int stack_list::pop()   {
    // If the stack is empty
    if (ptr == 0)
        std::cerr<<"No element in the stack"<<std::endl;
    else    {
        int to_return = ptr->elem;  // value to return
        stack_list * tmp_pt = ptr;  // pointer to the current value to erase
        ptr = ptr->ptr;             // erasing current cell (but still needs to be deleted from the heap)
        delete tmp_pt;              // deleting current element from the heap
        return to_return;           // returning value
    }
}

void stack_list::push(const int new_value) {
    stack_list * new_head = new stack_list; // Allocating new element
    new_head->ptr = this->ptr;              // Connecting to the list
    new_head->elem = new_value;             // Adding value
    this->ptr = new_head;                   
    return;
}
