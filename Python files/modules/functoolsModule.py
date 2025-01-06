from functools import reduce
'''
reduce(function, iterable, initializer=None): Applies a binary function cumulatively to the items in the iterable.
def multiply(a, b):
    return a * b
data = [1, 2, 3, 4]
result = reduce(multiply, data)
print(result)  # Output: 24 (1 * 2 * 3 * 4)
'''

from functools import lru_cache
'''
lru_cache(maxsize=128): A decorator that caches results of function calls to optimize repeated calls with the same arguments.
@lru_cache
def fib(n):
    if n < 2:
        return n
    return fib(n-1) + fib(n-2)
print(fib(10))  # Output: 55
'''

from functools import cache
'''
(Python 3.9+)
A simpler version of lru_cache with no maxsize limit.
'''

from functools import cached_property
'''
Turns a method into a cached property that computes its value only once.
class Circle:
    def __init__(self, radius):
        self.radius = radius

    @cached_property
    def area(self):
        print("Calculating area...")
        return 3.14159 * self.radius ** 2

c = Circle(10)
print(c.area)  # Output: Calculating area... 314.159
print(c.area)  # Output: 314.159 (cached value)
'''

from functools import partial
'''
# Define a simple function
def multiply(x, y):
    return x * y

# Create a partial function that multiplies by 2
double = partial(multiply, 2)

# Call the partial function
print(double(5))  # Output: 10
print(double(10))  # Output: 20
The double function is a partial application of multiply where x is pre-filled as 2.
You only need to provide the value for y when calling double.
'''

from functools import partialmethod

'''
Similar to partial, but works with methods in classes.
class MyClass:
    def greet(self, greeting, name):
        return f"{greeting}, {name}!"

    say_hello = partialmethod(greet, "Hello")

obj = MyClass()
print(obj.say_hello("Alice"))  # Output: Hello, Alice!
'''

from functools import total_ordering
'''

Simplifies the implementation of rich comparison methods (<, <=, >, >=) by deriving them from a single method (__lt__ or __eq__).

@total_ordering
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def __eq__(self, other):
        return self.age == other.age

    def __lt__(self, other):
        return self.age < other.age

p1 = Person("Alice", 30)
p2 = Person("Bob", 25)

print(p1 > p2)  # Output: True
'''

from functools import update_wrapper
'''
Updates a wrapper function to look more like the original function (e.g., name, docstring)
Use Case: When creating decorators, to retain metadata of the original function.

def my_decorator(func):
    def wrapper(*args, **kwargs):
        print("Before the function call")
        result = func(*args, **kwargs)
        print("After the function call")
        return result
    update_wrapper(wrapper, func)
    return wrapper
@my_decorator
def greet(name):
    """Greets a person."""
    print(f"Hello, {name}!")

print(greet.__name__)  # Output: greet
print(greet.__doc__)   # Output: Greets a person.
'''

from functools import wraps
'''
A shortcut for update_wrapper, used in decorators.
'''

from functools import singledispatch

'''
Provides a mechanism for single-dispatch generic functions, allowing function overloading based on argument types.

@singledispatch
def process(data):
    raise NotImplementedError("Unsupported type")

@process.register(int)
def _(data):
    return f"Processing integer: {data}"

@process.register(str)
def _(data):
    return f"Processing string: {data}"

print(process(42))    # Output: Processing integer: 42
print(process("hi"))  # Output: Processing string: hi
'''

from functools import singledispatchmethod
'''
A version of singledispatch for methods in a class.
'''

from functools import cmp_to_key
'''
cmp_to_key(func): Converts an old-style comparison function to a key function for sorting.
When to Use cmp_to_key:
    You have an old-style comparison function (common in Python 2 or certain legacy codebases).
    You need to adapt this comparison logic for use with modern Python sorting functions.
'''