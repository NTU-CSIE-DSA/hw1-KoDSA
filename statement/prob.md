## Problem Description

Little Cucumber is developing "Digital Savage Arena (DSA)", a KoH-like (King of the Hill) video game, with a plan to release the alpha version on April 4th for gathering feedback from players. Unfortunately, he has been struggling with the scoring system for weeks, given his lack of practice in data structure courses. As you have survived the notorious HW0, can you help him with the final piece of the puzzle?

In DSA, players fight each other in an arena to obtain a higher ranking and earn points.The game consists of $N$ rounds and $N$ players. The $i$-th player has an attack power of $a_i$, and they will enter the arena at the beginning of round $i$. When a player enters the arena, they immediately kill all other players who have a lower attack power. 

The scoring system is based on the King of the Hill concept. At the end of each round, the player with the highest attack power becomes the King of DSA and earns $M$ points. The player with the second-highest attack power earns $M-1$ points, and so on. Only the alive players in the arena are accounted for the scoring system. If more than one people have the same attack power, the one entered earlier has a higher ranking. 

However, if the number of alive players in the arena exceeds $M$, a revolution will occur. In this case, the King of DSA, the player with the highest attacker power, will be overthrown and killed by the other $M$ players. 

For simplicity, each round of the game can be viewed as having 3 phases:
1. Player $i$ enters the arena and kills every other alive player who has a lower attack power. 
2. Check if a revolution occurs. 
3. Rank and award the alive players. 


## Input 

The first line contains two integers $N$ and $M$ -- the number of rounds (players) and the maximum point. 
The second line contains $N$ integers $a_1, a_2, \dots, a_n$ -- the attack power of the $i$-th player.

## Output 

The output should consist of $N+1$ lines. 
The first $N$ lines should begin with the string "`Round i:`", where $i$ is the round number.
Each of the $N$ lines should include the final scores for the players who died during that round. 
The last line should begin with the string "`Final:`", followed by the final scores of the players who are still alive at the end of the game.

Each piece of scoring information should consist of the player's index and their total score, separated by a comma, as follows: "`index,score`". 
Scoring information on each line should be separated by a space, sorted by the scoring in **ascending** order.
Please refer to the sample outputs for a clearer understanding of the expected output format. 

## Constraints

- $1 \le N \le 10^6$
- $1 \le M \le 10^3$
- $1 \le a_i \le 10^9$

### Subtask 1 (10 pts)

- $1 \le N \le 10^3$

### Subtask 2 (40 pts)

- It is guaranteed that revolution will never occur. 

### Subtask 3 (50 pts)

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
Round 4: 3,2
Round 5: 4,2 2,9
Round 6:
Round 7:
Round 8: 1,28
Round 9: 8,1
Round 10: 9,1 7,5
Final: 10,2 6,13 5,21
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
Round 4: 1,9
Round 5: 4,1 3,3 2,7
Round 6:
Round 7:
Round 8: 7,1 6,4
Final: 8,2 5,12
```

## Hints

- Please note the special memory limit for this problem. You are expected to use $O(M)$ memory only.
- If you receive a Runtime Error (RE) on the DSA judge, it is possible that you have exceeded the memory limit.
- Little Cucumber suggests players to visualize things rather than staring at them.