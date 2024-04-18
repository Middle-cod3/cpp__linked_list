#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <limits>
#include <vector>
using namespace std;
//  Self define datatype,how to define it....
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node *child;
    Node *random;

    // Default constructor
    Node() : data(0), prev(nullptr), next(nullptr), child(nullptr), random(nullptr) {}

    // Constructor with data parameter
    Node(int x) : data(x), prev(nullptr), next(nullptr), child(nullptr), random(nullptr) {}

    // Constructor with data and next node parameters
    Node(int x, Node *nextNode) : data(x), prev(nullptr), next(nextNode), child(nullptr), random(nullptr) {}

    // Constructor with data, next, previous, and child node parameters
    Node(int x, Node *nextNode, Node *prevNode) : data(x), next(nextNode), prev(prevNode), random(nullptr) {}
    Node(int x, Node *nextNode, Node *prevNode, Node *childNode) : data(x), next(nextNode), prev(prevNode), child(childNode), random(nullptr) {}
};

template <typename T>
class ListNode
{
public:
    T data;
    ListNode<T> *next;
    ListNode()
    {
        this->data = 0;
        this->next = NULL;
    }
    ListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
    ListNode(T data, T *next)
    {
        this->data = data;
        this->next = next;
    }
    // Node(T value, Node *nextNode = nullptr) : data(value), next(nextNode) {}
};
auto compare = [](const Node *a, const Node *b)
{
    return a->data > b->data;
};
/* ===========================THEORY===========================>>
1. Where to use Linked List?
-> In stack/queue,browsers,gallery.....
2. How to define Linked List?
->  Node x=Node(2,nullptr);
Node * y=&x;
or,
Node *y=new Node(2,nullptr);
3. Memory space used?
-> For 32 bit=> int 4 byte and * 4 byte =>total 8 byte
For 6e bit=> int 4 byte and * 8 byte =>total 12 byte
4.



======================================================>>*/

// Short function start-->>
void printArray(int arr[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << arr[i] << " ";
    }
}
void printVector(vector<int> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
}
void printVectorString(vector<string> &arr)
{
    for (auto it : arr)
    {
        cout << it << endl;
    }
}
void printVectorVector(vector<vector<int>> x)
{
    for (const auto &row : x)
    {
        cout << "[";
        for (const auto &element : row)
        {
            cout << element << " ";
        }
        cout << "]";
        cout << std::endl;
    }
}
void printVectorVectorString(vector<vector<string>> x)
{
    for (const auto &row : x)
    {
        cout << "[";
        for (const auto &element : row)
        {
            cout << element << " ";
        }
        cout << "]";
        cout << std::endl;
    }
}
void printString(string s, int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << s[i] << " ";
    }
}
void printStack(stack<string> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
void printLinkedList(Node *head, int type)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data;
        if (current->next != nullptr)
        {
            type == 1 ? cout << " -> " : cout << " <-> ";
        }
        current = current->next;
    }
    cout << " -> NULL" << endl;
}

// Short function end-->>
/***************1D Linked List******************/
/*
1.Introduction To Linked List(Make linked list)
ANS : .You are given an array 'Arr' of size 'N' consisting of positive integers.
Make a linked list from the array and return the head of the linked list.
The head of the linked list is the first element of the array, and the tail of the linked list is the last element.
Input :|| Output :
*/
// Bruteforce ----------->
// TC : O(n), where n is the number of elements in the input vector arr.
// SC :O(n), where n is the number of elements in the input vector arr :
Node *constructLLBruteforce(vector<int> &arr)
{
    Node *head = nullptr;
    Node *tail = nullptr;

    for (int i = 0; i < arr.size(); ++i)
    {
        Node *newNode = new Node(arr[i]); // Creating a new node
        if (head == nullptr)
        {
            head = newNode; // This init for rem who is head and also return value
            tail = newNode; // This for construct chain linked lisk
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}
// Better ----------->
// TC :
// SC :
// Optimal ----------->
// TC : O(n), where n is the number of elements in the input vector arr.
// SC :O(n), where n is the number of elements in the input vector arr
Node *constructLLOptimal(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]); // Creating a new node
        mover->next = temp;
        mover = temp;
    }

    return head;
}

/*
2. Insert Node at beginning of Linked List
ANS : .For a given Singly LinkedList, insert a node at the beginning of the linked list.
Input : List = 10->20->30->40->null, Node = 0|| Output : 0->10->20->30->40->null
*/
// Bruteforce ----------->
// TC :
// SC :
ListNode<int> *insertAtFirst(ListNode<int> *list, int newValue)
{
    ListNode<int> *newNode = new ListNode(newValue);
    newNode->next = list;
    list = newNode;
    return list;
}
// Better ----------->
// TC :
// SC :
// Optimal ----------->
// TC :
// SC :
Node *insertPosition(Node *head, int el, int k)
{
    if (head == NULL)
    {
        if (k == 1)
        {
            return new Node(el);
        }
        else
        {
            return head;
        }
    }
    if (k == 1)
    {
        Node *t = new Node(el);
        t->next = head;
        head = t;
    }
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == (k - 1))
        {
            Node *x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

/*
3. Delete Last Node of Linked List
ANS : .Given a linked list, delete the tail of the linked list and print the updated linked list.
Input :0->1->2|| Output :  0->1
*/
// Bruteforce ----------->
// TC :
// SC :
Node *deleteFirst(Node *list)
{
    if (list == NULL)
        return list;
    Node *temp = list;
    list = temp->next;
    free(temp);
    return list;
}
// Better ----------->
// TC :
// SC :
Node *deleteLast(Node *list)
{ // 2 edge cases if list is null or head's next elem is null
    if (list == nullptr || list->next == nullptr)
        return nullptr;
    Node *temp = list;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return list;
}
// Optimal ----------->
// TC :O(k)
// SC :
Node *deleteK(Node *head, int k)
{
    if (head == NULL)
        return head;
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}
Node *deleteEl(Node *head, int el)
{
    if (head == NULL)
        return head;
    if (head->data == el)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {

        if (temp->data == el)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

/*
4.Count The nodes of linked list
ANS : .Given the head of a singly linked list of int,fnd and return its length.
Input : 1->2->3->NULL|| Output : 3
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ----------->
// TC :
// SC :
int length(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
/*
5. Search the elem in linked list
ANS : You're given a singly linked list of int with a head pointer.Every node of the linked list has a value on it
Now you have been given an int K . your task is to check wheather a node with a value equal to K.Return 1 if exist else 0.
Input :|| Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ----------->
// TC :
// SC :
int searchInLinkedList(ListNode<int> *head, int k)

{
    ListNode<int> *temp = head;

    while (temp != NULL)
    {
        if (temp->data == k)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
/***************Doubly Linked List******************/

/*
6. Introduction To Doubly Linked List (Make double linked list)
ANS : You're given an array of size N consisting of positive int. You're task is to make a dounle linked list from the array and return the head of the linked list.
Input :N=4 arr=[4,2,5,1|| Output : 4<->2<->5<->1
*/
// Bruteforce ----------->
// TC :
// SC :
Node *constructDLL(vector<int> &arr)
{
    Node *head = nullptr;
    Node *tail = nullptr;
    for (int i = 0; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    return head;
}
// Better ----------->
// TC :
// SC :
// Optimal ----------->
// TC :
// SC :
Node *constructDLLOptimal(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

/*
7. Insert at end of Doubly Linked List
ANS :  A doubly-linked list is a data structure that consists of sequentially linked nodes. and the nodes have reference to both the previous and the next nodes in the sequence of nodes.
Given a doubly-linked list and a value 'k, insert a node having value "k' at the end ofthe doubly linked list.
Input :|| Output :
*/
// Bruteforce ----------->
// TC :
// SC :
Node *insertBeforeHeadDLL(Node *head, int val)
{
    Node *newHead = new Node(val, head, nullptr);
    head->prev = newHead;
    return newHead;
}
// Better ----------->
// TC :
// SC :
Node *insertBeforeTailDLL(Node *head, int val)
{
    if (head->next == NULL)
        return insertBeforeHeadDLL(head, val);
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *pre = tail->prev;
    Node *newNode = new Node(val, tail, pre);
    pre->next = newNode;
    tail->prev = newNode;
    return head;
}
Node *insertBeforeKDLL(Node *head, int k, int val)
{
    if (k == 1)
        return insertBeforeHeadDLL(head, val);
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
            break;
        temp = temp->next;
    }
    Node *pre = temp->prev;
    Node *newNode = new Node(val, temp, pre);
    pre->next = newNode;
    temp->prev = newNode;
    return head;
}
// Optimal ----------->
// TC :
// SC :
Node *insertAtTailDLL(Node *head, int k)
{
    Node *newNode = new Node(k);
    if (head == nullptr)
    {
        return newNode;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    temp = newNode;
    return head;
}

/*
8. Delete Last Node of a Doubly Linked List
ANS : Given a doubly-linked list,delete the node at the end of the doubly linked list.
Input :1 <-> 2 <-> 3 <-> 4 <-> 5 -> NULL|| Output : 1 <-> 2 <-> 3 <-> 4 -> NULL
*/
// Bruteforce ----------->
// TC :
// SC :
Node *deleteDLLFirst(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *pre = head;
    head = head->next;

    head->prev = nullptr;
    pre->next = nullptr;
    delete pre;
    return head;
}
// Better ----------->
// TC :
// SC :
Node *deleteLastNode(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        delete head;
        return nullptr; // Return nullptr to indicate an empty head
    }
    // Traverse the head to find the second-to-last node
    Node *curr = head;
    while (curr->next->next != nullptr)
    {
        curr = curr->next;
    }

    // Delete the last node and update the second-to-last node's next pointer
    delete curr->next;
    curr->next = nullptr;

    return head;
}

// Optimal ----------->
// TC :
// SC :

Node *deleteKthNode(Node *head, int k)
{
    if (head == NULL)
        return NULL;
    int cnt = 0;
    Node *kNode = head;
    while (kNode != NULL)
    {
        cnt++;
        if (cnt == k)
            break;
        kNode = kNode->next;
    }

    Node *pre = kNode->prev;
    Node *front = kNode->next;
    if (pre == NULL && front == NULL)
        return NULL;
    else if (pre == NULL)
        return deleteDLLFirst(head);
    else if (front == NULL)
        return deleteLastNode(head);
    pre->next = front;
    front->prev = pre;

    kNode->next = nullptr;
    kNode->prev = nullptr;
    delete kNode;
    return head;
}

/*
9. You're given a doubly-linked list . You're task is to reverse it and retun the head of the modified list.
ANS : .
Input :1 <-> 2 <-> 3 <-> 4 <-> 5 -> NULL|| Output : 5<->4<->3<->2<->1->NULL
*/
// Bruteforce ----------->
// TC :O(2n)
// SC :O(n)
// Trevarse the linked list and push data into stack(last in fitst out)
// Again trevarse the temp=head then temp->data=st.top();After that remove top. st.pop()
// Better ----------->
// TC :
// SC :
// Swap next and prev pointer
// Optimal ----------->
// TC :
// SC :
Node *reverseDLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *pre = NULL;
    Node *curr = head;

    /* swap next and prev for all nodes of
    doubly linked list */
    while (curr != NULL)
    {
        pre = curr->prev;
        curr->prev = curr->next;
        curr->next = pre;
        curr = curr->prev;
    }
    return pre->prev;
    ;
}
/***************Medium Prob Linked List******************/

/*
10. Find middle element in a Linked List
ANS : Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.
Input : head = [1,2,3,4,5] or head = [1,2,3,4,5,6]|| Output : [3,4,5] or [4,5,6]
*/
// Bruteforce ----------->
// TC : O(n)+O(n/2)
// SC :O(1)
Node *middleNodeBruteforce(Node *head)
{
    int length = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        length++;
        temp = temp->next;
    }
    temp = head;
    int half = length / 2;
    while (half--)
    {
        temp = temp->next;
    }
    return temp;
}
// Better ----------->
// TC :
// SC :
// Optimal -----Tortoise-Hare-Approach------>
// TC :O(n/2)
// SC :O(1)
Node *middleNodeOptimal(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/*
11. Reverse Linked List
ANS : Given the head of a singly linked list, reverse the list, and return the reversed list.
Input : head = [1,2,3,4,5]|| Output : [5,4,3,2,1]
*/
// Bruteforce -----Using stack(last in first out)------>
// TC :O(2n)
// SC :O(n)
Node *reverseListBruteforce(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    stack<int> st;

    // step 1 insert data into stack
    Node *temp = head;
    while (temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}
// Better ----------->
// TC :O(n)
// SC :O(1)
Node *reverseListBetter(Node *head)
{
    Node *temp = head;
    Node *pre = NULL;
    while (temp)
    {
        Node *front = temp->next;
        temp->next = pre;
        pre = temp;
        temp = front;
    }
    return pre;
}
// Optimal -----Recursive Approach------>
// TC :O(n)
// SC :O(n)
Node *reverseListOptimal(Node *&head)
{

    if (head == NULL || head->next == NULL)
        return head;

    Node *nnode = reverseListOptimal(head->next);
    head->next->next = head;

    head->next = NULL;
    return nnode;
}

/*
12. Detect a Cycle in a Linked List
ANS : Given head, the head of a linked list, determine if the linked list has a cycle in it. There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
Return true if there is a cycle in the linked list. Otherwise, return false.
Input : head=[1,2,3,4,2] or head=[1,2,3,4]|| Output : True or False
*/
// Bruteforce -----using hash table----->
// TC :O(n)
// SC :O(n)
void createCycle(Node *&head, int pos)
{
    Node *ptr = head;
    Node *temp = head;
    int cnt = 0;
    while (temp->next != NULL)
    {
        if (cnt != pos)
        {
            ++cnt;
            ptr = ptr->next;
        }
        temp = temp->next;
    }
    temp->next = ptr;
}
// TC :O(n)
// SC :O(n)
bool detectCycleBruteforce(Node *head)
{
    unordered_set<Node *> hashTable;
    while (head != NULL)
    {
        if (hashTable.find(head) != hashTable.end())
        {
            return true;
        }
        hashTable.insert(head);
        head = head->next;
    }
    return false;
}
// Better ----------->
// TC :O(n)
// SC :O(n)
bool detectCycleBetter(Node *head)
{
    map<Node *, int> mpp;
    Node *temp = head;
    while (temp)
    {
        if (mpp.find(temp) != mpp.end())
        {
            return true;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }
    return false;
}
// Optimal -----slow and fast method------>
// TC :O(n)
// SC :O(1)
bool detectCycleOptimal(Node *head)
{
    if (head == NULL)
        return false;
    Node *fast = head;
    Node *slow = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}
/*
13. Starting point of loop in a Linked List
ANS : Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that the tail’s next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
Input : head = [1,2,3,4,3,6,10]|| Output :  Tail connects to node index 2
*/
// Bruteforce ----------->
// TC :O(n)
// SC :O(n)
Node *detectCycle(Node *head)
{
    unordered_set<Node *> hashTable;
    while (head != NULL)
    {
        if (hashTable.find(head) != hashTable.end())
            return head;
        hashTable.insert(head);
        head = head->next;
    }
    return NULL;
}
Node *firstNodeBruteforce(Node *head)
{
    Node *nodeRec = detectCycle(head);
    return nodeRec;
}
// Better ----------->
// TC :
// SC :

// Optimal ------slow and fast pointer----->
// 👉🏻Initially take two pointers, fast and slow. The fast pointer takes two steps ahead while the slow pointer will take a single step ahead for each iteration.
// 👉🏻We know that if a cycle exists, fast and slow pointers will collide.
// 👉🏻If the cycle does not exist, the fast pointer will move to NULL
// 👉🏻Else, when both slow and fast pointer collides, it detects a cycle exists.
// 👉🏻Take another pointer, say entry. Point to the very first of the linked list.
// 👉🏻Move the slow and the entry pointer ahead by single steps until they collide.
// 👉🏻Once they collide we get the starting node of the linked list.
// TC :O(n)
// SC :O(1)
Node *firstNodeOptimal(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *fast = head;
    Node *slow = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
/*
14. Find length of Loop
ANS : You’re given a linked list. The last node might point to null, or it might point to a node in the list, thus forming a cycle.
Find out whether the linked list has a cycle or not, and the length of the cycle if it does.
If there is no cycle, return 0, otherwise return the length of the cycle.
Input :head=[4,10,3,5,10] at position 2|| Output : length os the cycle is 3
*/
// Bruteforce ------using hashmap----->
// TC :O(n)
// SC :O(n)
int lengthOfLoopBruteforce(Node *head)
{
    if (head == NULL)
        return -1;
    map<Node *, int> mpp;
    Node *temp = head;
    int timer = 1;
    while (temp)
    {
        if (mpp.find(temp) != mpp.end())
        {
            int val = mpp[temp];
            return timer - val;
        }
        mpp[temp] = timer;
        timer++;
        temp = temp->next;
    }
    return 0;
}
// Better ----------->
// TC :
// SC :
// Optimal ----------->
// TC :O(n)
// SC :O(1)
int lengthF(Node *slow)
{
    Node *temp = slow;
    int cnt = 1;
    while (temp->next != slow)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int lengthOfLoopOptimal(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    int loopLength = 0;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            // Loop detected, now calculate its length
            return lengthF(slow);
        }
    }

    return 0; // No loop found
}

/*
15. Check if given Linked List is Plaindrome
ANS : Given the head of a singly linked list, return true if it is a palindrome.
Input :  head = [1,2,3,3,2,1]   || Output : True
*/
// Bruteforce -----using extra DS use stack cz its first in last out------>
// Let’s take a string, say “level” which is a palindrome. Let’s observe a thing.
// So we can see that each index letter is the same as (length-each index -1) letter.
// The same logic required to check an array is a palindrome.
// Following are the steps to this approach.
// Iterate through the given list to store it in an array.
// Iterate through the array.
// For each index in range of n/2 where n is the size of the array
// Check if the number in it is the same as the number in the n-index-1 of the array.
// TC :O(2n)
// SC :O(n)
bool isPalindromeBruteforce(Node *head)
{
    stack<int> st;
    Node *temp = head;
    while (temp != NULL)
    {
        st.push(temp->data); // temp is pointing address and data=value
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (temp->data != st.top())
            return false;
        st.pop();
        temp = temp->next;
    }

    return true;
}
// Better ----------->
// TC :
// SC :
// Optimal ----------->
// Find the middle element of the linked list. Refer to this article to know the steps https://takeuforward.org/data-structure/find-middle-element-in-a-linked-list/
// Reverse a linked list from the next element of the middle element. Refer to this article to know the steps https://takeuforward.org/data-structure/reverse-a-linked-list/
// Iterate through the new list until the middle element reaches the end of the list.
// Use a dummy node to check if the same element exists in the linked list from the middle element.
// TC : O(2N)
// SC :O(1)
Node *reverse(Node *ptr)
{
    Node *pre = NULL;
    Node *nex = NULL;
    while (ptr != NULL)
    {
        nex = ptr->next;
        ptr->next = pre;
        pre = ptr;
        ptr = nex;
    }
    return pre;
}
bool isPalindromeOptimal(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *newHead = reverse(slow->next);
    Node *first = head;
    Node *second = newHead;
    while (second != NULL)
    {
        if (first->data != second->data)
        {
            reverse(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverse(newHead);
    return true;
}
/*
16. Segregate Even And Odd Nodes In a Linked List
ANS : Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Input :    || Output :
*/
// Bruteforce -----Get a last pointer and move all odd values to the end------>
// The idea is to get a pointer to the last node of list. And then traverse the list starting from the head node and move the odd valued nodes from their current position to end of the list.
// Get a pointer to the last node.
// Move all the odd nodes to the end.
//  Consider all odd nodes before the first even node and move them to end.
//  Change the head pointer to point to the first even node.
//  Consider all odd nodes after the first even node and move them to the end.
// TC :O(2n)
// SC :O(n)
Node *segregateOddEvenBruteforce(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    vector<int> newArr;
    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        newArr.push_back(temp->data);
        temp = temp->next->next; // For odd numbers
    }
    if (temp)
        newArr.push_back(temp->data);
    temp = head->next;
    while (temp != NULL && temp->next != NULL)
    {
        newArr.push_back(temp->data);
        temp = temp->next->next; // For even numbers
    }
    if (temp)
        newArr.push_back(temp->data);
    // Now newArr have odd and even numbers
    int i = 0;
    temp = head;
    while (temp != NULL)
    {
        temp->data = newArr[i];
        i++;
        temp = temp->next;
    }
    return head;
}
// TC :O(n)
// SC :O(1)
Node *segregateEvenOddBruteforce(Node *head)
{
    Node *end = head;
    Node *prev = NULL;
    Node *curr = head;
    /* Get pointer to the last node */
    while (end->next != NULL)
        end = end->next;

    Node *new_end = end;
    /* Consider all odd nodes before the first
    even node and move then after end */
    while (curr->data % 2 != 0 && curr != end)
    {
        new_end->next = curr;
        curr = curr->next;
        new_end->next->next = NULL;
        new_end = new_end->next;
    }

    // 10->8->17->17->15
    /* Do following steps only if
    there is any even node */
    if (curr->data % 2 == 0)
    {
        /* Change the head pointer to
        point to first even node */
        head = curr;

        /* now current points to
        the first even node */
        while (curr != end)
        {
            if ((curr->data) % 2 == 0)
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                /* break the link between
                prev and current */
                prev->next = curr->next;

                /* Make next of curr as NULL */
                curr->next = NULL;

                /* Move curr to end */
                new_end->next = curr;

                /* make curr as new end of list */
                new_end = curr;

                /* Update current pointer to
                next of the moved node */
                curr = prev->next;
            }
        }
    }

    /* We must have prev set before executing
    lines following this statement */
    else
        prev = curr;

    /* If there are more than 1 odd nodes
    and end of original list is odd then
    move this node to end to maintain
    same order of odd numbers in modified list */
    if (new_end != end && (end->data) % 2 != 0)
    {
        prev->next = end->next;
        end->next = NULL;
        new_end->next = end;
    }
    return head;
}
// Better -----Split as odd and even then add even then odd------>
// The idea is to split the linked list into two:  one containing all even nodes and the other containing all odd nodes. And finally, attach the odd node linked list after the even node linked list.
// To split the Linked List, traverse the original Linked List and move all odd nodes to a separate Linked List of all odd nodes. At the end of loop, the original list will have all the even nodes and the odd node list will have all the odd nodes. To keep the ordering of all nodes same, we must insert all the odd nodes at the end of the even node list. And to do that in constant time, we must keep track of last pointer in the even node list.
// TC :O(n)
// SC :O(1)
Node *segregateEvenOddBetter(Node *head)
{
    // Starting node of list having even values.
    Node *evenStart = NULL;
    // Ending node of even values list.
    Node *evenEnd = NULL;
    // Starting node of odd values list.
    Node *oddStart = NULL;
    // Ending node of odd values list.
    Node *oddEnd = NULL;
    // Node to traverse the list.
    Node *currNode = head;

    while (currNode != NULL)
    {
        int val = currNode->data;

        // If current value is even, add it to even values
        // list.
        if (val % 2 == 0)
        {
            if (evenStart == NULL)
            {
                evenStart = currNode;
                evenEnd = evenStart;
            }
            else
            {
                evenEnd->next = currNode;
                evenEnd = evenEnd->next;
            }
        }

        // If current value is odd, add it to odd values
        // list.
        else
        {
            if (oddStart == NULL)
            {
                oddStart = currNode;
                oddEnd = oddStart;
            }
            else
            {
                oddEnd->next = currNode;
                oddEnd = oddEnd->next;
            }
        }

        // Move head pointer one step in forward direction
        currNode = currNode->next;
    }

    // If either odd list or even list is empty, no change
    // is required as all elements are either even or odd.
    if (oddStart == NULL || evenStart == NULL)
        return NULL;

    // Add odd list after even list.
    evenEnd->next = oddStart;
    oddEnd->next = NULL;

    // Modify head pointer to starting of even list.
    head = evenStart;
    return head;
}
// Optimal ------Maintaining an even queue and an odd queue----->
Node *segregateOddEvenOptimal(Node *head)
{
    if (head == NULL && head->next == NULL)
        return head;
    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = head->next;
    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
// TC :O(n)
// SC :O(n)
Node *segregateEvenOddOptimal(Node *head)
{
    queue<Node *> qe, qo, q;
    Node *cur = head;
    while (cur)
    {
        if (cur->data % 2 == 0)
            qe.push(cur);
        else
            qo.push(cur);
        cur = cur->next;
    }
    Node *node = new Node(-100);
    Node *ans = node;

    while (!qe.empty())
    {
        q.push(qe.front());
        qe.pop();
    }

    while (!qo.empty())
    {
        q.push(qo.front());
        qo.pop();
    }
    while (!q.empty())
    {
        node->next = q.front();
        node = q.front();
        q.pop();
    }

    node->next = NULL;
    return ans->next;
}

/*
17. Delete Kth Node From End
ANS : Given the head of a linked list, remove the nth node from the end of the list and return its head.
Input :  head = [1,2,3,4,5], n = 2  || Output : [1,2,3,5]
*/
// Bruteforce ----------->
// TC :O(len)+O(len-k)
// SC :O(1)
Node *removeKthNodeBruteforce(Node *head, int K)
{
    Node *temp = head;
    int cnt = 0;

    // Count the number of nodes in the linked list
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }

    // If K is greater than the number of nodes or invalid, return the original head
    if (K <= 0 || K > cnt)
    {
        return head;
    }

    // Calculate the position of the node to be removed from th e beginning
    int positionToRemove = cnt - K;

    // If the node to be removed is the head, update the head
    if (positionToRemove == 0)
    {
        Node *newHead = head->next;
        delete head;
        return newHead;
    }

    // Traverse the list to the node just before the one to be removed
    temp = head;
    for (int i = 0; i < positionToRemove - 1; ++i)
    {
        temp = temp->next;
    }

    // Remove the Kth node
    Node *nodeToRemove = temp->next;
    temp->next = temp->next->next;
    delete nodeToRemove;

    return head;
}
// Better ----------->
// TC :
// SC :
// Optimal -----Fast ptr move to K-th pos then fast++,slow++ when fast=NULL?remove slow->next;----->
// Approaches-->>
// Initialize Two Pointers: Use two pointers, fast and slow, both initially pointing to a dummy node (start). The fast pointer is advanced by K nodes means move fast pointer single from 1->K nodes like fast=fast->next.
// The calculation is if linked list length is 5 and K=2. If fast pointer advance move 2 step then remain 3 step for complete the liked list length.Now after advance move if you move fast pointer 3 steps then slow pointer also move 3 step that is removeNode’s prev node.
// Move Pointers to Find Kth Node from End: Move both fast and slow pointers simultaneously until fast reaches the end of the linked list. At this point, slow will be pointing to the node preceding the Kth node from the end.
// Remove Kth Node: Update the next pointer of the node pointed to by slow to skip the Kth node.
// Return the Modified List: Return the next pointer of the dummy node (start), which represents the head of the modified list.
// TC :O(n)
// SC :O(1)

Node *removeKthNodeOptimal(Node *head, int K)
{
    Node *start = new Node();
    start->next = head; // This is for if K==length
    Node *fast = start;
    Node *slow = start;
    for (int i = 1; i <= K; ++i)
    {
        fast = fast->next;
    }
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return start->next;
}

/*
18. Delete Middle Node
ANS : You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.
Input :    head = [1,3,4,7,1,2,6] || Output :[1,3,4,1,2,6]
*/
// Bruteforce ------using trevarse upto middle then remove----->
// TC :O(n)+O(n/2)
// SC :O(1)
Node *deleteMiddleBruteforce(Node *head)
{
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return NULL;

    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    int positionToRemove = cnt / 2;
    temp = head;
    for (int i = 0; i < positionToRemove - 1; ++i)
        temp = temp->next;
    // Remove the Kth node
    Node *nodeToRemove = temp->next;
    temp->next = temp->next->next;
    delete nodeToRemove;
    return head;
}
// Better ----------->
// TC :
// SC :
// Optimal ------using fast and slow method---->
// TC :O(n)
// SC :O(1)
Node *deleteMiddleOptimal(Node *head)
{
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return NULL;
    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Remove the middle node
    prev->next = slow->next;
    delete slow;

    return head;
}

/*
19. Sort Linked List
ANS : Given the head of a linked list, return the list after sorting it in ascending order.
Input :  head = [4,2,1,3]  || Output : [1,2,3,4]
*/
// Bruteforce ----------->
// TC :O(N)+O(NlogN)+O(N)
// SC :O(N)
Node *sortListBruteforce(Node *head)
{
    vector<int> arr;
    Node *temp = head;
    while (temp)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());
    int i = 0;
    temp = head;
    while (temp != NULL)
    {
        temp->data = arr[i];
        i += 1;
        temp = temp->next;
    }
    return head;
}
// Better ----------->
// TC :
// SC :
// Optimal -----Merge sort----->
// TC :  MergeSort Function O(n*logn)
// SC :O(1)
Node *mergelist(Node *l1, Node *l2)
{
    Node *ptr = new Node(0);
    Node *curr = ptr;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data <= l2->data)
        {
            curr->next = l1;
            l1 = l1->next;
        }
        else
        {
            curr->next = l2;
            l2 = l2->next;
        }

        curr = curr->next;
    }

    // for unqual length linked list

    if (l1 != NULL)
    {
        curr->next = l1;
        l1 = l1->next;
    }

    if (l2 != NULL)
    {
        curr->next = l2;
        l2 = l2->next;
    }

    return ptr->next;
}
Node *sortListOptimal(Node *head)
{
    // If List Contain a Single or 0 Node
    if (head == NULL || head->next == NULL)
        return head;

    Node *temp = NULL;
    Node *slow = head;
    Node *fast = head;

    // 2 pointer appraoach / turtle-hare Algorithm (Finding the middle element)
    while (fast != NULL && fast->next != NULL)
    {
        temp = slow;
        slow = slow->next;       // slow increment by 1
        fast = fast->next->next; // fast incremented by 2
    }
    temp->next = NULL; // end of first left half

    Node *l1 = sortListOptimal(head); // left half recursive call
    Node *l2 = sortListOptimal(slow); // right half recursive call

    return mergelist(l1, l2); // mergelist Function call
}

/*
20. Sort linked list of 0s 1s 2s
ANS :
Input :    || Output :
*/
// Bruteforce -----count how many,0,1,2 then create a new linked list------>
// TC :O(2n)
// SC :O(1)
Node *sortList012Bruteforce(Node *head)
{
    Node *temp = head;
    int count0 = 0, count1 = 0, count2 = 0;
    while (temp)
    {
        if (temp->data == 0)
            count0++;
        else if (temp->data == 1)
            count1++;
        else
            count2++;
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        if (count0)
        {
            temp->data = 0;
            count0--;
        }
        else if (count1)
        {
            temp->data = 1;
            count1--;
        }
        else
        {
            temp->data = 2;
            count2--;
        }
        temp = temp->next;
    }

    return head;
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(n)
// SC :O(1)
Node *sortList012Optimal(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);

    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twoHead;
    Node *temp = head;
    while (temp)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
    one->next = twoHead->next;
    two->next = NULL;
    Node *newHead = zeroHead->next;
    delete (zeroHead);
    delete (oneHead);
    delete (twoHead);
    return newHead;
}

/*
22. Find intersection of Two Linked Lists
ANS :  Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
** It is the node itself that is the common attribute not the value.
Input :    || Output :
*/
// Bruteforce -----Node comparing------>
//. Keep any one of the list to check its node present in the other list. Here, we are choosing the second list for this task.
//.Iterate through the other list. Here, it is the first one.
//. Check if the both nodes are the same. If yes, we got our first intersection node.
//.If not, continue iteration.
//.If we did not find an intersection node and completed the entire iteration of the second list, then there is no intersection between the provided lists. Hence, return null.
// TC :O(m*n)
// SC :O(1)
Node *findIntersectionBruteforce(Node *firstHead, Node *secondHead)
{
    while (secondHead != NULL)
    {
        Node *temp = firstHead;
        while (temp != NULL)
        {
            // if both nodes are same
            if (temp == secondHead) // Its comparing whole linked list
                return secondHead;
            temp = temp->next;
        }
        secondHead = secondHead->next;
    }
    // intersection is not present between the lists return null
    return NULL;
}
// Better -----Hashing------>
//. Iterate through list 1 and hash its node address. Why? (Hint: depends on the common attribute we are searching)
//. Iterate through list 2 and search the hashed value in the hash table. If found, return node.
// TC :O(n+m)
// SC :O(n)
Node *findIntersectionBetter(Node *firstHead, Node *secondHead)
{
    unordered_set<Node *> st;
    while (firstHead != NULL)
    {
        st.insert(firstHead);
        firstHead = firstHead->next;
    }
    while (secondHead != NULL)
    {
        if (st.find(secondHead) != st.end())
            return secondHead;
        secondHead = secondHead->next;
    }
    return NULL;
}
// Optimal1 -----Difference in length----->
// Find the length of both lists.
// Find the positive difference between these lengths.
// Move the dummy pointer of the larger list by the difference achieved. This makes our search length reduced to a smaller list length.
// Move both pointers, each pointing two lists, ahead simultaneously if both do not collide.
// TC : O(2max(length of list1,length of list2))+O(abs(length of list1-length of list2))+O(min(length of list1,length of list2))
// SC :O(1)
int getDifference(Node *head1, Node *head2)
{
    int len1 = 0, len2 = 0;
    while (head1 != NULL || head2 != NULL)
    {
        if (head1 != NULL)
        {
            ++len1;
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            ++len2;
            head2 = head2->next;
        }
    }
    return len1 - len2; // if difference is neg-> length of list2 > length of list1 else vice-versa
}
Node *findIntersectionOptimal1(Node *firstHead, Node *secondHead)
{
    int diff = getDifference(firstHead, secondHead);
    if (diff < 0)
        while (diff++ != 0)
            secondHead = secondHead->next;
    else
        while (diff-- != 0)
            firstHead = firstHead->next;
    while (firstHead != NULL)
    {
        if (firstHead == secondHead)
            return firstHead;
        secondHead = secondHead->next;
        firstHead = firstHead->next;
    }
    return firstHead;
}
// Optimal ---------->
// TC :O(n+m)
// SC :O(1)
Node *findIntersectionOptimal(Node *firstHead, Node *secondHead)
{
    if (firstHead == NULL || secondHead == NULL)
        return NULL;
    Node *temp1 = firstHead;
    Node *temp2 = secondHead;
    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
        if (temp1 == temp2)
            return temp1;
        if (temp1 == NULL)
            temp1 = secondHead;
        if (temp2 == NULL)
            temp2 = firstHead;
    }
    return temp1;
}
/*
23. Add 1 to a number represented by LL
ANS : you're given a linked list like 1->2->3.Add 1 to it like 123+1=124 then modify the linked list and return new linked list
Input :    || Output :
*/
// Bruteforce ----------->
// Reverse the linked list cz if at last digit is 9 then you have to increment prev one.
// So reverse it and traverse the linked list and add carry=1 add this one first if temp->data<10 then carry=0 else carry=1
// and temp->data=0 cz its 10
// Then temp=temp->next;
// After while loop if carry left over 1 then create a new node and reverese the main head
// Then add head after new node cz new node is 1 else return reverse head
// TC :O(3N)
// SC :
Node *add1ToLinkedListBruteforce(Node *head)
{
    head = reverse(head);
    Node *temp = head;
    int carry = 1;
    while (temp != NULL)
    {
        temp->data = temp->data + carry; // First add 1
        if (temp->data < 10)             // If it <10
        {
            carry = 0;
            break;
        }
        else // Carry get 1 for next node
        {
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }
    if (carry == 1)
    {
        Node *newNode = new Node(1);
        head = reverse(head);
        newNode->next = head;
        return newNode;
    }
    head = reverse(head);
    return head;
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// Using backtrcking
// TC :O(n)
// SC :O(n)
int addHelper(Node *temp)
{
    if (temp == NULL)
        return 1;
    int carry = addHelper(temp->next);
    temp->data += carry;
    if (temp->data < 10)
        return 0;
    temp->data = 0;
    return 1;
}
Node *add1ToLinkedListOptimal(Node *head)
{
    int carry = addHelper(head);
    if (carry == 1)
    {
        Node *newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

/*
24. Add 2 numbers in LL
ANS : Given the heads of two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
Input :   num1  = 243, num2 = 564 || Output : sum = 807; L = [7,0,8]
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(max(n1,n2))
// SC : O(max(n1,n2)) For storing the result
Node *addTwoNumbersOptimal(Node *num1, Node *num2)
{
    Node *dummyhead = new Node(-1);
    Node *curr = dummyhead;
    Node *temp1 = num1;
    Node *temp2 = num2;
    int carry = 0;
    while (temp1 || temp2)
    {
        int sum = carry;
        if (temp1)
            sum += temp1->data;
        if (temp2)
            sum += temp2->data;
        Node *newNode = new Node(sum % 10); // sum==2 digit then take one
        carry = sum / 10;                   // And add second digit add to carry
        curr->next = newNode;
        curr = curr->next;
        if (temp1)
            temp1 = temp1->next;
        if (temp2)
            temp2 = temp2->next;
    }
    if (carry)
    {
        Node *newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummyhead->next;
}

/*
25.  Delete all occurrences of a given key in a doubly linked list

ANS :A doubling list is a data structure that consist of sequencentially linked nodes,
 and the notes have reference to both the previous and the next nodes in the sequence of nodes.
 you are given a doubly-linked list and a key K .
 Delete all the nodes having data equals to K.
Input :   list=10<->4<->4<->10<->9 k=10 || Output :
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(n)
// SC :O(1)
Node *deleteAllOccurrencesOptimal(Node *head, int k)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == k)
        { // Then remove this node
            if (temp == head)
            {                      // Before delete check that is't a head
                head = head->next; // Init head to head ka next
            }
            // Deleting process
            Node *nextNode = temp->next;
            Node *prevNode = temp->prev;
            if (nextNode)
                nextNode->prev = prevNode;
            if (prevNode)
                prevNode->next = nextNode;
            free(temp);
            temp = nextNode;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}
/*
26. Find pairs with given sum in doubly linked list
ANS : you are given a sorted double linked list of size N.
consisting of distinct positive integers and a number K find out all the pairs in the link list with sum==K

Input : list=1<->2<->3<->4<->9 k=5  || Output :(1,4),(2,3)
*/
// Bruteforce ----------->
// TC :Near about O(n^2)
// SC :
vector<pair<int, int>> findPairsBruteforce(Node *head, int k)
{
    vector<pair<int, int>> ans;
    Node *temp1 = head;
    while (temp1)
    {
        Node *temp2 = temp1->next;
        while (temp2 && temp1->data + temp2->data <= k) // here temp2 checking is correct but to li'll bit of optimization is,if data+data<sum then go forword else break
        {
            if (temp1->data + temp2->data == k)
            {
                ans.push_back({temp1->data, temp2->data});
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return ans;
}
// Better ----------->
// TC :
// SC :
// Optimal -----using 2 pointers if data+data<sum left++ else right-- ----->
// TC :O(2n)
// SC :O(n) if in worst case
Node *findTail(Node *head)
{
    Node *tail = head;
    while (tail->next)
    {
        tail = tail->next;
    }
    return tail;
}
vector<pair<int, int>> findPairsOptimal(Node *head, int k)
{
    vector<pair<int, int>> ans;
    if (head == NULL)
        return ans;
    Node *left = head;
    Node *right = findTail(head);
    while (left->data < right->data)
    {
        if (left->data + right->data == k)
        {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (left->data + right->data < k)
        {
            left = left->next;
        }
        else
            right = right->prev;
    }
    return ans;
}

/*
28. Remove duplicates from a sorted Doubly Linked List

ANS : You're given a sorted doubly linked listof size n.
Remove all the duplicate nodespresent in tht linked list.
Input :  1<->2<->2<->2<->3  || Output :1<->2<->3
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(n)
// SC :O(1)
Node *removeDuplicatesOptimal(Node *head)
{
    Node *temp = head;
    while (temp && temp->next)
    {
        Node *nextNode = temp->next;
        while (nextNode && nextNode->data == temp->data)
        {
            Node *dupli = nextNode;
            nextNode = nextNode->next;
            free(dupli);
        }
        temp->next = nextNode;
        if (nextNode)
            nextNode->prev = temp;
        temp = temp->next;
    }
    return head;
}

/*
29. Reverse Linked List in groups of Size K
ANS : Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list. k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
Input :  head = [1,2,3,4,5,6,7,8] k=3  || Output : head = [3,2,1,6,5,4,7,8]
*/
// Bruteforce ----------->
// TC :
// SC :
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(2n)
// SC : O(1)
Node *findKthNode(Node *head, int k)
{
    k -= 1;
    while (head && k > 0)
    {
        k--;
        head = head->next;
    }
    return head;
}
Node *kReverseOptimal(Node *head, int k)
{
    Node *temp = head;
    Node *nextNode = NULL;
    Node *prevNode = NULL;
    while (temp)
    {
        Node *kth_Node = findKthNode(temp, k); // This will find kth node or say take 3 nodes and return as a last one
        if (kth_Node == NULL)
        {                              // Checking that kth_Node satisfied the k==no of nodes
            if (prevNode)              // If prevNode exist then...
                prevNode->next = temp; // If nodes are not satisfied to make group then it add it to last as same
            break;
        }
        nextNode = kth_Node->next; // We break the link after kth node and save it to a new node
        kth_Node->next = NULL;     // Here we break and make next as a NULL
        reverse(temp);
        if (temp == head)
            head = kth_Node; // reverese fn change the nodes not the head so here we define which is my first group
        else
            prevNode->next = kth_Node; // If you are not the main head then your next is next groups first and link it
        prevNode = temp;               // temp is head or say groups last one so it's next is next groups first and link it
        temp = nextNode;               // Now we go for next k groups
    }
    return head;
}

/*
30. Rotate a Linked List
ANS : Given the head of a linked list, rotate the list to the right by k places.
Input :  head = [1,2,3,4,5] k = 2  || Output : head = [4,5,1,2,3]
*/
// Bruteforce ----------->
// TC :O(Number of nodes present in the list*k)
// SC :
Node *rotateKTimesBruteforce(Node *head, int k)
{
    // Bruteforce
    if (head == NULL || head->next == NULL)
        return head;
    for (int i = 0; i < k; i++)
    {
        Node *temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        Node *end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC : O(2n)
// SC :O(1)
Node *rotateKTimesOptimal(Node *head, int k)
{
    if (head == NULL || k == 0)
        return head;
    int len = 1;
    Node *tail = head;
    while (tail->next)
    {
        len++; // Counting length of the linked list
        tail = tail->next;
    }
    if (k % len == 0)
        return head; // Means len==k if we rotate then it remain same
    k = k % len;     // For larger value like: if len is 5 and k=13 then you only have to rotate 3 times
    tail->next = head;
    Node *newLastNode = findKthNode(head, len - k);
    head = newLastNode->next;
    newLastNode->next = NULL;
    return head;
}

/*
31.  Flatten A Linked List
ANS : Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.
Note: The flattened list will be printed using the bottom pointer instead of the next pointer.
Input :  linked list = [5,7,8,30,10,20,19,22,50,28,35,40,45]  || Output :Flattened list = [5,7,8,10,19,20,22,28,30,35,40,45,50]
*/
// Bruteforce ----------->
// TC : Assume LL size is N and child is M then first while loop O(NxM), for sort O(XlogX) where X=N*M, and convert take all elem so its O(NxM) overall= O(NxM)*2+O(XlogX)
// SC :O(NxM)*2 , 2 cz first time for caring a arr then in convert creating  a new verticle LL
Node *convertArrToVrtLL(vector<int> &arr)
{
    if (arr.size() == 0)
        return NULL;
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->child = newNode;
        temp = temp->child;
    }
    return head;
}
Node *flattenLinkedListBruteforce(Node *head)
{
    vector<int> arr;
    Node *temp = head;
    while (temp != NULL)
    {
        Node *t2 = temp;
        while (t2 != NULL)
        {
            arr.push_back(t2->data);
            t2 = t2->child;
        }
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());
    Node *ans = convertArrToVrtLL(arr);
    return ans;
}

// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :  O(n)xO(2m)
// SC : O(n) its in memory which recursion uses or you can say O(1)
//
Node *merge(Node *first, Node *second)
{

    // If the first is NULL return second
    if (first == NULL)
    {
        second->next = nullptr;
        return second;
    }

    // If the second is NULL return first
    if (second == NULL)
    {
        first->next = nullptr;
        return first;
    }

    Node *merged = NULL;

    if (first->data < second->data)
    {
        merged = first;
        merged->child = merge(first->child, second);
    }
    else
    {
        merged = second;
        merged->child = merge(first, second->child);
    }
    merged->next = nullptr;
    return merged;
}
Node *meregeTwoList(Node *a, Node *b)
{
    Node *temp = new Node(0);
    Node *res = temp;
    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            temp->child = a;
            temp = temp->child;
            a = a->child;
        }
        else
        {
            temp->child = b;
            temp = temp->child;
            b = b->child;
        }
    }
    if (a)
        temp->child = a;
    else
        temp->child = b;
    return res->child;
}
Node *flattenLinkedListOptimal(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    // Recur for list on the right
    head->next = flattenLinkedListOptimal(head->next);
    // Now merege
    head = meregeTwoList(head, head->next);
    // head = merge(head, head->next);//Most optimal

    // Return the head
    return head;
}

/*
32. Clone Linked List with Random and Next Pointer
ANS : Given a Linked list that has two pointers in each node and one of which points to the first node and the other points to any random node. Write a program to clone the LinkedList.
Input :  head = [[1,3],[2,0],[3,null],[4,1]]  || Output :head = [[1,3],[2,0],[3,null],[4,1]]
*/
// Bruteforce ----------->
// TC : O(N)+O(N)
// Reason: Two iterations over the entire list. Once for inserting in the map and other for linking nodes with next and random pointer.
// SC :O(N) +O(N) for return the ans

Node *copyRandomListBruteforce(Node *head)
{
    // For each node, create a deep copy of each node and hash it with it.
    // Store it in the hashmap.
    // Now, again iterate through the given list.
    // For each node, link the deep node present as the hash value of the original node as per original node.
    // The head of the deep copy list will be the head of hashed value of original node.
    unordered_map<Node *, Node *> hashMap;
    Node *temp = head;
    while (temp != NULL)
    { // Hashing complete
        Node *newNode = new Node(temp->data);
        hashMap[temp] = newNode;
        temp = temp->next;
    }
    // Now Iterate
    Node *t = head;
    while (t != NULL)
    {
        Node *node = hashMap[t];
        node->next = (t->next != NULL) ? hashMap[t->next] : NULL; // If originals next!=NULL then points copy's next as same add
        node->random = (t->random != NULL) ? hashMap[t->random] : NULL;
        t = t->next;
    }
    return hashMap[head];
}
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :O(N)+O(N)+O(N)
// Reason: Each step takes O(N) of time complexity.
// SC :O(1)
Node *copyRandomListOptimal(Node *head)
{
    Node *temp = head;
    // Step-1
    // point originals next is originals copy
    while (temp != NULL)
    {
        Node *newNode = new Node(temp->data);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }
    // Step-2
    // For random achieved=>itr->next->random = itr->random->next
    Node *itr = head;
    while (itr != NULL)
    {
        if (itr->random != NULL)
            itr->next->random = itr->random->next;
        itr = itr->next->next;
    }
    // Step-3
    // Filter the deep copy and link a new dummy so that you can return dummy's next as a head
    Node *dummy = new Node(0);
    itr = head;
    temp = dummy;
    Node *fast;
    while (itr != NULL)
    {
        fast = itr->next->next;
        temp->next = itr->next;
        itr->next = fast;
        temp = temp->next;
        itr = fast;
    }
    return dummy->next;
    // You can breakdown 3 steps into
    //  insertCopyInBetween(head);
    //  connectRandomPointers(head);
    //  return getDeepCopyList(head);
}

/*
33. Merge K sorted lists
ANS :
Input : lists = [[1,4,5],[1,3,4],[2,6]]  || Output : 1->1->2->3->4->4->5->6
*/
// Bruteforce ----------->
// TC : O(nxk)+O(mlogm)+O(nxk) where m=NxK
// SC: O(m) + O(m)
Node *mergeKListsBruteforce(vector<Node *> &lists)
{
    int n = lists.size();
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        Node *temp = lists[i];
        while (temp)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }
    }
    sort(arr.begin(), arr.end());
    Node *head = constructLLOptimal(arr);
    return head;
}
// Better ----------->
// TC : Assume n1=head and n2=lists[i]
// first iteration (n1+n2)
// second " (n1+n2+n3)
// third " (n1+n2+n3+n4)
// Now assume that every list is same size
// N(1+2+3....K)
// so its near about N*((k*k+1)/2)
// SC : O(1)
Node *mergeKListsBetter(vector<Node *> &lists)
{
    Node *head = lists[0];
    for (int i = 1; i < lists.size(); i++)
    {
        head = mergelist(head, lists[i]);
    }
    return head;
}
// Optimal ---------->
// TC : O(klogk) its for for loop +O(NxKxlogK) assume that all list;s size is same
// SC :  O(k) at max it can store k elems
Node *mergeKListsOptimal(vector<Node *> &lists)
{
    priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<pair<int, Node *>>> minH;
    int n = lists.size();
    for (int i = 0; i < n; i++)
    {
        // We're pushing pq list's head list itself
        if (lists[i])
            minH.push({lists[i]->data, lists[i]});
    }
    Node *dummy = new Node(0);
    Node *temp = dummy;
    while (!minH.empty())
    {
        pair<int, Node *> p = minH.top();
        temp->next = p.second;
        minH.pop();
        // Now go to list's 2nd elem and push it to minH so that we can get the minimum value
        if (p.second->next)
            minH.push({p.second->next->data, p.second->next});
        temp = temp->next;
    }
    return dummy->next;
}

/*
34.
ANS :
Input :  || Output :
*/
// Bruteforce ----------->
// TC :
// SC:
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
35.
ANS :
Input :  || Output :
*/
// Bruteforce ----------->
// TC :
// SC:
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

/*
36.
ANS :
Input :  || Output :
*/
// Bruteforce ----------->
// TC :
// SC:
// Better ----------->
// TC :
// SC :
// Optimal ---------->
// TC :
// SC :

// Extra from leetcode===================================>>

/*
1. Merge two sorted lists
ANS : You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
Input : list1 = [1,2,4], list2 = [1,3,4]  || Output : [1,1,2,3,4,4]
*/
// Bruteforce ----------->
// TC : O(n1)=temp1 while loop, O(n2)=temp2 while loop, N=n1=n2, sort=O(NlogN), O(N)=convert Total=  O(n1)+O(n2)+O(NlogN)+O(N)
// SC : O(N)+O(N)
Node *mergeTwoListsBruteforce(Node *list1, Node *list2)
{
    Node *temp1 = list1;
    Node *temp2 = list2;
    vector<int> arr;
    while (temp1 != NULL)
    {
        arr.push_back(temp1->data);
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        arr.push_back(temp2->data);
        temp2 = temp2->next;
    }
    sort(arr.begin(), arr.end());
    // Convert arr to linked list which return head
    Node *head = constructLLOptimal(arr);
    return head;
}
// Better ----------->
// TC : O(N+M)
// SC : O(1)
Node *mergeTwoListsBetter(Node *list1, Node *list2)
{
    // if (list1 == NULL)
    //     return list2;
    // if (list2 == NULL)
    //     return list1;
    // Node *left = list1;
    // Node *right = list2;
    // Node *dummy = new Node(0);
    // Node *curr = dummy;
    // while (left && right)
    // {
    //     if (left->data <= right->data)
    //     {
    //         curr->next = left;
    //         left = left->next;
    //     }
    //     else
    //     {
    //         curr->next = right;
    //         right = right->next;
    //     }
    //     curr = curr->next;
    // }
    // while (left)
    // {
    //     curr->next = left;
    //     curr = curr->next;
    //     left = left->next;
    // }
    // while (right)
    // {
    //     curr->next = right;
    //     curr = curr->next;
    //     right = right->next;
    // }
    // return dummy->next;
    // ***************better optimized****************
    Node *t1 = list1;
    Node *t2 = list2;
    Node *dummy = new Node(0);
    Node *temp = dummy;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data < t2->data)
        {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    if (t1)
        temp->next = t1;
    else
        temp->next = t2;
    return dummy->next;
}
// Optimal ---------->
// TC :O(N+M)
// SC :O(1)
Node *mergeTwoListsOptimal(Node *list1, Node *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    if (list1->data > list2->data)
        swap(list1, list2);
    Node *res = list1;
    while (list1 != NULL && list2 != NULL)
    {
        Node *temp = NULL;
        while (list1 != NULL && list1->data <= list2->data)
        {
            temp = list1;
            list1 = list1->next;
        }
        temp->next = list2;
        swap(list1, list2);
    }
    return res;
}

// ================================MAIN START=================================>>
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("./i.txt", "r", stdin);
    //     freopen("./o.txt", "w", stdout);
    // #endif
    /*
        Some short function
           int maxi = *max_element(arr.begin(), arr.end());
            int sum = accumulate(arr.begin(), arr.end(), 0);
    */
    /*Calculating time and space start----->>*/
    auto start_time = std::chrono::high_resolution_clock::now();
    size_t initial_space = sizeof(Node);
    /*Calculating time and space end----->>*/

    // Example vector of integers
    vector<int> arr = {3, 4, 5};
    vector<int> arr2 = {1, 2, 3, 4, 5};

    // Call the constructLL function
    // Node *head = constructLLBruteforce(arr);
    // Node *head = constructLLOptimal(arr);
    Node *head1 = constructLLOptimal(arr2);
    // Node *head = nullptr;
    // ListNode<int> *head = nullptr;
    // head = insertAtFirst(head, 1);
    // head = insertAtFirst(head, 2);
    // head = insertAtFirst(head, 3);
    // head = insertAtFirst(head, 4);
    // head = insertAtFirst(head, 5);
    // cout << "LinkedList before inserting 0 at beginning : " << endl;
    printLinkedList(head1, 1);
    // cout<<endl;
    // Node * head=removeNthFromEnd(head1,2);
    // printLinkedList(head, 1);
    // head = insertAtFirst(head, 0);
    // cout << "LinkedList after inserting 0 at beginning : " << endl;
    // cout << "After Delete " << endl;
    // head = deleteFirst(head);
    // printLinkedList(head, 1);
    // head = deleteLast(head);
    // cout << "After Delete " << endl;
    // cout<<"The length of the linked list is "<<length(head);
    // cout << searchInLinkedList(head, 6);
    // Node* head=constructDLL(arr);
    // Node *head = constructDLLOptimal(arr);
    // printLinkedList(head, 2);
    // Node *head = NULL;
    // head = insertAtTailDLL(head, 3);
    // head = insertAtTailDLL(head, 1);
    // head = insertAtTailDLL(head, 1);
    // head = insertAtTailDLL(head, 2);
    // head = insertAtTailDLL(head, 4);
    // head = insertAtTailDLL(head, 1);
    // head = insertAtTailDLL(head, 10);
    // head = insertAtTailDLL(head, 2);
    // head = insertAtTailDLL(head, 6);
    // head = insertAtTailDLL(head, 3);
    // head = insertAtTailDLL(head, 4);
    // cout << "After Insert" << endl;
    // head = insertBeforeHeadDLL(head, 0);
    // head = insertAtTailDLL(head, 0);
    // head = insertBeforeTailDLL(head, 0);
    // head = insertBeforeKDLL(head, 2, 99);

    // printLinkedList(head, 2);

    // cout << "After Delete" << endl;
    // head = deleteDLLFirst(head);
    // head = deleteKthNode(head, 2);
    // head = deleteLastNode(head);
    // head = deleteK(head, 1);
    // head = deleteEl(head, 8);
    // printLinkedList(head, 2);
    // cout << "After Reverse DLL" << endl;
    // head = reverseDLL(head);
    // cout << "The middle node is ";
    // head = middleNodeBruteforce(head);
    // head = middleNodeOptimal(head);
    // cout << "After Reverse SLL" << endl;
    // head = reverseListBruteforce(head);
    // printLinkedList(head, 1);
    // head = reverseListBetter(head);
    // head = reverseListOptimal(head);
    // printLinkedList(head, 1);
    // createCycle(head, 2);
    // cout << detectCycleBruteforce(head) << endl;
    // cout << detectCycleOptimal(head) << endl;
    // Node *nodeRec = firstNodeBruteforce(head);
    // Node *nodeRec = firstNodeOptimal(head);

    // if (nodeRec != NULL)
    // {
    //     Node *temp = head;
    //     int pos = 0;
    //     while (temp != nodeRec)
    //     {
    //         ++pos;
    //         temp = temp->next;
    //     }
    //     cout << "Tail connects at pos " << pos << endl;
    // }
    // else
    // {
    //     cout << "No Tail" << endl;
    // }
    // cout << "Length is " << lengthOfLoopOptimal(head);
    // isPalindromeBruteforce(head) ? cout << "True"<<endl : cout << "False"<<endl;
    // isPalindromeOptimal(head) ? cout << "True" : cout << "False";

    // head = segregateOddEvenBruteforce(head);
    // head = segregateOddEvenOptimal(head);
    // head = segregateEvenOddBruteforce(head);
    // head = segregateEvenOddBetter(head);
    // head = segregateEvenOddOptimal(head);
    // head = removeKthNodeBruteforce(head, 2);
    // head = removeKthNodeOptimal(head, 7);
    // head = deleteMiddleBruteforce(head);
    // head = deleteMiddleOptimal(head);
    // head = sortListBruteforce(head);
    // printLinkedList(head, 1);
    // cout << endl;
    // Node *headd = sortListOptimal(head);
    // printLinkedList(headd, 1);
    // head = sortList012Bruteforce(head);
    // head = sortList012Optimal(head);
    // cout << "After modified" << endl;
    // Node *head = NULL;
    // head = insertAtTailDLL(head, 1);
    // head = insertAtTailDLL(head, 3);
    // head = insertAtTailDLL(head, 1);
    // head = insertAtTailDLL(head, 2);
    // head = insertAtTailDLL(head, 4);
    // Node *head1 = head;
    // head = head->next->next->next;
    // Node *headSec = NULL;
    // Node *head2 = headSec;
    // headSec = insertAtTailDLL(headSec, 3);
    // headSec->next = head;
    // cout << "Head1: ";
    // printLinkedList(head1, 1);
    // cout << "Head2: ";
    // printLinkedList(head2, 1);
    // Node *answerNode = findIntersectionBruteforce(head1, head2);
    // Node *answerNode = findIntersectionBetter(head1, head2);
    // Node *answerNode = findIntersectionOptimal1(head1, head2);
    // if (answerNode == NULL)
    // cout << "No intersection\n";
    // else
    //        cout << "The intersection point is " << answerNode->data << endl;
    // Insert Position
    // head=insertPosition(head,100,6);
    // cout<<"After Insert "<<endl;
    // printLinkedList(head,1);
    // add 2 numbers
    // Node *head1 = NULL;
    // head1 = insertAtTailDLL(head1, 10);
    // head1 = insertAtTailDLL(head1, 3);
    // head1 = insertAtTailDLL(head1, 10);
    // head1 = insertAtTailDLL(head1, 8);
    // head1 = insertAtTailDLL(head1, 5);
    // head1 = insertAtTailDLL(head1, 10);
    // // cout<<"Head1"<<endl;
    // printLinkedList(head1, 2);
    // cout << endl;
    // cout<<"Head2"<<endl;
    // Node *head2 = NULL;
    // head2 = insertAtTailDLL(head2, 4);
    // head2 = insertAtTailDLL(head2, 8);
    // cout << "After add 1" << endl;
    // head = add1ToLinkedListBruteforce(head);
    // head = add1ToLinkedListOptimal(head);
    // printLinkedList(head, 1);
    // Node*new_head=addTwoNumbersOptimal(head1,head2);
    // cout<<endl<<"After addition"<<endl;
    // printLinkedList(new_head,1);
    // cout<<longestPalindrome("abba");
    // cout << "After delete all occu that have 10" << endl;
    // head1 = deleteAllOccurrencesOptimal(head1, 10);
    // printLinkedList(head1, 2);
    // Extra from leetcode---------->>
    // Node *head3 = mergeTwoListsBruteforce(head, head1);
    // Node *head = mergeTwoListsBetter(head1, head2);
    // Node *head = mergeTwoListsOptimal(head1, head2);
    // vector<Node *> lists;
    // First linked list: 1 -> 4 -> 5
    // Node *list1 = new Node(1);
    // list1->next = new Node(4);
    // list1->next->next = new Node(5);
    // lists.push_back(list1);

    // Second linked list: 1 -> 3 -> 4
    // Node *list2 = new Node(1);
    // list2->next = new Node(3);
    // list2->next->next = new Node(4);
    // lists.push_back(list2);

    // Third linked list: 2 -> 6
    // Node *list3 = new Node(2);
    // list3->next = new Node(6);
    // lists.push_back(list3);
    // Node *head = mergeKListsBruteforce(lists);
    // cout << endl;
    // Node *head2 = mergeKListsBetter(lists);
    // Node *head2 = mergeKListsOptimal(lists);
    // printLinkedList(head, 1);
    // printLinkedList(head2, 1);

    // End code here-------->>
    /*Calculating time and space start----->>*/
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    size_t final_space = sizeof(Node);
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
    std::cout << "Space used by function: " << (final_space - initial_space) << " bytes" << std::endl;
    /*Calculating time and space end----->>*/

    return 0;
}
