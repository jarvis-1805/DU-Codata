class account:
    dic = {}
    def add(self, name, data):
        self.dic[name] = data
        print('\nAdded the data!')

    def modify(self, name, data):
        self.dic[name] = data
        print('\nModified the data!')

    def delete(self, name):
        del self.dic[name]
        print('\nDeleted the data!')

    def search(self, name):
        print('\nSearched data: ', self.dic[name])

    def display(self):
        import json as js
        print()
        print(js.dumps(self.dic, indent=4))

def main():
    ob = account()
    while 1:
        print('\n1. ADD')
        print('2. MODIFY')
        print('3. DELETE')
        print('4. SEARCH')
        print('5. DISPLAY')
        print('0. EXIT')
        c = int(input('\nEnter your choice: '))

        if c == 1:
            name = input('\nEnter the name: ')
            data = input('Enter the data: ')
            ob.add(name, data)
        elif c == 2:
            name = input('\nEnter the name: ')
            data = input('Enter the data: ')
            ob.modify(name, data)
        elif c == 3:
            name = input('\nEnter the name: ')
            ob.delete(name)
        elif c == 4:
            name = input('\nEnter the name: ')
            ob.search(name)
        elif c == 5:
            ob.display()
        elif c == 0:
            break

if __name__ == '__main__':
    main()