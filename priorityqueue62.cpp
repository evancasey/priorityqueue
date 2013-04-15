/**
 *  priorityqueue62.cpp
 * 
 *  A priority queue for CS 62. An element
 *  in the queue is a pair of integers: a key
 *  and a (non-negative) priority. 
 *
 *  This file implements the methods from the class
 *  priorityqueue62 in our header file.
 *
 *  Evan Casey
 *  April 14, 2013
 */

#include "priorityqueue62.h"
#include <assert.h> 
#include <iostream>

/*
 *  Constructs an empty container to store our vector and map of pairs
 */
priorityqueue62::priorityqueue62() {
	vector<pair<int,int> > numsVec;
	map<int,int> numsMap;
	queue_size = 0;
}

/**
 *  Does nothing since implementation has no dynamic data
 */
priorityqueue62::~priorityqueue62() {
	//do nothing
}

/**
 *  Takes in a key and priority and adds them to numsVec 
 *  and nums Map. Adds to numsVec as a pair.
 * 
 *  @param key key, integer
 *  @param priority priority, integer
 */
void priorityqueue62::push(int key, int priority) {
	//check that key does not exist already in our map
	assert(!is_present(key));

	//increment our queue size
	priorityqueue62::queue_size++;

	//add to our vector and percolate up
	numsVec.push_back(make_pair(key,priority));
	percolateUp(numsVec.size() - 1);

	//add to our map
	numsMap.insert(make_pair(key,priority));
}

/**
 *  Removes the element with the lowest priority (top of the queue).
 *  No value is returned.
 */
void priorityqueue62::pop() {
	//check if queue is not empty
	assert(!is_empty());

	//increment queue_size by -1
	queue_size--;

	//point our root to the next spot in the vector
	numsVec[0] = numsVec[1];

	//remove it from the map
	numsMap.erase(top_key());

	//call pushDownRoot for the value we popped off
	if(queue_size > 1) {
		pushDownRoot(0);
	}
}

/**
 *  Returns the priority of the lowest priority element in the queue
 */
int priorityqueue62::top_priority() const {
	//check if the queue is not empty
	assert(!is_empty);
	return numsVec[0].second;
}

/**
 *  Returns the key of the lowest priority element in the queue
 */
int priorityqueue62::top_key() const {
	//check if the queue is not empty
	assert(!is_empty);
	return numsVec[0].first;
}

/**
 *  Reduces of the priority of the pair associated with a given key.
 *  Takes in a key int value and sets it the new_priority value that
 *  the method is called with. 
 */
void priorityqueue62::reduce_priority(int key, int new_priority) {
	//make sure key is in the map
	assert(is_present(key));

	//make sure new priority is less than old priority
	assert(get_priority(key) > new_priority);

	//call find index of to find the index of the pair associated 
	//with the key that is passed in and assign it a variable
	int reduce_index = findIndexOf(get_priority(key), 0);
	pair<int,int> reduce_pair = numsVec[reduce_index];

	//erase the pair from the map and add in the new one
	numsMap.erase(key);
	pushDownRoot(reduce_index);
	push(key, new_priority);
}

/**
 *  Accesses numsMap to return the value associated with 
 *  a key that we pass in (in O(log(n)) time).
 *
 * 	If the key does not exist, -1 is returned.
 */
int priorityqueue62::get_priority(int key) {
	//check to see if the key exists in our map
	if(numsMap.count(key) > 0) {
		return numsMap.at(key);
	} else {
		return -1;
	}
}

/**
 *  Returns true if the queue is empty, false if not
 */
bool priorityqueue62::is_empty() const {
	return queue_size == 0;
}

/**
 *  Takes in a key and returns true if it is not already in the map
 */
bool priorityqueue62::is_present(int key) const {
	return numsMap.find(key) != numsMap.end();
}

/**
 *  Empties the priority queue
 */
void priorityqueue62::clear() {
	numsVec.clear();
	numsMap.clear();
}

/**
 *  Returns the size of the queue
 */
int priorityqueue62::size() const {
	return queue_size;
}

/**
 *  Percolates a pair up the heap.
 *  Takes in an index of the leaf to be percolated up and
 *  pushes it up to its proper location.
 *  
 *  @param index index of the pair to be percolated up
 */
void priorityqueue62::percolateUp(int leaf_index) {

	int parent_index = parent(leaf_index);
	int leaf_priority = numsVec[leaf_index].second;	

	//while this is true, keep swapping the elements up
	while (leaf_index > 0 && leaf_priority < numsVec[parent_index].second) {
		swap(parent_index,leaf_index);
		leaf_index = parent_index;
		parent_index = parent(leaf_index);
	}
}

/**
 *  Used to update the heap after the top node has been removed.
 *  Iterates down the heap starting from the root and pushes elements
 *  up if they have a greater priority than their parent
 */
void priorityqueue62::pushDownRoot(int root_index) {
	//if the node we put in root has no children, erase it
	if((left(root_index) >= queue_size) && (right(root_index) >= queue_size)) {
		numsVec.erase(numsVec.begin()+root_index);
		queue_size--;
	}
	//check to see if we've gone to far for the left node
	else if(left(root_index) >= queue_size) {
		numsVec[root_index] = numsVec[left(root_index)];
		numsVec.erase(numsVec.begin()+(left(root_index)));
		queue_size--;
	}

	//check to see if we've gone to far for the right node
	else if(right(root_index) >= queue_size) {
		numsVec[root_index] = numsVec[left(root_index)];
		numsVec.erase(numsVec.begin()+(right(root_index)));
		queue_size--;
	}

	//now we know we're swapping - check to see if we should 
	//swap left, if so call pushDownRoot
	else if(numsVec[left(root_index)].second < numsVec[right(root_index)].second) {
		numsVec[root_index] = numsVec[left(root_index)];
		pushDownRoot(left(root_index));
	}

	//check to see if we should swap right, if so call pushDownRoot
	else {
		numsVec[root_index] = numsVec[right(root_index)];
		pushDownRoot(right(root_index));
	}
}

/**
 *  Swaps the element at i with the element in j in numsVec
 */
void priorityqueue62::swap(int i, int j) {
	pair<int,int> temp_swap = numsVec[j];
	numsVec[j] = numsVec[i];
	numsVec[i] = temp_swap;
}

/**
 *  Returns index of left child of node at parent index
 */
int priorityqueue62::left(int parent) const {
	return (2*parent)+1;
}

/**
 *  Returns index of right child of node at parent index
 */
int priorityqueue62::right(int parent) const {
	return 2*(parent+1);
}

/**
 *  Returns index of the parent of the node at child index
 */
int priorityqueue62::parent(int child) const {
	return (child-1)/2;
}

/**
 *  Helper method to find the index of an element with a given 
 *  priority in O(log(n)) time. Index that is passed in is index 
 *  of the root of the subtree we are looking in. 
 *
 */
int priorityqueue62::findIndexOf(int priority, int index) {
	//if the element's priority is equal to the priority passed in,
	//return the index
	if(numsVec[index].second == priority) {
		return index;
	}

	//if not go down the right and left children
	else {
		if (numsVec[left(index)].second <= priority) {
			findIndexOf(priority,left(index));
		}
		
		if (numsVec[right(index)].second <= priority) {
			findIndexOf(priority,right(index));
		}
	}
}

