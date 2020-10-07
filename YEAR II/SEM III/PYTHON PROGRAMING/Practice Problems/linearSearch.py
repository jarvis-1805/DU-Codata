def linear_search(n, l, x):
    for i in range(0, n, 1):
        if l[i] == x:
            return True, i
    
    return False, -1

def main():
    l = []
    n = int(input("Enter the limit: "))
    for i in range(0, n, 1):
        a = int(input("Enter the element: "))
        l.append(a)
    
    x = int(input("Enter the element to be searched: "))
    flag, i = linear_search(n, l, x)
    
    if flag == True:
        print("Element found at position", i+1)
    else:
        print("Element not found")

if __name__ == "__main__":
    main()