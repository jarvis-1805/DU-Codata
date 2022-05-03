/**
 * 18. Write a program in PROLOG to implement merge(L1, L2, L3),
 *        : where L1 is first ordered list and L2 is second ordered list and L3 represents the merged list.
 * 
 * Author: Shubhang Gupta (19/78098)
 * 
 */

mergelist(L1, [], L1).
mergelist([], L2, L2).

mergelist([Head1 | Tail1], [Head2 | Tail2], L3) :-
  Head1 < Head2 -> append([Head1], L2, L3),
    mergelist(Tail1, [Head2 | Tail2], L2);

  Head1 > Head2 -> append([Head2], L2, L3),
    mergelist([Head1 | Tail1], Tail2, L2);
  
  append([Head1 | Head2], L2, L3),
    mergelist(Tail1, Tail2, L2).
