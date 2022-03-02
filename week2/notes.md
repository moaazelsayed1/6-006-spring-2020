# lecture 3. Sets and Sorting

## Set Interface

### container
- `build(A)` build the sequence
- `len()` return number of the sorted items

### static 
- `find(k)` return the sorted item with key k.

### dynamic (edit the set)
- `insert(x)` add x to the Set
- `delete(k)` remove and return the stored item with key key

### ordered 
- `iter_ord()` return the stored item one-by-one in key order
- `find_min()` return the stored item with the smallest key
- `find_max()` return the stored item with the largest key
- `find_next(k)` return the stored item with the smallest key larger than k
- `find_prev(k)` return the stored item with the largest key smaller than k

## Sorting
- Destructive Sorting: we overwrite the input array.
- In place: Destructive + uses extra memory.
 
### permutation sort 
if i have a list of numbers then one of its permutations is the sorted list.

```
def permutation_sort(A): 
  for B in permutations(A): 
      if is_sorted(B): 
         return B 
```

1. enumerate the permutations which takes Omega(n!) time.
2. check if the permutation is sorted which takes O(n) time.
, then takes Omega(n!).

### Selection sort
    [8, 2, 4, 9, 3]

1. Find the biggest element with index <= i.
2. Swap.
3. sort from 1 to i - 1

#### Inductive hypothesis:
previous steps gave the largest element between i and i - 1.

#### biggest element from 0 to i
1. it is at index i
2. otherwise :D.

```
def prefix_max(A, i): # returns index of the maximum in A[:i + 1]
    if i > 0:
        j = prefix_max(A, i - 1)   
        if A[i] < A[j]:
            return j
    return i    
```
##### recursive implementation:
1. Base case: when i equals 0 -> one element in the array
2. Inductive step: is to check whether the largest element is at index i or not 

In `selection_sort()` analysis T(n - 1) + theta(n) -> 1 + 2 + 3 + ... + n = theta(n^2) 
so we can do the substitution: T(n) = theta(n^2)

## Comparison (search/sort) model:
- only operations allowed are Comparisons.
- time cost = # Comparisons. => lg(n) to search/ nlg(n) to sort.

## Decision tree
any Comparison algorithm can be viewed as a tree of all possible Comparisons, their
outcomes and resulting answer.k
- binary search with n = 3

- A[1] < x? 
  - yes, A[2] < x?
    - yes, outside A. (answer)
    - no, A[1] < x <= A[2].(answer)
  
  - no, A[0] < x?
    - yes, A[0] < x <= A[1]. (answer) 
    - no, then x <= A[0]. (answer)
  
- *internal node* in the tree represent a Comparison. 
- a *leaf* represent an answer. (algorithm terminates) 
- *root-to-path* is the algorithm execution.
- *length of root-to-path** is the running time.
- ***he height of the tree is the worst case. O().** 
 
### searching lower bound:
- n preprocessed items 
- finding a given item among them in Comparison model requires Omega(lg (n)) in the 
worst case.

#### proof
- Decision tree is binary and must have >= n leafs one for each answer.
- then the height has to be lg(n). 
 
## Hashing

### Direct-access array
- puts every item at the corresponding index.
#### Badness 
1. keys (indices) may not be integers.
2. needs a lot of memory. (assume we need to store a 64-bit integer).

### First solution (prehash)
- maps keys to non-negative integers.
- in theory keys are finite & discrete. (string of bits) 

### second solution (hashing)
- take all possible keys U = {0,..., u - 1} and reduce them to reasonable size m of integers.
- we need m = Theta(n). n : number of keys in the hash table.

collision: h(ki) = h(kj) and ki != kj.

### chaining
some data structure (may be a linked list) of the colliding elements in each slot of a hash table. 

The worst case is Theta(n).
 **Simple uniform hashing**: each key is equally likely to be hashed to any slot of the table independent of where other keys hashing.
If **Simple uniform hashing** is true then the hash table takes constant time (insert/ delete/ search).

#### Analysis:
expected length of a chain for n keys stored and m slots = n/m = load factor = Alpha. => = Theta(1) if m = Theta(n).
- running time is O(1 + Alpha).

#### hashing functions

1. **division method** => h(k) = k mod m
- bad if m has some common factors with k. 
- good if m is prime and not too close to power of 2 and power of 10.
2. **multiplication method** => h(k) = ((a . k) mod 2^w) >> (w -r) in a w-bit machine, r is some length of bits and a better be odd.
3. **universal hashing** (more in 046) =>
 h(k)= ((a . k + b) mod p) mod m.
 a & b: random numbers in {0, ..., p -1}
 p: big prime number. (bigger then u).
 m: size of the table.

 -for worst-case keys k1 != k2 pr over a & b{h(k1) = h(k2)} = 1 / m.




Dictionary: Set of items in which each item has a key.

### Dictionary Interface:
- insert(item): overwrite any existing key,
- delete(item)
- search(key): return item with given key or report does not exist.






