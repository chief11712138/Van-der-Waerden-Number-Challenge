def run(k, j, index, x):
    def t_of(n):
        return t[n-j]

    global max, zeroCount, c
    print(max)

    if zeroCount > j:
        return
    if index > 0 and x > 0:
        if is_arithmetic_progression_of_colour(c[1:index+1], t_of(x+j-1), x):
            return
    if index > max:
        max = index
    for i in range(0, k - j + 1):
        if i == 0:
            zeroCount += 1
        c[index + 1] = i
        run(k, j, index + 1, i)
        if i == 0:
            zeroCount -= 1
        if i > 0 and all_equal(t):
            if index <= j + (i - 1) * (t[0] - 1) + 1:
                if any(c[index + 1] > c[l] for l in range(1, index + 1)):
                    break

def is_arithmetic_progression_of_colour(sublist: list, length, colour):
    for i in range(len(sublist)):
        if sublist[i] != colour:
            continue
        for j in range(i + 1, len(sublist)):
            if sublist[j] != colour:
                continue
            common_diff = j - i
            progression = [i + common_diff * k for k in range(0, length)]
            if any(t >= len(sublist) for t in progression):
                continue
            colouring = [sublist[t] for t in progression]
            if all(c == colour for c in colouring):
                return True
    return False


def all_equal(lst):
    return all(x == lst[0] for x in lst)


max = 0 
zeroCount = 0  
c = [0] * 1000  

t = [3,4]

res = run(4,2,0,0)
print(max+1)
