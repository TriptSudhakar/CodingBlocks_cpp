#include<iostream>
#include<queue>
using namespace std;
int main()
{
    // priority_queue<int> h;  // by default -> max heap
    priority_queue<int, vector<int>, greater<int> > h;  // min heap
    h.push(1);
    h.push(4);
    h.push(14);
    h.push(24);
    h.push(40);
    h.push(-4);
    h.push(3);
    h.push(20);
    h.push(13);
    h.push(13);
    h.push(5);

    while (!h.empty())  // output will be in sorted order, this is heap sort
    {
        cout<<h.top()<<" ";
        h.pop();
    }
    cout<<endl;
    return 0;
}