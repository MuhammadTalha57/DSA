# include <iostream>
# include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d, Node* n = nullptr): data{d}, next{n} {}
};

// Bubble Sort working
void bubbleSort(Node* head) {
    int n = 0, x;

    Node* temp = head;
    while(temp != nullptr) {
        n++;
        temp = temp->next;
    } 

    for(int i = 0; i < n-1; i++) {
        temp = head;
        for(int j = 0; j < n-1-i; j++) {
            if(temp->next->data < temp->data) {
                x = temp->data;
                temp->data = temp->next->data;
                temp->next->data = x;

            }
            temp = temp->next;
        }
    }


}

// Selection Sort working
void selectionSort(Node* head) {
    int n = 0, x;

    Node* temp = head;
    while(temp != nullptr) {
        n++;
        temp = temp->next;
    } 

    Node* iNode = head;
    Node* min;
    Node* jNode = nullptr;
    for(int i = 0; i < n-1; i++) {
        min = iNode;

        jNode = iNode->next;
        for(int j = i+1; j < n; j++) {
            if(jNode->data < min->data) {
                min = jNode;
            }

            jNode = jNode->next;
        }

        x = iNode->data;
        iNode->data = min->data;
        min->data = x;

        iNode = iNode->next;
    }

}

// Insertion sort working with MODIFICATION
void insertionSort(Node* head) {
    int n = 0, x;

    Node* iNode = head->next;
    Node* jNode = new Node(head->data);
    Node* temp = nullptr;

    Node* j1Node = nullptr;
    if(head->next != nullptr) {
        j1Node =new Node(head->next->data);
        j1Node->next = new Node(head->data);
    }

    Node* tempJNode = nullptr;
    Node* tempJ1Node = nullptr;


    while(true) {

        temp = iNode;

        tempJNode = j1Node->next;
        tempJ1Node = j1Node;
        
        while(tempJNode != nullptr && tempJNode->data < temp->data) {
            tempJ1Node->data = tempJNode->data;
            tempJ1Node = tempJ1Node->next;
            tempJNode = tempJNode->next;
        }

        tempJ1Node->data = temp->data;


        if(iNode->next == nullptr) {break;}



        iNode = iNode->next;

        temp = j1Node;
        j1Node = new Node(iNode->data);
        j1Node->next = temp;

        
    }

    temp = head;
    tempJ1Node = j1Node;

    while(temp != nullptr) {
        temp->data = j1Node->data;
        temp = temp->next;
        j1Node = j1Node->next;
    }
}

int main() {

    vector<int> v = {5, 1,2,7,6,21,89,1,3,43,12,32,4,8};
    Node* head = nullptr;
    Node* tempNode = nullptr;
    Node* newNode = nullptr;
    for(int i: v) {
        newNode = new Node(i);
        if(head == nullptr) {
            head = newNode;
            tempNode = head;
        }
        else {
            tempNode->next = newNode;
            tempNode = tempNode->next;
        }
    }

    insertionSort(head);

    tempNode = head;
    while(tempNode != nullptr) {
        cout << tempNode->data << ' ';
        tempNode = tempNode->next;
    }


    return 0;
}
