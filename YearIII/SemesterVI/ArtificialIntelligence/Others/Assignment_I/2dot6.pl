% Consider the following program:

f(1, one).
f(s(1), two).
f(s(s(1)), three).

f(s(s(s(X))), N) :- f(X, N).

% How will Prolog answer the following questions?
% Whenever several answers are possible, give at least two.
% (a) ?- f(s(1), A).
% (b) ?- f(s(s(1)), two).
% (c) ?- f(s(s(s(s(s(s(1)))))), C).
% (d) ?- f(D, three).
