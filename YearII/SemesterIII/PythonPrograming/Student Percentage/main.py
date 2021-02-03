'''
9. Use dictionary to store marks of the students in 4 subjects.
Write a function to find the name of the student securing highest percentage.
(Hint: Names of students are unique).
'''

def maximum(dic):
    '''
        Find the highest percentage in the
        dic passed as parameter
        and returns name and maximum percentage.
    '''
    maxim = 0.0
    
    for i in dic:
        if dic[i]['Percentage'] > maxim:
            maxim, name = dic[i]['Percentage'], i

    return name, maxim

def percentage(dic):
    '''
        Calculates the percentage of 4 subjects of all the students
        and adds it to the dictionary.
        parameters: dic -> dictionary containing names and marks in 4 subjects.
    '''
    import json
    
    for i in dic:
        total = 0
        for j in range(1, 5, 1):
            total += dic[i][f'Subject {j}']
        dic[i]['Percentage'] = total/4
    
    print(json.dumps(dic, indent = 4))
    name, maxim = maximum(dic)
    print(f"{name} has got the highest percentage of {maxim}%")

def main():
    dic = {}
    marks = {}
    n = int(input("Enter the no. of students: "))
    
    for i in range(1, n+1, 1):
        name = input("\nEnter the name: ")
        name = name.title()
        dic[name] = dict(marks)
        for j in range(1, 5, 1):
            mark = int(input(f"Marks in subject {j}: "))
            dic[name][f"Subject {j}"] = mark
    
    percentage(dic)

if __name__ == "__main__":
    main()