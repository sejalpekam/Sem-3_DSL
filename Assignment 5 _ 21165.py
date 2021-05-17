
'''Sorting Algorithms'''


def insertionSort(A, n):
    for i in range(1, n):
        value = A[i]
        hole = i-1
        while hole >= 0 and A[hole] > value:
            A[hole+1] = A[hole]
            hole -= 1
        A[hole+1] = value
    return A

def shellSort(A, n):
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            value = A[i]
            j = i
            while j >= gap and A[j - gap] > value:
                A[j] = A[j - gap]
                j -= gap
            A[j] = value
        gap //= 2
    return A

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

print("1.To sort array using Insertion Sort.\n"
      "2.To sort array using Shell Sort.\n"
      "3.Display Top 5 scores.\n"
      "4.To create a new array.\n"
      "0.Exit\n")

a = True
while a:
    ch = int(input("Enter choice: "))

    if ch == 1:
        display(insertionSort(arr, length))

    elif ch == 2:
        display(shellSort(arr, length))

    elif ch == 3:
        percentages = insertionSort(arr, length)
        top_5 = percentages[length:length-6:-1]
        print("Top 5 scores are: ", top_5, "\n")

    elif ch == 4:
        arr, length = create()

    elif ch == 0:
        a = False

    else:
        print("Enter valid choice.")



