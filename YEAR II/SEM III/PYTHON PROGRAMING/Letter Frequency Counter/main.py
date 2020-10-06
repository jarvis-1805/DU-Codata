''' 
10. Write a function that takes a sentence as an input from the user and calculates
the frequency of each letter. Use a variable of dictionary type to maintain the
count.
'''

def frequency_counter(string):
    '''
        Counts the frequency of each letter in the string passed as an argument
        and prints the dictionary of counted letters.
    '''
    
    import json

    dic = {}
    for i in range(0, len(string), 1):
        if string[i] in dic:
            dic[string[i]] = dic[string[i]] + 1
        elif string[i] == ' ':
            pass
        else:
            dic[string[i]] = 1
    
    print(json.dumps(dic, indent = 4))

def main():
    string = input("Enter a string: ")
    frequency_counter(string)

if __name__ == "__main__":
    main()