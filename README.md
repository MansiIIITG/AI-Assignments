# AI-Assignments

--> 8 QUEENS USING A*

Initial state : An empty board, in this case queue i.e. no queen present on the board

Set of states : The states are the number of queens that lie between 0 to 8, these are the column numbers of the ith row, on ith index of the vector

state operation : The operation is to move queen to left most empty column on the next row on the board such that neither does it attack nor is attcked by the present queens.

path cost : The path cost is same for states at each level.
			The cost of first level is 1, then it keeps increasing by 1 and reaches till 8;

Goal state : A board with 8 queens present on it , all in non attacking positions

Heuristic function : h(n) = n - i, where  n is the number of queens on board and i is the row where queen is being placed.

--> 8 QUEENS USING UCS 

Initial state : An empty board, in this case queue i.e. no queen present on the board

Set of states : The states are the number of queens that lie between 0 to 8, these are the column numbers of the ith row, on ith index of the vector

state operation : The operation is to move queen to left most empty column on the next row on the board such that neither does it attack nor is attcked by the present queens.

path cost : The path cost is same for states at each level.
			The cost of first level is 1, then it keeps increasing by 1 and reaches till 8;

Goal state : A board with 8 queens present on it , all in non attacking positions


--> GENETIC ALGORITHM

Encoding         : Dividing students into 3 groups

Gene             : A list of weights of students randomly chosen in the range of 50 to 80

Population       : A given number of collection of genes

Fitness function : Average of the variance of the three groups

Crossover        : Single-point crossover with randomly deciding the index/point

Mutation         : Randomly checking whether to do mutation, and if we have to do mutation then we randomly pick up an index to mutate

--> GAME OF STICKS 

I have used min max graph with alpha beta pruning for this prblem.
There are two options to play this game : Bot vs Bot or Bot vs AI.
You have to choose which player will go first. The initial value of alpha is -infinity and beta is +infinity.

