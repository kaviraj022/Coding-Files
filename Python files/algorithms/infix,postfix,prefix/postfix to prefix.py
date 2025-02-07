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


def infix_to_prefix(infix):
    infix = infix[::-1]
    infix = "".join(["(" if ch == ")" else ")" if ch == "(" else ch for ch in infix])
    postfix = infix_to_postfix(infix)
    return postfix[::-1]


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


def postToPre(post_exp):
    infix = postfix_to_infix(post_exp)
    return infix_to_prefix(infix)
