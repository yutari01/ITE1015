#include <string>
#include <functional>

#include "node.h"

template <typename T>
class List {
public:
    List() : count(0) {
        head = new Node<T>(0, nullptr);
    }

    ~List() {
        Node<T>* removenode = head;
        Node<T>* temp = head -> next;
        while(temp!=nullptr)
        {
            Node<T>* removenode = temp;
            temp = temp -> next;
            delete removenode;
        }

        delete head;
    }

    void push_front(T value) { //리스트 제일 앞에 원소 추가
        // TODO: write your code here
        // create new node with value
        // and add node to front of list
        Node<T>* new_node = new Node<T>(value); //새로운 노드
        Node<T>* temp = head -> next; //임시로 temp에 head의 다음주소를 저장

        head -> next = new_node; //head의 다음주소를 newnode로 설정
        new_node -> next = temp; //newnode의 다음 주소를 temp에서 가져옴
        count++; //+1
    }

    void push_back(T value) { //리스트 제일 뒤에 원소 추가
        // TODO: write your code here
        // create new node with value
        // and add node to back of list
        Node<T>* newnode = new Node<T>(value); //새로운 노드
        newnode -> next = nullptr; //newnode의 다음주소를 Null포인터로 저장

        Node<T>* temp = head; //임시로 temp에 head로 설정
        while(temp -> next != nullptr) { //마지막 노드를 찾자
            temp = temp -> next;
        }

        temp -> next = newnode; //temp에 저장되어있는 마지막 노드의 다음주소를 newnode로 설정
        count++;
    }
    T pop_front() { //리스트 제일 앞에 원소 삭제
        // TODO: write your code here
        // remove front node(not head)
        // and return its value
        // if try to remove head node return 0
        if (head->next == nullptr) { //head의 다음 주소가 없으면 return 0
            return 0;
        }

        T pop_value = head -> next -> value;
        Node<T>* pop = head -> next;
        Node<T>* temp = pop -> next;
        head -> next = temp;
        
        count = count - 1;

        delete pop;
        return pop_value;

    }
    T pop_back() { //리스트 제일 뒤에 원소 삭제
        // TODO: write your code here
        // remove back node(not head)
        // and return its value
        // if try to remove head node return 0
        if (head -> next == nullptr) { //head의 다음 주소가 없으면 return 0
            return 0;
        }

        Node<T>* temp = head -> next; //temp에 head의 다음 주소 저장
        while(temp -> next -> next != nullptr) //temp의 next값 뒤를 null로 설정하기 위해서 next -> next
        {
            temp = temp -> next;
        }

        T pop_value = temp -> next -> value; //삭제하기 전에 값을 저장
        
        delete temp -> next;
        temp -> next = nullptr; //temp의 다음 nullptr로 설정

        count = count - 1; //-1
        return pop_value; //값 리턴
    }

    size_t size() {
        // TODO: write your code here
        // return current items in list (except head)
        return count;
    }

    void traverse(const std::function<void(const Node<T>&)>& f) {
        for (Node<T>* node = head -> next; node != nullptr; node = node -> next) {
            f(*node);
        }
    }

private:
    Node<T>* head;
    size_t count;
    
    // OPTIONAL: you can write helper functions
};
