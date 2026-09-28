/* Ai helped me in 
    - Correcting my int* next to Node* next (we refer to another node, not an integer): line 7
    - I forgot the Node parameter in during writing constructor in push: line 27
*/

struct Node {
    Node *next; 
    int data;

    Node(Node *nxt, int dt) : next(nxt), data(dt) {}
};

class MinStack {
private:
    Node* head { }; 
    stack<int> mini;
    // Or Queue, or vector (but vector will take more implementation)
    // Using normal int is not effective! what if duplication occur? How to restore old values?
public:
    MinStack() {
    }
    
    void push(int value) {
        if(mini.empty() || value <= mini.top())
            mini.push(value);

        head = new Node(head, value);
    }
    
    void pop() {
        if(head->data == mini.top()) 
            mini.pop();

        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    int top() {
        return head->data;
    }
    
    int getMin() {
        return mini.top();
    }
};
