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
		if (tail) 
        {
			cout << "Have tail" << endl;
			tail->next = n;
		} else 
        {
			cout << "Have no tail" << endl;
        }
	}

    int get(int pos) {
        // IGNORE for now
        return 0;
    }

    int remove(int num) {
        int pos = 1;
        node* n = (node*) calloc( 1, sizeof(node) );
    	node* curr = head;
    	node* prev = head;
    	while (curr) {
    		if (curr->elem == num) {
                    if(curr==head)
                    {
                        head = head->next;
                    }
                    else{
                        tail = curr->next;
                     }
                      prev->next = curr->next;

                size--;
                free(curr);
                return pos++;
                }
            prev = curr;
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