'''
2. Consider a showroom of electronic productotal_sales, where there are various
salesmen.
Each salesman is given a commissionof 5%, depending on the sales
made per month.
In case the sale done is less than 50000, then the sales man is
not given any commission.
Write a function to calculate total sales of a salesman
in a month, commission and remarks for the salesman.
Sales done by each sales man per week is to be provided as input.
Use tuples/list to store data of salesmen.

Assign remarks according to the following criteria:

Excellent: Sales >= 80000
Good: Sales >= 60000 and < 80000
Average: Sales >= 40000 and < 60000
WorkHard: Sales < 40000
'''

def commission(n):
    '''
    Calculates and prints the total sales, commission and reamrk
    for the salesman inaccordance with his sale.
    Parameter: n -> number of salesman
    '''
    s = 0
    salesmen = []
    for i in range(1, n+1, 1):
        print('\n============= Salesman {} ============='.format(i))
        salesman = [0, 0, 0, '']
        total_sales = 0
        total_commission = 0.0
        for j in range(1, 5, 1):
            s = eval(input('Enter sales in weeek {} : '.format(j)))
            total_sales = total_sales + s         #Calculating total sales
        salesman[0] = i
        salesman[1] = total_sales
        
        #Calculating total commission
        if total_sales > 50000:
            total_commission = total_sales * 0.05
            salesman[2] = total_commission
        
        #Calculating remark
        if total_sales >= 80000:
            remark = 'Excellent'
        elif total_sales >=60000:
            remark = 'Good'
        elif total_sales >= 40000:
            remark = 'Average'
        else:
            remark = 'Work Hard'
        salesman[3] = remark
        salesmen.append(salesman)
    
    for i, j, k, l in salesmen:
        print(f'\n--------- Salesman {i} Summary ---------')
        print('   Total Sales : {:>15,.2f}'.format(j))
        print('   Total Commission : {:>10,.2f}'.format(k))
        print('   Remark : {:>20}'.format(l))

def main():
    n = int(input('\nEnter the no. of salesmen : '))
    commission(n)

if __name__ == '__main__':
    main()