
class Matrix:
    rows = 0
    cols = 0
    arr = []

    def __init__(self, rows, cols):
        self.rows = rows
        self.cols = cols
        self.arr = []

    def createMatrix(self):
        for i in range(self.rows):
            row = []
            for j in range(self.cols):
                ele = int(input("Enter element: "))
                row.append(ele)
            self.arr.append(row)

    def display(self):
        for x in self.arr:
            for y in x:
                print(y, end=' ')
            print()

    def addition(self, B):
        if self.rows == B.rows and self.cols == B.cols:
            C = Matrix(self.rows, self.cols)
            for i in range(self.rows):
                row = []
                for j in range(self.cols):
                    sum = self.arr[i][j] + B.arr[i][j]
                    row.append(sum)
                C.arr.append(row)
            return C
        else:
            print("Addition not possible.")

    def subtraction(self, B):
        if self.rows == B.rows and self.cols == B.cols:
            C = Matrix(self.rows, self.cols)
            for i in range(self.rows):
                row = []
                for j in range(self.cols):
                    diff = self.arr[i][j] - B.arr[i][j]
                    row.append(diff)
                C.arr.append(row)
            return C
        else:
            print("Subtraction not possible.")

    def multiplication(self, B):
        if self.cols == B.rows :
            C = Matrix(self.rows, B.cols)
            for i in range(self.rows):
                row = []
                for j in range(B.cols):
                    product = 0
                    for k in range(B.rows):
                        product = product+ (self.arr[i][k] * B.arr[k][j])
                    row.append(product)
                C.arr.append(row)
            return C

        else:
            print("Multiplication not possible.")

    def transpose(self):
        transpose = Matrix(self.cols, self.rows)
        for i in range(self.cols):
            row = []
            for j in range(self.rows):
                row.append(self.arr[j][i])
            transpose.arr.append(row)
        return transpose

    def symmetric(self):
        if self.rows == self.cols:
            AT = self.transpose()
            for i in range(self.rows):
                for j in range(self.cols):
                    if self.arr[i][j] != AT.arr[i][j]:
                        return "Not Symmetric Matrix"
            return "Symmetric Matrix"
        else:
            return "Not Square Matrix"

    def diagonal(self):
        if self.rows == self.cols:
            for i in range(self.rows):
                for j in range(self.cols):
                    if i != j:
                        if self.arr[i][j] != 0:
                            return "Not Diagonal Matrix"
            return "Diagonal Matrix"
        else:
            return "Not Square Matrix"

    def UpperTriangular(self):
        if self.rows == self.cols:
            for i in range(self.rows):
                for j in range(self.cols):
                    if i > j:
                        if self.arr[i][j] != 0:
                            return "Not Upper Triangular Matrix"
            return "Upper Triangular Matrix"
        else:
            return "Not Square Matrix"

    def LowerTriangular(self):
        if self.rows == self.cols:
            for i in range(self.rows):
                for j in range(self.cols):
                    if i < j:
                        if self.arr[i][j] != 0:
                            return "Not Lower Triangular Matrix"
            return "Lower Triangular Matrix"
        else:
            return "Not Square Matrix"

print("1.Create Matrix"
      "\n2.Addition"
      "\n3.Subtraction"
      "\n4.Multiplication"
      "\n5.Transpose"
      "\n6.Symmetric"
      "\n7.Diagonal"
      "\n8.Upper Triangular"
      "\n9.Lower Triangular"
      "\n0.Exit")

def createA():
    rows_a = int(input("Enter number of rows in Matrix A: "))
    cols_a = int(input("Enter number of columns in Matrix A: "))
    A = Matrix(rows_a , cols_a)
    print("Enter elements for matrix A")
    A.createMatrix()
    A.display()
    return A
def createB():
    rows_b = int(input("Enter number of rows in Matrix B: "))
    cols_b = int(input("Enter number of columns in Matrix B: "))
    B = Matrix(rows_b, cols_b)
    print("Enter elements for matrix B")
    B.createMatrix()
    B.display()
    return B



while True:
    c = int(input("Enter choice:"))
    if c == 1:
        A = createA()
        B = createB()
    elif c == 2:
        C = A.addition(B)
        C.display()
    elif c == 3:
        C = A.subtraction(B)
        C.display()
    elif c == 4:
        C = A.multiplication(B)
        C.display()
    elif c == 5:
        print("Transpose of A: ")
        transposeA = A.transpose()
        transposeA.display()
        print("Transpose of B: ")
        transposeB = B.transpose()
        transposeB.display()
    elif c == 6:
        print("Enter matrix to check if symmetric.")
        mat = createA()
        print(mat.symmetric())
    elif c == 7:
        print("Enter matrix to check if diagonal.")
        mat = createA()
        print(mat.diagonal())
    elif c == 8:
        print("Enter matrix to check if upper triangular.")
        mat = createA()
        print(mat.UpperTriangular())
    elif c == 9:
        print("Enter matrix to check if lower triangular.")
        mat = createA()
        print(mat.LowerTriangular())
    elif c == 0:
        break
    else:
        print("Enter valid choice.")
