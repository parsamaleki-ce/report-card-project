#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
struct sabt
{
string name;
string lastname;
int shomare;
string reshte;
string lessonname[10];
int vahed[10];
double nomre[10];
double moadel=0;
int tedaddars;
}s;
sabt read()
{
sabt s;
cout<<"enter name:";cin>>s.name;
cout<<"enter family:";cin>>s.lastname;
cout<<"enter number of student courses:";cin>>s.tedaddars;
cout<<"enter student id:";cin>>s.shomare;
cout<<"enter field:";cin>>s.reshte;
int sum=0;
int jamevahed=0;
for(int i=0;i<s.tedaddars;i++)
   {
     cout<<"enter lesson name:";cin>>s.lessonname[i];
     cout<<"enter number of units:";cin>>s.vahed[i];
     cout<<"enter nomre:";cin>>s.nomre[i];
        sum+=s.vahed[i]*s.nomre[i];
        jamevahed+=s.vahed[i];
   }


 s.moadel = static_cast<double>(sum) / jamevahed;
 return s;
}


void bubblesort(sabt s[], int n)
{ 
    for (int i=0;i<n-1;i++)
    {for (int j=0;j<n-i-1;j++)
     { if (s[j].moadel<s[j+1].moadel)
        {   sabt temp =s[j+1];
             s[j+1] =s[j];
             s[j]=temp;
        }
    }
}}


void write1(sabt s)
{
cout<<"-----------------------------------------------------------------------------"<<endl;

cout<<s.name<<s.lastname<<"   "<<s.shomare<<"   "<<s.reshte<<"   "<<fixed << setprecision(2) << s.moadel;

cout<<endl;

}

void write2(sabt s,string p)
{

int k=s.reshte.find(p);
if(k!=-1)

{cout<<s.name<<" "<<s.lastname<<"    "<<s.shomare<<"    "<<s.reshte<<"    "<<fixed << setprecision(2) << s.moadel;

cout<<endl;
}
}

void write3(sabt s,int p)
{cout<<"-----------------------------------------------------------------------------"<<endl;
if(p==s.shomare)
{
cout<<s.name<<" "<<s.lastname<<"    "<<s.shomare<<"    "<<s.reshte<<"    "<<fixed << setprecision(2) << s.moadel;
cout<<endl;
}
}

void write4(sabt s,string p)
{

int k=s.name.find(p);
if(k!=-1)
{cout<<"-----------------------------------------------------------------------------"<<endl;
cout<<s.name<<" "<<s.lastname<<"    "<<s.shomare<<"    "<<s.reshte<<"    "<<fixed << setprecision(2) << s.moadel;
cout<<endl;
}

}

void karname(sabt s,int p,string name,string family,int tedaddaneshju)
{
if(p==s.shomare && name==s.name && family==s.lastname )
{cout<<"-----------------------------------------------------------------------------"<<endl;
cout<<"First name:"<<s.name<<"\t"<<"Last name:"<<s.lastname<<"\t"<<"student number:"
<<s.shomare<<endl;
cout<<"major:"<<s.reshte<<"          "<<"grade point average:"<<s.moadel<<endl;
cout<<"-----------------------------------------------------------------------------"<<endl;
cout<<"Lessons"<<"    "<<"Number of Unit"<<"      "<<"score"<<endl;
    for(int i=0;i<s.tedaddars;i++)
    { cout<<s.lessonname[i]<<"\t"<<"\t"<<s.vahed[i]<<"\t"<<"\t"<<s.nomre[i]<<endl;
    
    }
}
}
void deletee(sabt s[], int &tedaddaneshju, int p)
{
for(int i=0;i<tedaddaneshju;i++)
{
if(s[i].shomare==p)
{
  for(int j=i; j<tedaddaneshju-1;j++)
  {
    s[j] = s[j + 1];
  }
tedaddaneshju--; 
cout<<"Student with ID"<< p <<"has been deleted." <<endl;
return;
}
}
 cout <<"Student with ID "<<p<<" not found."<<endl;
}
void edit(sabt &s,int p)
{
  if(p==s.shomare)
  {
    cout << "Editing student information:" << endl;
    cout << "Current name: " << s.name << endl;
    cout << "Enter new name: "; cin >> s.name;
    cout << "Current family: " << s.lastname << endl;
    cout << "Enter new family: "; cin >> s.lastname;
    cout << "Current field: " << s.reshte << endl;
    cout << "Enter new field: "; cin >> s.reshte;
    cout << "Enter number of courses: "; cin >> s.tedaddars;
    
    int sum = 0;
    int jamevahed = 0;
    for(int i = 0; i < s.tedaddars; i++)
    {
        cout << "Enter lesson name: "; cin >> s.lessonname[i];
        cout << "Enter number of units: "; cin >> s.vahed[i];
        cout << "Enter nomre: "; cin >> s.nomre[i];
        sum += s.vahed[i] * s.nomre[i];
        jamevahed += s.vahed[i];
    }
    s.moadel = static_cast<double>(sum) / jamevahed;
}

}

int main()
{

int tedaddaneshju;
cout<<"enter number of student:";
int a;
cin>>tedaddaneshju;
sabt s[tedaddaneshju];
for (int i=0;i<tedaddaneshju;i++)
{
 s[i]=read();
}
bubblesort(s,tedaddaneshju);
label_parsa:
cout<<"-----------------------------------------------------------------------------"<<endl;
cout<<"1-add a student information"<<endl;
cout<<"2-search by id"<<endl;
cout<<"3-search by name"<<endl;
cout<<"4-list student"<<endl;
cout<<"5-show report card"<<endl;
cout<<"6-edit information of student"<<endl;
cout<<"7-delete student"<<endl;
cout<<"8-exit"<<endl;
cout<<"enter your choice:";
int c;
cin>>c;
if(c==4)
{cout<<"1-list by major"<<endl;
 cout<<"2-list by grade point average"<<endl;
  int w;
  cin>>w;
    if(w==1)
    {string p;
      cout<<"enter your desired major:";
        cin>>p;
        for (int i=0;i<tedaddaneshju;i++)
        write2(s[i],p);
    }
  else if(w==2)
  {
  for (int i=0;i<tedaddaneshju;i++)
    {
      write1(s[i]);
    }
  }


}
else if(c==2)
{int x;
cout<<"enter student number:";
cin>>x;
for (int i=0;i<tedaddaneshju;i++)
{
write3(s[i],x);
}

}
else if(c==3)
{string x;
cout<<"enter student name:";
cin>>x;
for (int i=0;i<tedaddaneshju;i++)
{
write4(s[i],x);
}

}
else if(c==5)
{string name;
string family;
int id;
cout<<"enter student name:";cin>>name;
cout<<"enter student lastname:";cin>>family;
cout<<"enter student id:";cin>>id;
for (int i=0;i<tedaddaneshju;i++)
karname(s[i],id,name,family,tedaddaneshju);

}
else if(c==6)
{
cout<<"enter student id you want to edit:";
int id;
cin>>id;
for(int i=0;i<tedaddaneshju;i++)
edit(s[i],id);

}
if(c==7)
{
int id;
cout<<"Enter student ID to delete:";
cin>>id;
deletee(s,tedaddaneshju,id);

}
if(c==8)
exit(0);
goto label_parsa;


}