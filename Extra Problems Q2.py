'''Q2. Translate quicksort into a subprogram QUICKSORT(A,  N, NUMB )
which  sorts the array A  with N elements and
which also count the numbers NUMB of comparisons .'''

comparisons = 0

def partition(arr, low, high):
    global comparisons
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        comparisons += 1
        if arr[j]<pivot:
            i+=1
            arr[i] , arr[j] = arr[j] , arr[i]
    arr[i+1] , arr[high] = arr[high] , arr[i+1]
    return i+1


def quickSort(arr, low, high):
    if low<high:
        pi = partition(arr, low, high)

        quickSort(arr, low, pi-1)
        quickSort(arr, pi+1, high)

    return arr

arr = [44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88, 66, 26]
sorted_arr = quickSort(arr,0, len(arr)-1)
print("Sorted array is: ", sorted_arr)
print("Comparisons = ", comparisons)
