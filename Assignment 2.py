def length(list):
    count = 0
    for i in list:
        count+= 1
    return count

class String:
    def createString(self, string):
        self.str = []
        count = 0
        for i in string:
            self.str.append(i)
            count+=1
        self.length = count
        return self.str

    def addChar(self, char):
        self.str.append(char)
        return self.str

    '''def longestString(self):
        longeststring = String()
        longeststring.createString(string='')
        longlength = 0
        templength = 0
        index = 0
        for i in range(self.length):
            if self.str[i] == ' ' or i == self.length - 1 :
                if templength > longlength:
                    longlength = templength
                    index = i - templength

                templength = 0
            else:
                templength += 1

        for j in range(index, index + longlength + 1 ):
            longeststring.addChar(self.str[j])
        return longeststring.str'''

    '''def longestString(self):
        longeststring = String()
        longeststring.createString(string='')
        longlength = 0
        templength = 0
        index = 0
        for i in range(self.length):
            if self.str[i] == ' ' :
                if templength > longlength:
                    longlength = templength
                    index = i - templength

                templength = 0
            elif i == self.length - 1:
                templength += 1
                if templength > longlength:
                    longlength = templength
                    index = i - templength

                templength = 0

            else:
                templength += 1

        for j in range(index, index + longlength + 1 ):
            longeststring.addChar(self.str[j])
        return longeststring.str'''

    def longestString(self):
        longeststring = String()
        longeststring.createString(string='')
        longlength = 0
        templength = 0
        index = 0
        a = 0
        for i in range(self.length):
            if self.str[i] == ' ' or i == self.length - 1:
                if i == self.length -1:
                    a = 1

                if a == 1:
                    templength+=1

                if templength > longlength:
                    longlength = templength
                    index = i - templength

                templength = 0

            else:
                templength += 1

        for j in range(index, index + longlength + 1 ):
            longeststring.addChar(self.str[j])
        return longeststring.str


    def charOccurrence(self, char):
        frequency = 0
        for i in range(0, self.length):
            if char == self.str[i]:
                frequency += 1
        return frequency

    def palindrome(self, index):
        word = String()
        word.createString(string='')
        counter = 0
        for i in range(0, self.length):

            if self.str[i] == ' ':
                counter += 1
                continue
            if counter == index:
                word.addChar(self.str[i])
            if counter > index:
                break

        for j in range(0, length(word.str)):
            if word.str[j] != word.str[length(word.str) - j -1]:
                return False
        return True

    def firstAppearance(self, string):
        substr = String()
        substr.createString(string)
        for i in range(self.length):
            if i + substr.length - 1 < self.length:
                a = 1
                for j in range(substr.length):
                    if substr.str[j] != self.str[i + j]:
                        a = 0
                if a == 1:
                    return i
        return -1


    def subString(self, string):
        substr = String()
        substr.createString(string)
        count = 0
        for i in range(self.length):
            if i + substr.length - 1 < self.length:
                a = 1
                for j in range(substr.length):
                    if substr.str[j] != self.str[i + j]:
                        a = 0
                if a == 1:
                    count += 1
            else:
                break
        return count


    def wordOccurrence(self):
        wordslist = []  #contains all words present in the main string
        occurrences = [[['w'], 0]]  #contains lists of a pair of a word with its count of occurrence
        word = []

        for i in range(self.length):
            if self.str[i] == ' ':
                wordslist.append(word)
                word = []
            else:
                word.append(self.str[i])
        wordslist.append(word)

        for i in range(length(wordslist)):
            if [wordslist[i],0] not in occurrences:
                occurrences.append([wordslist[i], 0])
        print(occurrences[1:])
        #print(wordslist)
        #count = 0
        for i in range(length(occurrences)):
            for j in range(0, length(wordslist)):
                if occurrences[i][0] == wordslist[j]:
                    occurrences[i][1]+=1
            #occurrences.append(count)
            #count = 0
        print(occurrences[1:])



mainstring = String()

print("1.Enter string and display List of characters"
      "\n2.Add single Character"
      "\n3.Find the longest String"
      "\n4.Find the character occurrence"
      "\n5.Check if Palindrome"
      "\n6.Find index of first appearance of a substring"
      "\n7.Find the number of substring occurrences"
      "\n8.Find the number of occurrences of all words"
      "\n0.Exit")

while True:

    c= int(input("\nEnter choice: "))

    if c == 1:
        string = input("Enter String: ")
        print("Main String: " , mainstring.createString(string))
    elif c == 2:
        char = input("Enter single character to be added: ")
        print("New Main String: ", mainstring.addChar(char))
    elif c == 3:
        print("Longest String: " , mainstring.longestString())
    elif c == 4:
        char = input("Enter character: ")
        print("Number of occurrences: " , mainstring.charOccurrence(char))
    elif c == 5:
        index = int(input("Enter index of word to be checked: "))
        print(mainstring.palindrome(index))
    elif c == 6:
        string = input("Enter substring: ")
        print(mainstring.firstAppearance(string))
    elif c == 7:
        string = input("Enter substring: ")
        print(mainstring.subString(string))
    elif c == 8:
        mainstring.wordOccurrence()
    elif c == 0:
        break
    else:
        print("Enter valid choice.")



