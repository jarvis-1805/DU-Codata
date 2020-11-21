def main():
    print('\n======= STUDENT FMS =======\n')
    name = input("Enter the file name: ")
    while 1:
        print('\n1. WRITE')
        print('2. READ')
        print('3. DELETE')
        print('0. EXIT')
        c = int(input('\nEnter your choice: '))

        try:
            if c == 1:
                with open("{}.txt".format(name), "a") as f:
                    data = input("\nEnter the data:\n")
                    f.write(data + "\n")
            elif c == 2:
                with open("{}.txt".format(name), "r") as f:
                    data = f.readlines()
                    print()
                    for line in data:
                        print(line)
            elif c == 3:
                with open("{}.txt".format(name), "r+") as f:
                    f.seek(0)
                    f.truncate()
                    print("\nSuccessfully deleted the file's data!")
            elif c == 0:
                break
        except:
            print('\nAN UNEXPECTED ERROR ENCOUNTERED!')
            name = input("Enter the file name: ")

if __name__ == '__main__':
    main()