// Warning: Do not modify this file.
// Go to linkedlist.h's get method

#include <iostream>
#include "linkedlist.h"
using namespace std;

int main() {
    DoublyLL* list = new DoublyLL();
    char op;
    int num, pos;
    do {
      cout << "Enter op: ";
    	cin >> op;
    	switch (op) {
    		case 'a' :
		    	cin >> num;
		    	list->add(num);
		    	break;
		    case 'R':
                cin >> num;
                cout << "Removed " << list->removeAll(num) << " element/s" << endl;
                break;
		    case 'p':
		    	list->print();
		    	break;
		    case 'x':
		    	cout << "Exiting";
		    	break;
            default:
                cout << "Invalid operation" << endl;
        }
    } while (op != 'x');
    return 0;
}