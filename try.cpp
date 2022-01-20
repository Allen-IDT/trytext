#include <iostream>
using namespace std;

struct node
{
    int data;       //資料
    node *next;     //下一個節點位置
};
//宣告結點


struct Queue
{
    node *front;    //開頭
    node *end;     //結尾
    int size;       //大小
};
//宣告Queue


void add(Queue &q, int v)
{
    node *n = new node;
    n->data = v;
    n->next = NULL;
    if(q.front == NULL){
        q.front = q.end = n;
    }
    else{
        q.end->next = n;
        q.end = n;
    }
    q.size++;
}
//新增結點


int del(Queue &q)
{
    if(q.front == NULL) return -1;
    int v = q.front->data;
    q.front = q.front->next;
    return v;
}
//刪除結點


void prin(Queue &q)
{
    for(node *n=q.front;n!=NULL;n=n->next)
        cout << n->data << '\n';
}

int main()
{
    Queue q;
    q.front = NULL;
    q.end = NULL;
    q.size = 0;
    //初始畫
    for(int i=1;i<=10;i++){
        add(q,i);
    }
    cout<<"第一次印出：\n";
    prin(q);
    add(q,999);
    add(q,888);
    cout<<"第二次印出：\n\n";
    cout<<"新增999和888到q\n";
    prin(q);
    del(q);
    cout<<"第三次印出：\n\n";
    cout<<"刪除List頂端元素(1)\n";
    prin(q);

    return 0;
}

