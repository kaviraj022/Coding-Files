def is_operator(ch):
    return ch in {"^", "/", "*", "+", "-", "(", ")"}


def prefix_to_infix(expression):
    stack = []
    for ch in reversed(expression):
        if not is_operator(ch):
            stack.append(ch)
        else:
            operand1 = stack.pop()
            operand2 = stack.pop()
            stack.append(f"({operand1}{ch}{operand2})")
    return "".join(stack)
