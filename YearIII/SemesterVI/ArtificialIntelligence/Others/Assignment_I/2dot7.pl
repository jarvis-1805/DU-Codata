% The following program says that two people are relatives if:
% (a) one is an ancestor of the other, or
% (b) they have a common ancestor, or
% (c) they have a common successor:

% relatives(X, Y) :- ancestor(X, Y).
% relatives(X, Y) :- ancestor(Y, X).
% relatives(X, Y) :- ancestor(Z, X),      % X and Y have common ancestor
%                     ancestor(Z, Y).
% relatives(X, Y) :- ancestor(X, Z),      % X and Y have a common successor
%                     ancestor(Y, Z).

% Can you shorten this program by using the semicolon notation?

ancestor(X, Y).
ancestor(Y, X).
ancestor(Z, X).
ancestor(Z, Y).
ancestor(X, Z).
ancestor(Y, Z).

relatives(X, Y) :-
    ancestor(X, Y);
    ancestor(Y, X);
        % X and Y have common ancestor
    ancestor(Z, X),
    ancestor(Z, Y);
        % X and Y have common successor
    ancestor(X, Z),
    ancestor(Y, Z).
