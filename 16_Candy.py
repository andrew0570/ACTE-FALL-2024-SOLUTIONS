"""
    Since Joey always goes first, he will always win and get more candy
    if both players play optimally

    When there are 2 piles, the first player can always take the larger pile.
    When there are 4 piles, the first player can either take piles 1+3 or 2+4, and one of the groups will always be larger.
    This concept can be extended to every number after where the first player takes all the even indexed groups or all the odd indexed groups.
"""
#input()
#input()
#print("Joey")


"""
    Alternatively, you can solve with dynamic programming.
    dp(i,j) = joey's max score from piles i through j
     - john's points count as negative of joey's points
     - if joey has positive points from 0 to N then he wins
"""
# GETTING INPUT
n = int(input())
piles = [int(i) for i in input().split()]

# DEFINE dp(i,j) FUNCTION
def dp(i,j):
    if i>j: return 0

    if (j-i) % 2 == 1: # joey (player 1)
        return max(dp(i+1,j)+piles[i], dp(i,j-1)+piles[j])
    else: # john (player 2)
        return min(dp(i+1,j)-piles[i], dp(i,j-1)-piles[j])
    
if dp(0,n-1) > 0:
    print("Joey")
else:
    print("John")
