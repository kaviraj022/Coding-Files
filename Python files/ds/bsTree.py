def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
    def dfs(root):
        if not root:
            return None
        if(key>root.val):
            root.right=dfs(root.right)
        elif(key<root.val):
            root.left=dfs(root.left)
        else:
            if root.left and root.right:
                succ=root.right
                while(succ.left):
                    succ=succ.left
                root.val=succ.val
                root.right=self.deleteNode(root.right,succ.val)
            elif root.right:
                return root.right
            elif root.left:
                return root.left
            else:
                return None                
        return root
    return dfs(root)