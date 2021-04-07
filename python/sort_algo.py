import os


def sort_bubble(a):
    n = len(a)
    for i in range(n):
        for j in range(1, n - i):
            if a[j - 1] > a[j]:
                a[j - 1], a[j] = a[j], a[j - 1]
        print(a)
    return a


def sort_selection(a):
    n = len(a)
    for i in range(n):
        min_val = i
        for j in range(i + 1, n):
            if a[j] < a[min_val]:
                min_val = j
        a[i], a[min_val] = a[min_val], a[i]
        print(a)
    return a


def sort_quick(a, start, end):
    if start >= end:
        return a
    base = a[start]
    i = start
    j = end
    while i != j:
        while a[j] >= base and i < j:
            j -= 1
        while a[i] <= base and i < j:
            i += 1
        a[i], a[j] = a[j], a[i]
        print(a)
    a[start] = a[i]
    a[i] = base
    print("search done:%s" % a)
    sort_quick(a, start, i - 1)
    sort_quick(a, i + 1, end)
    return a


def sort_insert(a):
    n = len(a)
    for i in range(1, n):
        if a[i] < a[i - 1]:
            key = a[i]
            index = i
            for j in range(i - 1, -1, -1):
                if a[j] > key:
                    a[j + 1] = a[j]
                    index = j
                else:
                    break
                a[index] = key
        print("search done:%s" % a)
    return a


def sort_shell(a):
    n = len(a)
    scale = round(n / 2)  # 初始步长 , 用round四舍五入取整
    while scale > 0:
        for i in range(scale, n):  # 每一列进行插入排序 , 从gap 到 n-1
            temp = a[i]
            j = i
            while j >= scale and a[j - scale] > temp:  # 插入排序
                a[j] = a[j - scale]
                j = j - scale
            a[j] = temp
        scale = round(scale / 2)  # 重新设置步长
        print("search done:%s" % a)
    return a


def main():
    while 1:
        print("initial data:")
        data = [17, 6, 19, 45, 1, 2, 23, 5, 4, 11, 3]
        print(data)
        cmd = input("options: 1.[bubble sort] 2.[selection sort] 3.[quick sort] 4.[insert sort] 5.[shell sort]")

        if cmd == '1':
            print("starting bubble_sort:")
            sort_bubble(data)
        elif cmd == '2':
            print("starting selection_sort:")
            sort_selection(data)
        elif cmd == '3':
            print("starting quick_sort:")
            sort_quick(data, 0, len(data) - 1)
        elif cmd == '4':
            print("starting insert_sort:")
            sort_insert(data)
        elif cmd == '5':
            print("starting shell_sort:")
            sort_shell(data)
        else:
            print("executed none!")

        print("after sort, data:%s" % data)


if __name__ == '__main__':
    main()
