/*
 *  priorityqueue62.h
 *
 *  A priority queue for CS 62. An element
 *  in the queue is a pair of integers: a key
 *  and a (non-negative) priority. The operations are
 *  described below.The implementation details are
 *  suggested, not required.
 *
 *  Rett Bull
 *  April 7, 2009
 *  Modified: Evan Casey 4/14/2013
 *
 */
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>
#include <map>

using namespace std;

class priorityqueue62 {

public:
  /*
   *  Constructs an empty container.
   */
  priorityqueue62();

  /*
   *  The destructor must destroy any dynamic data.
   *  The suggested implementation has no dynamic
   *  data, so the destructor's action can be "do
   *  nothing" in that case.
   */
  ~priorityqueue62();

  /*
   *  Insert a new element into the queue, with the
   *  given key and priority. The name "push"
   *  follows the usage of the STL priority_queue.
   *
   *  It is an error to push key that already
   *  appears in the priority queue.
   */
  void push(int key, int priority);

  /*
   *  Remove the element with the lowest priority. Notice
   *  that no value is returned.
   *
   *  It is an error to pop from an empty queue.
   */
  void pop();

  /*
   *  Returns the lowest priority among all the elements
   *  in the queue.
   *
   *  It is an error to request a top value from an empty
   *  queue.
   */
  int top_priority() const;

  /*
   *  Returns the key of the element with the
   *  lowest priority.
   *
   *  It is an error to request a top value from an empty
   *  queue.
   */
  int top_key() const;

  /*
   *  Reduce the priority of an element already in the
   *  priority queue.
   *
   *  The key must be in the queue and the
   *  new priority must not be greater than the current
   *  priority.
   */
  void reduce_priority(int key, int new_priority);

  /*
   *  Returns the priority of the element with the given
   *  key. Returns -1 if no element with that
   *  key is in the queue.
   */
  int get_priority(int key);

  /*
   *  Returns true if the priority queue is empty.
   */
  bool is_empty() const;

  /*
   *  Returns true if an element with the given key
   *  number is in the priority queue.
   */
  bool is_present(int key) const;

  /*
   *  Empties the priority queue.
   */
  void clear();

  /*
   *  Returns the number of elements in the priority queue.
   */
  int size() const;

  
private:
  //variables that we store the queue elements in
  vector<pair<int,int> > numsVec;
  map<int,int> numsMap;

  //instance variable to store the size of the queue
  int queue_size;

  //documentation for these methods provided in .cpp file
  void percolateUp(int leaf_index);
  void pushDownRoot(int root_index);
  void swap(int i, int j);
  int left(int parent) const;
  int right(int parent) const;
  int parent(int child) const;
  int findIndexOf(int priority, int index);
};
#endif
