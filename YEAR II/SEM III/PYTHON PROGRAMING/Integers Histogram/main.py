def calc_freq(l, n):
    import json
    l_set = set(l)
    l_dic = {}
    for i in l_set:
        l_dic[i] = 0
        for j in range(0, n, 1):
            if i == l[j]:
                l_dic[i] += 1

    print(json.dumps(l_dic, indent = 4))
    plot_hist(l_dic)

def plot_hist(l_dic):
    import matplotlib.pyplot as plt
    plt.hist(x = l_dic)
    plt.show()

def main():
    n = int(input("\nEnter the limit: "))
    l = []
    for i in range(0, n, 1):
        l.append(int(input("Enter the integer: ")))
    print(l)
    print(set(l))
    print(l)
    calc_freq(l, n)

if __name__ == "__main__":
    main()