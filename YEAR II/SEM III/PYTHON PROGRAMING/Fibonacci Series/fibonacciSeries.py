def fibonacciSeries():
    n1 = 0
    n2 = 1
    t = int(input('Enter the term of fibonacci series :'))
    if t == 1:
        print('1st term of fibonacci series is :', n1)
        return
    if t == 2:
        print('2nd term of fibonacci series is :', n2)
        return
    for i in range(3, t+1):
        n = n1 + n2
        n1 = n2
        n2 = n
    
    print('The {}th term of fibonacci series is : '.format(t), end = '')
    return n

if __name__ == "__main__":
    val = fibonacciSeries()
    print(val)