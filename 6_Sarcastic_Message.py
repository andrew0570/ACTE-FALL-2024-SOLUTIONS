s = input()

alternator = 0
result = []  # List to build the new string with alternating capitalization

for char in s:
    if char.isalpha():  # only change case for letters
        if alternator == 0:
            result.append(char.upper())  # change to uppercase
            alternator = 1  
        else:
            result.append(char.lower())  # change to lowercase
            alternator = 0  
    else:
        result.append(char)  # for any non-letter character, leave it alone


s = ''.join(result) #join back into one string 
print(s)

