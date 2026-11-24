# Day 1

The purpose of making this game is to also understand some cpp concepts and use them in a real scenario (this game).

First I will be learning about X-Macros.

These are used when you have this kind of problem:
This game will start out with having 3 elements, fire, ice and lightning (that can be used to attack), normally in cpp you would have to write the same list 3 times.
1. to create the enum (so the code knows the types exist)
2. inside a switch if we want to print "Fire" or make a sprite appear on screen.
3. inside another switch if we want to get each element's damage point

Now if we want to add poison a little later you would now have to update it in all the 3 above mentioned places and if you forget one, its a bug.

The simple solution to this is obviously X-Macros.

An X-Macro is a single master list of data that we feed into different #define X templates so the proprocessor writes our enum and switch statements automatically, keeping them 100% in sync.


Now operator overloading.

So this is quite simple, used when we want to change how an operator works with our custom structs.
Good:
- makes math comparisons easy to ready

Bad: 
- can be confusing if used ambiguously
- never overload && or ||, its a deadly sin


