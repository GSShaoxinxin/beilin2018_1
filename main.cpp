#include <iostream>

using namespace std;

// �������еĽڵ�����
typedef struct LNode{
    int data;
    struct LNode* next;
}LNode,*LinkList;

//��ʼ��
bool InitList(LinkList &L){
    L=new LNode;
    L->next=NULL;
    return true;
}

//������Ĳ���
bool ListInsert(LinkList &L,int i,int e){
    //j�Ǽ���p��next���ǵڼ������ҿ�ΪNULL
    //���ҵ�i-1����㣬��pָ��ýڵ� Ҫ�ҵ�i-1��ָ�롣��i=1ʱ��Ҫ�õ���0��
    LinkList p=L;
    int j=0;
    while(p && j<i-1){
        //�ҵ���i-1��Ԫ�ص�ָ��
        p=p->next;
        j++;
    }
    if(!p || j>i-1) return false;//i��n+1����i��1 ���������ĩβ���룬����i������n+1,iҲ������1
    LinkList s=new LNode;//ʹ��new�õ�����ָ��
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}
//ɾ��
bool ListDelete(LinkList &L,int i){
    //j�Ǽ���p��next���ǵڼ����Ҳ���ΪNULL Ҫ�ҵ�i��ָ���ǰһ��ָ�룬Ҫ�ҵ�i-1��ָ�롣L�ǵ�0������i=1ʱ��Ҫʹ�õ�0��
    LinkList p=L;
    int j=0;
    while((p->next) && j<i-1){//i���Ϸ���i>n
        p=p->next;
        j++;
    }
    if(!(p->next) || j>i-1){//i�ķ�Χ��1��n��p�ҵ��ǵ�n-1����㡣
        return false;
    }
    LinkList q=p->next;
    p->next = q->next;
    delete q;

    return true;
}

//ǰ�巨����������

void CreateList_H(LinkList& L,int n){
    L = new LNode;//�Ƚ���һ����ͷ���Ŀ�����
    L->next=NULL;
    for(int i=0;i<n;i++){
        LinkList p=new LNode;
        cin>>p->data;
        p->next=L->next;
        L->next =p;
    }
}

//β�巨����������
void CreateList_R(LinkList &L,int n){
     L = new LNode;//�Ƚ���һ����ͷ���Ŀ�����
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
//�ڴ�ͷ���ĵ�����L�и������i����Ԫ�أ���e���� pָ��Ҫ�ҵĵ�i����㡣p��j����һ��
    LinkList p=L->next;
    int j=1;
    while(p && j<i){
        p=p->next;
        ++j;
    }
    if(!p || j>i) return false;//iֵ���Ϸ�i>n��i<=0
    e=p->data;
    return true;
}
void ReverseLinkList(LinkList &L){
    //����ֻ����һ�飬�ı������򼴿�
    if(L==NULL || L->next==NULL) return;//���LΪ�ջ���ֻ��һ��Ԫ�أ�����Ҫת��
    LinkList frontList=NULL;//�Ѿ����ת����
    LinkList remain=L->next;//û�����ת����
    while(remain!=NULL){
        LinkList p=remain;//���ڴ���Ľ��
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
