class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        l=[]
        for i in range (0,len(temperatures)) :
            for j in range(1,len(temperatures)) :
                if (i+j<len(temperatures)): 
                    if(temperatures[i]<temperatures[i+j]):
                        l.append(j)
                        break
            else:
                l.append(0)

        return l                