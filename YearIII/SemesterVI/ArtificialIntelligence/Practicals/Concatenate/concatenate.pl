/**
 * 9.  Write a Prolog program to implement conc(L1, L2, L3),
 *          : where L2 is the list to be appended with L1 to get the resulted list L3.
 * 
 * Author: Shubhang Gupta (19/78098)
 * 
*/

conc([], List, List).                            % Base Call
conc([Head | Tail], List2, [Head | Result]) :- 
    conc(Tail, List2, Result).                   % Recursive Call
