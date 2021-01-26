def checkPrime():
    num = int(input('Enter any number : '))
    if num == 1 or num == 0:
        print('{} is universally regarded as non-prime.'.format(num))
        return
    if num < 0:
        print('Negative integers can not be prime.')
        return
    flag = True
    for i in range(2, int(num/2)+1):
        if num%i == 0:
            flag = False
            break
            
    if flag == True:
        print('{} is a prime number!'.format(num))
    else:
        print('{} is not a prime number!'.format(num))

if __name__ == "__main__":
    checkPrime()