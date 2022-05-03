/**
 * 12. Write a prolog program to implement sumlist(L, S),
 *          : so that S is the sum of a given list L.
 * 
 * Author: Shubhang Gupta (19/78098)
 * 
*/

sumlist([], 0).                            % Base Call
sumlist([Head | Tail], S) :-
  sumlist(Tail, S1), S is Head + S1.     % Recursive Call
