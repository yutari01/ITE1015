#include <string>
#include <functional>

#include "double_linked_node.h"

template <typename T>
class List {
public:
    List() : count(0) {
        head = new Node<T>(0, nullptr, nullptr);
        tail = new Node<T>(0, nullptr, nullptr); //tail has been add...LOL

        head->next = tail;
        tail->prev = head;
    }
    ~List() {
        // TODO: write your code here
        // release remain nodes before delete head node
        Node<T>* removenode = head;
        while(removenode -> next != tail)
        {
            Node<T>* temp = removenode;
            removenode = removenode -> next;
            delete temp;
            
        }
        delete removenode;
        delete tail;
    }

    void push_front(T value) {
        // TODO: write your code here
        // create new node with value
        // and add node to front of list
        Node<T>* new_node = new Node<T>(value, head -> next, head);
        head -> next -> prev = new_node; //역방향 추가
        head -> next = new_node;
        count++;
    }
    void push_back(T value) {
        // TODO: write your code here
        // create new node with value
        // and add node to back of list
        Node<T>* new_node= new Node<T>(value, tail, tail->prev);
        tail -> prev -> next = new_node; //역방향 추가
        tail -> prev = new_node;
        count++;
    }
    T pop_front() {
        // TODO: write your code here
        // remove front node(not head)
        // and return its value
        // if try to remove head node return 0
        if(head -> next == tail){
            return 0;
        }

        T pop_value = head -> next->value;
        Node<T>* pop = head -> next;

        head -> next = pop -> next;
        pop -> next -> prev = head;

        count = count - 1;
        delete pop;
        return pop_value;
    }
    T pop_back() {
        // TODO: write your code here
        // remove back node(not head)
        // and return its value
        // if try to remove head node return 0
        if(head -> next == tail)
        {
            return 0;
        }
        
        T pop_value = tail -> prev -> value;
        Node<T>* pop = tail -> prev;
        tail -> prev = pop -> prev;
        pop -> prev -> next = tail;
        
        count = count - 1;
        delete pop;
        return pop_value;
    }

    size_t size() {
        // TODO: write your code here
        // return current items in list (except head)
        return count;
    }

    void traverse(const std::function<void(const Node<T>&)>& f) {
        for (Node<T>* node = head->next; node != nullptr; node = node->next) {
            f(*node);
        }
    }

    void reverse_traverse(const std::function<void(const Node<T>&)>& f) {
        for (Node<T>* node = tail->prev; node != nullptr; node = node->prev) {
            f(*node);
        }
    }

private:
    Node<T>* head;
    Node<T>* tail;
    size_t count;
    
    // OPTIONAL: you can write helper functions
};
