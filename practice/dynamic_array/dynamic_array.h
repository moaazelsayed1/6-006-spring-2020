#include <bits/stdc++.h>

namespace practice {

static const int MinCapacity = 16;
static const int GrowthFactor = 2;
static const int ShrinkFactor = 4;

class DArray {
public:
  DArray();
  ~DArray();
  // number of items
  int size();

  // number of items it can hold
  int capacity();

  // if it holds no items
  bool empty();

  // returns item at given index, blows up if index out of bounds
  int at(int index);

  void set_at(int index, int item);

  void push(int item);

  // inserts item at index
  void insert(int index, int item);

  // delete item at index
  int delete_at(int index);

  // looks for value and removes index holding it (even if in multiple places)
  void remove(int item);

  // looks for value and returns first index with that value, -1 if not found
  int find(int item);

  // delete the last element
  int pop();

private:
  // the whole available capacity
  int capacity_ = MinCapacity;
  // the actual size of the array
  int size_;
  // The storage array where ints are stored
  int *data_;
  /*
   when you reach capacity, resize to double the size
   when popping an item, if size is 1/4 of capacity, resize to half
  */
  void resize();
  // Increases the capacity of the vector.
  void increase_size();
  // Decreases the capacity of the vector.
  void decrease_size();
  // out of bounds check
  void check_index(int index);
  // move after resize()
  void move_items(int *tmp);
};

}; // namespace practice
