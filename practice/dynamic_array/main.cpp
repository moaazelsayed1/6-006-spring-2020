#include "dynamic_array.h"
#include <bits/stdc++.h>

using namespace std;
using namespace practice;

int main() {
  DArray arr;
  cout << "capacity: " << arr.capacity() << endl;
  cout << "size: " << arr.size() << endl;
  cout << "push... " << endl;

  for (int i = 0; i < 20; i++) {
    arr.push(i);
  }
  cout << "after push()" << endl;
  cout << "capacity: " << arr.capacity() << endl;
  cout << "size: " << arr.size() << endl;
  cout << arr.find(1) << endl;
  cout << arr.at(arr.size() - 1) << endl;
  cout << "pop()..." << endl;
  for (int i = 0; i < 20; i++) {
    arr.pop();
  }
  cout << "after pop()" << endl;
  cout << "capacity: " << arr.capacity() << endl;
  cout << "size: " << arr.size() << endl;

  cout << arr.empty() << endl;
  cout << "capacity: " << arr.capacity() << endl;
  cout << "size: " << arr.size() << endl;
  for (int i = 0; i < 20; i++) {
    arr.push(5);
  }
  cout << "capacity: " << arr.capacity() << endl;
  cout << "size: " << arr.size() << endl;

  arr.remove(5);
  cout << arr.empty() << endl;
  cout << "capacity: " << arr.capacity() << endl;
  cout << "size: " << arr.size() << endl;

  for (int i = 0; i < 20; i++) {
    arr.push(i);
  }

  arr.insert(10, 100);
  cout << arr.at(10) << endl;
  cout << "capacity: " << arr.capacity() << endl;
  cout << "size: " << arr.size() << endl;

  arr.delete_at(10);
  cout << arr.at(10) << endl;
  cout << "capacity: " << arr.capacity() << endl;
  cout << "size: " << arr.size() << endl;

  for (int i = 0; i < arr.size(); i++) {
    cout << arr.at(i) << " ";
  }
  cout << endl;
}
