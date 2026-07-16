class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        p=1
        su=0
        for i in (str(n)):
            p=p*int(i)
            su=su+int(i)
        return p-su
        