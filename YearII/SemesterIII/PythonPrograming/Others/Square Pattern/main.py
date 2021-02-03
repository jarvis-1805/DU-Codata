import math

def square_pattern(string, root):
    k = 0
    for i in range(0, root, 1):
        for j in range(0, root, 1):
            print(string[k], end=' ')
            k += 1
        print()

def square_sclicing(string, length, root):
    for i in range(0, length, root):
        print(string[i:i+root])

def main():
    string = input("Enter the string: ")
    length = len(string)
    root = math.sqrt(length)
    if int(root + 0.5) ** 2 == length:
        square_sclicing(string, length, int(root))
    else:
        print('Invalid string! TRY AGAING!')

if __name__ == "__main__":
    main()