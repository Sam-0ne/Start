import math
import os
import random
import re
import sys

#
# Complete the 'timeConversion' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def timeConversion(s):
    meridiem = s[-2:-1]    
    time = s[0:8]
    time = time.split(":")
    hour = int(time[0])
    if meridiem == "P":
        if hour < 12:
            hour += 12
    if meridiem == "A" and hour == 12:
        hour = 0
        
    convTime = str(hour).zfill(2)+":"+time[1]+":"+time[2]
    return convTime

if __name__ == '__main__':
    
    s = "12:45:00AM"
    result = timeConversion(s)

    print(result)