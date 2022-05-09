A = [47, 61, 36,  52, 56, 33, 92]

for c in range(7, 100):
    hashes = [(((10 * k) + 4 )% c ) % 7 for k in A]
    print(c, '\t', end="");
    print('\t'.join(str(h) for h in hashes))
    if len(set(hashes)) == 7:
        break
    
