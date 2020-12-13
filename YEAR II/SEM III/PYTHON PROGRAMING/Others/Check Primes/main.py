'''
Consider a tuple T1 = (1, 2, 5, 7, 9, 3, 4, 6, 8, 10). Write a function primes()
that accepts tuple T1 as argument and creates a list T2 having values that are prime numbers in the
tuple T1. The function should return a dictionary primeCubes where keys are items of the list
T2 and the values are cubes of the keys. For example, when T1 as passed as an argument, T2 will
be [2, 5, 7, 3] and primeCubes will be {2:8,5:125,7:343,3:27}.
'''

def primes(T1):
  T2 = []
  primeCubes = dict()
  for i in T1:
    if i == 1:
      continue
    for j in range(2, i):
      if i % j == 0:
        break
    else:
      T2.append(i)
      primeCubes[i] = i**3
  return primeCubes
def main():
  T1 = (1,2,5,7,9,3,4,6,8,10)
  primeCubes = primes(T1)
  print(primeCubes)
main()