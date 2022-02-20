def reverse(D, i, k):
    if k < 2:
        return
    
    x1 = D.delete_at(i);
    x2 = D.delete_at(i + k - 1);
    D.insert_at(i, x2);
    D.insert_at(i + k - 1, x1);
    reverse(D, i + 1, k - 2)
