# 42-Filler
The filler project from 42, a basic game playing algorithm.

The rules of the game are that each player must place their piece and receives a point for doing so. The game ends when all player can no longer place a piece. It is invalid to place a piece if it would overlap the board and all placed shapes must overlap an already placed shape in one but no more positions. The shapes cannot be rotated in any way.

#usage
```sh
./ressources/filler_vm -p1 [ressources/.filler | ./filler] -p2 [ressources/.filler | ./filler] -f [maps/*.map]
```
