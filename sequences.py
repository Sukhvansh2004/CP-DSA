def f(n, k):
    if k == 1:
        return list(range(1, n+1))
    else:
        arr = f(n, k-1)
        arr_ = list()
        for i in arr:
            l = n//i
            for j in range(1, l+1):
                arr_.append(j*i)
        return arr_

if __name__ == '__main__':
    print(len(f(4,1)))
    