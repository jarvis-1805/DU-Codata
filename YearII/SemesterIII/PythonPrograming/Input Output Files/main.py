'''
14. Write a function that reads a file file1 and copies only alternative lines to
another file file2. Alternative lines copied should be the odd numbered lines.
Use Exception.
'''
def main():
    try:
        with open('file_1.txt', "r") as f:
            for i in range(0, len(f.readlines()), 2):
                with open('file_1.txt', "r") as f1:
                    with open('file_2.txt', "a") as f2:
                        f2.writelines(f1.readlines()[i])
            else:
                print("Successfully copied alternate odd lines!")
    except:
        print("An ERROR encountered!")


if __name__ == '__main__':
    main()