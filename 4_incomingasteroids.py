#Incoming asteroids
import math
num=int(input()) #takes user input
distances=[] #stores distances
for _ in range(num): #loop
    x,y=map(int,input().split(",")) #takes in coordinates
    dist=math.sqrt(math.pow((x-0),2)+math.pow((y-0),2)) #distance formula
    distances.append(str(round(dist))) #add distance to list
print(" ".join(distances)) #prints the distances list as a string