# Introduction To C
I have learnt C in my undergraduate days, as my first programming language in Electrical/Electronics engineering, but never saw real application for the language. At that time it was to explain the 2's compliment and how machine store bits internally on the memory of the machine and how the different arithmetic calculations are carried at the low level. All of these were taught in the computer architecture class.

Today i am trying to build a database software and simulated machines and i need the direct control C offers programmers. So i have to go learn the language from scratch. And the experience has been great!
## Challenges And Solutions
1. Of Course one of the greatest challenge for learning C is understanding pointers and how they relate with arrays. It took me one week, but after i understand the precedence rule and associativity. Then i got it! I applied what i know to know what i don't know, i.e., learn by analogy, for example, if an array is:
**int x[20]={0};** to initialize the first element to **20** you write **x[0] = 20;**. This can read as set the first element at index 0 to 20. But to read the first element into another variable let say **int y=0;** we will have to write **y=x[0];**. This read set value of y to first element of the x array at index 0. This can also be applied to pointers. Once a pointer has been created, based on the side of the assignment operator, **=**, it can be read different,i.e., `lvalue` or `rvalue`. if a pointer is created let say **int * yPtr = &y;** .Then if is on the left side (i.e., *lvalue* , ***yPtr**) it should be read as set the value that is been reference by yPtr to what ever on the rightside (i.e., *rvalue*). Likewise the same for when it is on the right side.
2. Ability to use the **sizeof** operator with array and pointers. It took me 3 days to figure this out. Again is the ability to read or speak it well that matters. This is how i read it now. Get me the number of byte this variable, let say x consume in memory at this `address` represented by the variable x. The variable can be an array, pointer or just an int variable.
3. Understanding arrays and how arrays are contiguous blocks of memory and indexes are calculated from the beginning of the array.


## What to find in this subdirectories
Every folder contains different test of the ideas, that is the name of the folders. But not just that, in each of the folder, there is game for you to play! All you to do install your gcc compiler and compile my source code, to play your fun game. But to start read the comments at the beginning of the source code. 

### Thank You For reading!