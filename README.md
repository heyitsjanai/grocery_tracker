# grocery_tracker
SNHU CS-210 Portfolio Submission

This is Project 3 - creating a grocery-tracking program that displays a menu to the user, gets input,
& displays certain grocery-tracking functions. It uses an input file which I named "dailyPurchases"
as the data input, gets user selection input, & displays either a) a word frequency counter list of every 
item purchased that day (data used from "dailyPurchases.txt" file), b) a specific word frequency counter 
(user-input that is word specific), or c) a text-based histogram that replaces the number with a visual
asterik. 

Each function in itself is functional, implementing for & while loops efficiently, but I would like to enhance
the code by adding more data validation. For example, in menu option 2, I would like to add more
user-input validation. If the user enters an item that is not on the list, I need to add a case for this.

The most challenging piece of the code to write would be the wrapper that allows the programming languages
C++ & Python to interact with each other, however, there is something wrong in this code, as I did not write it,
I was given the wrapper as a starting point. I would like to learn more about this piece of the code & correct it
so that my functions are properly displaying output. As it stands now, the C++ function "CallProcedure" is
not functioning correctly. I need to go back & check my settings in Visual Studios, make sure the correct 
version of all languages are being used, & what else needs to be changed to correctly get output.
I referenced StackOverflow for the same types of problems, & the consensus is it is an incorrect object being dereferenced, so I would like to learn more about this and how to fix.

Using multiple languages will come in handy in many projects to come. I need to get familiar and comfortable
using different languages together to make the most efficient programs in the future.

By posting this project here, I am making this program maintanable, readable,
and adaptable even with future changes I will be making to it. Any changes, help, or guidance going forward
with this program would be welcomed.

-Janai C.
