'''
15. Define a class Student to store his/her name and marks in three subjects.
Use a class variable to store the maximum average marks of the class.
Use constructor and destructor to initialize and destroy the objects.
'''
class Student:
    maxim = 0.0

    def __init__(self):
        self.dic = {}
        self.marks = {}
        self.maxim_avg = {}
        self.total = 0
        self.name = ''
        self.mark = 0
    
    def __del__(self):
        del self.dic
        del self.marks
        del self.maxim_avg
        del self.total
        del self.name
        del self.mark
        print("\nDetroyed clasroom in milliseconds...")
    
    def input_values(self, n):
        for i in range(1, n+1, 1):
            self.name = input(f"\nEnter the name {i}: ")
            self.name = self.name.title()
            self.dic[self.name] = dict(self.marks)
            for j in range(1, 4, 1):
                self.mark = int(input(f"Marks in subject {j}: "))
                self.dic[self.name][f"Subject {j}"] = self.mark
                self.total += self.mark
            self.dic[self.name]['Average'] = self.total/3
            self.total = 0
    
    def maximum(self):
        '''
            Find the highest percentage in the
            dic passed as parameter
            and returns name and maximum percentage.
        '''
        
        for i in self.dic:
            if self.dic[i]['Average'] > self.maxim:
                self.maxim, self.name = self.dic[i]['Average'], i
        self.maxim_avg[self.name] = self.maxim

    def display(self):
        import json as js
        print(js.dumps(self.dic, indent=4))
        print('\n{} has highest average of {:.2f}'.format(self.name, self.maxim_avg[self.name]))

def main():
    print("\n============== CLASSROOM ==============")
    n = int(input("Enter the number of students: "))
    ob = Student()
    ob.input_values(n)
    ob.maximum()
    ob.display()
    del ob

if __name__ == "__main__":
    main()