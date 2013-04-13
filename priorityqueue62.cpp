#include "priorityqueue62.h"
#include <assert.h> // assert

using namespace std;

class prioriytqueue62 {

public:
	/*
	 *  Constructs an empty container to store our vector and map of pairs
	 */
	priorityqueue62::priorityqueue62() {
		vector<pair<int,int>> numsVec;
		map<int,int> numsMap;
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
		if (numsMap.find(key) == numsMap.end()) {

			//add to our vector and percolate up
			numsVec.push_back(make_pair(key,priority));
			numsVec.percolateUp(numsVec.size() - 1);

			//add to our map
			numsMap.insert(key,priority);
			cout << "push: " << key << ", " << priority << endl;
		}
	}

	/**
	 *  Percolate a pair up the heap
	 *  
	 *  @param index index of the pair to be percolated up
	 */
	void priorityqueue62::percolateUp(int index) {
		numsVec
	}

	/**
	 *  Removes the element with the lowest priority (top of the queue).
	 *  No value is returned.
	 */
	void priorityqueue62::pop() {
		//check if queue is not empty
		if (!numsVec.is_empty()) {
			//pop the top value off
			numsVec.pop_back();
		}
	}

	/**
	 *  Returns the lowest prioriyt of all the elements in the queue
	 */
	int priorityqueue62::top_priority() const {
		return numsVec.back().first;
	}

	int priorityqueue62::top_key() const {
		return numsVec.back().second;
	}

	void priorityqueue62::reduce_priority(int key, int newpriority) {

	}

	int priorityqueue62::get_priority(int key) {
		priority = numsMap.find(key)

	}

	bool priorityqueue62::is_empty() {
		return numsVec.empty();
	}

	bool priorityqueue62::is_present(int key) const {


	}

	void priorityqueue62::clear() {
		numsVec.clear();
	}

	int priorityqueue62::size() const {
		return numsVec.size();
	}

private:

	void priorityqueue62::pushDownRoot(int i) {

	}

	void priorityqueue62::swap(int i, int j) {

	}

	int priorityqueue62::left(int parent) const {

	}

	int priorityqueue62::right(int parent) const {

	}

	int priorityqueue62::parent(int child) const {

	}





//main for testing
int main() {

}

