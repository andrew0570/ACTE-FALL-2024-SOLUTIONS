#pascal's triangle
import math
n=int(input()) #nth row
row=[] #list to store coefficient
for k in range(n+1):
    coeff=math.comb(n,k) #function to find each coefficient of the nth row
    row.append(coeff)
print(" ".join(map(str,row))) #prints the coefficients in row list