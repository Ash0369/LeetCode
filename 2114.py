#Method-1 : 

class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:
        res=0;
        for word in sentences:
            res=max(res,len(word.split()))
        return res
      
 #Method-2 : 

class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:
        return max(len(words.split()) for words in sentences)
