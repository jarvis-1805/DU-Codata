/**
 * 16. Write a prolog program to implement insert_nth(I, N, L, R),
 *          : that inserts an item I into Nth position of list L to generate a list R.
 * 
 * Author: Shubhang Gupta (19/78098)
 * 
 */

insert_nth(I, 0, L, [I | L]).

insert_nth(I, N, [Head | Tail], [Head | Tail1]) :-
  N1 is N - 1,
  insert_nth(I, N1, Tail, Tail1).
