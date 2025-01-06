import queue
'''
queue.Queue: FIFO (First In, First Out) queue.
queue.LifoQueue: LIFO (Last In, First Out) queue (like a stack).
queue.PriorityQueue: A priority queue where elements are sorted by priority.
    q = queue.Queue(maxsize=3)          Declaring size is optional
    put(item, block=True, timeout=None)	Adds item to the queue. Blocks if the queue is full (optional timeout).
    get(block=True, timeout=None)	    Removes and returns the first item. Blocks if the queue is empty (optional timeout).
    qsize()	                            Returns the approximate size of the queue.
    empty()                         	Returns True if the queue is empty, otherwise False.
    full()	                            Returns True if the queue is full(only if maxsize is specified), otherwise False.
'''

import heapq
'''
heapify()
heappush()
heappop()
heappushpop() - first push and then pop
heapreplace() - first pop and then push
nlargest() and nsmallest() - if n>len(heap) it works fine and give entire heap andd didn't raise error
merge() - merge more than 1 heaps
'''

import bisect
'''
bisect.bisect_left(a, x, lo=0, hi=len(a)) - returns position
bisect.bisect_right(a, x, lo=0, hi=len(a))
bisect.insort_left(a, x, lo=0, hi=len(a)) - insert the value in the list
bisect.insort_right(a, x, lo=0, hi=len(a))
'''

from sortedcontainers import SortedList,SortedDict,SortedSet
'''
sortedcontainers is optimized for performance. It uses a binary search tree internally, ensuring:
    O(log n) for most operations like add, remove, and lookup.
    O(n) for iteration over all elements.

To use sortedcontainers, you need to install it via pip:
    pip install sortedcontainers


sl = SortedList([5, 2, 9, 1])
sd = SortedDict({'b': 2, 'a': 1, 'c': 3})
ss = SortedSet([5, 2, 9, 1, 5])

Key Methods for All SortedContainers:
add(item):          Adds an item to the container.
remove(item):       Removes an item from the container.
discard(item):      Removes an item if it exists; does nothing otherwise.
clear():            Removes all items from the container.
__contains__(item): Checks if an item exists in the container.
__len__():          Returns the number of elements in the container.
__iter__():         Iterates over elements in sorted order.
index(value):       Returns the index of an item.
count(value):       Returns the count of an item.
isdisjoint(other):  Checks if the container and other share no elements.
'''

import string
'''
string.function
ascii_letters	All ASCII letters (lowercase + uppercase)
ascii_lowercase	Lowercase ASCII letters
ascii_uppercase	Uppercase ASCII letters	
digits	        All digit characters	
hexdigits	    Hexadecimal characters
octdigits	    Octal digits
punctuation	    Printable punctuation characters	!"#$%&'()*+,-./:;<=>?@[\\]^_{
printable	    All printable characters	Letters, digits, punctuation, and whitespace
whitespace	    Whitespace characters	\t\n\r\x0b\x0c
'''

import re
'''
re.fullmatch(pattern,string) - for regular expression matching
re.findall(pattern,string) - finds all non-overlapping matches of the pattern in the string and returns them as a list
re.sub(pattern, replacement, text) - replaces parts of the string that match the pattern with a specified replacement.
    pattern = r"\d+"  # Match one or more digits
    text = "There are 3 cats, 4 dogs, and 5 birds."

.: Matches any character except a newline.
^: Matches the beginning of a string.
$: Matches the end of a string.
*: Matches 0 or more repetitions of the preceding pattern.
+: Matches 1 or more repetitions of the preceding pattern.
?: Matches 0 or 1 repetition of the preceding pattern.
[]: Matches any one of the characters inside the brackets.
\d: Matches any digit (equivalent to [0-9]).
\w: Matches any word character (alphanumeric or underscore).
\s: Matches any whitespace character (spaces, tabs, newlines).
|: Matches either the pattern before or the pattern after it (OR operator).
(): Groups patterns together.

    # Pattern to match an email address
    pattern = r"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})"
'''

from typing import List, Set, Tuple, Optional
'''
ensure the datatype
'''

import random
'''
Basic Random Number Functions
random.random()

Returns a random floating-point number in the range [0.0, 1.0).
random.randint(a, b)

Returns a random integer N such that a <= N <= b.
random.uniform(a, b)

Returns a random float N such that a <= N <= b.
random.choice(sequence)

Returns a randomly selected element from a non-empty sequence (like a list, tuple, or string).
random.shuffle(sequence)

Shuffles the elements of a sequence in place.
'''