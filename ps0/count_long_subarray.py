def count_long_subarray(A):
    '''
    Input:  A     | Python Tuple of positive integers
    Output: count | number of longest increasing subarrays of A
    '''
    count = 1
    curr_count = 1
    max = 1
    for i in range(1,len(A)):
        # print(A[i - 1])
        # print(A[i])
        if A[i] > A[i - 1]:
            curr_count += 1
            # if curr_count > max:
        else:
            curr_count = 1
        if curr_count == max:
            count += 1
        elif curr_count > max:
            max = curr_count
            count = 1
            # if curr_count > count:
            #     count = curr_count
            # curr_count = 1
    ##################
    # YOUR CODE HERE #
    ##################
    return count

# A = (7, 8, 5, 7, 7, 3, 2, 8)
# print(count_long_subarray(A))
