/**
 * 4. Write a program in PROLOG to implement generate_fib(N,T),
 *        : where T represents the Nth term of the fibonacci series.
 * 
 * Author: Shubhang Gupta (19/78098)
 * 
 */

generate_fib(0, 1).
generate_fib(1, 1).

generate_fib(N, T) :- N1 is N - 1,
  % T1 = (N-1)th term of the fibonacci series
  generate_fib(N1, T1),
  N2 is N - 2,
  % T2 = (N-2)th term of the fibonacci series
  generate_fib(N2, T2),
  T is T1 + T2.
