from collections import Counter
'''
return 0 if key not present

elements(): Returns an iterator over the elements, including repetitions.
keys(), values(), items(): Methods for accessing keys, values, and items in the Counter.
most_common(n): Returns the most common elements and their counts.
                If n is not specified, it returns all elements ordered by frequency.
clear(): Removes all elements from the Counter.
for both of the below operation the count update based on the occourance in case of iterables and key:values in case of dictionary
    subtract([iterable-or-mapping]): Subtracts counts from the Counter.
    update([iterable-or-mapping]): adds counts with new elements in the Counter.
'''

from collections import defaultdict
'''
return empty object if the key not present
supports both builtin functions and classes if the count
'''

from collections import deque
'''
all list functions will works and some special features are there too
appendleft()
popleft()
rotate(n)
dq = deque([1, 2, 3, 4, 5])
dq.rotate(2) #same output if we use -2
print(dq)  # Output: deque([4, 5, 1, 2, 3])
'''

from collections import namedtuple
'''
for creating tuple subclasses with named fields.
# Define a namedtuple type
MyTuple = namedtuple('MyTuple', ['field1', 'field2', 'field3'])

# Create an instance of the namedtuple
instance = MyTuple(field1='value1', field2='value2', field3='value3')

# Access elements using field names
print(instance.field1)  # Output: value1
print(instance.field2)  # Output: value2
'''

from collections import ChainMap
'''
A class for linking multiple mappings into a single view.
d1 = {'a': 1, 'b': 2}
d2 = {'b': 3, 'c': 4}
cm = ChainMap(d1, d2)
print(cm)  # Output: ChainMap({'a': 1, 'b': 2}, {'b': 3, 'c': 4})
'''

from collections import OrderedDict
'''
A dictionary that maintains the order in which keys are inserted.
d = OrderedDict([('a', 1), ('b', 2)])
d['c'] = 3
print(d)  # Output: OrderedDict([('a', 1), ('b', 2), ('c', 3)])

usage for LRU Cache
class LRUCache:
    def __init__(self, capacity: int):
        self.cache=OrderedDict()
        self.capacity=capacity
        self.ln=0
    def get(self, key: int) -> int:
        if key in self.cache:
            self.cache.move_to_end(key) #can have last = False to denote first
            return self.cache[key]
        return -1
    def put(self, key: int, value: int) -> None:
        if(key in self.cache):
            self.cache[key]=value
        elif(self.ln==self.capacity):
            self.cache.popitem(last=False) #can have last = False to denote first
            self.cache[key]=value
        else:
            self.cache[key]=value
            self.ln+=1
        self.cache.move_to_end(key)

'''

from collections import UserDict,UserList,UserString
'''
UserDict, UserList, UserString: Classes for easily subclassing dictionary-like objects.
'''