#include<bits/stdc++.h>
using namespace std;

int Array[100];
int N;

void TwoDvector()
{
    vector<pair<int,int> >v[10];
//    0 8
// vector<int>v[10];
//    x y
//    v[0].push_back(8)
//    v[x].push_back(y)
//
//    [0]->8
//    [1]->
//    [2]->
//    [3]->
//    [4]->
//    [5]->
//    [6]->
//    [7]->
//
//    [8]->0
//    [9]->
    //freopen("input.txt","r",stdin);
/*
 7
 Dhaka Manikganj
 Dhaka Gazipur
 Dhaka Narayanganj
 Narayanganj Narsingi
 Narsingi Kishorgonj
 Gazipur Tangail
 Gazipur Mymensing

 7
 Dhaka Manikganj 40
 Dhaka Gazipur 30
 Dhaka Narayanganj 25
 Narayanganj Narsingi 80
 Narsingi Kishorgonj 120
 Gazipur Tangail 100
 Gazipur Mymensing 150
*/
    int edge ;
    cout<<"Enter the number of friendships\n";
    cin>>edge;
    int cnt = 0;
    map<string,int>M;
    string name[100];
    for(int i=0;i<edge;i++)
    {

//Dhaka Manikganj
// Dhaka Gazipur
        int x,y,dis;
        string name1, name2;
        cin>>name1>>name2>>dis;
        if(M.find(name1)==M.end())
        {
            M[name1]=cnt + 1;
            ++cnt;
            name[cnt] = name1;
        }
        x = M[name1];

        if(M.find(name2)==M.end())
        {
            M[name2]=cnt + 1;
            ++cnt;
            name[cnt] = name2;
        }
        y = M[name2];


        v[x].push_back( make_pair(y,dis) );
        v[y].push_back(make_pair(x,dis));

    }
//    v[0]-> 1,    5,     9
//        v[0][0] v[0][1] v[0][2]


    for(int j=1;j<=M.size();j++)
    {
        cout<<"Adjacents for "<<name[j]<<" node are: ";
        for(int i=0;i<v[j].size() ;i++)
        {
            int id = v[j][i].first;
            int d = v[j][i].second;
            cout<<"("<< name[id]<<", distance = "<<d<<") ";
        }
        cout<<endl;
    }

//    v[0]
//    v[1]
//    v[2]

}

void TestQueue()
{
    /// 2 3 4 5
    queue<int>Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(5);
    cout<<"expected = 5 and found "<<Q.size()<<endl;
    cout<<"expected = 1 and found "<< Q.front()<<endl;
    Q.pop();
    cout<<"expected = 2 and found "<< Q.front()<<endl;
    cout<<"expected = 4 and found "<<Q.size()<<endl;

    cout<<Q.empty()<<" should say false\n";
    /// Empty the queue
    while(Q.empty()==false )
    {
        cout<<Q.front()<<endl;
        Q.pop();
    }
    cout<<Q.empty()<<" should say True\n";
}

void TestPriorityQueue()
{
    priority_queue<int, vector<int>, greater<int> >PQ;
    PQ.push(1);
    PQ.push(2);
    PQ.push(3);
    PQ.push(4);
    PQ.push(5);
    cout<<"expected = 5 and found "<<PQ.size()<<endl;
    cout<<"expected = 1 and found "<< PQ.top()<<endl;
    PQ.pop();

    cout<<"expected = 2 and found "<< PQ.top()<<endl;
//    cout<<"expected = 4 and found "<<Q.size()<<endl;
//
    cout<<PQ.empty()<<" should say false\n";
    /// Empty the queue
    while(PQ.empty()==false )
    {
        PQ.pop();
    }
    cout<<PQ.empty()<<" should say True\n";
}

void TestStack()
{

    stack<int>S;

    S.push(1);
//    1



    S.push(2);
//
//    2
//    1


    S.push(3);
//    3
//    2
//    1
//
    S.push(4);
//    4
//    3
//    2
//    1

    //Q.push(5);
    cout<<"expected = 4 and found "<<S.size()<<endl;
    cout<<"expected = 4 and found "<< S.top()<<endl;

    S.pop();
    cout<<"expected = 3 and found "<<S.size()<<endl;

    cout<<S.empty()<<" should say false\n";
    /// Empty the queue
    while(S.empty()==false )
    {
        S.pop();
    }
    cout<<S.empty()<<" should say True\n";
}
void TestPair()
{
    ///        roll, name , dept
    pair<int,string>Student;
    Student.first = 1;
    Student.second = "ABC";
    pair<int,string>Students[10];
    cout<<Student.first<<" "<<Student.second<<endl;
    pair<int,pair<string,string> >P;
    P.first=1;
    P.second.first ="ABC";
    P.second.second;
     ///        roll, name , dept, gpa
    pair<pair<int,string>,pair<string,float> >S;
    S.first.first = 1;
    S.first.second ="Rahim";
    S.second.first = "CSE";
    S.second.second = 3.4;
}

void TestSet()
{
    int day1[]={4,5,1,2};
    int day2[]={9,5,1,10};
    set<int>S;
    for(int i=0;i<4;i++)S.insert(day1[i]);
    if(S.find(3)==S.end()){

        cout<<"Roll 3 not found\n";
    }
    else cout<<"3 was found\n";

     if(S.find(3)==S.end()){

        cout<<"Roll 3 not found\n";
    }
    else {

        cout<<"We can perform erase operations";
    }


    S.erase(3);
    S.erase(13);
    S.erase(23);
    S.erase(43);
    S.erase(332);
    S.erase(312);
    S.erase(111);
    cout<<"Finished\n";
}


void TestMap()
{

    map<string,int>M;
//    M["Dhaka"]=1;
//    M["Manikganj"]=2;

    M.insert( make_pair("Dhaka",1) );
    cout<<M["Dhaka"]<<endl;
    //cout<<M["Manikganj"]<<endl;
    if(M.find("Manikganj")==M.end())cout<<"Manikganj not found\n";
    else {
        cout<<"We have the id , and it is "<<M["Manikganj"];
    }


}

int main()
{
    TestQueue();
//TwoDvector();


//    TestPriorityQueue();
//TestPair();
//    cin>>N;
//    for(int i=0;i<N;i++)cin>>Array[i];
//    /// break for terminating a loop




    return 0;
}
/*
 7
 Dhaka Manikganj 40
 Dhaka Gazipur 30
 Dhaka Narayanganj 25
 Narayanganj Narsingi 80
 Narsingi Kishorgonj 120
 Gazipur Tangail 100
 Gazipur Mymensing 150

    12
    0 8
    1 2
    1 3
    1 7
    1 9
    2 4
    2 8
    3 4
    3 5
    5 6
    6 7
    8 9


*/
