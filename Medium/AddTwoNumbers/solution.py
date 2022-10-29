# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        num1 = ''
        num2 = ''
        current = l1
        while current != None:
            num1 = str(current.val) + num1
            current = current.next
        current = l2
        while current != None:
            num2 = str(current.val) + num2
            current = current.next
        total = str(int(num1) + int(num2))[::-1]
        output = ListNode(int(total[0]))
        current = output
        for char in total[1:]:
            current.next = ListNode(int(char))
            current = current.next
        return output
        
