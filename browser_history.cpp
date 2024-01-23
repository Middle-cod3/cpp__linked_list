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
    string data;
    Node *next;
    Node *back;

    // Default constructor
    Node() : data(0), next(nullptr), back(nullptr) {}

    // Constructor with data parameter
    Node(string x) : data(x), next(nullptr), back(nullptr) {}
    Node(string x, Node *next, Node *random) : data(x), next(next), back(random) {}
};
class Browser
{
    Node *currentPage;

public:
    Browser(string &homepage)
    {
        currentPage = new Node(homepage);
    }

    void visit(string &url)
    {
        Node *newNode = new Node(url);
        currentPage->next = newNode;
        newNode->back = currentPage;
        currentPage = newNode;
    }

    string back(int steps)
    {
        while (steps)
        {
            if (currentPage->back)
                currentPage = currentPage->back;
            else
                break;
            steps--;
        }
        return currentPage->data;
    }

    string forward(int steps)
    {
        while (steps)
        {
            if (currentPage->next)
                currentPage = currentPage->next;
            else
                break;
            steps--;
        }
        return currentPage->data;
    }
};

/*
1. Design browser hostory.
ANS : Your task is to maintain a data structure that supports the following functions of a web browser.

1- Browser(homepage): Set homepage of the browser

2- Visit(url): Visit the url from the current page. It clears up all the forward history.

3- Back(steps): Move ‘steps’ backward in the browser history

4- Forward(steps): Move ‘steps’ forward in the browser history
Note:
If you can’t move steps forward or backward, just return the last website that can be reached.

The Queries are in the given format-:
The first line of each query contains the string representing the homepage of the web browser.

(1, url): Visit the url from the current page.

(2, steps): Move ‘steps’ backward in the browser history.

(3, steps): Move ‘steps’ forward in the browser history.
For example:
You are queries as  [[“homepage.com”], [1 , “facebook.com”], [1, “codingninjas.com”],[2, 1], [3, 1]]
1 query is the query that sets the homepage as “homepage.com”.
2 query is the query to visit “facebook.com”
3 query is the query to visit “codingninjas.com”
4 query is the query that moves back one step to “facebook.com”
5 query is the query that moves forward one step to “codingninjas.com”
Time Complexity : constructor O(1), visit O(1),back O(steps), forword O(steps)
*/
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

    return 0;
}
