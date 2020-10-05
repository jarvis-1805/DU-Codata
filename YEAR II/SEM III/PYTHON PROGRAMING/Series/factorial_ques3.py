'''
3. Write a Python function to find the nth term of Fibonacci sequence and its
factorial. Return the result as a list.
'''

def fibonacciSeries(t):
    '''
    Calculates the value of t'th term in Fibonacci Series.
    Parameters: t -> term of the fibonacci series.
    Return: n -> t'th term of series. Returns -1 for -ve value of t.
    '''
    n1, n2 = 0, 1
    if t < 0:
        return -1
    if t == 1:
        return 0
    if t == 2:
        return 1
    for i in range(3, t+1):
        n = n1 + n2
        n1 = n2
        n2 = n
    
    return n

def factorial(n):
    '''
    Calculates the factorial of a number.
    Parameters: n -> number whose factorial is to be calculated.
    Return: fact -> calculated factorial
    '''
    fact = 1
    for i in range(1,n+1): 
        fact = fact * i
    
    return fact

def main():
    t = int(input('\nEnter the term of fibonacci series : '))
    val = fibonacciSeries(t)
    print('\nThe {}th term of fibonacci series is : {}'.format(t, val))
    fact = factorial(val)
    print('The factorial of {} is : {}'.format(val, fact))
    
if __name__ == "__main__":
    main()