from collections import defaultdict

class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)  # Automatically create new TrieNode when accessing a missing key
        self.is_end_of_word = False  # To mark the end of a word


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        """
        Inserts a word into the Trie.
        """
        node = self.root
        for char in word:
            node = node.children[char]
        node.is_end_of_word = True

    def search(self, word):
        """
        Searches for a word in the Trie.
        Returns True if the word exists, False otherwise.
        """
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]
        return node.is_end_of_word

    def starts_with(self, prefix):
        """
        Checks if there is any word in the Trie that starts with the given prefix.
        Returns True if such a prefix exists, False otherwise.
        """
        node = self.root
        for char in prefix:
            if char not in node.children:
                return False
            node = node.children[char]
        return True

    def delete(self, word):
        """
        Deletes a word from the Trie if it exists.
        """

        def delete_recursive(node, word, index):
            # Base case: If we've reached the end of the word
            if index == len(word):
                if not node.is_end_of_word:
                    return False  # Word not found
                node.is_end_of_word = False
                return len(node.children) == 0  # If no children, delete this node

            char = word[index]
            if char not in node.children:
                return False  # Word not found

            should_delete_child = delete_recursive(node.children[char], word, index + 1)

            # If the child node should be deleted, remove it from the children
            if should_delete_child:
                del node.children[char]
                return len(node.children) == 0 and not node.is_end_of_word

            return False

        delete_recursive(self.root, word, 0)


# Example Usage
trie = Trie()

# Insert words into the Trie
trie.insert("apple")
trie.insert("app")
trie.insert("bat")
trie.insert("ball")

# Search for words
print(trie.search("apple"))  # True
print(trie.search("app"))    # True
print(trie.search("bat"))    # True
print(trie.search("cat"))    # False

# Check for prefixes
print(trie.starts_with("app"))  # True
print(trie.starts_with("ba"))   # True
print(trie.starts_with("ca"))   # False

# Delete a word
trie.delete("app")
print(trie.search("app"))    # False
print(trie.search("apple"))  # True (other words with "app" prefix still exist)
