#Node class
class Node:

    def __init__(self, data):
        self.data = data
        self.next = None

#Linked list class
class LinkedList:

    def __init__(self):
        self.head = None
	
    def push(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def reverse(self):
	#makes sure list is not empty or has only one value
        if self.head is None or self.head.next is None:
            return

        prev = None
        temp = self.head

        while temp:
            next_node = temp.next
            temp.next = prev
            prev = temp
            temp = next_node
        self.head = prev

    

    def print_list(self):
        temp = self.head
        List = []
        while temp:
            l1.append(temp.data)
            temp = temp.next
        return List

#Main to test reverse function
head = LinkedList()
head.push(77)
head.push(66)
head.push(55)
head.push(44)
head.push(33)
head.push(22)
head.push(11)
head.push(0)
print("Given list is: ", head.print_list())
head.reverse()
print("Reversed list is: ", head.print_list())