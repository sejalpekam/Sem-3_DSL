'''Q3. An array A contain 25 positive integers. Write a program which find
a)	all pair of elements whose sum is 25
b)	Find the numbers EVNUM of elements of A which are even,
and the numbers ODNUM of elements A which is odd
'''

def bubblesort(list):
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
    list = bubblesort(list)
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


def isSum25(arr):
    arr = bubblesort(arr)
    for i in arr:
        complement = 25 - i
        result = binarySearch(arr, complement)
        if result == -1:
            continue
        else:
            print(i, complement)

def evorodd(arr):
    evnum = []
    oddnum = []
    for i in range(n):
        if arr[i]%2 == 0:
            evnum.append(arr[i])
        else:
            oddnum.append(arr[i])
    print("Array of even numbers is: ", evnum)
    print("Array of odd numbers is: ", oddnum)



n = 25
A = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25]


# for i in range(n):
#     ele = int(input("Enter element {}: ".format(i+1)))
#     A.append(ele)

print("Pair of elements whose sum is 25 are: ")
isSum25(A)

evorodd(A)