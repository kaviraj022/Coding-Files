def binary_to_decimal(s):
    decimal = 0
    for i, bit in enumerate(reversed(s)):
        if bit == "1":
            decimal += 2**i
    return decimal


def decimal_to_binary(num):
    if num == 0:
        return "0"
    binary = ""
    while num > 0:
        binary = str(num % 2) + binary
        num //= 2
    return binary
