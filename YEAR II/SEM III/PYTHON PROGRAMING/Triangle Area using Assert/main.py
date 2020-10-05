'''
1. Write a function that takes the lengths of three sides: side1, side2 and side3 of
the triangle as the input from the user using input function and return the area
and perimeter of the triangle as a tuple. Also, assert that sum of the length of any
two sides is greater than the third side.
'''

def calc_area(a, b, c):
    '''
    Calculates area of triangle and asserts if wrong sides entered.
    Paramaters: a -> side1
                b -> side2
                c -> side3
    Return: area of triangle.
    '''
    assert (a+b)>c, "You entered wrong sides!"
    assert (a+c)>b, "You entered wrong sides!"
    assert (b+c)>a, "You entered wrong sides!"
    s = (a+b+c)/2
    area = (s*(s-a)*(s-b)*(s-c))**0.5
    return area

def main():
    a = int(input("Enter the side1 : "))
    b = int(input("Enter the side2 : "))
    c = int(input("Enter the side3 : "))
    area = calc_area(a, b, c)
    print("\nThe area of triangle is : %0.2f" %area)

if __name__ == "__main__":
    main()