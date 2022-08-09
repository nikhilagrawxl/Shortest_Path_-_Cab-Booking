#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <unistd.h>
#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <iomanip>
using namespace std;

int endp = 1;

int distanced=0;
int rentalfees=0;

int wt[]={1,2,5,10,20,50,100,200,500,2000};
int numb=10;
void findmin(int v)
{

    int deno[]={1,2,5,10,20,50,100,500,2000};
    int n=sizeof(deno)/sizeof(deno[0]);

    vector<int> ans;
    for(int i=n-1;i>=0;--i)
    {
        while(v>=deno[i])
        {
            v-=deno[i];
            ans.push_back(deno[i]);
        }
    }
    for (auto i : ans)
    {
        cout<<i<<" ";
    }
}

int minimumchange(int wt[], int m, int V)
{
    int table[V+1];
    table[0] = 0;
    for (int i=1; i<=V; i++)
        table[i] = INT_MAX;
    for (int i=1; i<=V; i++)
    {
        for (int j=0; j<m; j++)
          if (wt[j] <= i)
          {
              int sub_res = table[i-wt[j]];
              if (sub_res != INT_MAX && sub_res + 1 < table[i])
                  table[i] = sub_res + 1;
          }
    }

      if(table[V]==INT_MAX)
        return -1;

    return table[V];
}

/*
int minimumchange(int wt[], int W, int n)
{
    int t[n + 1][W + 1];
    memset(t, -1, sizeof(t));

    for (int i = 0; i < W + 1; i++)
    {
        t[n][W] = INT_MAX - 1;
    }
    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = 1;
    }
    for (int j = 1; j < W + 1; j++)
    {
        if (j % wt[0] == 0)
        {
            t[1][j] = j / wt[0];
        }
        else
        {
            t[1][j] = INT_MAX - 1;
        }
    }

for (int i = 2; i < n + 1; i++)
{
    for (int j = 1; j < W + 1; j++)
    {

        if (wt[n - 1] <= W)
        {
            return t[n][W] = min(minimumchange(wt, W - wt[n - 1], n - 1), minimumchange(wt, W, n - 1));
        }
        else if (wt[n - 1] > W)
        {
            return t[n][W] = minimumchange(wt, W, n - 1);
        }
    }
}
}
*/
/*
void printClosestCab(std::vector<coordinates> dcc,const coordinates myLocation){
	std::cout << "\nThe 5 Closest Cabs" <<"\n";
	for(int i=0;i<5;i++){
		std::cout<<i+1<<". "<<myLocation.distance(dcc[i])<<" Km away at "<<dcc[i].get_address()<<".    ( "<< dcc[i].get_latitude()<<" , "<< dcc[i].get_longitude()<<" )\n";
	}
}

void printClosestAuto(std::vector<coordinates> dcc,const coordinates myLocation){
	std::cout << "\nThe 5 Closest Autos" <<"\n";
	for(int i=0;i<5;i++){
		std::cout<<i+1<<". "<<myLocation.distance(dcc[i])<<" Km away at "<<dcc[i].get_address()<<".    ( "<< dcc[i].get_latitude()<<" , "<< dcc[i].get_longitude()<<" )\n";
	}
}
*/
class customer
{
	private:
	public:
	string customername;
    string carmodel;
    string carnumber;
    char data;
    // variables defined in this class in public mode.
};
class rent : public customer // inhereted class from customer class
{
	public:
	int days=0,rentalfee=0; // additional int vatiables defined
	void data()
	{

	cout << "Please Enter your Name for Cab Booking: "; //taking data from the user
    cin >> customername;
    cout<<endl;
    do
    {
        cout <<"\t\t\t\tPlease Select a Car"<<endl; //giving user a choice to select among three different models
        cout<<"\t\t\t\tEnter 'A' for Mini."<<endl;
        cout<<"\t\t\t\tEnter 'B' for Sedan."<<endl;
        cout<<"\t\t\t\tEnter 'C' for SUV."<<endl;
        cout<<endl;
        cout<<"\t\t\t\tChoose a Car from the above options: ";
        cin >>carmodel;
        cout<<endl;
 cout<<"--------------------------------------------------------------------------"<<endl;
 if(carmodel=="A")
 {
 	system("CLS");

		cout<<"You have choosed Mini Cab"<<endl;
		 ifstream inA("A.txt"); //displaying details of model A
         char str[200];
         while(inA) {
         inA.getline(str, 200);
         if(inA) cout << str << endl;
}
sleep(2);
  }
  if(carmodel=="B")
  {
  	system("CLS");

		cout<<"You have choosed Sedan Cab"<<endl;
		 ifstream inB("B.txt"); //displaying details of model B
         char str[200];
         while(inB) {
         inB.getline(str, 200);
         if(inB) cout << str << endl;

     }
     sleep(2);
 }
 if(carmodel=="C")
 {
 	system("CLS");
	     cout<<"You have choosed SUV"<<endl;
		 ifstream inC("C.txt"); //displaying details of model C
         char str[200];
         while(inC) {
         inC.getline(str, 200);
         if(inC) cout << str << endl;
     }
     sleep(2);
}
if(carmodel !="A" && carmodel !="B" &&  carmodel !="C" )

      cout<<"Invaild Car Model. Please try again!"<<endl;
        }
while(carmodel !="A" && carmodel !="B" &&  carmodel !="C" );
    cout<<"--------------------------------------------------------------------------"<<endl;
  //  cout << "Please provide following information: "<<endl;
	//getting data from user related to rental service
    cout<<endl;
	}
	void calculate()
	{
		sleep(1);
		system ("CLS");
		cout<<"Calculating rent. Please wait......"<<endl;
		sleep(2);
		if(carmodel == "A"||carmodel=="a")
        rentalfee=distanced*8;
        if(carmodel == "B" ||carmodel=="b")
        rentalfee=distanced*10;
        if(carmodel == "C" ||carmodel=="c")
        rentalfee=distanced*13;
        rentalfees=rentalfee;
    }
void showrent()
    {
    cout << "\n\t\t                       Car Rental - Customer Invoice                  "<<endl;
    cout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
    cout << "\t\t	| Invoice No. :"<<"------------------|"<<setw(10)<<"#Cnb81353"<<" |"<<endl;
    cout << "\t\t	| Customer Name:"<<"-----------------|"<<setw(10)<<customername<<" |"<<endl;
    cout << "\t\t	| Car Model :"<<"--------------------|"<<setw(10)<<carmodel<<" |"<<endl;
    //cout << "\t\t	| Car No. :"<<"----------------------|"<<setw(10)<<carnumber<<" |"<<endl;
    cout << "\t\t	| Total distance :"<<"---------------|"<<setw(10)<<distanced<<" |"<<endl;
    cout << "\t\t	| Your Base Amount is :"<<"----------|"<<setw(10)<<rentalfee<<" |"<<endl;
    cout << "\t\t	| Caution Money :"<<"----------------|"<<setw(10)<<"0"<<" |"<<endl;
    cout << "\t\t	| Advanced :"<<"---------------------|"<<setw(10)<<"0"<<" |"<<endl;
    cout << "\t\t	 ________________________________________________________"<<endl;
    cout <<"\n";
    cout << "\t\t	| Total Amount is :"<<"-------|"<<setw(10)<<rentalfee<<" |"<<endl;
    cout << "\t\t	 ________________________________________________________"<<endl;
    cout << "\t\t	 # This is a computer generated invoce and it does not"<<endl;
    cout << "\t\t	 require an authorised signture #"<<endl;
    cout <<" "<<endl;
    cout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
    cout << "\t\t	You are advised to pay up the amount before due date."<<endl;
    cout << "\t\t	Otherwise penelty fee will be applied"<<endl;
    cout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
    int f;
    system("PAUSE");

    system ("CLS");

    cout<<"\nYour total amount is : "<<rentalfees;
    cout<<"\nYou can pay the fee in the following currency denominations : [1,2,5,10,20,50,100,200,500,2000]";
    cout<<"\nYou can pay the amount with minimum no. of denominations as : "<<minimumchange(wt,numb,rentalfees);
    cout<<"\nTotal possible ways to pay the fee is : ";
    findmin(rentalfees);
     cout<<"\n\n\n";
     ifstream inf("thanks.txt");


  char str[300];

  while(inf) {
    inf.getline(str, 300);
    if(inf) cout << str << endl;
  }
  inf.close();
	}
};



string usn;
int tmr;
void valid(string str)
{
    string dir, user;
    ifstream file;
    dir = str + ".txt";
    file.open(dir.c_str());
    if (!file.is_open() && file.fail())
    {
        // file.close();
        return;
    }
    else
    {
        tmr++;
        if (tmr == 3)
        {
            cout << "\nThis username already exists\nPlease try Again.";
            // file.close();
            return;
        }
        cout << "\nThis username already exists!\nCreate a username:";
        cin >> usn;
        // file.close();
        valid(usn);
    }
}

void Welcome_window()
{

    //  SetConsoleTextAttribute(color, 14);
    cout << "\t\t\tWelcome to our Travel Agency\n\n\n";

    cout << "\t\t\tThe Agency is managed by: \n\n\n";

    cout << "\t\t\tSRIJAN ,NIKHIL & UTKARSH\n\n";
}
class Pair
{
public:
    string destination;
    float dist;
    int condition;
    Pair(string dest, float weight, int cond = 1)

    {
        destination = dest;
        dist = weight;
        condition = cond;
    }
};
class myComparator
{
public:
    int operator()(Pair p1, Pair p2)
    {
        return p1.dist > p2.dist;
    }
};

class Graph
{
    int V;
    map<string, list<Pair>> adjList;

public:
    Graph(int v)
    {
        V = v;
    }

    void addEdge(string src, string dest, float wt, int condition)
    {
        Pair p(dest, wt, condition);
        Pair k(src, wt, condition);
        adjList[src].push_back(p);
        adjList[dest].push_back(k);
    }

    void print()

    {

        for (auto it = adjList.begin(); it != adjList.end(); it++)
        {
            cout << "\t" << (it)->first << " -->\t";
            for (auto lit = ((it)->second).begin(); lit != ((it)->second).end(); lit++)
            {
                cout << (lit)->destination << ",";
            }
            cout << endl;
        }
        cout << endl;
    }

    void printAllPathsUtil(string u, string d, map<string, bool> &visited, string path[], int &path_index, int cond, float wt, int rate)
    {
        visited[u] = true;
        path[path_index] = u;
        path_index++;

        if (u.compare(d) == 0)
        {
            cout << "\t";
            for (int i = 0; i < path_index; i++)
                cout << path[i] << "-->";
            cout << endl;
            cout << endl;
            if (cond <= -1)
                cout << "\tThe travel conditions are Bad " << endl;
            else if (cond == 0)
                cout << "\tThe travel conditions are Normal " << endl;
            else
                cout << "\tThe travel conditions are Good " << endl;
            cout << endl;

            cout << "\tThe distance for the route being " << wt << " KM" << endl;
            cout << endl;
            cout << "\tThe cost of Travel Inclusive of Taxes : Rs " << wt * rate << endl;
            cout << endl;
            cout << endl;
            cout << endl;
        }

        else
        {
            for (auto i = adjList[u].begin(); i != adjList[u].end(); ++i)
                if (!visited[i->destination])
                    printAllPathsUtil(i->destination, d, visited, path, path_index, cond + i->condition, wt + i->dist, rate);
        }

        path_index--;
        visited[u] = false;
    }

    void Validate_input(string &src, string &des)
    {
        if ((adjList.find(src) == adjList.end()))
        {
            cout << "\tSource Could Not be Found, Renter\n";
            string src1;
            cin >> src1;
            src = src1;
        }
        if ((adjList.find(des) == adjList.end()))
        {
            cout << "\tDestination Could Not be Found, Renter\n";
            string des1;
            cin >> des1;
            des = des1;
        }
    }

    void printAllPaths(string s, string d, int rate)
    {
        map<string, bool> visited;
        for (auto it = adjList.begin(); it != adjList.end(); it++)
        {
            visited[it->first] = false;
        }
        string *path = new string[V];
        int path_index = 0;
        printAllPathsUtil(s, d, visited, path, path_index, 0, 0, rate);
    }

    void Dijkstras(string src, string des, int rate)
    {

        map<string, float> distance;
        map<string, int> conditions;
        map<string, string> parent;

        for (auto it = adjList.begin(); it != adjList.end(); it++)
        {
            distance[it->first] = INT_MAX;
        }
        distance[src] = 0;
        conditions[src] = 0;

        priority_queue<Pair, vector<Pair>, myComparator> Q;
        Pair P(src, distance[src], conditions[src]);
        Q.push(P);
        string last;

        while (!Q.empty())
        {
            Pair Temp = Q.top();
            Q.pop();
            string u = Temp.destination;
            last = Temp.destination;

            for (auto it = adjList[u].begin(); it != adjList[u].end(); it++)
            {
                Pair f = *it;
                string v = f.destination;
                float w = f.dist;
                int cond = f.condition;
                if (distance[u] + w < distance[v])
                {
                    parent[v] = u;
                    distance[v] = distance[u] + w;
                    conditions[v] = conditions[u] + cond;
                    Pair L(v, distance[v], conditions[v]);
                    Q.push(L);
                }
            }
        }
        if (distance[des] == INT_MAX)
        {
            cout << "\n\n";
            cout << "\tNo Path between the source and the destination Exists, Sorry for the Inconvenience";
            exit(0);
        }

        cout << "-----SHORTEST ROUTE BETWEEN THE SORCE AND DESTINATION-------" << endl;
        cout << endl;
        cout << endl;
        cout << "\tThe shortest distance between " << src << " and " << des << " is : " << distance[des] << " KM" << endl;
        cout << endl;
        distanced=distance[des];
        cout << endl;
    //    cout << "\tThe cost of Travel Inclusive of Taxes : Rs " << distance[des] * rate << endl;
    //    cout << endl;
     //   cout << endl;
      //  cout << "\tThe path Of the Shortest Route is: " << endl;
      //  cout << endl;
        cout << endl;
        cout << "\t";
        string k = des;
        cout << k << "<--";

        while (parent[k].compare(src) != 0)
        {
            cout << parent[k] << " <--";
            k = parent[k];
        }
        cout << src;
        cout << endl;
        cout << endl;
        if (conditions[des] <= -1)
            cout << "\tThe travel conditions are Bad\n"
                 << endl;
        else if (conditions[des] == 0)
            cout << "\tThe travel conditions are Normal\n"
                 << endl;
        else
            cout << "\tThe travel conditions are Good\n"
                 << endl;
    }

    void fn()
    {
        // SetConsoleTextAttribute(color, 10);
        cout << "\tEnter the City from the list above:\t";
        string src;
        cin >> src;

        cin.ignore();
        cout << "\tEnter Your Destination:\t";
        string dest;
        cin >> dest;
        Validate_input(src, dest);

        cout << "\n";

        cout << endl;
        cout << endl;

        cout << "\tDo you want to book a cab ?\n " << endl;
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "\t[1] Yes \n \t[2] No \n\t"<< endl;

        int choice;

        cout << "\t";
        cin >> choice;
        cout << "\n\n\t";

        cout << endl;
        cout << endl;

        switch (choice)
        {
        case 2:

        {

            break;
        }
        case 1:

        {
            Dijkstras(src, dest, 7);
            cout << "---ALL ROUTES FROM SOURCE TO DESTINATION-----" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            printAllPaths(src, dest, 7);
            rent obj2;
            obj2.data();
            obj2.calculate();
            obj2.showrent();

            break;
        }

        }
    }
};

int main()
{
    system("COLOR 8F");
    Welcome_window();
    Sleep(1500);


    int choice, i, exit = 0;
    string ans, psd, name, fname, usern, pw, line, nusn;
    ofstream fileo;
    ifstream filei;
    cout << "----------------------------------------------Welcome to our system!------------------------------------------------------\n";
    while (endp == 1)
    {
        cout << "\nChoose one option:\n1. SignIn/LogIn(press 1 to select this)\n2. SignUp/Register(press 2 to select this)\n\npress any key and enter to exit\n";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter your username:";
            cin >> usn;
            cout << "\nEnter your password:";
            cin >> psd;
            fname = usn + ".txt";
            filei.open(fname.c_str());
            if (!filei.is_open() && filei.fail())
            {
                cout << "\nYou are not registered, please register before logging in.\n";
                filei.close();
                continue;
            }
            getline(filei, usern);
            getline(filei, line);
            getline(filei, pw);
            if (usn == usern && psd == pw)
            {
                cout << "\nYou are successfully logged in:) ";

                Graph g(60);
                system("cls");

                string lines = " ";
                ifstream readFile("Distance.txt");
                string source;
                string destination;
                string distance;
                string condition;
                while (getline(readFile, lines))
                {

                    stringstream iss(lines);
                    iss >> source >> destination >> distance >> condition;
                    float D = strtof((distance).c_str(), 0);
                    int C = atoi((condition).c_str());
                    g.addEdge(source, destination, D, C);
                }
                cout << "\n\n";

                cout << "-----THE LIST OF CITIES THAT THE AGENCY MANAGES ARE------";
                cout << endl;
                cout << endl;
                cout << endl;
                g.print();
                g.fn();
                cout << "Do you want to continue ? (Yes==1/N0==0)";
            cin >> endp;

                filei.close();
            }
            else
            {
                cout << "\nWrong username or password!\nPlease try Again.\n";
            }
            cout << endl;
        }
        else if (choice == 2)
        {
            cout << "\nEnter your name:";
            cin.ignore();
            getline(cin, name);
            cout << "\nCreate a username:";
            cin >> usn;
            tmr = 0;
            valid(usn);
            if (tmr >= 3)
            {
                continue;
            }
            cout << "\nCreate a password:";
            cin >> psd;
            fname = usn + ".txt";
            // cout<<fname;
            fileo.open(fname.c_str());
            fileo << usn << endl
                  << name << endl
                  << psd << endl;
            cout << "\nYou are successfully registered:)";

            Graph g(60);
            system("cls");

            string lines = " ";
            ifstream readFile("Distance.txt");
            string source;
            string destination;
            string distance;
            string condition;
            while (getline(readFile, lines))
            {

                stringstream iss(lines);
                iss >> source >> destination >> distance >> condition;
                float D = strtof((distance).c_str(), 0);
                int C = atoi((condition).c_str());
                g.addEdge(source, destination, D, C);
            }
            cout << "\n\n";

            cout << "-----THE LIST OF CITIES THAT THE AGENCY MANAGES ARE------";
            cout << endl;
            cout << endl;
            cout << endl;
            g.print();
            g.fn();

            cout << "Do you want to continue ? (Yes==1/N0==0)";
            cin >> endp;

            fileo.close();
        }

    }

    return 0;
}
