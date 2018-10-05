#include "stack_array.hpp"
#include <iostream>

using std::cerr;
using std::endl;

stack_array::stack_array()
{
    my_vec = new int [max_allowed_size];
    v_top = 0;
}

stack_array::~stack_array()
{
    delete [] my_vec;
}

int stack_array::top () const {
    if (v_top <= 0)   
        cerr<<"Empty or invalid stack"<<endl;
    else{
        return my_vec[v_top - 1];
    }
}


void stack_array::push (const int new_elem){
    if (v_top >= max_allowed_size)    {
        cerr<<"Going over authorized length of the stack"<<endl;
        return;
    }
    else {
        my_vec[v_top] = new_elem;
        //std::cout<<"AA = "<<(v_top++)<<std::endl;
        v_top++;
        return;
    }
}

int stack_array::pop () {
        if (v_top <= 0)   
        cerr<<"Empty or invalid stack"<<endl;
    else{
        v_top--;
        return my_vec[v_top];
    }
}

int stack_array::size() const   {
    return v_top;
}