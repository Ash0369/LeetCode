class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        for i in ransomNote:
            if magazine.count(i)<ransomNote.count(i):
                return False
        return True
