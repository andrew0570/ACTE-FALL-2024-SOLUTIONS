#secret message
num=int(input()) #number of iterations
anslist=[] #list for storing letters of decoded message
letters=['a','e','i','o','u','A','E','I','O','U'] #vowel list
for i in range(num): #iterates num times
    word=input() #takes in string
    hiddenmessage=""
    flag=False
    for char in word:
        if char in letters and not flag: #ensures to count the vowel following a vowel
            flag=True
        elif flag: #appends char current char to hidden message string
            hiddenmessage+=char
            flag=False
    anslist.append(hiddenmessage) #appends answer string to list
for items in anslist: #prints the hidden messages for each string
    print(items)