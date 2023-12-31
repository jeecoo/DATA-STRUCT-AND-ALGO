// Warning: Do not modify this file.
// Go to linkedlist.h's get method

#include <iostream>
#include "linkedlist.h"
using namespace std;

int main() {
    DoublyLL* list = new DoublyLL();
    char ch;
    int num, pos;
    do {
        cout << "Op: ";
        cin >> ch;
        switch (ch) {
            case 'a':
                cin >> num;
                list->add(num);
                break;
            case 'r':
                cin >> num;
                cout << "Removed position " << list->remove(num) << endl;
		    	break;
            case 'g':
                cin >> pos;
                cout << "Element " << pos << ": " << list->get(pos) << endl;
                break;
            case 'p':
                list->print();
                break;
            case 'x':
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid operation" << endl;
        }
    } while (ch != 'x');
    return 0;
}