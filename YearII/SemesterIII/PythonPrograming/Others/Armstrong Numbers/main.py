lim = int(input('Enter the limit: '))
for i in range(1, lim+1, 1):
    #num = str(i)
    #n = len(num)
    num = i
    x = num
    sum1 = 0
    temp = 0
    while x != 0:
     temp = x % 10
     sum1 += temp ** 3
     x = x // 10
    if sum1 == num:
     print(num)
