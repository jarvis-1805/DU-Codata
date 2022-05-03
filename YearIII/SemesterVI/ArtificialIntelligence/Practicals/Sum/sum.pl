/**
 * 1. Write a prolog program to calculate the sum of two numbers.
 * 
 * Author: Shubhang Gupta (19/78098)
 * 
 */

sum(X, Y):- 
  S is X + Y, 
  write('Sum is: '), 
  write(S).
