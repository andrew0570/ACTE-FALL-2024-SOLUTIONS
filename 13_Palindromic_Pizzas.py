#palindromic pizzas
from itertools import permutations
str1=input() #input string
uniqueperms=set(permutations(str1)) #generates list of distinct combinations of letters in str1
ans=[] #list of palindromes
anslist=["".join(p) for p in uniqueperms] #makes list of the different arrangements of letters in str1
for words in anslist: #iterates through each word in anslist
    str1=words #sets str1 to the current word
    str2=words[::-1] #sets str2 to reverse str1
    if(str1==str2): #checks for palindrome
        ans.append(str1)
ans.sort() #sorts palindromes by alphabetical order
print(ans[0]) #prints the first palindrome alphabetically
