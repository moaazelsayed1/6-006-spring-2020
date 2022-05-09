# model answer solution :(
def merge_bookings(B1, B2):
    n1, n2, i1, i2 = len(B1), len(B2), 0, 0
    x = 0
    # invariant: t < min(t1, t2)
    B = []
     # invariant: B is satisfying booking up to time x
    while i1 + i2 < n1 + n2:
        if i1 < n1: k1, s1, t1 = B1[i1]
        if i2 < n2: k2, s2, t2 = B2[i2]
        if i2 == n2:
             
            # only bookings in B1 remain
            k, s, x = k1, max(x, s1), t1
            i1 += 1
        elif i1 == n1:
            # only bookings in B2 remain
            k, s, x = k2, max(x, s2), t2
            i2 += 1
        else:
         # bookings remain in B1 and B2
            if x < min(s1, s2):
             # shift x to start of first booking
                x = min(s1, s2)
            if t1 <= s2:
             # overlaps only B1 up to t1
                k, s, x = k1, x, t1
                i1 += 1
            elif t2 <= s1:
             # overlaps only B2 up to t2
                k, s, x = k2, x, t2
                i2 += 1
            elif x < s2:
             # overlaps only B1 up to s2
                k, s, x = k1, x, s2
            elif x < s1:
             # overlaps only B2 up to s1
                k, s, x = k2, x, s1
            else:
             # overlaps B1 and B2 up to t1 or t2
                k, s, x = k1 + k2, x, min(t1, t2)
                if t1 == x: i1 += 1
                if t2 == x: i2 += 1
        B.append((k, s, x))
    B_ = [B[0]]
    # remove adjacent with same rooms
    for k, s, t in B[1:]:
        k_, s_, t_ = B_[-1]
        if (k == k_) and (t_ == s):
            B_.pop()
            s = s_
        B_.append((k, s, t))
    return B_

def satisfying_booking(R):
     
    if len(R) == 1:
          # base case
         s, t = R[0]
         return ((1, s, t),)
    m = len(R) // 2
    R1, R2 = R[:m], R[m:]
     # divide
    B1 = satisfying_booking(R1)
     # conquer
    B2 = satisfying_booking(R2)
     # conquer
    B = merge_bookings(B1, B2)
    return tuple(B)
# print(B)

