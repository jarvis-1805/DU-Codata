% Knowledge Base
human(sudipto).
human(shubhang).
human(tania).
male(sudipto).
male(shubhang).
female(tania).
sibling(shubhang, sudipto).
sibling(sudipto, shubhang).
sibling(tania, sudipto).
sibling(sudipto, tania).

% Rules
brother(X, Y) :- sibling(X, Y), male(X).
sister(X, Y) :- sibling(X, Y), female(X).
