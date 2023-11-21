#include<stdio.h>
#include<string>
#include<iostream>
#define OP 0
#define NUM 1
#define MAX 1000
using namespace std;
struct tree
{
    char type;
    struct Node *right;
    struct Node *left;
};
struct Node
{
    int type;
    union
    {
        int num;
        struct tree opera;
    };
};
Node *create_node()
{
    return (Node *)malloc(sizeof(Node));
}
int read_num(string str,int &l)
{
    int num=0;
    for(;str[l]!='\0';l++)
    {
        if(isdigit(str[l]))
        {
            num=num*10+str[l]-'0';
        }
        else
        {
            break;
        }
        
    }
    l-=1;
    return num;
}
void read_op(Node *num_stack[],char op_stack[],int &op_d,int &num_d)
{
    Node *temp_node=create_node();
    tree temp_tree;

    temp_tree.type=op_stack[--op_d];
    temp_tree.right=num_stack[--num_d];
    temp_tree.left=num_stack[--num_d];
    

    temp_node->type=OP;
    temp_node->opera=temp_tree;
    num_stack[num_d++]=temp_node;
}
Node *read_expression(string str)
{
    Node *num_stack[MAX];
    char op_stack[MAX];

    int op_d=0,num_d=0;

    for(int i=0;str[i]!='\0';i++)
    {
        if(isdigit(str[i]))
        {
            Node *temp=create_node();
            temp->type=NUM;
            temp->num=read_num(str,i);
            num_stack[num_d++]=temp;
        }
        else if(str[i]=='+'||str[i]=='-')
        {
            while(op_d>0&&(op_stack[op_d-1]=='+'||op_stack[op_d-1]=='-'||op_stack[op_d-1]=='*'||op_stack[op_d-1]=='/'||op_stack[op_d-1]=='%'))
            {
                read_op(num_stack,op_stack,op_d,num_d);
            }
            op_stack[op_d++]=str[i];
        }
        else if(str[i]=='*'||str[i]=='/'||str[i]=='%')
        {
            while(op_d>0&&(op_stack[op_d-1]=='*'||op_stack[op_d-1]=='/'||op_stack[op_d-1]=='%'))
            {
                read_op(num_stack,op_stack,op_d,num_d);
            }
            op_stack[op_d++]=str[i];
        }
        else if(str[i]=='(')
        {
            op_stack[op_d++]=str[i];
        }
        else if(str[i]==')')
        {
            while(op_d>0&&(op_stack[op_d-1]!='('))
            {
                read_op(num_stack,op_stack,op_d,num_d);
            }
            op_d--;
        }
    }
    return num_stack[0];
}
void tail_travel(Node *op_tree,string &str)
{
    if(op_tree->type==NUM)
    {
        str=str+to_string(op_tree->num)+" ";
        cout<<op_tree->num<<' ';
        return;
    }

        tail_travel((op_tree->opera).left,str);
        
        tail_travel((op_tree->opera).right,str);

        str=str+(op_tree->opera).type+" ";
        cout<<(op_tree->opera).type<<' ';
}
void head_travel(Node *op_tree,string &str)
{
    if(op_tree->type==NUM)
    {
        str=str+to_string(op_tree->num)+" ";
        cout<<op_tree->num<<' ';
        return;
    }
        str=str+(op_tree->opera).type+" ";
        cout<<(op_tree->opera).type<<' ';

        head_travel((op_tree->opera).left,str);
        
        head_travel((op_tree->opera).right,str);
}
string mid_remake(string str)
{
    string res_s="(";
    for(int i=0;str[i]!='\0';i++)
    {
        if((str[i]=='+'||str[i]=='-')&&(i==0||str[i-1]=='('))
        {
            res_s+="0";
        }
        res_s+=str[i];
    }
    res_s+=")";
    res_s+="\0";
    return res_s;
}
string trans_head_ex(string str)
{
    string res;
    for(int i=0;str[i]!='\0';i++)
    {
        if(isdigit(str[i]))
        {
            res=to_string(read_num(str,i))+res;
        }
        else
        {
            res=str[i]+res;
        }
    }
    return res;
}
int head_compute(string str)
{
    int num_stack[MAX];
    int num_d=0;
    for(int i=0;str[i]!='\0';i++)
    {
        if (isdigit(str[i]))
        {
            num_stack[num_d++]=read_num(str,i);
        }
        else if(str[i]!=' ')
        {
            int temp=0;
            if (str[i]=='+')
            {
                temp=num_stack[--num_d]+num_stack[--num_d];
                num_stack[num_d++]=temp;
            }
            else if (str[i]=='-')
            {
                temp=num_stack[--num_d]-num_stack[--num_d];
                num_stack[num_d++]=temp;
            }
            else if (str[i]=='*')
            {
                temp=num_stack[--num_d]*num_stack[--num_d];
                num_stack[num_d++]=temp;
            }
            else if (str[i]=='/')
            {
                temp=num_stack[--num_d]/num_stack[--num_d];
                num_stack[num_d++]=temp;
            }
            else if (str[i]=='%')
            {
                temp=num_stack[--num_d]%num_stack[--num_d];
                num_stack[num_d++]=temp;
            }
        }
    }
    return num_stack[0];
}
int tail_compute(string str)
{
    int num_stack[MAX];
    int num_d=0;
    for(int i=0;str[i]!='\0';i++)
    {
        if (isdigit(str[i]))
        {
            num_stack[num_d++]=read_num(str,i);
        }
        else if(str[i]!=' ')
        {
            int temp=0;
            if (str[i]=='+')
            {
                temp=num_stack[num_d-2]+num_stack[num_d-1];
                num_d-=2;
                num_stack[num_d++]=temp;
            }
            else if (str[i]=='-')
            {
                temp=num_stack[num_d-2]-num_stack[num_d-1];
                num_d-=2;
                num_stack[num_d++]=temp;
            }
            else if (str[i]=='*')
            {
                temp=num_stack[num_d-2]*num_stack[num_d-1];
                num_d-=2;
                num_stack[num_d++]=temp;
            }
            else if (str[i]=='/')
            {
                temp=num_stack[num_d-2]/num_stack[num_d-1];
                num_d-=2;
                num_stack[num_d++]=temp;
            }
            else if (str[i]=='%')
            {
                temp=num_stack[num_d-2]%num_stack[num_d-1];
                num_d-=2;
                num_stack[num_d++]=temp;
            }
        }
    }
    return num_stack[0];
}
int compute_pair(int lv,int rv,char otype)
{
    if(otype=='+')
        return lv+rv;
    else if(otype=='-')
        return lv-rv;
    else if(otype=='*')
        return lv*rv;
    else if(otype=='/')
        return lv/rv;
    else
        return lv%rv;
}
int compute_mid(Node *root)
{
    if (root->type==NUM)
        return root->num;
    int lv=compute_mid((root->opera).left);
    char otype=(root->opera).type;
    int rv=compute_mid((root->opera).right);
    
    return compute_pair(lv,rv,otype);
}
int main()
{
    printf("Please input your mid_expression:\n");

    string mid_expression;
    getline(cin,mid_expression);
    mid_expression=mid_remake(mid_expression);

    Node *op_tree=create_node();
    op_tree=read_expression(mid_expression);

    system("cls");

    int haha=compute_mid(op_tree);
    cout<<"The mid_expression'value is:"<<haha;
    cout<<endl;
    string head_ex;
    cout<<"head_expression:";
    head_travel(op_tree,head_ex);
    cout<<endl;
    cout<<"The head_ex'value is:"<<head_compute(trans_head_ex(head_ex));
    cout<<endl;
    
    cout<<endl;

    string tail_ex;
    cout<<"tail_expression:";
    tail_travel(op_tree,tail_ex);
    cout<<endl;
    cout<<"The tail_ex'value is:"<<tail_compute(tail_ex);
    cout<<endl;
}