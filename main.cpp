#include <iostream>

using namespace std;

// 单链表中的节点类型
typedef struct LNode{
    int data;
    struct LNode* next;
}LNode,*LinkList;

//初始化
bool InitList(LinkList &L){
    L=new LNode;
    L->next=NULL;
    return true;
}

//单链表的插入
bool ListInsert(LinkList &L,int i,int e){
    //j是几，p的next就是第几个，且可为NULL
    //查找第i-1个结点，且p指向该节点 要找第i-1个指针。当i=1时，要用到第0个
    LinkList p=L;
    int j=0;
    while(p && j<i-1){
        //找到第i-1的元素的指针
        p=p->next;
        j++;
    }
    if(!p || j>i-1) return false;//i＞n+1或者i＜1 插入可以在末尾插入，所以i可以是n+1,i也可以是1
    LinkList s=new LNode;//使用new得到的是指针
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}
//删除
bool ListDelete(LinkList &L,int i){
    //j是几，p的next就是第几个且不可为NULL 要找第i个指针的前一个指针，要找第i-1个指针。L是第0个。当i=1时，要使用第0个
    LinkList p=L;
    int j=0;
    while((p->next) && j<i-1){//i不合法，i>n
        p=p->next;
        j++;
    }
    if(!(p->next) || j>i-1){//i的范围是1到n，p找的是第n-1个结点。
        return false;
    }
    LinkList q=p->next;
    p->next = q->next;
    delete q;

    return true;
}

//前插法创建单链表

void CreateList_H(LinkList& L,int n){
    L = new LNode;//先建立一个带头结点的空链表
    L->next=NULL;
    for(int i=0;i<n;i++){
        LinkList p=new LNode;
        cin>>p->data;
        p->next=L->next;
        L->next =p;
    }
}

//尾插法创建单链表
void CreateList_R(LinkList &L,int n){
     L = new LNode;//先建立一个带头结点的空链表
    L->next=NULL;
    LinkList r=L;
    for(int i=0;i<n;i++){
        LinkList p=new LNode;        cin>>p->data;

        p->next=NULL;
        r->next=p;
        r=p;
    }
}
bool GetElem(LinkList L,int i,int &e){
//在带头结点的单链表L中根据序号i返回元素，用e返回 p指向要找的第i个结点。p与j保持一致
    LinkList p=L->next;
    int j=1;
    while(p && j<i){
        p=p->next;
        ++j;
    }
    if(!p || j>i) return false;//i值不合法i>n或i<=0
    e=p->data;
    return true;
}
void ReverseLinkList(LinkList &L){
    //逆序。只遍历一遍，改变链表方向即可
    if(L==NULL || L->next==NULL) return;//如果L为空或者只有一个元素，则不需要转换
    LinkList frontList=NULL;//已经完成转换的
    LinkList remain=L->next;//没有完成转换的
    while(remain!=NULL){
        LinkList p=remain;//正在处理的结点
        remain=p->next;
        p->next=frontList;
        frontList=p;
    }
    L->next=frontList;
}
void ReverseList(LinkList& ListHead)
{
if( (NULL==ListHead)||(NULL==ListHead->next) )return ;
LinkList pre=ListHead;
LinkList cur=pre->next;
LinkList Next=NULL;
while(cur!=NULL)
{
Next=cur->next;
cur->next=pre;
pre=cur;
cur=Next;
}
ListHead->next=NULL;
ListHead=pre;
}


int main()
{
    LinkList L;
    CreateList_R(L,10);
    int e;
ReverseList(L->next);
   // ReverseLinkList(L);
    GetElem(L,3,e);
    printf("e:%d",e);
    return 0;
}
