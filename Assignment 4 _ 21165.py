
'''Search Algorithms'''

def linearSearch(list, ele):
    for i in range(0, len(list)):
        if list[i] == ele:
            return i
    return None

def sentinelSearch(list1, ele):
    list = list1.copy()
    list.append(ele)
    i = 0
    while list[i] != ele:
        i += 1
    if i < len(list)-1:
        return i
    else:
        return None


def sort(list):
    n = len(list)
    for i in range(0,n):
        swapped = False
        for j in range(0, n-i-1):
            if list[j] > list[j+1]:
                list[j], list[j+1] = list[j+1], list[j]
                swapped = True
        if swapped == False:
            break

    return list

def binarySearch(list, ele):
    list = sort(list)
    print("Sorted list is: ", list)
    n = len(list)
    beg = 0
    end = n - 1
    while beg <= end:
        mid = (beg + end)//2
        if list[mid] == ele:
            return mid
        elif list[mid] < ele:
            beg = mid + 1
        else:
            end = mid - 1
    return -1


def fibSearch(list,ele):
    list = sort(list)
    print("Sorted list is: ", list)
    n = len(list)
    fibMm2 = 0
    fibMm1 = 1
    fibM = fibMm1 + fibMm2

    while fibM < n:
        fibMm2 = fibMm1
        fibMm1 = fibM
        fibM = fibMm1 + fibMm2

    offset = -1

    while fibM > 1:
        i = min(offset + fibMm2, n)
        if list[i] < ele:
            fibM = fibMm1
            fibMm1 = fibMm2
            fibMm2 = fibM - fibMm1
            offset = i
        elif list[i] > ele:
            fibM = fibMm2
            fibMm1 = fibMm1 - fibMm2
            fibMm2 = fibM - fibMm1
        else:
            return i

    if fibMm1 == 1 and list[offset + 1] == ele:
        return offset + 1

    return -1


s = input("Enter space separated Roll Numbers: ")
arr = list(map(int, s.split()))
ele = int(input("Enter Roll no. to be searched: "))

print("1.To search using Linear Search.\n"
      "2.To search using Sentinel Search.\n"
      "3.To search using Binary Search.\n"
      "4.To search using Fibonacci Search.\n"
      "0.Exit\n")


n = True
while n:
    ch = int(input("Enter choice:" ))
    if ch == 1:
        result = linearSearch(arr, ele)
        if result is None:
            print("Roll no. not found.\n")
        else:
            print("Roll no. found at location: ", result, "\n")

    elif ch == 2:
        result = sentinelSearch(arr, ele)
        if result is None:
            print("Roll no. not found.\n")
        else:
            print("Roll no. found at location: ", result, "\n")

    elif ch == 3:
        result = binarySearch(arr, ele)
        if result == -1:
            print("Roll no. not found.\n")
        else:
            print("Roll no. found at location: ", result, "\n")

    elif ch == 4:
        result = fibSearch(arr, ele)
        if result == -1:
            print("Roll no. not found.\n")
        else:
            print("Roll no. found at location: ", result, "\n")

    elif ch == 0:
        n = False
    else:
        print("Enter valid choice.")



