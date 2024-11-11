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

// Insertion Sort working
void insertionSort(Node*& head) {
    Node* current = head->next;
    Node* sorted = head;
    sorted->next = nullptr;

    while(current!= nullptr) {
        
        Node* next = current->next;

        if(current->data < sorted->data) {
            current->next = sorted;
            sorted = current;
        }
        else {
            Node* temp = sorted;
            while(temp->next != nullptr && temp->next->data <= current->data) {
                temp = temp->next;
            }

            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    head = sorted;
    
}


Node* partition(Node* head, Node* tail) {
    Node* pivot = head;

    Node* j = head;
    Node* curr = head;

    while(curr != tail->next) {
        if(curr->data < pivot->data) {
            swap(curr->data, j->next->data);
            j = j->next;
        }
        curr = curr->next;
    } 

    swap(pivot->data, j->data);
    return j;
}

void quickSortHelper(Node* head, Node* tail) {
    if(head == nullptr || head == tail) {return;}

    Node* j = partition(head, tail);
    quickSortHelper(head, j);
    quickSortHelper(j->next, tail);
}

void quickSort(Node* head) {
    if(head == nullptr) {return;}

    Node* tail = head;
    while(tail->next != nullptr) {
        tail = tail->next;
    }

    quickSortHelper(head, tail);

}

Node* merge(Node* first, Node* second) {
    if(first == nullptr) {
        return second;
    }
    else if(second == nullptr) {
        return first;
    }

    if(first->data < second->data) {
        first->next = merge(first->next, second);
        return first;
    }
    else {
        second->next = merge(first, second->next);
        return second;
    }
}

Node* split(Node* head) {


    Node* fast = head;
    Node* slow = head;

    while(fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        if(fast != nullptr) {
            slow = slow->next;
        }
    }

    Node* temp = slow->next;
    slow->next = nullptr;
    return temp;

}

Node* mergeSort(Node*& head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* second = split(head);

    head = mergeSort(head);
    second = mergeSort(second);

    head =  merge(head, second);
    return head;

}

int main() {

    vector<int> v = {32,8,1,54,23,98,3,7,43,71,29,1};
    //vector<int> v = {10,9,8,7,6,5,4,3,2,1};
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

    mergeSort(head);

    tempNode = head;
    while(tempNode != nullptr) {
        cout << tempNode->data << ' ';
        tempNode = tempNode->next;
    }


    return 0;
}
