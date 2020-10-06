'''
11. c
'''

def input_list():
    l = []
    n = int(input("\nEnter the number of students: "))
    for i in range(0, n, 1):
        l.append(input(f"Enter the name {i+1}: ").lower())

    return n, l

def linear_Search(n, l):
    import linearSearch as ls
    
    x = input("\nEnter the name to be searched: ").lower()
    flag, i = ls.linear_search(n, l, x)
    
    if flag == True:
        print("\nElement found at position", i+1)
    else:
        print("\nElement not found!")

def binary_search(n, l):
    l1 = bubble_sort(n, l.copy())
    flag = False
    x = input("\nEnter the name to be searched: ").lower()
    lb, ub = 0, n-1
    
    while lb <= ub:
        mid = (lb+ub)//2
        if x == l1[mid]:
            flag = True
            break
        if x < l1[mid]:
            ub = mid - 1
        if x > l1[mid]:
            lb = mid + 1
    
    if flag == True:
        print("\nElement found!")
    else:
        print("\nElement not found!")

def bubble_sort(n, l1):
    for i in range(0, n, 1):
        for j in range(0, n-i-1, 1):
            if l1[j] > l1[j+1]:
                l1[j], l1[j+1] = l1[j+1], l1[j]
    
    return l1

def insertion_sort(n, l1):
    pass

def selection_sort(n, l1):
    pass

search_switcher = {
                    1: linear_Search,
                    2: binary_search
                  }

sort_switcher = {
                    1: bubble_sort,
                    2: insertion_sort,
                    3: selection_sort
                }

def main(n, l):
    
    print("\n========= Menu =========")
    print("1. Search an element\
         \n2. Sort the elements\
         \n0. Exit")

    ch = int(input("\nEnter you choice: "))
    if ch == 1:
        print("\n========= Searching Menu =========")
        print("1. Linear Search\
                \n2. Binary Search")
        choice = int(input("\nEnetr your choice: "))
        func = search_switcher.get(choice, lambda n,l: print("\nInvlaid Choice!"))
        func(n, l)
    elif ch == 2:
        print("\n========= Sorting Menu =========")
        print("1. Bubble Sort\
                \n2. Insersion Sort\
                \n3. Selection Sort")
        choice = int(input("\nEnter your choice: "))
        func = sort_switcher.get(choice, lambda n,l: print("\nInvlaid Choice!"))
        if choice == 1:
            l1 = func(n, l.copy())
            print("\nBubble Sorted List:", l1)
        else:
            func(n,l.copy())
    elif ch == 0:
        exit()
    else:
        print("\nInvalid Choice!")

if __name__ == "__main__":
    n, l = input_list()
    while True:
        main(n, l)