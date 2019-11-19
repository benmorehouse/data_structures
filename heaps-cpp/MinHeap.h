#include <iostream>
#include <vector>

class MinHeap {
	public:
		MinHeap (int);
	/* Constructor that builds a d-ary Min Heap
	  This should work for any d >= 2,
	  but doesn't have to do anything for smaller d.*/

		~MinHeap ();

		int add (int item);
		 /* adds the item to the heap, with the given priority. 
		    multiple identical items can be in the heap simultaneously. 
		    Returns the number of times add has been called prior to this
		    call (for use with the update function).*/

		int peek ();
		 /* returns the element with smallest priority.  
		    If two elements have the same priority, use operator< on the 
		    T data, and return the one with smaller data.*/

		void remove ();
		 /* removes the element with smallest priority, with the same tie-breaker
		    as peek. */

		void update (int nth, int priority);
		 /* finds the nth item (where nth is 0-based) that has ever been added 
		    to the heap (the node that was created on the nth call to add), 
		    and updates its priority accordingly. */

		bool isEmpty ();
		 /* returns true iff there are no elements on the heap. */
		
		void print();
	private:
		std::vector<int> array; 
		int d; // d is the max size of each branch
		void heapify(int index);
		std::vector<int> addHistory; // this will hold in its nth value the index you can find it in array
		int addCalls;
		
		// whatever you need to naturally store things.
// You may also add helper functions here.
};


