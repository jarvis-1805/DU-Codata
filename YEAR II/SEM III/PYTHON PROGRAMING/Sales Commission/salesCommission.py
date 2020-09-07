def commission():
    ts = 0
    for i in range(1, 5):
        s = eval(input('Enter sales in weeek {} : '.format(i)))
        ts = ts + s     #Calculating total sales
    
    print('\n--------- Salesman Summary ---------')
    print('   Total Sales : {:>15,.2f}'.format(ts))
    
    #Calculating total commission
    tc = 0.0
    if ts > 50000:
        tc = ts * 0.05
    print('   Total Commission : {:>10,.2f}'.format(tc))
    
    #Calculating remark
    if ts >= 80000:
        rm = 'Excellent'
    elif ts < 80000 and ts >=60000:
        rm = 'Good'
    elif ts < 60000 and ts >= 40000:
        rm = 'Average'
    else:
        rm = 'Work Hard'
    
    print('   Remark : {:>20}'.format(rm))

def main():
    n = int(input('\nEnter the no. of salesmen : '))
    for i in range(1, n+1):
        print('\n============= Salesman {} ============='.format(i))
        commission()

if __name__ == '__main__':
    main()