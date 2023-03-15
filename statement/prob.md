## Problem Description

**Problem 5 described the bonus (i.e. hard) version of the game. Compared with the basic version in Problem 4, this version is harder by having a "scoring system" in the game.** We allocate **only 20** bonus (extra) points for this problem. That is, your score for HW1 can be as high as $520$. Somehow calling the problem "bonus" means we do not expect everyone to try to solve the problem---you are recommended to solve other problems first before visiting this problem.

Our story is exactly the same as Problem 4, except that Little Cucumber decides to add a scoring system to the game. 
After confirming the players that are alive in each round, the player with the highest attack power (i.e. King of DSA) earns $M$ points. The player with the second-highest attack power earns $M-1$ points, and so on. Only the surviving players in the arena are given points. Ties are broken by the order that the players entered the arena---i.e. the player that enters earlier earns more points.

In short, round $i$ of the game executes the following three steps orderly:
- Player $i$ enters the arena.
- Player $i$ kills all other players that hold a lower attack power.
- Check if a revolution occurs. If so, the King of DSA is killed.
- **Assign points to the surviving players.**

Given the attack power of the $N$ players, can you help Little Cucumber calculate not only the players that are killed in each round, but also their scores (accumulated points)?

## Input

The first line contains two integers $N$ and $M$---the number of rounds (players) and the arena's maximum capacity. $M$ also means the points given to King of DSA in each round.
The second line contains $N$ integers $a_1, a_2, \dots, a_N$,  which is the attack power of each player, separated by space.

## Output
The output should consist of $N+1$ lines. The first $N$ lines should begin with the string "`Round i:`", where $i$ is the round number. Each of the $N$ lines should include the player(s) that are killed in that round. The last line should begin with the string "`Final:`", followed by the players who are still alive at the end of the game. 

When outputting the players (killed ones in the first lines and the surviving ones in the last line), print out the players, separated by space, in the **descending** order of their **indices** (the round that each of them entered the arena). Each player should be outputted as a string that consists of zir index and total score, separated by a comma, like "`index,score`". 

## Constraints
- $1 \le N \le 10^6$
- $1 \le M \le 10^3$
- $1 \le a_i \le 10^9$

### Subtask 1
- $1 \le N \le 10^3$

### Subtask 2
- It is guaranteed that revolution will never occur. 

### Subtask 3
- No other constraints.

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