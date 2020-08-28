for i in range(0, 5):
    for k in range(0, 2*i-1):
        print('#', end = '')
    for j in range(-i-1, 0):
        print('*', end = '')
    print()
    
'''  
for i in range(0, 5):
    for k in range(0, (2*i-1)):
        print('#', end = '')
    for j in range(0, 5-i-1):
        print('*', end = '')
    print()
'''