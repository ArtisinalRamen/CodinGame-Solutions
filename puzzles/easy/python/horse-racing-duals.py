# https://www.codingame.com/training/easy/horse-racing-duals
# Both functions/methods are functionally idential however
# Using list comprehension is barely faster due to the avoidance of the list.append() function
def GetMinDiffUsingListComprehension(nums: list[int]) -> int:
    '''Takes a list of numbers and returns the minimum difference between all elements'''
    return min([nums[i + 1] - nums[i] for i in range(len(nums)) if i+1 < len(nums)])


def GetMinDiff(nums : list[int]) -> int:
    '''Takes a list of numbers and returns the minimum difference between all elements'''
    diffs: list[int] = []
    for x in range(len(nums)): 
        if (x + 1 < len(nums)):
            difference: int = nums[x + 1] - nums[x]
            diffs.append(difference)
    return min(diffs)


numOfHorses: int = int(input())
horseStrengths: list[int] = []

for i in range(numOfHorses):
    strength: int = int(input()) 
    horseStrengths.append(strength)

horseStrengths.sort()
print(GetMinDiffUsingListComprehension(horseStrengths))