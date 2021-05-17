'''Q1. Tranlsate insertion sort into a subprogram INSERTSORT(A,N)
which sorts th array A with N elements .
Test the program using:
 44,33, 11,55,77,90,40,60,99,22,88,66
D,A,T,A,S,T,R,U,C,T,U,R,E,S.
'''


'''def insertionSort(A, n):
    for i in range(1, n):
        value = A[i]
        hole = i-1
        while hole >= 0 and A[hole] > value:
            A[hole+1] = A[hole]
            hole -= 1
        A[hole+1] = value
    return A


arr = []
length = int(input("Enter number of total elements: "))
print("Choose data type of elements:\n"
      "1. int\n"
      "2. float\n"
      "3. characters\n")
ch = int(input("Enter choice: "))
if ch == 1 or ch ==2:
    if ch == 1:
        for i in range(length):
            ele = int(input("Enter element {}: ".format(i + 1)))
            arr.append(ele)
    elif ch == 2:
        for i in range(length):
            ele = float(input("Enter element {}: ".format(i + 1)))
            arr.append(ele)
    print("Unsorted array is: ", arr, "\n")

    sorted_arr = insertionSort(arr, length)
    print("Sorted array is: ", sorted_arr, "\n")

elif ch == 3:
    char_arr =[]
    sorted_char_arr = []
    for i in range(length):
        ele = (input("Enter element {}: ".format(i + 1)))
        char_arr.append(ele)
        arr.append(ord(ele))
    print("Unsorted array of characters is: ", char_arr, "\n")

    sorted_arr = insertionSort(arr, length)
    for i in range(length):
        sorted_char_arr.append(chr(sorted_arr[i]))

    print("Sorted array of characters is: ", sorted_char_arr, "\n")

else:
    print("Enter valid choice.\n")
'''

def insertionSort(A, n):
    for i in range(1, n):
        value = A[i]
        hole = i-1
        while hole >= 0 and A[hole] > value:
            A[hole+1] = A[hole]
            hole -= 1
        A[hole+1] = value
    return A

print("Sorted Arrays are: ")
A=[44,33, 11,55,77,90,40,60,99,22,88,66]
print(insertionSort(A,len(A)))
A=['D','A','T','A','S','T','R','U','C','T','U','R','E','S']
print(insertionSort(A,len(A)))