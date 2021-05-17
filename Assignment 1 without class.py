'''Group A = Cricket
   Group B = Badminton
   Group C = Football'''


def addEle(total, set):
    for i in range(total):
        a = int(input("Enter roll number. "))
        if a not in set:
            set.append(a)

def unionSet(set1, set2):
    union = set1.copy()
    for element in set2:
        if element not in union:
            union.append(element)
    return union

def intersectionSet(set1, set2):
    intersection = []
    for element in set1:
        if element in set2:
            intersection.append(element)
    return intersection

def diffSet(set1, set2):
    diff = []
    for element in set1:
        if element not in set2:
            diff.append(element)
    return diff
def sym_diffSet(set1, set2):
    x = unionSet(set1, set2)
    y = intersectionSet(set1, set2)
    return diffSet(x, y)

def display(result):
    print("{", end="")
    for i in result:
        print(i, ",", end="")
    print("}")

total_A = int(input("Enter number of students playing cricket. "))
A = []
addEle(total_A, A)

total_B = int(input("Enter number of students playing badminton. "))
B = []
addEle(total_B, B)

total_C = int(input("Enter number of students playing football. "))
C = []
addEle(total_C, C)

while True:
    print("1.List of students who play both cricket and badminton \n2.List of students who play cricket or badminton but not both \n3.Number of students who play neither cricket nor badminton \n4.Number of students who play cricket and football but not badminton \n0.Exit")
    c = int(input("Enter choice: "))

    if c == 1:
        display(intersectionSet(A, B))

    elif c == 2:
        display(sym_diffSet(A, B))

    elif c == 3:
        x = unionSet(A, B)
        y = unionSet(x, C)
        result = diffSet(y,x)
        print(len(result))

    elif c == 4:
        x = intersectionSet(A, C)
        y = intersectionSet(x, B)
        result = diffSet(x,y)
        print(len(result))

    elif c == 0:
        break
    else:
        print("Enter valid choice.")
