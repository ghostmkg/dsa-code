"""
            Assign Cookies
            
Problem Statement: Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

Algorithm / Intuition: Greedy Algorithms are approached to solve problems by making the current best choice at each stage with the hope of getting the best answer overall as well. At each step of the algorithm, we choose the best possible option available without considering the consequences of the choice in future steps.
To solve this question, we sort the greed and cookies array to easily make decisions about which cookie to assign to which child. We then iterate over the sorted arrays comparing elements and assigning the smallest available cookie with the least greedy child.
This way we are able to leave larger cookies for potentially gredier children so that we are able to maximise the overall satisfaction.

Algorithm:
Step 1:Sort both the greed and cookieSize array. By sorting, we are able to pair the smallest cookies with the least greedy children, maximising overall content.
Step 2: Use two pointers, l and r to iterate through the cookieSize and greed arrays. These pointers represent the positions of the smallest available cookie and the least greedy child.
Step 3: We iterate through the arrays, checking if the current cookie can satisfy the current child’s greed. Ie. cookieSize[l] >= greed[r].
If the current cookie can satisfy the current child’s greed, we move to the next child.
Regardless of whether a child is satisfied or not, we move to the next cookie.
Step 4: At the end, the value of r, represents the number of children that were satisfied as we increment it each time a child’s greed is satisfied. We return this value as the total number of satisfied children.
"""

def assignCookies(g, s):
    g.sort()
    s.sort()
    child = 0
    cookie = 0
    while child < len(g) and cookie < len(s):
        if s[cookie] >= g[child]: 
            child += 1  
        cookie += 1 
    return child

#Sample Input For Checking
g = [1, 2, 3]  
s = [1, 1, 2, 3] 

print("Maximum content:", assignCookies(g, s))#Output: 3

"""
Complexity

Time Complexity: O(n log n + m log m)
Space Complexity: O(1) (in-place)
"""

"""
g → Greed Factors of Children
s → Sizes of Cookies
n → The number of children
m→ The number of cookies
"""