
'''Quick Sort'''


def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return i+1


def quickSort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)

        quickSort(arr, low, pi-1)
        quickSort(arr, pi+1, high)

    return arr


def top5scores(arr, low, high):
    sorted = quickSort(arr, low, high)
    top_5 = sorted[length:length - 6:-1]
    print("Top 5 scores are:")
    for i in range(len(top_5)):
        print(top_5[i])
    print("\n")


def display(arr):
    print("Sorted array is: ", arr,"\n")


def create():
    arr = []
    length = int(input("Enter number of students: "))
    for i in range(length):
        ele = float(input("Enter percentage of student {}: ".format(i+1)))
        arr.append(ele)
    print("Unsorted array is: ", arr, "\n")
    return arr, length


arr, length = create()

print("1.To sort array using Quick Sort.\n"
      "2.Display Top 5 scores.\n"
      "3.To create a new array.\n"
      "0.Exit\n")

a = True
while a:
    ch = int(input("Enter choice: "))

    if ch == 1:
        sorted_arr = quickSort(arr, 0, length-1)
        display(sorted_arr)

    elif ch == 2:
        top5scores(arr, 0, length-1)

    elif ch == 3:
        arr, length = create()

    elif ch == 0:
        a = False

    else:
        print("Enter valid choice.")