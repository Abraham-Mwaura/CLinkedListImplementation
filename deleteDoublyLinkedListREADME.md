# Delete operation in a doubly linked list

## Delete from the first position.
First, the pointer variable temp is initialized with the head pointer, afterwards the head pointer variable is overwrritten with pointer to the second node.
Most importantly, the previous pointer variable in the second node is updated with a null value since the previous node will be deprecated. For purposes of 
garbage collection the memory space temp is freed and the now not only the links to the first not are lost but also its memory space is vacated.
This operation has time complexity of 0(1).

## Delete from the last position
The approach is quite similar to deleting from the first position only that this time around it is carried out in reverse. 
The pointer variable temp is initialized with the tail pointer, afterwards the the tail pointer is overwritten with the pointer to the second last node.
Then the next pointer of the new tail node is updated with a null value. Finally the temp pointer variable is freed for garbage collection.
This operation has time complexity of 0(1).

## Delete from a specified position
The temp pointer variable is initialized with the node to be deleted, this is achieved by traversing the doubly linked list by use of a for loop up to the specified 
delete position. The next pointer of the node to left of temp node is overwritten with the pointer to the node right of the temp node. Similarly the previous pointer variable to the
right of temp pointer is updated with the pointer to the node left of the temp node.
Ultimately the temp node memory space is freed by use of the free function in c.
