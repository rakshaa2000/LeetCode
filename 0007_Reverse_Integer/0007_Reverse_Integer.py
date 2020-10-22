class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x < 0:
            return -self.reverse(-x)

        result = 0
        while x:
            result = result * 10 + x % 10
            x //= 10
        return result if result <= 0x7fffffff else 0  # Handle overflow.

    def reverse2(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x < 0:
            x = int(str(x)[::-1][-1] + str(x)[::-1][:-1])
        else:
            x = int(str(x)[::-1])
        x = 0 if abs(x) > 0x7FFFFFFF else x
        return x

    def reverse3(self, x):
        """
        :type x: int
        :rtype: int
        """
        s = cmp(x, 0)
        r = int(repr(s * x)[::-1])
        return s * r * (r < 2 ** 31)

# Alternative solution

class Solution:
    # @return an integer

    # def reverse(self, x):
    #     max_int = 2147483647
    #     if x == 0:
    #         return 0
    #     isPos = True
    #     if x < 0:
    #         x *= (-1)
    #         isPos = False
    #     ltemp = []
    #     while x != 0:
    #         temp = x % 10
    #         ltemp.append(temp)
    #         x /= 10
    #     result = 0
    #     # the main solution
    #     for t in ltemp:
    #         result = result * 10 + t
    #     if result > max_int:
    #         result = 0
    #     if isPos:
    #         return result
    #     else:
    #         return -1 * result

    def reverse(self, x):
        # Note that in Python -1 / 10 = -1
        res, isPos = 0, 1
        if x < 0:
            isPos = -1
            x = -1 * x
        while x != 0:
            res = res * 10 + x % 10
            if res > 2147483647:
                return 0
            x /= 10
        return res * isPos