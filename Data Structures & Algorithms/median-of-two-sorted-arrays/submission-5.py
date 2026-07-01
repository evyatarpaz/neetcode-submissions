class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        A = 0 # A is define to be the smaller array
        B = 0 # B is define to be the larger array

        # arrange the array so A hold the small array and B hold the large array
        if len(nums1) < len(nums2):
            A = nums1
            B = nums2
        else:
            A = nums2
            B = nums1
        
        # the length of the marge arrays
        total = len(A) + len(B)

        # round down
        half = total // 2

        left, right = 0, len(A) - 1

        # in an array the maiden is a must so the while will stop
        while True:

            # the right most index on the left partition in Array A (the maiden)
            i = (left + right) // 2

            # the right most index on the left partition in Array B (the maiden)
            # half represent the number of elements in the left partition of Array B
            # and the i represent index and not the amount of element in the left partition of Array A
            # so to calculate the index needed we need to take 1 from half and add 1 to i.
            j = half - i - 2

            # take the val of the right most index on the left patition in Array A
            # unless the index is less the 0 then -inf because we want only from array B
            Aleft = A[i] if i >= 0 else float("-infinity")

            # take the val of the left most index on the right patition in Array A
            # unless the index is grater then the len of A
            Aright = A[i + 1] if (i + 1) < len(A) else float("infinity")

            # take the val of the right most index on the left patition in Array B
            # unless the index is less the 0 then -inf because we want only from array A       
            Bleft = B[j] if j >= 0 else float("-infinity")

            # take the val of the left most index on the right patition in Array B
            # unless the index is grater then the len of B
            Bright = B[j+1] if (j+1) < len(B) else float("infinity")

            # if the partition is the correct one
            if Aleft <= Bright and Bleft <= Aright:
                
                # we have 2 cases Add, Even

                if total % 2 == 0:
                    mid1 = max(Aleft,Bleft)
                    mid2 = min(Aright,Bright)
                    return (mid1 + mid2) / 2
                else:
                    return min(Aright,Bright)
            elif Aleft > Bright:
                right = i - 1
            else:
                left = i + 1

