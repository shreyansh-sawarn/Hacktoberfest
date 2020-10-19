#Given an array arr of 4 digits, find the latest 24-hour time that can be made using each digit exactly once.
#24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59. The earliest 24-hour time is 00:00, and the latest is 23:59.
#Return the latest 24-hour time in "HH:MM" format.  If no valid time can be made, return an empty string.

import itertools
from builtins import object, max


class Solution(object):
    def largestTimeFromDigits(self, A):
        """
        :type A: List[int]
        :rtype: str
        """
        max_time = -1
        # enumerate all possibilities, with the permutation() func
        for h, i, j, k in itertools.permutations(A):
            hour = h * 10 + i
            minute = j * 10 + k
            if hour < 24 and minute < 60:
                max_time = max(max_time, hour * 60 + minute)

        if max_time == -1:
            return ""
        else:
            return "{:02d}:{:02d}".format(max_time // 60, max_time % 60)
