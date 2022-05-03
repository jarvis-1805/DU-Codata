/**
 * 7. Prolog program to implement multi(N1, N2, R)
 *      : Where N1 and N2 denotes the numbers to be multiplied and R represents the result.
 * 
 * Author: Shubhang Gupta (19/78098)
 * 
*/

multi(N, 1, N).

multi(N1, N2, R) :- T is N2 - 1,
                    multi(N1, T, Y),
                    R is Y + N1.


/**
 * Example:-
 *      multi(N1=8, N2=3, R=A)                                      M(8, 3, A) → A=24
 *      T = 3-1 = 2 → multi(N1=3, T=2, Y)                    R=16+8      /
 *          multi(N1=8, N2=2, R=Y)                             ∟  M(8, 2, Y) →  Y=16
 *          T = 2-1 = 1 → multi(N1=8, T=1, Y)              R=8+8      /
 *              multi(N=8, 1, N=Y=8)                         ∟   M(8, 1, 8)
 *         Return calls:-
 *                  R = 8 + 8 = 16  [∵ Y=8]
 *              R = 16 + 8 = 24  [∵ Y=16]
*/