# Last updated: 1/19/2026, 8:48:01 PM
1# Definition for singly-linked list.
2# class ListNode(object):
3#     def __init__(self, val=0, next=None):
4#         self.val = val
5#         self.next = next
6class Solution(object):
7    def addTwoNumbers(self, l1, l2):
8        """
9        :type l1: Optional[ListNode]
10        :type l2: Optional[ListNode]
11        :rtype: Optional[ListNode]
12        """
13
14        #Temporary list head for returning the start of the result list
15        temp = ListNode(0)
16        curr = temp
17        carry = 0
18
19        #Loop through the nodes or if there is a carry over digit
20        while l1 or l2 or carry:
21            val1 = l1.val if l1 else 0
22            val2 = l2.val if l2 else 0
23
24            total = val1 + val2 + carry
25            carry = total // 10
26            newVal = total % 10
27
28            #Create the new node and move result pointer
29            curr.next = ListNode(newVal)
30            curr = curr.next
31
32            #Move to next input pointers
33            if l1:
34                l1 = l1.next
35            if l2:
36                l2 = l2.next
37
38        return temp.next
39        