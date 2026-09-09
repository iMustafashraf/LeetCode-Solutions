/* Wrong way to think
  - Complicate the code: try to make utilities for addition complex operations
  - Didn't recognize that head is the first node
  - Adding carry before adding numbers themselves
  - Forgot to delete the other node component in the last section
*/

void add_two(LinkedList &another){
		int carry = 0;

		Node* it1 = head;
		Node* it2 = another.head;

		while (it1 != nullptr || it2 != nullptr || carry > 0){
			int val1 = (it1 ? it1->data : 0);
			int val2 = (it2 ? it2->data : 0);

			int sum = val1 + val2 + carry;
	        carry = sum / 10;
	        int digit = sum % 10;

			if(it1){
				it1->data = digit;
				if (it1->next == nullptr) tail = it1;
				it1 = it1->next;
			}else{ // another approach: insert_end(digit) + after while(..) => insert_end(carry);
				Node* newnode = new Node(digit);
				if (head == nullptr)
					head = tail = newnode;
				else{
					tail->next = newnode;
					tail = newnode;
				}
				add_node(newnode);
			}
			if (it2) it2 = it2->next;
		}

			another.head = another.tail = nullptr;
			another.length = 0;
	}
