def hcf(s, g):
    while s:
        g, s = s, g%s
    
    return g
    
def lcm(s, g):
    l = (s*g)//hcf(s, g)

    return l
    
if __name__ == "__main__":
    a = int(input('Enter 1st number :'))
    b = int(input('Enter 2nd number :'))

    if a < b:
        s = a
        g = b
    else:
        s = b
        g = a
    
    print('LCM of {} and {} is : {}'.format(a, b, lcm(s, g)))
    print('HCF of {} and {} is : {}'.format(a, b, hcf(s, g)))