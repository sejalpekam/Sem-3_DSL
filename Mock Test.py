'''Write a python program to store second year percentage of students in array.
Write function for sorting array of floating-point numbers in ascending order using
a) Insertion sort
b) Shell Sort and display top five scores
'''


class StudentPercentage:

    def __init__(self):
        self.arr = []
        self.length = 0

    def create(self):
        self.length = int(input("Enter number of students: "))
        for i in range(self.length):
            ele = float(input("Enter percentage of student {}: ".format(i + 1)))
            self.arr.append(ele)
        print("Unsorted array is: ", self.arr, "\n")

    def insertionSort(self):
        for i in range(1, self.length):
            value = self.arr[i]
            hole = i - 1
            while hole >= 0 and self.arr[hole] > value:
                self.arr[hole + 1] = self.arr[hole]
                hole -= 1
            self.arr[hole + 1] = value
        print("Sorted Array is: ", self.arr, "\n")

    def shellSort(self):
        gap = self.length // 2
        while gap > 0:
            for i in range(gap, self.length):
                value = self.arr[i]
                j = i
                while j >= gap and self.arr[j - gap] > value:
                    self.arr[j] = self.arr[j - gap]
                    j -= gap
                self.arr[j] = value
            gap //= 2
        print("Sorted Array is: ", self.arr, "\n")

    def top5scores(self):
        self.insertionSort()
        top_5 = self.arr[self.length:self.length - 6:-1]
        print("Top 5 scores are: ", top_5, "\n")


print("*****MENU*****\n"
      "1.To create an array.\n"
      "2.To sort array using Insertion Sort.\n"
      "3.To sort array using Shell Sort.\n"
      "4.Display Top 5 scores.\n"
      "0.Exit\n")

start = True
while start:
    ch = int(input("Enter choice: "))

    if ch == 1:
        A = StudentPercentage()
        A.create()

    elif ch == 2:
        A.insertionSort()

    elif ch == 3:
        A.shellSort()

    elif ch == 4:
        A.top5scores()

    elif ch == 0:
        start = False

    else:
        print("Enter valid choice.")
