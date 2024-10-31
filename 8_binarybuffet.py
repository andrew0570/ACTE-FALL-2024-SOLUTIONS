#number sets
N,K,L=map(int,input().split()) #takes in user input
tuples=[list(map(int,input().split())) for _ in range(N)] #takes in tuples
tuples.sort(key=lambda x:x[L]) #sorts by the Lth index
for i in tuples: #prints the first number of sorted tuples
    print(i[0])