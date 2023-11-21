#include<stdio.h>
#include<string>
#include<time.h>
#include<stdlib.h>
#include<vector>
#include<iostream>
#include<iomanip>
#include<algorithm>
struct classes
{
    int course[3];
};
classes Class[10];

namespace examtime
{
    int check[10][10];
    int node[10];
    std::vector<int>exam_list[10];
    int l_ptr=0;
    bool node_empty()
    {
        int flag=1;
        for(int i=0;i<10;i++)
        {
            if(node[i]==1)
            {
                flag=0;
                break;
            }
        }
        return flag==1;
    }
    void arrange()
    {
        int ptr=0;
        while(node_empty()==0)
        {
            if(node[ptr]==1)
            {
                exam_list[l_ptr].push_back(ptr);
                node[ptr]=-1;
                for(int i=ptr+1;i!=ptr;i=(i+1)%10)
                {
                    if(((check[i][ptr]&&check[ptr][i])==0)&&
                        node[i]==1)
                    {
                        exam_list[l_ptr].push_back(i);
                        node[i]=-1;
                    }
                }
                l_ptr++;
            }
            ptr=(ptr+1)%10;
        }
    }
    void putout()
    {
        std::cout<<"Examtime table:\n"<<"The class's course:\n";
        for(int i=0;i<10;i++)
        {
            std::cout<<"Class"<<i<<":"<<Class[i].course[0]<<"  "<<Class[i].course[1]<<"  "<<Class[i].course[2]<<"  "<<'\n';
        }

        for(int i=0;i<l_ptr;i++)
        {
            std::cout<<"Time"<<i+1<<":"<<'('<<' ';
            for(auto j=exam_list[i].begin();j!=exam_list[i].end();j++)
            {
                std::cout<<*j<<' ';
            }
            std::cout<<")\n";
        }
    }
}
namespace scores
{
    
    struct students
    {
        int classid;
        int id;
        std::string name;
        int score[3];
        int course[3];
        int all_score;
    };
    students student[20];
    void init()
    {
        srand((unsigned)time(NULL));
        int ptr=0;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<2;j++)
            {
                student[ptr].classid=i;
                student[ptr].id=(i+1)*100+j;
                student[ptr].name='A'+ptr;
                student[ptr].course[0]=Class[i].course[0];
                student[ptr].course[1]=Class[i].course[1];
                student[ptr].course[2]=Class[i].course[2];
                
                int a=rand()%101;
                int b=rand()%101;
                int c=rand()%101;
                student[ptr].score[0]=a;
                student[ptr].score[1]=b;
                student[ptr].score[2]=c;
                student[ptr++].all_score=(a+b+c)/3;
            }
        }
        
    }
    bool cmp1(students a,students b)
    {
        return a.all_score>b.all_score;
    }
    bool cmp2(students a,students b)
    {
        if(a.classid!=b.classid)return a.classid<b.classid;
        else return a.all_score>b.all_score;
    }
    
    
    void output1()
    {
        students temp[20];
        memcpy(temp,student,sizeof(student));
        std::cout<<"Press 1 to show by scores.\n"
                 <<"Press 2 to show by class.\n"
                 <<"Press 3 to show selected class.\n";
        char t;
        std::cin>>t;
        system("cls");
        if(t=='1')
        {
            std::sort(temp,temp+20,cmp1);
            std::cout<<std::setw(15)<<"Name"<<std::setw(15)<<"Id"<<std::setw(15)<<"Class"<<std::setw(15)<<"Course1"<<std::setw(15)<<"Course2"<<std::setw(15)<<"Course3"<<std::setw(15)<<"Aver_score\n";
            for(int i=0;i<20;i++)
            {
                std::string a='('+std::to_string(temp[i].course[0])+','+std::to_string(temp[i].score[0])+')';
                std::string b='('+std::to_string(temp[i].course[1])+','+std::to_string(temp[i].score[1])+')';
                std::string c='('+std::to_string(temp[i].course[2])+','+std::to_string(temp[i].score[2])+')';
                std::cout<<std::setw(15)<<temp[i].name<<std::setw(15)<<temp[i].id<<std::setw(15)<<temp[i].classid<<std::setw(15)<<a<<std::setw(15)<<b<<std::setw(15)<<c<<std::setw(15)<<temp[i].all_score<<'\n';
            }
        }
        else if(t=='2')
        {
            std::sort(temp,temp+20,cmp2);
            std::cout<<std::setw(15)<<"Name"<<std::setw(15)<<"Id"<<std::setw(15)<<"Class"<<std::setw(15)<<"Course1"<<std::setw(15)<<"Course2"<<std::setw(15)<<"Course3"<<std::setw(15)<<"Aver_score\n";
            for(int i=0;i<20;i++)
            {
                std::string a='('+std::to_string(temp[i].course[0])+','+std::to_string(temp[i].score[0])+')';
                std::string b='('+std::to_string(temp[i].course[1])+','+std::to_string(temp[i].score[1])+')';
                std::string c='('+std::to_string(temp[i].course[2])+','+std::to_string(temp[i].score[2])+')';
                std::cout<<std::setw(15)<<temp[i].name<<std::setw(15)<<temp[i].id<<std::setw(15)<<temp[i].classid<<std::setw(15)<<a<<std::setw(15)<<b<<std::setw(15)<<c<<std::setw(15)<<temp[i].all_score<<'\n';
            }
        }
        else if(t=='3')
        {
            std::cout<<"Please input selected class id.\n";
            char ch;
            int tt;
            std::cin>>ch;
            tt=ch-'0';
            system("cls");
            std::cout<<std::setw(15)<<"Name"<<std::setw(15)<<"Id"<<std::setw(15)<<"Class"<<std::setw(15)<<"Course1"<<std::setw(15)<<"Course2"<<std::setw(15)<<"Course3"<<std::setw(15)<<"Aver_score\n";
            for(int i=0;i<20;i++)
            {
                if(tt==temp[i].classid)
                {
                    std::string a='('+std::to_string(temp[i].course[0])+','+std::to_string(temp[i].score[0])+')';
                    std::string b='('+std::to_string(temp[i].course[1])+','+std::to_string(temp[i].score[1])+')';
                    std::string c='('+std::to_string(temp[i].course[2])+','+std::to_string(temp[i].score[2])+')';
                    std::cout<<std::setw(15)<<temp[i].name<<std::setw(15)<<temp[i].id<<std::setw(15)<<temp[i].classid<<std::setw(15)<<a<<std::setw(15)<<b<<std::setw(15)<<c<<std::setw(15)<<temp[i].all_score<<'\n';
                }
            }
        }
        
        return;
    }
    void output2()
    {
        students temp[20];
        memcpy(temp,student,sizeof(student));
        std::cout<<"Press 1 to show statistics of all.\n"
                 <<"Press 2 to show statistics of selected course.\n"
                 <<"Press 3 to show statistics of selected class.\n";
        char t;std::cin>>t;system("cls");
        if(t=='1')
        {
            int a=0,b=0,c=0,d=0,e=0;
            for(int i=0;i<20;i++)
            {
                if(temp[i].all_score>=90)a++;
                else if(temp[i].all_score>=80&&temp[i].all_score<90)b++;
                else if(temp[i].all_score>=70&&temp[i].all_score<80)c++;
                else if(temp[i].all_score>=60&&temp[i].all_score<70)d++;
                else if(temp[i].all_score<60)e++;
            }
            std::cout<<"statistics of all:\n";
            std::cout<<">90:"<<a<<"\n";
            std::cout<<"80-89:"<<b<<"\n";
            std::cout<<"70-79:"<<c<<"\n";
            std::cout<<"60-69:"<<d<<"\n";
            std::cout<<"<60:"<<e<<"\n";
        }

        else if(t=='2')
        {
            std::cout<<"Select statistics of course:\n";
            char tt;std::cin>>tt;system("cls");
            int ttt=tt-'0';
            int a=0,b=0,c=0,d=0,e=0;
            for(int i=0;i<20;i++)
            {
                if(temp[i].course[0]==ttt)
                {
                    if(temp[i].score[0]>=90)a++;
                    else if(temp[i].score[0]>=80&&temp[i].score[0]<90)b++;
                    else if(temp[i].score[0]>=70&&temp[i].score[0]<80)c++;
                    else if(temp[i].score[0]>=60&&temp[i].score[0]<70)d++;
                    else if(temp[i].score[0]<60)e++;
                }
                else if(temp[i].course[1]==ttt)
                {
                    if(temp[i].score[0]>=90)a++;
                    else if(temp[i].score[1]>=80&&temp[i].score[1]<90)b++;
                    else if(temp[i].score[1]>=70&&temp[i].score[1]<80)c++;
                    else if(temp[i].score[1]>=60&&temp[i].score[1]<70)d++;
                    else if(temp[i].score[1]<60)e++;
                }
                else if(temp[i].course[2]==ttt)
                {
                    if(temp[i].score[0]>=90)a++;
                    else if(temp[i].score[2]>=80&&temp[i].score[2]<90)b++;
                    else if(temp[i].score[2]>=70&&temp[i].score[2]<80)c++;
                    else if(temp[i].score[2]>=60&&temp[i].score[2]<70)d++;
                    else if(temp[i].score[2]<60)e++;
                }
            }
            std::cout<<"statistics of course"<<ttt<<":\n";
            std::cout<<">90:"<<a<<"\n";
            std::cout<<"80-89:"<<b<<"\n";
            std::cout<<"70-79:"<<c<<"\n";
            std::cout<<"60-69:"<<d<<"\n";
            std::cout<<"<60:"<<e<<"\n";
        }
        else if(t=='3')
        {
            std::cout<<"Select statistics of class:\n";
            char tt;std::cin>>tt;//class id
            std::cout<<"Select statistics of all-score or course:\n<1 to all-score,2 to course>\n";
            char ttt;std::cin>>ttt;//course id
            system("cls");
            if(ttt=='1')//all score
            {
                int a=0,b=0,c=0,d=0,e=0;
                for(int i=0;i<20;i++)
                {
                    if(temp[i].classid==(tt-'0'))
                    {
                        if(temp[i].all_score>=90)a++;
                        else if(temp[i].all_score>=80&&temp[i].all_score<90)b++;
                        else if(temp[i].all_score>=70&&temp[i].all_score<80)c++;
                        else if(temp[i].all_score>=60&&temp[i].all_score<70)d++;
                        else if(temp[i].all_score<60)e++;
                    }
                }
                std::cout<<"statistics of all-score and class"<<tt<<":\n";
                std::cout<<">90:"<<a<<"\n";
                std::cout<<"80-89:"<<b<<"\n";
                std::cout<<"70-79:"<<c<<"\n";
                std::cout<<"60-69:"<<d<<"\n";
                std::cout<<"<60:"<<e<<"\n";
            }
            else if(ttt=='2')//course
            {
                int a=0,b=0,c=0,d=0,e=0;
                for(int i=0;i<20;i++)
                {
                    if(temp[i].classid==(tt-'0'))
                    {
                        if(temp[i].course[0]==(ttt-'0'))
                        {
                            if(temp[i].score[0]>=90)a++;
                            else if(temp[i].score[0]>=80&&temp[i].score[0]<90)b++;
                            else if(temp[i].score[0]>=70&&temp[i].score[0]<80)c++;
                            else if(temp[i].score[0]>=60&&temp[i].score[0]<70)d++;
                            else if(temp[i].score[0]<60)e++;
                        }
                        else if(temp[i].course[1]==(ttt-'0'))
                        {
                            if(temp[i].score[0]>=90)a++;
                            else if(temp[i].score[1]>=80&&temp[i].score[1]<90)b++;
                            else if(temp[i].score[1]>=70&&temp[i].score[1]<80)c++;
                            else if(temp[i].score[1]>=60&&temp[i].score[1]<70)d++;
                            else if(temp[i].score[1]<60)e++;
                        }
                        else if(temp[i].course[2]==(ttt-'0'))
                        {
                            if(temp[i].score[0]>=90)a++;
                            else if(temp[i].score[2]>=80&&temp[i].score[2]<90)b++;
                            else if(temp[i].score[2]>=70&&temp[i].score[2]<80)c++;
                            else if(temp[i].score[2]>=60&&temp[i].score[2]<70)d++;
                            else if(temp[i].score[2]<60)e++;
                        }
                    }
                }
                std::cout<<"statistics of class"<<tt<<" && course"<<ttt<<":\n";
                std::cout<<">90:"<<a<<"\n";
                std::cout<<"80-89:"<<b<<"\n";
                std::cout<<"70-79:"<<c<<"\n";
                std::cout<<"60-69:"<<d<<"\n";
                std::cout<<"<60:"<<e<<"\n";
            }
            
        }
        
        return;
    } 
    void output3()
    {
        students temp[20];
        memcpy(temp,student,sizeof(student));
        std::cout<<"Press 1 to search by studentid.\n"
                 <<"Press 2 to search by class.\n"
                 <<"Press 3 to search by all-score.\n";
        int t;std::cin>>t;system("cls");
        if(t==1)
        {
            std::cout<<"Input the studentid.\n";
            long long int tt;std::cin>>tt;system("cls");
            for(int i=0;i<20;i++)
            {
                if(temp[i].id==tt)
                {
                    std::cout<<std::setw(15)<<"Name"<<std::setw(15)<<"Id"<<std::setw(15)<<"Class"<<std::setw(15)<<"Course1"<<std::setw(15)<<"Course2"<<std::setw(15)<<"Course3"<<std::setw(15)<<"Aver_score\n";
                    std::string a='('+std::to_string(temp[i].course[0])+','+std::to_string(temp[i].score[0])+')';
                    std::string b='('+std::to_string(temp[i].course[1])+','+std::to_string(temp[i].score[1])+')';
                    std::string c='('+std::to_string(temp[i].course[2])+','+std::to_string(temp[i].score[2])+')';
                    std::cout<<std::setw(15)<<temp[i].name<<std::setw(15)<<temp[i].id<<std::setw(15)<<temp[i].classid<<std::setw(15)<<a<<std::setw(15)<<b<<std::setw(15)<<c<<std::setw(15)<<temp[i].all_score<<'\n';
                    break;
                }
            }
        }
        else if(t==2)
        {
            std::cout<<"Input the classid.\n";
            int tt;std::cin>>tt;system("cls");
            std::cout<<"1 to all-score.\n"
                     <<"2 to course score.";
            int ttt;std::cin>>ttt;system("cls"); 
            std::cout<<"score>=60:\n";
            if(ttt==1)
            {
                std::cout<<std::setw(15)<<"Name"<<std::setw(15)<<"Id"<<std::setw(15)<<"Class"<<std::setw(15)<<"Course1"<<std::setw(15)<<"Course2"<<std::setw(15)<<"Course3"<<std::setw(15)<<"Aver_score\n";
                for(int i=0;i<20;i++)
                {
                    if(temp[i].classid==tt&&temp[i].all_score>=60)
                    {
                        
                        std::string a='('+std::to_string(temp[i].course[0])+','+std::to_string(temp[i].score[0])+')';
                        std::string b='('+std::to_string(temp[i].course[1])+','+std::to_string(temp[i].score[1])+')';
                        std::string c='('+std::to_string(temp[i].course[2])+','+std::to_string(temp[i].score[2])+')';
                        std::cout<<std::setw(15)<<temp[i].name<<std::setw(15)<<temp[i].id<<std::setw(15)<<temp[i].classid<<std::setw(15)<<a<<std::setw(15)<<b<<std::setw(15)<<c<<std::setw(15)<<temp[i].all_score<<'\n';
                    }
                }
            }
            else if(ttt==2)
            {
                std::cout<<"Input course.\n";
                int cid;std::cin>>cid;system("cls");
                std::cout<<std::setw(15)<<"Name"<<std::setw(15)<<"Id"<<std::setw(15)<<"Class"<<std::setw(15)<<"Course1"<<std::setw(15)<<"Course2"<<std::setw(15)<<"Course3"<<std::setw(15)<<"Aver_score\n";
                for(int i=0;i<20;i++)
                {
                    if(temp[i].course[0]==cid)
                    {
                        if(temp[i].score[0]>=60)
                        {
                        std::string a='('+std::to_string(temp[i].course[0])+','+std::to_string(temp[i].score[0])+')';
                        std::string b='('+std::to_string(temp[i].course[1])+','+std::to_string(temp[i].score[1])+')';
                        std::string c='('+std::to_string(temp[i].course[2])+','+std::to_string(temp[i].score[2])+')';
                        std::cout<<std::setw(15)<<temp[i].name<<std::setw(15)<<temp[i].id<<std::setw(15)<<temp[i].classid<<std::setw(15)<<a<<std::setw(15)<<b<<std::setw(15)<<c<<std::setw(15)<<temp[i].all_score<<'\n';
                        }
                    }
                    else if(temp[i].course[1]==cid)
                    {

                        if(temp[i].score[1]>=60)
                        {
                        std::string a='('+std::to_string(temp[i].course[0])+','+std::to_string(temp[i].score[0])+')';
                        std::string b='('+std::to_string(temp[i].course[1])+','+std::to_string(temp[i].score[1])+')';
                        std::string c='('+std::to_string(temp[i].course[2])+','+std::to_string(temp[i].score[2])+')';
                        std::cout<<std::setw(15)<<temp[i].name<<std::setw(15)<<temp[i].id<<std::setw(15)<<temp[i].classid<<std::setw(15)<<a<<std::setw(15)<<b<<std::setw(15)<<c<<std::setw(15)<<temp[i].all_score<<'\n';
                            
                        }
                    }
                    else if(temp[i].course[2]==cid)
                    {
                        if(temp[i].score[2]>=60)
                        {
                        std::string a='('+std::to_string(temp[i].course[0])+','+std::to_string(temp[i].score[0])+')';
                        std::string b='('+std::to_string(temp[i].course[1])+','+std::to_string(temp[i].score[1])+')';
                        std::string c='('+std::to_string(temp[i].course[2])+','+std::to_string(temp[i].score[2])+')';
                        std::cout<<std::setw(15)<<temp[i].name<<std::setw(15)<<temp[i].id<<std::setw(15)<<temp[i].classid<<std::setw(15)<<a<<std::setw(15)<<b<<std::setw(15)<<c<<std::setw(15)<<temp[i].all_score<<'\n';
                            
                        }
                    }
                }
            }
        }
        else if(t==3)
        {
            std::cout<<"1 to >=60.\n2 to <=60.\n";
            int tt;std::cin>>tt;system("cls");
            std::cout<<std::setw(15)<<"Name"<<std::setw(15)<<"Id"<<std::setw(15)<<"Class"<<std::setw(15)<<"Course1"<<std::setw(15)<<"Course2"<<std::setw(15)<<"Course3"<<std::setw(15)<<"Aver_score\n";
            if(tt==1)
            {
                for(int i=0;i<20;i++)
                {
                    if(temp[i].all_score>=60)
                    {
                        std::string a='('+std::to_string(temp[i].course[0])+','+std::to_string(temp[i].score[0])+')';
                        std::string b='('+std::to_string(temp[i].course[1])+','+std::to_string(temp[i].score[1])+')';
                        std::string c='('+std::to_string(temp[i].course[2])+','+std::to_string(temp[i].score[2])+')';
                        std::cout<<std::setw(15)<<temp[i].name<<std::setw(15)<<temp[i].id<<std::setw(15)<<temp[i].classid<<std::setw(15)<<a<<std::setw(15)<<b<<std::setw(15)<<c<<std::setw(15)<<temp[i].all_score<<'\n';
                    }
                }
            }
            else if(tt==2)
            {
                for(int i=0;i<20;i++)
                {
                    if(temp[i].all_score<=60)
                    {
                        std::string a='('+std::to_string(temp[i].course[0])+','+std::to_string(temp[i].score[0])+')';
                        std::string b='('+std::to_string(temp[i].course[1])+','+std::to_string(temp[i].score[1])+')';
                        std::string c='('+std::to_string(temp[i].course[2])+','+std::to_string(temp[i].score[2])+')';
                        std::cout<<std::setw(15)<<temp[i].name<<std::setw(15)<<temp[i].id<<std::setw(15)<<temp[i].classid<<std::setw(15)<<a<<std::setw(15)<<b<<std::setw(15)<<c<<std::setw(15)<<temp[i].all_score<<'\n';
                    }
                }
            }
        }
        
        return;
    }
}
void init()
{
    for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
        examtime::check[i][j]=0;
    srand((unsigned)time(NULL));
    for(int i=0;i<10;i++)examtime::node[i]=0;
    for(int i=0;i<10;i++)
    {
        /* int a=rand()%10;
        int b=rand()%10;
        int c=rand()%10; */
        printf("Input the class%d 's course:",i);
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);

        examtime::node[a]=1,examtime::node[b]=1,examtime::node[c]=1;
        Class[i].course[0]=a;
        Class[i].course[1]=b;
        Class[i].course[2]=c;
        examtime::check[a][b]=1;
        examtime::check[a][c]=1;
        examtime::check[b][a]=1;
        examtime::check[b][c]=1;
        examtime::check[c][a]=1;
        examtime::check[c][b]=1;
    }
}
int main()
{
    init();
    scores::init();
    system("cls");
    while(true)
    {
        std::cout<<"Press 1 to show examtime tabel.\n"
                 <<"Press 2 to show infomation of score.\n";
        char t;std::cin>>t;system("cls");
        if(t=='1')
        {
            examtime::arrange();
            examtime::putout();
            std::cout<<"Press any key to continue.\n";
            system("pause");
            system("cls");
        }
        else if(t=='2')
        {
            std::cout<<"Press 1 to show rank.\n"
                     <<"Press 2 to show statistics.\n"
                     <<"Press 3 to search.\n";
            int tt;std::cin>>tt;
            if(tt==1)
            {
                scores::output1();
                std::cout<<"Press any key to continue.\n";
                system("pause");
                
                system("cls");
            }
            else if(tt==2)
            {
                scores::output2();
                std::cout<<"Press any key to continue.\n";
                system("pause");
                
                system("cls");
            }
            else if(tt==3)
            {
                scores::output3();
                std::cout<<"Press any key to continue.\n";
                system("pause");
                
                system("cls");
            }
        }
    }
}