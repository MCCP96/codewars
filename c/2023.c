#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

// Hello World					9/16/2023
/*
int main(void)
{
  printf("Hello, world!\n");
} */

// Two Sum					9/16/2023
/*
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

// Example 1:
// 		Input: nums = [2,7,11,15], target = 9
// 		Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:
// 		Input: nums = [3,2,4], target = 6
// 		Output: [1,2]

// Example 3:
// 		Input: nums = [3,3], target = 6
// 		Output: [0,1]

// Constraints:
//		2 <= nums.length <= 104
//		-109 <= nums[i] <= 109
//		-109 <= target <= 109
//		Only one valid answer exists.

// Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
  for (int i = 0; i < numsSize; i++)
  {
    for (int j = i + 1; j < numsSize; j++)
    {
      if (nums[i] + nums[j] == target)
        return (int[2]){i, j};
    }
  }
}

int main(void)
{
  printf("%d", twoSum((int[4]){2, 7, 11, 15}, 4, 9, (int[2]){0, 1})); // [0,1]
  return EXIT_SUCCESS;
}

// I'm out of my depth in C

int *topVotedTwoSum(int *nums, int numsSize, int target, int *returnSize)
{
  *returnSize = 2;
  int *returnValues = malloc((*returnSize) * sizeof(int));

  for (int i = 0; i < numsSize - 1; i++)
  {
    for (int j = i + 1; j < numsSize; j++)
    {
      if (nums[i] + nums[j] == target)
      {
        returnValues[0] = i;
        returnValues[1] = j;
        break;
      }
    }
  }

  return returnValues;
}

// Started my second year of software engineering this September and we're learning C. Thought I might try out some easy questions and get some practice in.

// Definitely need to study.

// https://www.tutorialspoint.com/c_standard_library/c_function_malloc.htm
// "The C library function void *malloc(size_t size) allocates the requested memory and returns a pointer to it." */

// Palindrome Number					9/17/2023

// Given an integer x, return true if x is a palindrome and false otherwise.

// Example 1:
// 		Input: x = 121
// 		Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.

// Example 2:
// 		Input: x = -121
// 		Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

// Example 3:
// 		Input: x = 10
// 		Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

// Constraints:
//		-231 <= x <= 231 - 1

// Follow up: Could you solve it without converting the integer to a string?

bool isPalindrome(int x)
{
  if (x < 0)
  {
    return false;
  }

  char str[(int)((ceil(log10(x)) + 1) * sizeof(char))]; // from stackoverflow
  sprintf(str, "%d", x);

  for (int i = 0, j = strlen(str) - 1; i < strlen(str) / 2; i++, j--)
  {
    if (str[i] != str[j])
    {
      return false;
    }
  }

  return true;
}

// Leetcode gives a runtime error
// Probably string conversion or sprintf

// Memory allocation is something I've really taken for granted in javascript

bool topVotedIsPalindrome(int x)
{
  if (x < 0 || x != 0 && x % 10 == 0)
    return false;

  int check = 0;
  while (x > check)
  {
    check = check * 10 + x % 10;
    x /= 10;
  }

  return (x == check || x == check / 10);
}

int main(void)
{
  topVotedIsPalindrome(121);  // true
  topVotedIsPalindrome(-121); // false
  topVotedIsPalindrome(10);   // false
  return EXIT_SUCCESS;
}

// Better to use the math approach
// While loop cuts it in half and "... || x == check / 10" accounts for odd amount of digits