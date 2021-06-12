# [interviewbit-Subarray-with-B-odd-numbers](https://www.interviewbit.com/problems/subarray-with-b-odd-numbers/)

My solution for the problem - [interviewbit Subarray with B odd numbers](https://www.interviewbit.com/problems/subarray-with-b-odd-numbers/)

## Problem Description 
Given an array of integers A and an integer B.

Find the total number of subarrays having exactly B odd numbers.



## Problem Constraints
- 1 <= length of the array <= 10^5
- 1 <= A[i] <= 109
- 0 <= B <= A



## Input Format
The first argument given is the integer array A.
The second argument given is integer B.



## Output Format
Return the total number of subarrays having exactly B odd numbers.



## Example Input
### Input 1:

 A = [4, 3, 2, 3, 4]
 B = 2
### Input 2:

 A = [5, 6, 7, 8, 9]
 B = 3


## Example Output
### Output 1:
 4
### Output 2:
 1


## Example Explanation
### Explanation 1:

 The subarrays having exactly B odd numbers are:
 [4, 3, 2, 3], [4, 3, 2, 3, 4], [3, 2, 3], [3, 2, 3, 4]
### Explanation 2:

 The subarrays having exactly B odd numbers is [5, 6, 7, 8, 9]


## My Approach 
### Way 1 

Lets try to calculate 2 tables mx[] and mn[] . mx[i] will tell us maximum index we can go up to if we start from i so that the segment A[i...mx[i]] fulfills the condition . Similarly , mn[i] will tell us minimum index we can go up to if we start from i so that the segment A[i...mn[i]] fulfills the condition . Then number of subarrays that starts from i and fulfills the condition is  - mx[i]-mn[i]+1

So , result = sum(mx[i]-mn[i]+1) for i = 0 to A.size() 

We can calculate mx[] and mn[] with 2 for loops easily in N^2 complexity where N is lenght of A . But we can see it will always be mx[i] >= i and mn[i] >= i . So we can reduce the complexity using sliding window or 2 pointer. 

Complexity : O(N) time and O(N) space where N is lenght of A. 

### Way 2 

We can have a hashmap 'map'so that map[t] will tell us the number of subarrays starting from index 0 that ends before index i and have t odd numbers. So if number of odd numbers till i is x , number of subarrays that end at i and fulfills the condition will be map[x-B]. We can find the total result if we do this for every index . 

Complexity : O(N) time and O(N) space where N is lenght of A. 
