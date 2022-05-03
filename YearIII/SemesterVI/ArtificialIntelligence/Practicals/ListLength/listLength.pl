/**
 * 13. Write a Prolog program to implement two predicates evenlength(List) and oddlength(List),
 *        : so that they are true if their argument is a list of even or odd length respectively.
 * 
 * Author: Shubhang Gupta (19/78098)
 * 
 */

oddlength([_| Tail]) :-
  evenlength(Tail).

evenlength([]).
evenlength([_| Tail]) :-
  oddlength(Tail).
