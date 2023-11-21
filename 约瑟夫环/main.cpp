#include<bits/stdc++.h>
#include<windows.h>
struct Node
{
    int data;
    struct Node *next;
};

Node *create_node_list(int data)
{
    Node *head=(Node *)malloc(sizeof(Node));

    head->next=head;
    head->data=data;

    return head;
}

Node *push_node(Node *head,int data)
{
    if(head==NULL)return NULL;

    Node *tail=head;
    for(;tail->next!=head;tail=tail->next)
    {
        /*KAFFFFFFFFFFFFFFFFSUKIPZC*/;
    }
    
    Node *kaf=(Node *)malloc(sizeof(Node));
    kaf->next=head;
    kaf->data=data;
    tail->next=kaf;

    return kaf;
}

Node *pop_node(Node *head,int *data)
{
    if(head==NULL)return NULL;

    Node *tail=head;
    for(;tail->next!=head;tail=tail->next)
    {
        /*KAFFFFFFFFFFFFFFFFSUKIPZC*/
    }

    tail->next=head->next;
    *data=head->data;

    free(head);

    return tail->next;
}
int main()
{
    int n,m;
    printf("input the n: ");
    scanf("%d",&n);
    printf("input the m: ");
    scanf("%d",&m);

    printf("Now we'll give the shunxu of chuquande ren\nloading...");
    
    system("cls");
    Node *first=create_node_list(n);

    for (int i=n-1;i>=1;i--)
        first=push_node(first,i);

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<m;j++)
        {
            first=first->next;
        }
        int data;
        first=pop_node(first,&data);
        printf("%d-th is poped ---person:%d\n",i,data);
    }
    system("pause");
}