/**
 * 5. Prolog Program to implement GCD of two numbers.
 * 
 * Author: Shubhang Gupta (19/78098)
 * 
*/

gcd(X, Y) :- X == 0 -> write(Y);
             Y == 0 -> write(X);
             X == Y -> write(X);
             X > Y -> (Z is X - Y, gcd(Z, Y));
             Y > X -> (C is Y - X, gcd(X, C)).


/**
 * Example:-
 * 
 *  gcd(X=12, Y=15)
 *       Y > X => C = Y-X = 3 => gcd(X=12, C=3)
 *       gcd(X=12, Y=3)
 *           X > Y => Z = X-Y = 9 => gcd(Z=9, Y=3)
 *           gcd(X=9, Y=3)
 *               X > Y => Z = X-Y = 6 => gcd(Z=6, Y=3)
 *               gcd(X=6, Y=3)
 *                   X > Y => Z = X-Y = 3 => gcd(Z=3, Y=3)
 *                   gcd(X=3, Y=3)
 *                       X == Y => print(X)
*/