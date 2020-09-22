def main():
    dict = {}
    for i in range(1, 5, 1):
        name = input("Enter the name: ")
        for j in range(1, 5, 1):
            marks = int(input(f"Marks in subject {j}: "))
            dict[name][f"Subject {j}"] = marks
    print(dict)

if __name__ == "__main__":
    main()