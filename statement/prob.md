## Problem Description

**This is an easy version of the problem. This version has no scoring system.**

Little Cucumber is developing "Digital Savage Arena (DSA)", a KoH-like (King of the Hill) video game, with a plan to release the alpha version on April 4th for gathering feedback from players. Unfortunately, he has been struggling with the arena system for weeks, given his lack of practice in data structure courses. As you have survived the notorious HW0, can you help him with the final piece of the puzzle?

In DSA, players fight each other in an arena to obtain prestigious honor. The game consists of $N$ rounds and $N$ players. The $i$-th player has an attack power of $a_i$, and they will enter the arena at the beginning of round $i$. When a player enters the arena, they immediately kill all other payers who have a lower attack power. 

Each round, the player with the highest attack power will gain the title "King of DSA". If two or more players have the same attack power, the one entered earlier will take the honor. However, due to the limited memory, the arena cannot be too big. If the number of alive players in the arena exceeds $M$, a revolution will occur. In this case, the King of DSA will be overthrown and killed by the other $M$ players. 

For simplicity, each round of the game can be viewed as having 3 phases:
- Player $i$ enters the arena
- Player $i$ kills every other alive player who has a lower attack power. 
- Check if a revolution occurs. 

Given the attack power of the $N$ players, can you help Little Cucumber calculate the death events in each round?

## Input 

The first line contains two integers $N$ and $M$ -- the number of rounds (players) and the maximum point. 
The second line contains $N$ integers $a_1, a_2, \dots, a_n$ -- the attack power of the $i$-th player.

## Output 


The output should consist of $N+1$ lines. The first $N$ lines should begin with the string `Round i: `, where $i$ is the round number. Each of the $N$ lins should include the player(s) died during that round. The last line should begin with the string `Final: `, followed by the players who are still alive at the end of the game.

If more than one people died in one round, one should output the player **indices** in **ascending** order, separated by a space. Please refer to the sample outputs for a clearer understanding of the expected output format. 

## Constraints

- $1 \le N \le 10^6$
- $1 \le M \le 10^3$
- $1 \le a_i \le 10^9$

### Subtask 1 (10 pts)

- $1 \le N \le 10^3$

### Subtask 2 (30 pts)

- It is guaranteed that revolution will never occur. 

### Subtask 3 (60 pts)

- No other constraints.

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

## Hints

- Please note the special memory limit for this problem. You are expected to use $O(M)$ memory only.
- If you receive a Runtime Error (RE) on the DSA judge, it is possible that you have exceeded the memory limit.
- Little Cucumber suggests players to visualize things rather than staring at them.