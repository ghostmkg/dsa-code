"""
            Lemonade Change

Problem Statement: At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.
Note that you do not have any change in hand at first.
Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.

Algorithm / Intuition: We can approach this question by maintaining two counters to keep track of the available 5$ and 10$ bills. We iterate through the customers and provide change accordingly.
If a customer pays with a 5$ bill, we simply keep it as we will not have to provide any change. If the customer pays with a 10$ bill, we check if there is at least one 5$ bill available to provide change and decrement the counter.
If the customer uses a 20$ bill, we provide change using 5$ and 10$ bills or with three 5$ bills. If at any point, we are not able to provide the required change we return false.
Otherwise, if we successfully serve all customers with the correct change, we can return true.

Algorithm:
Step 1:Initialise two counters, fives and tens to keep track of the number of 5$ and 10$ bills at hand. Initialise them to zero as we hold no change at the starting.
Step 2: Loop through each bill in the bills array and check the following: If the bill is 5$, increment the fives counter.
Step 3: If the bill is 10$, check if there are any 5$ bills available.
If yes, provide change by incrementing the 10$ bill counter and decrementing the 5$ bill counter.
If there are no 5$ bills available, return false as we cannot provide change.
Step 4: If the current bill is 20$, check if both 5$ and 10$ bills are available. If yes, provide change by decreasing the counter of 5$ and 10$ bills.
If there are not enough 10$ bills available, check if there are at atleast three 5$ bills available. If yes, provide change by decreasing the 5$ counter by 3.
If not able to provide change, return false.
Step 5: If all customers are served with the correct change, we exit out of the loop and return true.
"""
def lemonadeChange(bills):
    five, ten = 0, 0
    for bill in bills:
        if bill == 5:
            five += 1
        elif bill == 10:
            if five == 0:
                return False
            five -= 1
            ten += 1
        else:
            if ten > 0 and five > 0:
                ten -= 1
                five -= 1
            elif five >= 3:
                five -= 3
            else:
                return False
    return True

#Sample Input For Checking
bills1 = [5,5,5,10,20]
bills2 = [5,5,10,10,20]

print(lemonadeChange(bills1)) #Output: True
print(lemonadeChange(bills2)) #Output: False

"""
Complexity

Time Complexity: O(n)
where n = len(bills)
Space Complexity: O(1)
"""
