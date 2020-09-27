def digit_set(n):
    digits = set()
    i = 0
    while n != 0:
        i = n%10
        digits.add(i)
        n = int(n/10)
    print(type(digits))
    return digits

def main():
    n = int(input("Enter a number >= 10: "))
    digits = digit_set(n)
    print("\nThe digits in set are:", digits)

if __name__ == "__main__":
    main()