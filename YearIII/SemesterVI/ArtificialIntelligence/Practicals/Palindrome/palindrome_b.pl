/**
 * 11. Write a prolog program to implement palindrome(L), 
 *          : which checks whether L is palindrome or not.
 * 
 * Author: Shubhang Gupta (19/78098)
 * 
*/

conc([], List, List).                            % Base Call
conc([Head | Tail], List2, [Head | Result]) :- 
  conc(Tail, List2, Result).                   % Recursive Call

reverse([], []).                            % Base Call
reverse([Head | Tail], R) :-
  reverse(Tail, RT),                      % Recursive Call
  conc(RT, [Head], R).

palindrome(L) :- reverse(L, L).
