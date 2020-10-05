'''
6. Consider a tuple t1={1,2,5,7,9,2,4,6,8,10}. Write a program to perform following
operations:
a) Print another tuple whose values are even numbers in the given tuple.
b) Concatenate a tuple t2={11,13,15) with t1.
c) Return maximum and minimum value from this tuple.
'''

def max_min(t1):
    '''
    Calculates maximum and minimum in a given tuple.
    Parameters: t1 -> a tuple
    Return: maxim, minim -> maximum and minimum value
    '''
    maxim = minim = t1[0]
    for i in t1:
        if maxim < i:
            maxim = i
        if minim > i:
            minim = i
    
    return maxim, minim

def concatenate_tuple(t1):
    '''
    Prints tuple after concatinating tuple t2={11,13,15) with given tuple t1.
    Parameters: t1 -> a tuple
    '''
    t2 = (11,13,15)
    t1 = t1 + t2
    print("\nConcatenating tuple t2=(11,13,15):",t1)

def even_tuple(t1):
    '''
    Prints all even values in the given tuple.
    Parameters: t1 -> an integer tuple
    '''
    t2 = ()
    for i in t1:
        if i%2 == 0:
            t2 = t2 + (i,)
    
    print("\nAll even elements in tuple:",t2)

def main():
    t1 = (1,2,5,7,9,2,4,6,8,10)
    print("\nYour tuple is:",t1)
    even_tuple(t1)
    concatenate_tuple(t1)
    maxim, minim = max_min(t1)
    print(f"\nMaximum element: {maxim}\nMinimum element: {minim}")

if __name__ == "__main__":
    main()