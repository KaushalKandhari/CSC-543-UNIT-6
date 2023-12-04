from collections import defaultdict

class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

def generate_huffman_codes(characters, frequencies):
    def build_tree(characters, frequencies):
        nodes = []
        for i in range(len(characters)):
            nodes.append(Node(characters[i], frequencies[i]))

        while len(nodes) > 1:
            nodes = sorted(nodes, key=lambda x: x.freq)

            left = nodes[0]
            right = nodes[1]

            new_node = Node('$', left.freq + right.freq)
            new_node.left = left
            new_node.right = right

            nodes.remove(left)
            nodes.remove(right)
            nodes.append(new_node)

        return nodes[0]

    def generate_codes(node, code, huffman_codes):
        if node:
            if node.char != '$':
                huffman_codes[node.char] = code
            generate_codes(node.left, code + '0', huffman_codes)
            generate_codes(node.right, code + '1', huffman_codes)

    root = build_tree(characters, frequencies)
    huffman_codes = {}
    generate_codes(root, '', huffman_codes)
    return huffman_codes

def main():
    array_size = int(input("Enter the size of the character array: "))
    characters = []
    frequencies = []

    print("Enter the characters and their frequencies:")
    for i in range(array_size):
        char = input(f"Character {i + 1}: ")
        freq = int(input(f"Frequency {i + 1}: "))
        characters.append(char)
        frequencies.append(freq)

    codes = generate_huffman_codes(characters, frequencies)
    print("\nHuffman Codes:")
    for char, code in codes.items():
        print(f"{char}: {code}")

if __name__ == "__main__":
    main()
