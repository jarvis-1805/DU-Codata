def reverseSum():
    num = input('Enter a number : ')
    sum = 0
    rev = ""
    for i in num:
        rev = i + rev
        sum = sum + int(i)
    print('Number in reverse is :',rev)
    print('Sum of the digits is :', sum)
    
if __name__ == "__main__":
    reverseSum()