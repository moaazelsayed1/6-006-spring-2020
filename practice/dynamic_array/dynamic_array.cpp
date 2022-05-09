#include "dynamic_array.h"
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

namespace practice {

DArray::DArray() {
  size_ = 0;
  capacity_ = MinCapacity;
  data_ = (int *)malloc(capacity_ * sizeof(*data_));
  if (!data_) {
    throw bad_alloc();
  }
}

DArray::~DArray() { free(data_); }

int DArray::size() { return this->size_; }

int DArray::capacity() { return this->capacity_; }

bool DArray::empty() {
  if (size_ == 0) {
    return true;
  }
  return false;
}

int DArray::at(int index) {
  check_index(index);
  return *(data_ + index);
}

void DArray::set_at(int index, int item) {
  check_index(index);
  *(data_ + index) = item;
}

void DArray::push(int item) {
  size_++;
  resize();
  *(data_ + size_ - 1) = item;
}

void DArray::insert(int index, int item) {
  check_index(index);
  size_++;
  resize();
  for (int i = size_ - 1; i >= index; i--) {
    *(data_ + i + 1) = *(data_ + i);
  }

  *(data_ + index) = item;
}
int DArray::delete_at(int index) {
  check_index(index);
  int deleted_item = *(data_ + index);
  size_--;
  resize();
  for (int i = index; i < size_; i++) {
    *(data_ + i) = *(data_ + i + 1);
  }
  return deleted_item;
}

void DArray::remove(int item) {
  for (int i = 0; i < size_; i++) {
    if (*(data_ + i) == item) {
      delete_at(i);
      i--;
    }
  }
}

int DArray::find(int item) {
  int found = -1;
  for (int i = 0; i < this->size_; i++) {
    if (*(data_ + i) == item) {
      found = i;
    }
  }
  return found;
}

int DArray::pop() {
  int item = *(data_ + size_ - 1);
  delete_at(size_ - 1);
  return item;
}

void DArray::resize() {
  if (size_ >= capacity_) {
    increase_size();
  } else if (size_ <= (capacity_ / ShrinkFactor)) {
    decrease_size();
  }
}

void DArray::increase_size() {
  int new_capacity_ = capacity_ * GrowthFactor;

  int *tmp = (int *)realloc(this->data_, sizeof(int) * new_capacity_);
  if (tmp == NULL) {
    throw bad_alloc();
  }
  // move_items(tmp);
  this->data_ = tmp;
  this->capacity_ = new_capacity_;
}

void DArray::decrease_size() {
  int new_capacity_ = capacity_ / GrowthFactor;
  if (new_capacity_ < MinCapacity) {
    new_capacity_ = MinCapacity;
  }

  if (new_capacity_ != capacity_) {
    int *tmp = (int *)realloc(this->data_, sizeof(int) * new_capacity_);
    if (!tmp) {
      throw bad_alloc();
    }
    // this->move_items(tmp);
    this->data_ = tmp;
    this->capacity_ = new_capacity_;
  }
}

void DArray::check_index(int index) {
  // cout << "index: " << index << endl;
  // cout << "size: " << size_ << endl;
  if (index >= size_ || index < 0) {
    cout << "out of bounds" << endl;
    exit(EXIT_FAILURE);
  }
}
void DArray::move_items(int *tmp) {
  for (int i = 0; i < size(); i++) {
    *(tmp + i) = *(data_ + i);
  }
}

} // namespace practice
