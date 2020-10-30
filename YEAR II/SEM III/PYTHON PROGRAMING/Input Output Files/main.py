def main():
    with open('file_1.txt', "r") as f:
        for i in range(0, len(f.readlines()), 2):
            with open('file_1.txt', "r") as f1:
                with open('file_2.txt', "a") as f2:
                    f2.writelines(f1.readlines()[i])
        else:
            print("Successfully copied alternate odd lines!")


if __name__ == '__main__':
    main()