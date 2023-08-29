[1,4,6,8,10]
​
**for element 6**
* leftsum=(6-4)+(6-1)=(2*6)-(4+1)
=(no. of elements on left*current element)-sum of elements on left
* rightsum=(8-6)+(10-6)=(8+10)-(2*6)
=sum of elements on right-(no. of elements on right*current element)
* so for 6,  ans[2]=leftsum+rightsum
* sum of elements on left and right can be maintained though prefix and suffix sum arrays
respectively