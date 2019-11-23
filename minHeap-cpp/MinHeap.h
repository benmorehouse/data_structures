#include <iostream>
#include <vector>

class MinHeap {
	struct Item {
		int priority;	
		int val;
		int currentPosition;
	
		Item(int v, int nth){
			val = v;
			priority = v; // for now it will be v because of testing but later on we will update the priority to be whatever we have in our A* search...
			currentPosition = nth;
		}
	};

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

		int peek (); // this will return the templated value T
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
		std::vector<Item*> array; 
		int d; // d is the max size of each branch
		//std::vector<int> nthValue; // this indexing is aligned with the indexing for array. the value will be the nth time it was added. If it was deleted then it will be evaluated to -1
		std::vector<Item*> nthValueIndexInArray; // just keeps a pointer to the item and then when we want it we can just access it
		
		int addCalls; // dont get rid of this... size of vectors is variable! So keep this as a constant separate from them
		void bubbleDown(int);		
		void bubbleUp(int);		
		// whatever you need to naturally store things.
// You may also add helper functions here.
};

