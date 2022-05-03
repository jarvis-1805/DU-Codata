/**
 * 6. Prolog program to implement power(Num,Pow, Ans)
 *      : Where Num is raised to the power Pow to get Ans.
 * 
 * Author: Shubhang Gupta (19/78098)
 * 
*/

power(0, Power, 0) :- Power > 0.    % Base Case
power(Num, 0, 1) :- Num > 0.        % Base Case
power(Num, Power, Ans) :- Num > 0, Power > 0,
                          P1 is Power - 1,
                          power(Num, P1, A1),
                          Ans is A1 * Num.


/**
 * Example:-
 *      power(Num=3, Power=3, Ans=A)                                    P(3, 3, A) → A=27
 *      P1 = 3-1 = 2 → power(Num=3, P1=2, A1)                  Ans=9*3      /
 *          power(Num=3, Power=2, Ans=A1)                         ∟   P(3, 2, A1) →  A1=9
 *          P1 = 2-1 = 1 → power(Num=3, P1=1, A1)            Ans=3*3      /
 *              power(Num=3, Power=1, Ans=A1)                   ∟   P(3, 1, A1)  →   A1=3
 *              P1 = 1-1 = 0 → power(Num=3, P1=0, A1)      Ans=1*3      /
 *                  power(Num=3, 0, 1)                        ∟    P(3, 0, 1)
 *         Return calls:-
 *                  Ans = 1 * 3 = 3  [∵ A1=1]        
 *              Ans = 3 * 3 = 9  [∵ A1=Ans=3]      
 *          Ans = 9 * 3 = 27  [∵ A1=Ans=9]
*/