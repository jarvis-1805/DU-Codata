def fibonacciSeries():
    n1, n2 = 0, 1
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

def main():
    val = fibonacciSeries()
    print(val)
    
if __name__ == "__main__":
    main()