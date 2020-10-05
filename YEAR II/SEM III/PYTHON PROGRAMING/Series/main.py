'''
5. Write a function that finds the sum of then terms of the following series.
1–x2/2!+x4/4!–x6/6!+...xn/n!
'''

def series_sum(n, x):
    '''
    Calculates the sum of series 1–x2/2!+x4/4!–x6/6!+...xn/n!
    Parameters: n -> limit of series
                x -> value of x
    Return: sum -> sum of series
    '''
    from factorial_ques3 import factorial
    sum = 1
    for i in range(2, n+2, 4):
        sum -= (x*i)/factorial(i)
        sum += (x*(i-2))/factorial(i-2)
    
    return sum

def main():
    n = int(input("Enter the limit: "))
    x = int(input("Enter the value of x: "))
    sum = series_sum(n, x)
    print("SUM:", round(sum, 2))

if __name__ == "__main__":
    main()