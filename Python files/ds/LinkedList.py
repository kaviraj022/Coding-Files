class Node:
  def __init__(self,val):
    self.val = val
    self.next = None
class LinkedList:
  def __init__(self):
    self.headNode = None
    self.lastNode = None
    self.length = 0
  def isEmpty(self):
    return self.headNode == None
  def addNode(self,val):
    nd = Node(val)
    if self.isEmpty():
      self.headNode = self.lastNode = nd
    else:
      self.lastNode.next = nd
      self.lastNode = nd
    self.length+=1
  def display(self):
    curr = self.headNode
    while curr!=None:
      print(curr.val,end=" ")
      curr = curr.next
    print()
LL = LinkedList()
LL.addNode(12)
LL.addNode(78)
LL.addNode(100)
LL.addNode(25)
LL.display()