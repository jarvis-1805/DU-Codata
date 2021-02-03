'''
4. Write a function that takes a number (>=10) as an input and return the digits of
the number as a set.
'''

def digit_set(n):
    '''
    Extracts each digit from any number greater than or equal 10.
    Parameters: n -> any int number >= 10
    Return: digits -> extracted digits as set
    '''
    digits = set()
    i = 0
    while n != 0:
        i = n%10
        digits.add(i)
        n //= 10
    
    return digits

def main():
    n = int(input("Enter a number >= 10: "))
    digits = digit_set(n)
    
    print("\nThe digits in set are:", digits)

if __name__ == "__main__":
    main()