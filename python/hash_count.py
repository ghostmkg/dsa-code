class Solution:
    def hashCount(self, arr,n):
        hash={}
        for i in range (n):
            if arr[i] in hash:
                hash[arr[i]]+=1
            else:
                hash[arr[i]]=1

        for key,value in hash.items():
            print(key,value)


n=int(input("Enter how many numbers you want in the array"))
arr=[]
for i in range(n):
    ele=int(input("Enter: "))
    arr.append(ele)

soution=Solution()
soution.hashCount(arr,n)