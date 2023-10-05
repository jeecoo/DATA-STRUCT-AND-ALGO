#include <cstdlib>
#include <iostream>
#include "list.h"
#include "node.h"
using namespace std;

class DoublyLL : public List {
	node* head;
	node* tail;
	int size;

	public:
	void add(int num) {
		// STEP 1: Create node
		node* n = (node*) malloc( sizeof(node) );
		n->elem = num;
		n->next = nullptr;
		n->prev = tail;
		// STEP 2: Tail's next = n

        if(size==0)
        {
                head = n;
                tail = n;
        }
        else 
        {
			cout << "Have tail" << endl;
			tail->next = n;
            tail = n;
    	}
        size++;
}
    int get(int pos) {
        node* currNode = head;
		int currPos = 1;
		while (currNode != nullptr) {
            if (currPos == pos) {
                return currNode->elem;
            }
            currNode = currNode->next;
            currPos++;
        }
        return -1;
    }

    int remove(int num) {
        node* curr = head;
        int pos = 1;
        // Traverse the list to find the node with the specified value
        while (curr) {
            if (curr->elem == num) {
                // If the node is found, adjust the pointers to remove it
                if (curr->prev) {
                    curr->prev->next = curr->next;
                } else {
                    // If the node is the head, update the head
                    head = curr->next;
                }
                if (curr->next) {
                    curr->next->prev = curr->prev;
                }
                free(curr);
                return pos; // Found and removed the node, exit the function
            }
            curr = curr->next;
            pos++;
        }
        return -1;
        }
       

    // TODO implement addHead and addTail
    	void addHead(int num)
            {
                node* n = (node*) calloc( 1, sizeof(node) );
        		n->elem = num;
        		// Step 2: Set the n's next to head
        		n->next = head;
        		if (head) {
        			head->prev = n;
        		}
        		// Step 3: Head to n
        		head = n;
        		if (!tail) {
        			tail = n;
        		}
        		// Step 4: Inc size
        		size++;
        	}
        void addTail(int num)
        {
              add(num);
        }

    void print() {
    	node* curr = head;
    	if (size == 0) {
    		cout << "Empty" << endl;
		} else {
	    	do {
	    		cout << curr->elem;
	    		if (curr->next) {
	    			cout << " -> ";
				} else {
					cout << endl;
				}
	    		curr = curr->next;
			} while (curr);
		}
    }
};