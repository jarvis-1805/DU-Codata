def factorial():
    num = int(input('Enter a number :'))
    if num < 0:
        print('Factorial of negative numbers is undefined!')
        return
    fact = 1
    for i in range(2, num+1):
        fact = fact * i;
    print('Factorial of {} is : {}'.format(num, fact))

if __name__ == "__main__":
    factorial()