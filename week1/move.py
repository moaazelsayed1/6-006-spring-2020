def move(D, i, k, j):
    if(k == 0):
        return

    x1 = D.delete_at(i + k - 1);

    if j > i:
        D.insert_at(j - 1, x1)
    else:
        D.insert_at(j, x1)


    move(D, i, k - 1, j)
