# HW3

I was unable to understand Java threads well enough to be able to implement my own concurrent list in Java.  I tried to implement it in C++ but I've also had difficulties with that, and looking over the question of why there are more gifts than thank you cards, I just realized my implenetation was off.  I was having the servants randomly select their tasks when they should be alternating.  This is why there will be more gifts than thank you cards because the servants criteria for completion is emptying the bag of gifts, thus at least some of the final gifts pulled from the bag will go without a thank you note.  The best way to solve both problems would be to implement a concurrent list, I believe the best implementation would be some form of skiplist.  I dont have time to finish this assignment, but I need at least the 20% for documentation and any other points you're willing to spare.

To compile and run what I have:

g++ Minotaur_Chain.cpp && ./a.out
