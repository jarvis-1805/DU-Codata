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

def binary_search():
    pass

def bubble_sort():
    pass

def insertion_sort():
    pass

def selection_sort():
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
        func = search_switcher.get(choice, lambda: print("Invlaid Choice!"))
        func(n, l)
    elif ch == 2:
        print("\n========= Sorting Menu =========")
        print("1. Bubble Sort\
                \n2. Insersion Sort\
                \n0. Selection Sort")
        choice = int(input("\nEnetr your choice: "))
        func = sort_switcher.get(choice, lambda: print("Invlaid Choice!"))
        func()
    elif ch == 0:
        exit()

if __name__ == "__main__":
    n, l = input_list()
    while True:
        main(n, l)