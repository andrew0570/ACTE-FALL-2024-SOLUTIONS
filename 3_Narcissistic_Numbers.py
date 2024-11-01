#narcissistic numbers
num1=int(input()) #takes in number input
num2=list(map(int,str(num1))) #makes number input a list of integers
sum=0
for numbers in num2: #loops through digits of num1
    sum+=(numbers**len(num2)) #adds together all digits, each raised to the power of the number of digits
print(sum==num1) #prints boolean value
