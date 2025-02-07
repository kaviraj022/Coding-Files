def is_operator(ch):
    return ch in {"^", "/", "*", "+", "-", "(", ")"}


def postfix_to_infix(postfix):
    stack = []
    for ch in postfix:
        if is_operator(ch):
            a = stack.pop()
            b = stack.pop()
            stack.append("(" + b + ch + a + ")")
        else:
            stack.append(ch)
    return "".join(stack)
