# Insertion in Doubly Linked lists
This c written code demonstrates how one can insert a node at various positions of a predefined doubly linked list in a very first principle approach, a common 
characteristic with the c programming language.

## Insertion at the beginning
In the implementation of a doubly linked list the practise of keeping the head pointer does the heavylifting for us in this case. To achieve insertion at the 
beginning you only update the new node to be the head and update the next pointer of the newnode to point to the previous head. The previous pointer of the newnode
will definitely point zero.
This intuitive approach boils down to a complexity of of 0(1).

## Insertion at the end
With the inspiration of the head pointer it makes a  lot of sense to maintain the tail pointer. The next pointer of the tail pointer is pointed to the newnode,
the previous pointer of the newnode now strores the tail pointer, finally the new node is updated to be our tail.
Similar to insertion at the begginning this approach also has a complexity of 0(1).

## Insertion at  specified position.
The temporary pointer comes in handy in this operation, firstly we traverse the linked list up to a node away to the node in the specified position. The temporary 
pointer is updated to pointer to this node. 
Then the following operations take place in the given order;
  * update the next pointer of newnode to point to the next pointer of the temporary node.
  * upadte the previous pointer of the newnode to point to the temporarily stored node.
  * update the next pointer of the temporary node to point to the newnode.
  * Access the next node after newnode by use of the newnode next pointer, update the prev pointer of the next node to point at the new node.   
  
This operation has a time complexity of 0(n) due to a while loop used in node traversal.

## insertion after a specified  position of the doubly linked list
This operation is pretty much identical to the insertion at a specified position only that this time around the temporary pointer points the node which is 
in the exact position as the one where the user wants to insert the node. 
This operation has a time complexity of 0(n) due to a while loop used in node traversal.
