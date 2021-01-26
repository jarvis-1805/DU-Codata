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

def series_sum(n, x):
    '''
    Calculates the sum of series x+x^2/2!-x^3/3!+x4/4!+...xn/n!
    Parameters: n -> limit of series
                x -> value of x
    Return: sum -> sum of series
    '''
    sum = x
    for i in range(2, n+1, 2):
        sum += (x**i)/factorial(i)
        sum -= (x**(i+1))/factorial(i+1)
    
    return sum

def main():
    n = int(input("Enter the limit: "))
    x = int(input("Enter the value of x: "))
    sum = series_sum(n, x)
    print("SUM:", round(sum, 2))

if __name__ == "__main__":
    main()