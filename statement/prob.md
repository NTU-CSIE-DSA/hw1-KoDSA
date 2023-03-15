## Problem Description

**Problem 4 described the basic (i.e. simplified) version of the game. Compared with the bonus version in Problem 5, this version is simpler by not having a "scoring system" in the game.**

Little Cucumber is currently developing "Digital Savage Arena" (DSA), a video game inspired by KoH (King of the Hill), with plans to release the alpha version on April 11th to collect feedback from players. However, he has been facing difficulties with the arena system for weeks due to his lack of study in the data structures and algorithms class. Since you have successfully completed the notorious Homework 0 in the class, can you assist him with solving the final piece of the puzzle?

In DSA, $N$ players compete in an arena to earn prestigious honor. The game consists of $N$ rounds. The $i$-th player, which carries an attack power of $a_i$, enters the arena at the beginning of the $i$-th round. As soon as the player enters the arena, ze kills all other players that hold a lower attack power.

At the end of each round, the player with the highest attack power is awarded the "King of DSA." In the event of a tie, the player who entered the arena earlier will be awarded the title. However, due to memory limitations, the size of the arena must be limited. If the number of surviving players in the arena exceeds $M$, a revolution will occur, resulting in the King of DSA being overthrown and killed by the other $M$ players.

In short, round $i$ of the game executes the following three steps orderly:
- Player $i$ enters the arena.
- Player $i$ kills all other players that hold a lower attack power.
- Check if a revolution occurs. If so, the King of DSA is killed.

Given the attack power of the $N$ players, can you help Little Cucumber calculate the players that are killed in each round?

## Input 

The first line contains two integers $N$ and $M$---the number of rounds (players) and the arena's maximum capacity. 
The second line contains $N$ integers $a_1, a_2, \dots, a_N$,  which is the attack power of each player, separated by space.

## Output

The output should consist of $N+1$ lines. The first $N$ lines should begin with the string "`Round i:`", where $i$ is the round number. Each of the $N$ lines should include the player(s) that are killed in that round. The last line should begin with the string "`Final:`", followed by the players who are still alive at the end of the game. When outputting the players (killed ones in the first lines and the surviving ones in the last line), print out the players' **indices** (the round that each of them entered the arena), sorted in **descending** order and separated by space.

## Constraint 
- $1 \le N \le 10^6$
- $1 \le M \le 10^3$
- $1 \le a_i \le 10^9$

### Subtask 1 (10 pts)
- $1 \le N \le 10^3$

### Subtask 2 (30 pts)
- It is guaranteed that a revolution will never occur. 

### Subtask 3 (60 pts)
- No other constraints.

## Hints 
- Please note the memory limit, which requires you to use $O(M)$ memory.
- If you receive a Runtime Error (RE) on the DSA judge, it is possible that you have exceeded the memory limit.
- Little Cucumber suggests you to carefully visualize how the game is played instead of staring at the numbers.

## Sample Testcases
### Sample Input 1
```
10 4
8 5 2 4 7 6 5 3 4 6
```

### Sample Output 1
```
Round 1:
Round 2:
Round 3:
Round 4: 3
Round 5: 4 2
Round 6:
Round 7:
Round 8: 1
Round 9: 8
Round 10: 9 7
Final: 10 6 5
```

### Sample Input 2
```
8 3
5 5 5 5 6 4 4 5
```

### Sample Output 2
```
Round 1:
Round 2:
Round 3:
Round 4: 1
Round 5: 4 3 2
Round 6:
Round 7:
Round 8: 7 6
Final: 8 5
```