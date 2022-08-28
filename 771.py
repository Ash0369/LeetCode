class Solution(object):
    def numJewelsInStones(self, jewels, stones):
        count=0
        for x in stones:
            if(jewels.count(x)!=0):
                count+=1
        return count

    
 class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        count=0
        for x in stones:
            if(jewels.count(x)!=0):
                count+=1
        return count
  

class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        count=0
        for x in stones:
            if(x in jewels):
                count+=1
        return count
