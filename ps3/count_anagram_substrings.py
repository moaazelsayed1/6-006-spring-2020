def freq(str):
    arr = [0] * 26
    for c in str:
        arr[ord(c) - ord('a')] += 1
    
    return arr


def count_anagram_substrings(T, S):
    '''
    Input:  T | String
            S | Tuple of strings S_i of equal length k < |T|
    Output: A | Tuple of integers a_i:
              | the anagram substring count of S_i in T
    '''
    A = [0] * len(S) 
    frq = [0] * 26
    hsh = {}
    k = len(S[0])
    for i in range(len(T)):
        frq[ord(T[i]) - ord('a')] += 1;
        if i > k - 1:
            frq[ord(T[i - k]) - ord('a')] -= 1;
        if i >= k - 1:
            key = tuple(frq) # tuple is a hashable type
            if key in hsh:
                hsh[key] += 1 
            else:
                hsh[key] = 1 

    
        
    for i in range(len(S)):
        arr = freq(S[i])
        key = tuple(arr)
        if key in hsh:
            A[i] = hsh[key]


        # arr1 = freq(str)
        # print(arr)
        # print(arr1)
                
    

    return tuple(A)
    

# count_anagram_substrings('esleastealaslatet', ('tesla'))
