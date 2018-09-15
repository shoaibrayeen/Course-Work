#iterative Partition
def partition(array , low , high):
    i = ( low - 1 )
    x = array[high]
    for j in range(low , high):
        if array[j] <= x:
            i = i+1
            array[i] , array[j] = array[j] , array[i]
    array[i+1],array[high] = array[high],array[i+1]
    return (i+1)

def quickSortIterative(array):
    stack = [0] * (len(array))
    low  = 0
    high = len(array) - 1
    top = -1
    top = top + 1
    stack[top] = low
    top = top + 1
    stack[top] = high
    while top >= 0:
        high = stack[top]
        top = top - 1
        low = stack[top]
        top = top - 1
        partitionIndex = partition( array , low , high )
        if partitionIndex - 1 > low:
            top = top + 1
            stack[top] = low
            top = top + 1
            stack[top] = partitionIndex - 1
        if partitionIndex + 1 < high:
            top = top + 1
            stack[top] = partitionIndex + 1
            top = top + 1
            stack[top] = high
 
arr = [6 , 5 , 4 , 3 , 1]
quickSortIterative(arr)
print "\nSorted list is"
print arr
