def precedence(ch):
    if ch == "^":
        return 3
    elif ch in {"/", "*"}:
        return 2
    elif ch in {"+", "-"}:
        return 1
    else:
        return 0


def is_operator(ch):
    return ch in {"^", "/", "*", "+", "-", "(", ")"}


def infix_to_postfix(infix):
    postfix = []
    stack = []

    for ch in infix:
        if not is_operator(ch):
            postfix.append(ch)
        else:
            if ch == "(":
                stack.append(ch)
            elif ch == ")":
                while stack and stack[-1] != "(":
                    postfix.append(stack.pop())
                stack.pop()
            else:
                while (
                    stack
                    and stack[-1] != "("
                    and precedence(ch) <= precedence(stack[-1])
                ):
                    postfix.append(stack.pop())
                stack.append(ch)

    while stack:
        postfix.append(stack.pop())

    return "".join(postfix)
