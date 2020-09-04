def area(a, b, c):
    assert(not(a+b<=c or a+c<=b or b+c<=a)), "You entered wrong sides!"
    s = (a+b+c)/2
    ar = (s*(s-a)*(s-b)*(s-c))**0.5
    return ar

def main():
    a = int(input("Enter the side1 : "))
    b = int(input("Enter the side2 : "))
    c = int(input("Enter the side3 : "))
    ar = area(a, b, c)
    print("\nThe area of triangle is : %0.2f" %ar)

if __name__ == "__main__":
    main()