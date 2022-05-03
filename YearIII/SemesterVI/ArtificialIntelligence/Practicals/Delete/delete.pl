/**
 * 17. Write a Prolog program to implement delete_nth(N, L, R),
 *        : that removes the element on Nth position from a list L to generate a list R.
 * 
 * Author: Shubhang Gupta (19/78098)
 * 
 */

delete_nth(0, [_ | Tail], Tail).

delete_nth(N, [Head | Tail], [Head | Tail1]) :-
  N1 is N - 1,
  delete_nth(N1, Tail, Tail1).
