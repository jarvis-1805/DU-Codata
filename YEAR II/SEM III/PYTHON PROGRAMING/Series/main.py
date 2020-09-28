'''
Write a function that finds the sum of then terms of the following series.
1–x2/2!+x4/4!–x6/6!+...xn/n!
'''

def factorial(num):
    fact = 1
    for i in range(2, num+1):
        fact = fact * i
    
    return fact

def series_sum(n, x):
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