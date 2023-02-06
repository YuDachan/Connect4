Name: Dachan Yu
ONID: 933832577
Section: CS 161
Assignment 5, due 3/13/2021

Description:

Lets play a cool game of connect four with a questionable AI!

Instructions:

1) Compile the program with

g++ ass5.cpp -o ass5

2) Run the program with

./ass5 #player(1 or 2) rows columns

3) If command line arguments were ont entered correctly, you must enter in the info again.

If info is not entered correctly:
	-Asks for single/multi player
	-Asks for number of columns
	-Asks for number of rows
	-Asks who goes first (only in singleplayer)

Once game has started, choose a column you'd like to put your disk in
Repeat until you win.

If game has finished, it will ask if you would like to play again

4) Limitations:
- There is no way to undo a move.
- Sometimes the AI chooses a poor number multiple times so you must spam enter a few times.

5) Extra credit:
- the AI will try to win only under very specific circumstances. (I would add more but I could not go over 20 lines)
AI will recognize a win in if player goes first and the CPU sees that the winning move is horizontal