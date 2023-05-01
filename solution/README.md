# Tutorial
keywords: `monotonic queue`, `difference array`, `circular queue`

## Dying Round
We can maintain the rankings with a deque. For each player $i$: we `pop_back` every player who has a lower attack power, then `push_back` it. This remains to be a decreasing sequence. If the size exceeds $M$, we `pop_front`. 

## Score Calculation
Notice that regardless a revolution has occurred or not, a ranked $i$ player gains one extra point each round than a ranked $i+1$ player. Therefore, if we subtract the total points of each player by $\text{alive\_time}$, the difference of the remaining points, lets call it $\text{pt}_{\text{r}}$, between player $i$ and $i+1$ will never change. Since $\text{alive\_time}$ can be easily calculated via subtracting its leaving time by its enter time (or equivalently, its $\text{id}$), we only need to maintain $\text{pt}_{\text{r}}$.

Suppose that we have $\text{pt}_{\text{r}}$ of the highest ranked player (`front` element in deque) and the lowest ranked player (`back` element in deque). With the point difference between each pair of players with adjacent ranks, which does not change during the game, we can update `front` and `back` accordingly on each `pop_back` and `pop_front` in $O(1)$ time. 

To maintain $\text{pt}_{\text{r}}$ of `front`, we can simply add $M$ points on each round. As for `back`, since it is always the newest player, its $\text{pt}_{\text{r}}$ is always $M - \text{deque.size} - 1$. 

## Limited Memory

Since the deque size will not exceed $M$, we can use a circular deque with size $M$. 
Utilizing `malloc` and `free` is also viable but not recommended due to its difficult implementation.
