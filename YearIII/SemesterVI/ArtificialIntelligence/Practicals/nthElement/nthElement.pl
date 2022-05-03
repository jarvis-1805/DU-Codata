/**
 * 14. Write a Prolog program to implement nth_element(N, L, X),
 *        : where N is the desired position, L is a list and X represents the Nth element of L.
 * 
 * Author: Shubhang Gupta (19/78098)
 * 
 */

nth_element(N, [Head | _], X) :-
  N == 0, X is Head.                    % Base Case

nth_element(N, [_ | Tail], X) :-
  N1 is N - 1,
  nth_element(N1, Tail, X).             % Recursive Call
