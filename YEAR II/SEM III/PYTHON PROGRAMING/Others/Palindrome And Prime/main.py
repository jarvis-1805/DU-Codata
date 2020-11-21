def prime_number(n):
    if n>1:
        for i in range(2, n+1, 1):
            for j in range(2, i, 1):
                if i%j == 0:
                    break
            else:
                print(i, end = ' ')

def palindrome(n):
    for i in range(1, n+1, 1):
        x = i; t = 0
        while x != 0:
            t = (t*10) + (x % 10)
            x = x // 10
        if t == i:
            print(i, end=' ')

def main():
    while 1:
        print('\n1. PALINDROME')
        print('2. PRIME')
        print('0. EXIT')
        choice = int(input('\nEnter your choice: '))
        if choice == 1:
            n = int(input("\nEnter the range: "))
            print('\nPalindrome: ', end='')
            palindrome(n)
            print()
        elif choice == 2:
            n = int(input("\nEnter the range: "))
            print('\nPrime: ', end='')
            prime_number(n)
            print()
        else:
            break

if __name__ == '__main__':
    main()