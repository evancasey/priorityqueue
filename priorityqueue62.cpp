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
		map<pair<int,int>> numsMap;
	}

	/**
	 *  Does nothing since implementation has no dynamic data
	 */

	priorityqueue62::~priorityqueue62() {
		//do nothing
	}


	/**
	 *  Takes in a key and priority and adds them
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
			numsMap.insert(make_pair(key,priority));
			cout << "push: " << key << ", " << priority << endl;
		}


	}

	void priorityqueue62::percolateUp(int index) {
		numsVec
	}

	/**
	 *  Pop the top value off the queue
	 */
	void priorityqueue62::pop() {
		//check if queue is not empty
		if (!numsVec.is_empty()) {
			//pop the top value off
		}
		
	}

	int priorityqueue62::top_priority() const {

	}

	int priorityqueue62::top_key() const {

	}

	void priorityqueue62::reduce_priority(int key, int newpriority) {

	}

	int priorityqueue62::get_priority(int key) {

	}

	bool priorityqueue62::is_present(int key) const {

	}

	void priorityqueue62::clear() {

	}

	int priorityqueue62::size() const {

	}

private:






//main for testing
int main() {

}

