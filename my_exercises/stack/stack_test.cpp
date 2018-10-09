#include "stack_array.cpp"
#include "stack_list.cpp"
#include <iostream>

using std::cout;
using std::endl;


int main()  {
    stack_array s_a;
    stack_list s_l;

    s_a.push(12);

    cout<<s_a.top()<<endl;

    s_a.pop();

    for (int i = 0; i < 1203; i++)  {
        s_a.push(i);
        cout<<"Added "<<s_a.top()<<" | Size of the stack = "<<s_a.size()<<endl;
    }

    for (int i = 0; i < 1200; i++)  {
        s_a.pop();
        cout<<"Emptying stack - Members= "<<s_a.size()<<endl;
    }

    s_l.push(10);

    cout<<endl<<"New List = "<<s_l.top()<<endl;


        for (int i = 0; i < 5020; i++)  {
        s_l.push(i);
        cout<<"Added "<<s_l.top()<<endl;
    }

    for (int i = 0; i < 5022; i++)  {
        s_l.pop();
    }


}


