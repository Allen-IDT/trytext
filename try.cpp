#include <iostream>
using namespace std;

struct node
{
    int data;       //���
    node *next;     //�U�@�Ӹ`�I��m
};
//�ŧi���I


struct Queue
{
    node *front;    //�}�Y
    node *end;     //����
    int size;       //�j�p
};
//�ŧiQueue


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
//�s�W���I


int del(Queue &q)
{
    if(q.front == NULL) return -1;
    int v = q.front->data;
    q.front = q.front->next;
    return v;
}
//�R�����I


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
    //��l�e
    for(int i=1;i<=10;i++){
        add(q,i);
    }
    cout<<"�Ĥ@���L�X�G\n";
    prin(q);
    add(q,999);
    add(q,888);
    cout<<"�ĤG���L�X�G\n\n";
    cout<<"�s�W999�M888��q\n";
    prin(q);
    del(q);
    cout<<"�ĤT���L�X�G\n\n";
    cout<<"�R��List���ݤ���(1)\n";
    prin(q);

    return 0;
}

