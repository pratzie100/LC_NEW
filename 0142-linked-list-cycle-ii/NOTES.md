EXPLAINATION FOR DIFFERENT INTITIALISATIONS IN Leetcode 141 and Leetcode 142

1. **Detecting the Presence of a Cycle (`fast = head->next`)**:
   - When you are detecting whether a cycle is present or not, initializing the `fast` pointer to `head->next` creates an initial separation between the pointers.
   - This separation ensures that the `fast` pointer has room to enter the cycle and eventually catch up to the `slow` pointer if there is a cycle.
   - If there's no cycle, the `fast` pointer will eventually reach the end of the list (or `nullptr`).
   - This initialization guarantees that the pointers will meet inside the cycle if a cycle exists, or that they will separate if there's no cycle.

2. **Finding the Starting Node of the Cycle (`fast = head`)**:
   - When you are finding the starting node of the cycle, you already know that a cycle exists. You are not concerned about whether the pointers will meet; you're just trying to find the starting point.
   - To find the starting node of the cycle, you want both pointers to start at the same position so that you can measure the exact length of the cycle.
   - By initializing both pointers to `head`, you ensure that they meet at the starting node of the cycle and then move together to calculate the cycle's length.
   - Once you know the length, you can use a second pointer to move ahead by that length, while keeping the first pointer at the head. When they meet again, you have found the starting node of the cycle.

In summary, the choice of initialization for the `slow` and `fast` pointers depends on the specific task you're trying to accomplish. For detecting the presence of a cycle, you need an initial separation between the pointers. For finding the starting node of a cycle, you want them to meet at the same starting point so you can measure the cycle's length accurately.
