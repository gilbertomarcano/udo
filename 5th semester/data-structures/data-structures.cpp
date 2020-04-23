// data-structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//#include "unit-1/static_stack.hpp"
//#include "unit-1/static_queue.hpp"
#include "unit-2/node.hpp"

int main()
{
    using namespace std;
    cout << "Hello World!\n";
    node<int> a(5, nullptr, nullptr);

    node<int> b(77, nullptr, nullptr);

    node<int>* ptr = &b;

    cout << "&ptr: " << &ptr << endl;
    cout << "ptr:  " << ptr << endl;
    cout << "&b: " << &b << endl;

    cout << "\n\n\n";
    cout << *ptr << endl;

    a.set_prev(ptr);
    cout << a << endl;
    cout << a.get_prev() << endl;
    cout << *a.get_prev() << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
