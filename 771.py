class Solution(object):
    def numJewelsInStones(self, jewels, stones):
        count=0
        for x in stones:
            if(jewels.count(x)!=0):
                count+=1
        return count
