from itertools import combinations, permutations
'''
    itertools.permutations(iterable, r=None) - r value is optional
    itertools.combinations(iterable, r) - r value is compulsory
'''

from itertools import accumulate

'''nums = [1, 2, -3, 4, -2]
result = list(accumulate(nums))
print(result)  # [1, 3, 0, 4, 2]'''

from itertools import groupby
'''
groups consecutive elements of an iterable based on a specified key function.
itertools.groupby(iterable, key=None) - if key not specified group the iterables by consecutive elements

    data = [(1,1),(1,2),(3,1)]
    data.sort(key=lambda x: x[1]) //sort based on the category you wants to group
    grouped = groupby(data, key=lambda x: x[1])
    for key, group in grouped:
        print(key, list(group))
    # Output:
    # 1 [(1, 1), (3, 1)]
    # [(1, 2)]
'''

from itertools import zip_longest
'''
zip_longest(*iterables, fillvalue=None): Similar to zip() but fills the none/given value for unmatched indices
result = list(zip_longest([1, 2, 3], [4, 5], fillvalue=0))
print(result)  # Output: [(1, 4), (2, 5), (3, 0)]
'''

from itertools import product
'''
product(*iterables, repeat=1): Returns the Cartesian product of input iterables.
from itertools import product
result = list(product([1, 2], ['a', 'b']))
print(result)  # Output: [(1, 'a'), (1, 'b'), (2, 'a'), (2, 'b')]
'''
from itertools import starmap
'''
starmap(function, iterable): Applies the function to the items in the iterable(tuple values passed as argument), unpacking them if necessary.
from itertools import starmap
result = list(starmap(pow, [(2, 3), (3, 2), (10, 3)]))
print(result)  # Output: [8, 9, 1000]
'''

from itertools import count,cycle,repeat,chain
'''
count(start=0, step=1): Returns an infinite iterator that generates consecutive numbers.
for i in count(10, 2):
    if i > 20:
        break
    print(i)  # Output: 10, 12, 14, 16, 18, 20

cycle(iterable): Returns an iterator that cycles through an iterable indefinitely.
count = 0
for x in cycle('AB'):
    if count == 6:
        break
    print(x)  # Output: A B A B A B
    count += 1

repeat(item, times=None): Repeats the item a specific number of times (or infinitely if times is not specified).
from itertools import repeat
for x in repeat(10, 3):
    print(x)  # Output: 10 10 10

chain(*iterables): Chains multiple iterables together into one continuous iterable.
from itertools import chain
result = list(chain([1, 2], [3, 4], [5, 6]))
print(result)  # Output: [1, 2, 3, 4, 5, 6]

'''