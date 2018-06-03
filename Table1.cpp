#include<iostream>
#include<string.h>
using namespace std;

class Cell
{
    public:
    	Cell(){
		}
        Cell(char con[]);
//        ~Cell();

        void show();
    private:
        string content;
};

Cell::Cell(char con[])
{
	int i=0;
	while(con[i]!='\0')
	content[i]=con[i];
}

void Cell::show()
{
	int len;
	len=content.size();
	for(int k=0;k<len;k++)
	cout<<content[k];
	for(int k=0;k<14-len;k++)
	cout<<' ';
}

class Table
{
    public:
    	Table();
		Table(int row,int col)
		{
			a=row;
			b=col;
			for(int i=0;i<10;i++)
        	for(int j=0;j<10;j++)
        	concept[i][j]=1;
        	for(int i=0;i<15;i++)
        	words[i]='\0';
		}
		void show();  
    	void set(int i,int j,int k);
	    void set(int i,int j,char str[]);
        int addRow();
        void delRow(int n);
        int addColumn();
        void delColumn(int n);
    private:
        Cell cells;
        int a,b;
		int concept[10][10];
		int c;
		char words[15];
};

Table::Table()
{
	a=2;
	b=2;
	for(int i=0;i<10;i++)
	for(int j=0;j<10;j++)
	concept[i][j]=1;
}

void Table::show()
{
	if(a<=0 || b<=0) cout<<"无法制成表格"; 
	else
	{
		int i,j;
		for(i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			for(int k=0;k<15;k++)
			cout<<'_';
			cout<<'_'<<endl;
			for(j=0;j<b;j++)
			{
				cout<<'*';
				if(concept[i][j]==1)
				for(int k=0;k<14;k++)
				cout<<' ';                                                        
				else if(concept[i][j]==3)
				{
					int len;
					len=strlen(words);
					Cell cell(words);
					cell.show();
				}
				else
				{
					int count=0;
					cout<<c;
					int obj=c;
					while(obj/10!=0)
					{
						count++;
						obj=obj/10;
					}				
					for(int k=0;k<14-count-1;k++)
					cout<<' ';
				}
			}
			cout<<'*'<<endl;
		}
		for(j=0;j<b;j++)
		for(int k=0;k<15;k++)
		cout<<'_';
		cout<<'_'<<endl;
		cout<<endl<<endl;
	} 
}

int Table::addRow()  {a++;return 0;}
int Table::addColumn()  {b++;return 0;}
void Table::delRow(int n)
{
	if(n>a) cout<<"显示行数过小";
	else a-=n;
}
void Table::delColumn(int n)
{
	if(n>b) cout<<"显示列数过小";
	else b-=n;
}

void Table::set(int i,int j,int k)
{
	concept[i-1][j-1]=2;
	c=k;
}

void Table::set(int i,int j,char str[])
{
	concept[i-1][j-1]=3;
	if(strlen(str)<=14)
	for(i=0;i<strlen(str);i++)
	words[i]=str[i];
	else
	for(i=0;i<14;i++)
	words[i]=str[i];
}

int main()
{
	char str[15]="\0";
    Table tb;
    tb.show();
    tb.addRow();
    tb.show();
    tb.addColumn();
    tb.show();
    Table tb1(5,5);
    tb1.show();
    tb1.set(1,1,30);
    tb1.set(2,2,"hello");
    tb1.show();
    tb1.delRow(1);
    tb1.show();
    tb1.delColumn(1);
    tb1.show();
    return 0;
}
