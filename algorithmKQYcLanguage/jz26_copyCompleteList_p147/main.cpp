//
//  main.cpp
//  jz26_copyCompleteList_p147
//
//  Created by kqy on 01/04/2017.
//  Copyright © 2017 KQY. All rights reserved.
//

#include <iostream>
using namespace std;
typedef struct _NODE_
{
    int data;
    struct _NODE_ *next;
    struct _NODE_ *sibling;
}Node,*pNode;
//创建一个单链表
void createLinkedList(pNode *pHead,int num)
{
    if(num <= 0)
    {
        return;
    }
    int data;
    *pHead = (pNode)malloc(sizeof(Node));
    if(!pHead)
    {
        exit(-1);
    }
    cin>>data;
    (*pHead)->data = data;
    (*pHead)->next = NULL;
    (*pHead)->sibling = NULL;
    num--;
    pNode pTemp = *pHead;
    while(num > 0)
    {
        cin>>data;
        pNode pNew = (pNode)malloc(sizeof(Node));
        if(!pNew)
        {
            exit(-1);
        }
        pNew->data = data;
        pNew->next = NULL;
        pNew->sibling = NULL;
        pTemp->next = pNew;
        pTemp = pNew;
        num--;
    }
}
//创建一个复杂链表，为测试方便，这里定死了
void createComplexList(pNode *pHead)
{
    //先创建一个单链表
    createLinkedList(pHead,5);
    //然后为每个结点设置sibling指针
    (*pHead)->sibling = (*pHead)->next->next;
    (*pHead)->next->sibling = (*pHead)->next->next->next->next;
    pNode pTemp = (*pHead)->next->next->next;
    pTemp->sibling = (*pHead)->next;
}
//打印链表
void display(pNode pHead)
{
    pNode pTemp = pHead;
    while(pTemp != NULL)
    {
        cout<<pTemp->data<<" ";
        pTemp = pTemp->next;
    }
    cout<<endl;
}

pNode cloneHeadList(pNode pHead) {
    pNode pStart = pHead;
    while (pStart) {
        pNode pAddNode = new Node( );
//        pAddNode ->next = NULL;
        pAddNode -> next = pStart -> next;
        pAddNode ->data = pStart -> data;
//        没有置空  0403  -4
//        pAddNode->sibling = NULL;

        pStart -> next = pAddNode;
        pStart = pAddNode -> next;
    }
     return pHead;
}
pNode copyPoint(pNode pHead) {
    pNode  originP = pHead;
    pNode  cloneP = originP -> next;
    //提示cloneP是空的。要生成 new?  0403  -1
//    pNode cloneP = new Node( );
//    cloneP  = originP -> next;
//    while ( originP) {这与 ！NULL 一样？  0403  -2
    while ( originP ->sibling  ) {
        if (originP -> sibling) {
            cloneP -> sibling = originP ->sibling ->next;
        }
//        originP -> next = cloneP -> next;错的这里了：
        originP = cloneP -> next;
        cloneP = originP -> next;
        
    }
    return pHead;
}
pNode divoceTwoList(pNode pHead) {
    // 0406 ++:要用一个固定的头，指向 。返回这个结点。
    pNode cloneHead = pHead ->next;
    //NULL 一样？  0403  -3 要不要new? 就是一个指向的。
    pNode cloneP = new Node( );
    cloneP = pHead -> next;
    pNode originP = pHead;
    originP -> next = cloneP -> next;
    while (originP -> next) {
        cloneP -> next = originP -> next;
        cloneP = cloneP -> next;
        originP -> next = cloneP -> next;
        originP = originP -> next;
       
    }
    return cloneHead;
}

pNode Clone(pNode pHead)
{
    if(pHead == NULL)
    {
        return NULL;
    }
    cloneHeadList(pHead);
    copyPoint(pHead);
    return divoceTwoList(pHead);
}

int main(int argc, const char * argv[]) {
    pNode pHead = NULL;
    createComplexList(&pHead);
    cout<<"原始链表如下:"<<endl;
    display(pHead);
    cout<<"my change : 链表如下:"<<endl;
    pHead = cloneHeadList(pHead);
    pHead = copyPoint(pHead);
    pHead = divoceTwoList(pHead);
    display(pHead);

    pNode pCloneHead = Clone(pHead);
    if(pCloneHead != NULL)
    {
        cout<<"克隆链表如下"<<endl;
        display(pCloneHead);
        cout<<"打印克隆链表每个结点的值以及sibling结点的值如下\n";
        pNode p = pCloneHead;
        while(p != NULL)
        {
            cout<<p->data<<" ";
            if(p->sibling != NULL)
            {
                cout<<p->sibling->data<<endl;
            }
            else
            {
                cout<<"NULL\n";
            }
            p = p->next;
        }
    }
    return 0;
}
