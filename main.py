# Assuming necessary global variables are defined elsewhere, as the pseudocode suggests
# max, zeroCount, and an array c[] to hold certificates

max = 0  # Assuming 'max' keeps track of the maximum index reached in a valid sequence
zeroCount = 0  # Assuming 'zeroCount' keeps track of zeros for a particular condition
c = [0] * 1000  # Assuming a large enough list to hold certificate elements

# if t_j = t_j+1 = ... = t_k−1 = t, then t is defined below, and all_equal is set to True
t = 3
all_equal = True

def run(k, j, index, x):
    global max, zeroCount, c

    # print()
    # print('seq:', c[1:index+1], 'len:', t, 'colour:', x, has_arithmetic_progression(c[1:index+1], x, t), len(c[1:index+1]))
    # print()
    if zeroCount > j:
        return
    if index > 0 and x > 0:
        # Checking if the indices of tx+j−1 x’s in c[1]...c[index] form an AP
        # if is_arithmetic_progression(c[1:index+1], x):
        if is_arithmetic_progression_of_colour(c[1:index+1], t, x):
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
        if i > 0 and all_equal:  # Assuming t[j:] are equal and check is needed
            if index <= j + (i - 1) * (t - 1) + 1:
                if any(c[index + 1] > c[l] for l in range(1, index + 1)):
                    break

def is_arithmetic_progression_of_colour(sublist: list, length, colour):
    # This function should implement the check for arithmetic progression
    # as per the specific requirements mentioned in the pseudocode.
    # Placeholder logic; needs actual implementation based on the document's specifics
    # print(sublist, len(sublist))
    count_of_colour = sublist.count(colour)
    colour_indices = [i for i, c in enumerate(sublist) if c == colour]

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
            # print(common_diff, progression, colouring)
            if all(c == colour for c in colouring):
                return True
    return False


def all_equal(lst):
    # Check if all elements in the list are equal
    return all(x == lst[0] for x in lst)

# Example of calling the run function
# The values for k, j, index, x, and t need to be defined as per the specific problem
# run(k, j, index, x, t)  # Example call, parameters need to be set


def has_arithmetic_progression(color_list, t, x):
    """
    This function checks if there's an arithmetic progression of size t
    for the color x in the given list color_list.
    
    :param color_list: List of integers/colors
    :param x: Target color to check for arithmetic progression
    :param t: Size of the desired arithmetic progression
    :return: True if there is an arithmetic progression of size t for color x; False otherwise
    """
    
    # Find all indices of color x
    indices = [i for i, color in enumerate(color_list) if color == x]
    
    # If there are less than t indices, we cannot form an AP of size t
    if len(indices) < t:
        return False
    
    # Check for any arithmetic progression of size t among indices
    for i in range(len(indices) - t + 1):
        # Calculate the difference between the first two indices
        diff = indices[i+1] - indices[i]
        # Assume there is an AP starting from this point
        is_ap = True
        for j in range(1, t):
            if not (i + j < len(indices) and indices[i + j] - indices[i + j - 1] == diff):
                is_ap = False
                break
        if is_ap:
            return True
    
    return False

# Example call to the function
# res = has_arithmetic_progression([0, 1, 1, 0, 1, 0, 1, 0], 0, 3)
res = run(2,0,0,0)
print(max+1)


# print(is_arithmetic_progression_of_colour([0, 0, 1, 1, 1, 1, 0, 1, 1, 1], 3, 1))