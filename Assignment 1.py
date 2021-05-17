def exists(ele, set):
    if ele in set:
        return True
    else:
        return False

def length(result):
    count = 0
    for i in result:
        count += 1
    return count

def display(result):
    print("{", end="")
    for i in range(length(result)):
        if i == length(result)-1:
            print(result[i], "}")
        else:
            print(result[i], ",", end="")


class Set:
    def __init__(self):
        self.set = []

    '''def __init__(self, str):
        self.str = str
        self.total = int(input("Enter number of students playing " + self.str + ":"))
        self.set = []'''

    def addEle(self, total):
        for i in range(total):
            try:
                a = int(input("Enter roll number. "))
                if a not in self.set:
                    self.set.append(a)
            except:
                print("Enter valid roll number.")
                break

    def unionSet(self, set2):
        # union = self.set.copy()
        union = []
        for i in range(length(self.set)):
            union.append(self.set[i])
        for element in set2:
            if exists(element, union) == False:
                union.append(element)
        return union

    def intersectionSet(self, set2):
        intersection = []
        for element in self.set:
            if exists(element, set2) == True:
                intersection.append(element)
        return intersection

    def diffSet(self, set2):
        diff = []
        for element in self.set:
            if exists(element, set2) == False:
                diff.append(element)
        return diff

    def sym_diffSet(self, set2):
        x = Set()
        x.set = self.unionSet(set2)
        y = self.intersectionSet(set2)
        return x.diffSet(y)

    @staticmethod
    def subset(ss, set):
        flag = 0
        if (all(x in set for x in ss)):
            flag = 1

        if (flag):
            print("Yes, list is subset of other.")
        else:
            print("No, list is not subset of other.")


total_A = int(input("Enter number of students playing cricket. "))
A = Set()
A.addEle(total_A)

total_B = int(input("Enter number of students playing badminton. "))
B = Set()
B.addEle(total_B)

total_C = int(input("Enter number of students playing football. "))
C = Set()
C.addEle(total_C)

'''A = Set("cricket")
A.addEle()

B = Set("badminton")
B.addEle()

C = Set("football")
C.addEle()'''


while True:
    print("1.List of students who play both cricket and badminton "
          "\n2.List of students who play cricket or badminton but not both "
          "\n3.Number of students who play neither cricket nor badminton "
          "\n4.Number of students who play cricket and football but not badminton "
          "\n5.Check if subset"
          "\n0.Exit")
    c = int(input("Enter choice: "))

    if c == 1:
        display(A.intersectionSet(B.set))

    elif c == 2:
        display(A.sym_diffSet(B.set))

    elif c == 3:
        y = Set()
        x = A.unionSet(B.set)
        y.set = C.unionSet(x)
        result = y.diffSet(x)
        print(length(result))

    elif c == 4:
        x = Set()
        x.set = A.intersectionSet(C.set)
        y = B.intersectionSet(x.set)
        result = x.diffSet(y)
        print(length(result))

    elif c == 5:
        lengthss = int(input("Enter length of subset:"))
        ss = []
        for i in range(lengthss):
            ele = int(input("Enter element:"))
            ss.append(ele)
        length = int(input("Enter length of set:"))
        s = []
        for i in range(length):
            ele = int(input("Enter element:"))
            s.append(ele)

        Set.subset(ss, s)

    elif c == 0:
        break
    else:
        print("Enter valid choice.")
