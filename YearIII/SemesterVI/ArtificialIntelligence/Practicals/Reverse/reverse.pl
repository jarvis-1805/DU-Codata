/**
 * 10. Write a Prolog program to implement reverse(L, R),
 *        : Where List L is original and List R is reversed list.
 * 
 * Author: Shubhang Gupta (19/78098)
 * 
*/

append([], L, L).                            % Base Call
append([X|L1], L2, [X|L3]) :-
  append(L1, L2, L3).                   % Recursive Call

reverse([], []).                            % Base Call
reverse([H|T], R) :-
  reverse(T, L1),                      % Recursive Call
  append(L1, [H], R).
