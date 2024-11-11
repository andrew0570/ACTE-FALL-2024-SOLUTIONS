#historical figures
name=input()
greatest=0
dictletters={}
for letters in name: #loops through every letter
    if(letters in dictletters.keys()): #checks if there is already an existing key for the letter
        dictletters[letters]=dictletters[letters]+1 #updates dictionary to keep running total of letters
    else: #if there is not already an existing key, make a new key of current letter and set it to 1 
        dictletters[letters]=1
for keys in dictletters: #traverses dictionary
    if(dictletters[keys]>greatest): #finding key (Letter) with greatest count
        greatest=dictletters[keys]
print(str(greatest)+" packs")
