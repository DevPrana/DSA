## Time Complexity
---
Time complexity is defined as the amount of time taken to run the algorithm as a function of the length of input.
It does not represent the time taken to execute all the statements in an algorithm rather it gives information on the varaitions in time when we increase the number of operations in the algorithm

Ex. An algorithm might take different amount of time to run in different machines but time complexity represnts the amount of time taken as we increase or decrease the statements inside our code.

### Big-Oh 'O' notation:
Represents the worst case complexity of an algorithm if an algorithm is said to be O(N^3) it means that the true functions might have variations of a function `f(N)= 7N^3 + 6N^2 + 3N + 5`
but since the worst is N^3 so big oh will take the worse argument remove constants making it O(N^3)

`f(N) = O(g(N))` Implies that growth of f in terms of complexity is not faster than `g(N)`



### Big Omega notation:
Unlike the Big Oh notations Big Omega represents the best case of a functions for example in our previous `f(N)= 7N^3 + 6N^2 + 3N + 5` the big omega will be Omega(1) since there is a also a constant term present.

---

## Space Complexity

Refers to the space occupied by an algorithm where the space represent input space + auxillary space where input space is the space our input takes and auxillary space is the space which our algorithm uses for example if we map a heap it tkaes f(N) space where N is the length of the input. Hence our auxillary space depends on the size of the input since while mapping our input parameters in a heap we create a unit space for each element in our input.

### Recursive algorithms Space analysis
It refers to the space our recursive algorithm occupies inside the Stack.

For example in a `fibbonacci sequence` recursive algorithm we call fib(N)= fib(n-1) + fib(n-2)
which forms a recurive tree in this recursive tree all the fib calls cannot be present in the stack at the same time this is because when we do fib(N)= fib(n-1) + fib(n-2) We call fib(n-1) first everytime and till tis fib(n-1) has not finished executing by getting its value forming from its own implementation fib(n-2) will not execute. This makes it so that fib(n-1) will have to finish first and fib(n-1) will call fib(n-2) and fib(n-3) but fib (n-2) will ahve to finish first this causes our stack to never be occupied by two stacks from the same level in a recursive tree.

#### Infix to Postfix
If there is an operand append to postfi<br>
Character is left parenthesis then Push<br>
Character is Right parenthesis then pop all values from stack and append to postfix expression until left parenthesis is ignored<br>
While precendence of input character is less than precedence of stack top append it to postfix
If precedence of input character is greater than or equal to then push to `TODO`<br>
Repeat 3 to 7 pop all the operators from stack then 

