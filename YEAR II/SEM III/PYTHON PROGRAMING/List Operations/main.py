'''
Write a Python program to perform the following using list:
a) Check if all elements in list are numbers or not.
b) If it is a numeric list, then count number of odd values in it.
c) If list contains all Strings, then display largest String in the list.
d) Display list in reverse form.
e) Find a specified element in list.
f) Remove the specified element from the list.
g) Sort the list in descending order.
h) Accept 2 lists and find the common members in them.
'''

def check_num(l1):
    for i in l1:
        if i.isdigit():
            continue
        break
    else:
        return True
    return False

def check_string(l1):
    for i in l1:
        if not i.isdigit():
            continue
        break
    else:
        return True
    return False

def odd_num(l1):
    l2 = []
    flag = check_num(l1)
    if flag:
        for i in l1:
            i = int(i)
            if i%2 != 0:
                l2.append(i)
    else:
        print("\nNot all elements in the list are numbers.")
        return
    print("\nOdd numbers in the list are:", l2)

def largest_string(l1):
    flag = check_string(l1)
    maxim = l1[0]
    if flag:
        for i in l1:
            if maxim < i:
                maxim = i
    else:
        print("\nNot all elements in list are string.")
        return
    print("\nLargest string in the list is:", maxim)

def reverse_list(l1):
    l2 = []
    print("\nThe list in reverse order is:", end = ' ')
    for i in range(-1, -(len(l1))-1, -1):
        l2.append(l1[i])
    print(l2)

def find_element(l1):
    ele = input('\nEnter the element to be searched: ') 
    for i in range(0, len(l1), 1):
        if l1[i] == ele:
            print(f"{ele} found at position {i+1}.")
            return
    print(f"\n{ele} is not present in list.")

def remove_element(l1):
    ele = input('\nEnter the element to be deleted: ')
    if ele in l1:
        l1.remove(ele)
        print(f"\n{ele} deleted successfully from the list")
    else:
        print(f"\n{ele} is not pesent in list")

def sort_descend(l1):
    for i in range(0, len(l1), 1):
        for j in range(0, len(l1)-i-1):
            if l1[j] < l1[j+1]:
                l1[j], l1[j+1] = l1[j+1], l1[j]
    
    print("\nSuccessfully sorted the list in descending order.")

def common_element(l1):
    n = int(input("\nEnter the range of list l2: "))
    l2 = []
    l3 = []
    for i in range(0, n, 1):
        l2.append(input(f"Enter the element {i+1}: "))
    print("\nList l1:", l1)
    print("\nList l2:", l2)
    for i in l1:
        for j in l2:
            if i == j:
                l3.append(i)
    
    print("\nCommon elements are:", l3)

def exit(l1):
    quit()

switcher = {
                1: check_num,
                2: odd_num,
                3: largest_string,
                4: reverse_list,
                5: find_element,
                6: remove_element,
                7: sort_descend,
                8: common_element,
                0: exit
            }

def main(l1):
    input("\nEnter enter to continue...")
    print("\n========= Menu =========")
    print("1. Check if all are numbers\
         \n2. Odd numbers\
         \n3. Largest string\
         \n4. Reverse\
         \n5. Find specific element\
         \n6. Remove specific element\
         \n7. Sort in descending order\
         \n8. Common elements\
         \n9. Display\
         \n0. Exit")

    ch = int(input("\nEnter your choice: "))
    func = switcher.get(ch, lambda l1: print("\nInvlaid Choice!"))
    if ch == 1:
        flag = func(l1)
        if flag:
            print("\nAll elements in the list are numbers.")
        else:
            print("\nNot all elements in the list are numbers.")
    elif ch == 9:
        print("\nList l1:", l1)
    else:
        func(l1)

if __name__ == "__main__":
    n = int(input("\nEnter the range of list l1: "))
    l1 = []
    for i in range(0, n, 1):
        l1.append(input(f"Enter the element {i+1}: "))
    print("\nList l1:", l1)
    while 1:
        main(l1)