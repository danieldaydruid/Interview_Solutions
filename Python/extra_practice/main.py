'''
return a new sorted merged list from K sorted lists, each with size N.

[[10, 15, 30], [12, 15, 20], [17, 20, 32]]
'''
'''
#Instructor solution
import heapq

def merge(lists):
    merged_list = []

    heap = [(lst[0], i, 0) for i, lst in enumerate(lists) if lst]
    heapq.heapify(heap)

    while heap:
        val, list_ind, element_ind = heapq.heappop(heap)

        merged_list.append(val)

        if element_ind + 1 < len(lists[list_ind]):
            next_tuple = (lists[list_ind][element_ind + 1],
                          list_ind,  
                          element_ind + 1)
            heapq.heappush(heap, next_tuple)
    return merged_list
#End instructor solution 
print(merge([[10, 15, 30], [12, 15, 20], [17, 20, 32]]))
'''     