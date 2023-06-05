'''Implement all the functions of a dictionary (ADT) using hashing and handle collisions 
using chaining with / without replacement. 
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, 
Keys must be unique. Standard Operations: Insert(key, value), Find(key), Delete(key) 

CODE GENERATED USING ChatGPT
'''

class KeyValuePair:
    def __init__(self, key, value):
        self.key = key
        self.value = value


class Dictionary:
    def __init__(self):
        self.size = 10  # Initial size of the hash table
        self.table = [[] for _ in range(self.size)]  # Hash table using lists

    def hash_function(self, key):
        # A simple hash function to calculate the index based on the key
        return hash(key) % self.size

    def insert(self, key, value):
        index = self.hash_function(key)
        chain = self.table[index]

        # Check if the key already exists in the dictionary
        for item in chain:
            if item.key == key:
                item.value = value  # Update the existing key-value pair
                return

        chain.append(KeyValuePair(key, value))  # Insert a new key-value pair

    def find(self, key):
        index = self.hash_function(key)
        chain = self.table[index]

        # Search for the key in the chain
        for item in chain:
            if item.key == key:
                return item.value  # Return the value associated with the key

        return None  # Key not found

    def delete(self, key):
        index = self.hash_function(key)
        chain = self.table[index]

        # Search for the key in the chain and remove it
        for i, item in enumerate(chain):
            if item.key == key:
                del chain[i]  # Delete the key-value pair
                return

    def display(self):
        # Display the contents of the dictionary
        for index, chain in enumerate(self.table):
            print(f"Index {index}: ", end="")
            for item in chain:
                print(f"({item.key}, {item.value}) ", end="")
            print()


# Driver code
dictionary = Dictionary()

while True:
    print("\n------ Dictionary Menu ------")
    print("1. Insert a key-value pair")
    print("2. Find a value by key")
    print("3. Delete a key-value pair")
    print("4. Display the dictionary")
    print("0. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 0:
        print("Exiting the program... Goodbye!")
        break
    elif choice == 1:
        key = input("Enter the key: ")
        value = input("Enter the value: ")
        dictionary.insert(key, value)
        print("Key-value pair inserted successfully!")
    elif choice == 2:
        key = input("Enter the key to find: ")
        value = dictionary.find(key)
        if value is not None:
            print(f"Value found: {value}")
        else:
            print("Key not found!")
    elif choice == 3:
        key = input("Enter the key to delete: ")
        dictionary.delete(key)
        print("Key-value pair deleted successfully!")
    elif choice == 4:
        dictionary.display()
    else:
        print("Invalid choice! Please try again.")
