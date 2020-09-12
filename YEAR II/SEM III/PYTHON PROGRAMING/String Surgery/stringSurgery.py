def lenOfString():
    str = input("Enter the string: ")
    print("Length of {} is {}".format(str, len(str)))

def maxOfString():
    pass
    
def replaceVowels():
    str = input("Enter the string: ")
    sym = input("Enter the character to replace vowel: ")
    str1 = ""
    for i in range(len(str)):
        ch = str[i]
        if ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or\
           ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U':
           str1 = str1 + sym
        else:
            str1 += ch
    
    print(str1)
    
def wordsInString():
    pass
    
def palindrome():
    pass

def exit():
    quit()

switcher = {
                1: lenOfString,
                2: maxOfString,
                3: replaceVowels,
                4: wordsInString,
                5: palindrome,
                0: exit
            }

def main():
    print("1. Length of string\
         \n2. Maximum of three strings\
         \n3. Replace vowels\
         \n4. Number of words in a string\
         \n5. Check palindrome\
         \n0. Exit")
         
    ch = int(input("Enter your choice:"))
    func = switcher.get(ch, lambda: print("Invlaid Choice!"))
    func()

if __name__ == "__main__":
    main()