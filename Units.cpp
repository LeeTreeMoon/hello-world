//单位转换程序，输入值和原单位，新单位，返回新单位下的值。
//重量单位：Kg, g, lb, gr,......
//压力单位：Pa, MPa, psi,......
//长度单位：m, km, ft, in,......
//其它单位：md, cp,......
//还有很多单位转换，有些单位是其它单位组合出来的
#include<iostream> 
#include<vector>
using namespace std;

class Unit
{
	public:
		virtual void trans(double)=0;
		virtual bool find(string,string)=0;
};

class Base:public Unit
{
	private:
		int mark,now,next;
		vector<string> length_name;
		vector<double> length_mul;
		vector<string> time_name;
		vector<double> time_mul;
		vector<string> quality_name;
		vector<double> quality_mul;
		vector<string> temperature_name;
		vector<double> temperature_mul;
		
	public:
		Base()
		{
			mark=0;
			now=next=100;
			length_name.push_back("in"); length_name.push_back("ft"); length_name.push_back("yd"); length_name.push_back("sm");
			length_name.push_back("mm"); length_name.push_back("cm"); length_name.push_back("km"); length_name.push_back("m");
			length_name.push_back("nm"); 
			
			length_mul.push_back(0.0254); length_mul.push_back(0.3048); length_mul.push_back(0.9144); length_mul.push_back(1852);
			length_mul.push_back(0.001); length_mul.push_back(0.01);   length_mul.push_back(1000);   length_mul.push_back(1);
			length_mul.push_back(0.000000001);
			
			time_name.push_back("ms"); time_name.push_back("s"); time_name.push_back("min"); time_name.push_back("h"); time_name.push_back("d");
			time_mul.push_back(1.0/60); time_mul.push_back(1); time_mul.push_back(60); time_mul.push_back(3600);time_mul.push_back(216000) ;
			
			quality_name.push_back("g"); quality_name.push_back("t"); quality_name.push_back("dwt"); quality_name.push_back("cwt");
			quality_name.push_back("oz"); quality_name.push_back("kg"); quality_name.push_back("mg"); quality_name.push_back("lb");
			quality_name.push_back("dr");
			
			quality_mul.push_back(1); quality_mul.push_back(0.000001); quality_mul.push_back(1.5551738); quality_mul.push_back(50802.3454400);
			quality_mul.push_back(28.3495231); quality_mul.push_back(0.001); quality_mul.push_back(1000); quality_mul.push_back(453.59237);
			quality_mul.push_back(1.7718452);
			
			temperature_name.push_back("摄氏度(℃)"); temperature_name.push_back("华氏度(℉)"); temperature_name.push_back("开氏度(K)");
            temperature_name.push_back("列氏度(°Re)"); temperature_name.push_back("兰氏度(°R)");

            temperature_mul.push_back(1); temperature_mul.push_back(33.8); temperature_mul.push_back(274.15);
            temperature_mul.push_back(0.8); temperature_mul.push_back(493.47);			
		}
		virtual bool find(string str1,string str2)
		{
			vector<string>::iterator it1,it2;
			for(it1=length_name.begin();it1!=length_name.end();it1++)
			{
				if(str1==*it1)
				{
					for(it2=length_name.begin();it2!=length_name.end();it2++)
					{
						if(str2==*it2)
						{
							mark=1;
							now=it1-length_name.begin();
							next=it2-length_name.begin();
//							cout<<now<<" " <<next<<endl;
							return true;
						}
					}
				}
			}
			for(it1=time_name.begin();it1!=time_name.end();it1++)
			{
				if(str1==*it1)
				{
					for(it2=time_name.begin();it2!=time_name.end();it2++)
					{
						if(str2==*it2)
						{
							mark=2;
							now=it1-time_name.begin();
							next=it2-time_name.begin();
//							cout<<now<<" " <<next<<endl;
							return true;
						}
					}
				}
			}
			for(it1=quality_name.begin();it1!=quality_name.end();it1++)
			{
				if(str1==*it1)
				{
					for(it2=quality_name.begin();it2!=quality_name.end();it2++)
					{
						if(str2==*it2)
						{
							mark=3;
							now=it1-quality_name.begin();
							next=it2-quality_name.begin();
//							cout<<now<<" " <<next<<endl;
							return true;
						}
					}
				}
			}
			for(it1=temperature_name.begin();it1!=temperature_name.end();it1++)
			{
				if(str1==*it1)
				{
					for(it2=temperature_name.begin();it2!=temperature_name.end();it2++)
					{
						if(str2==*it2)
						{
							mark=4;
							now=it1-temperature_name.begin();
							next=it2-temperature_name.begin();
//							cout<<now<<" " <<next<<endl;
							return true;
						}
					}
				}
			}
			if(!mark) return false;
		}
		
		virtual void trans(double num)
		{
			if(now==next)
			{
				cout<<num;
				return;
			}
			vector<double>::iterator it1,it2;
			switch(mark)
			{
				case 1:it1=now+length_mul.begin();it2=next+length_mul.begin();cout<<"换算结果："<<num*(*it1)/(*it2)<<endl<<endl; break;
				case 2:it1=now+time_mul.begin();it2=next+time_mul.begin();cout<<"换算结果："<<num*(*it1)/(*it2)<<endl<<endl; break;
				case 3:it1=now+quality_mul.begin();it2=next+quality_mul.begin();cout<<"换算结果："<<num*(*it1)/(*it2)<<endl<<endl; break;
				case 4:it1=now+temperature_mul.begin();it2=next+temperature_mul.begin();cout<<"换算结果："<<num*(*it2)/(*it1)<<endl<<endl; break;
			}
		}
};

class Mix:public Unit
{
	private:
		int mark,now,next;
	    vector<string> area_name;
	    vector<double> area_mul;
	    vector<string> power_name;
	    vector<double> power_mul;
	    vector<string> pressure_name;
	    vector<double> pressure_mul;
	    vector<string> volume_name;
	    vector<double> volume_mul;
	    vector<string> velocity_name;
	    vector<double> velocity_mul;
	public:
		Mix()
		{
			mark=0;
			now=next=100;
			area_name.push_back("ha"); area_name.push_back("m2"); area_name.push_back("cm2"); area_name.push_back("sq_mi");
			area_name.push_back("sq_rd"); area_name.push_back("sq_ft"); area_name.push_back("sq_in"); area_name.push_back("sq_yd");
			area_name.push_back("mm2"); area_name.push_back("km2");
			
			area_mul.push_back(10000); area_mul.push_back(1); area_mul.push_back(0.0001); area_mul.push_back(2589988.1);
			area_mul.push_back(25.292853); area_mul.push_back(0.09290304); area_mul.push_back(0.00064516); area_mul.push_back(0.83612736);
			area_mul.push_back(1000000) ; area_mul.push_back(0.000001);
			
			power_name.push_back("w"); power_name.push_back("J/s"); power_name.push_back("N.m/s"); 
            power_name.push_back("ps"); power_name.push_back("kcal/s"); power_name.push_back("kw"); 
            power_name.push_back("hp"); power_name.push_back("ft·lb/s"); power_name.push_back("Btu/s"); 
            power_name.push_back("kg.m/s");

            power_mul.push_back(1); power_mul.push_back(1); power_mul.push_back(1); 
            power_mul.push_back(0.0013596); power_mul.push_back(0.000239); power_mul.push_back(0.001); 
            power_mul.push_back(0.001341); power_mul.push_back(0.7375621); power_mul.push_back(0.0009478); 
            power_mul.push_back(0.1019716);
            
            pressure_name.push_back("pa"); pressure_name.push_back("hpa"); pressure_name.push_back("mbar"); 
            pressure_name.push_back("kpa"); pressure_name.push_back("bar"); pressure_name.push_back("MPa"); 
            pressure_name.push_back("mmHg"); pressure_name.push_back("inHg"); pressure_name.push_back("psi"); 
            pressure_name.push_back("atm"); pressure_name.push_back("psf"); pressure_name.push_back("kgf/cm2"); 
            pressure_name.push_back("kgf/m2"); 

            pressure_mul.push_back(1); pressure_mul.push_back(0.01); pressure_mul.push_back(0.01); 
            pressure_mul.push_back(0.001); pressure_mul.push_back(0.00001); 
            pressure_mul.push_back(0.000001); pressure_mul.push_back(0.0075006); 
            pressure_mul.push_back(0.0002953); pressure_mul.push_back(0.000145); pressure_mul.push_back(0.0000098692); 
            pressure_mul.push_back(0.0208854); pressure_mul.push_back(0.0000102); pressure_mul.push_back(0.1019716); 
            
            volume_name.push_back("m3"); volume_name.push_back("l"); volume_name.push_back("ml"); 
            volume_name.push_back("cm3"); volume_name.push_back("dm3"); volume_name.push_back("dl"); 
            volume_name.push_back("cl"); volume_name.push_back("hl"); volume_name.push_back("ul"); 
            volume_name.push_back("mm3"); volume_name.push_back("cu_in"); volume_name.push_back("cu_yd"); 
            volume_name.push_back("cu_ft"); volume_name.push_back("uk_gal"); volume_name.push_back("us_gal"); 
            volume_name.push_back("uk_loz"); volume_name.push_back("us_loz"); 

            volume_mul.push_back(1); volume_mul.push_back(1000); volume_mul.push_back(1000000); 
            volume_mul.push_back(1000000); volume_mul.push_back(1000); volume_mul.push_back(10000); 
            volume_mul.push_back(100000); volume_mul.push_back(10); volume_mul.push_back(1000000000); 
            volume_mul.push_back(1000000000); volume_mul.push_back(61023.8445022); volume_mul.push_back(1.3079528); 
            volume_mul.push_back(35.3147248); volume_mul.push_back(219.9691573); volume_mul.push_back(264.1720524); 
            volume_mul.push_back(35198.873636); volume_mul.push_back(34164.6737274); 
            
            velocity_name.push_back("m/s"); velocity_name.push_back("km/h"); velocity_name.push_back("km/s");
            velocity_name.push_back("mach"); velocity_name.push_back("in/s"); velocity_name.push_back("c"); 
            velocity_name.push_back("mile/h"); 

            velocity_mul.push_back(1); velocity_mul.push_back(3.6); velocity_mul.push_back(0.001); 
            velocity_mul.push_back(0.0029386); velocity_mul.push_back(39.370079); velocity_mul.push_back(0.0000000033356); 
            velocity_mul.push_back(2.236936); 
		}
		
		virtual bool find(string str1,string str2)
		{
			vector<string>::iterator it1,it2;
			for(it1=area_name.begin();it1!=area_name.end();it1++)
			{
				if(str1==*it1)
				{
					for(it2=area_name.begin();it2!=area_name.end();it2++)
					{
						if(str2==*it2)
						{
							mark=1;
							now=it1-area_name.begin();
							next=it2-area_name.begin();
//							cout<<now<<" " <<next<<endl;
							return true;
						}
					}
				}
			}
			for(it1=power_name.begin();it1!=power_name.end();it1++)
			{
				if(str1==*it1)
				{
					for(it2=power_name.begin();it2!=power_name.end();it2++)
					{
						if(str2==*it2)
						{
							mark=2;
							now=it1-power_name.begin();
							next=it2-power_name.begin();
//							cout<<now<<" " <<next<<endl;
							return true;
						}
					}
				}
			}
			for(it1=pressure_name.begin();it1!=pressure_name.end();it1++)
			{
				if(str1==*it1)
				{
					for(it2=pressure_name.begin();it2!=pressure_name.end();it2++)
					{
						if(str2==*it2)
						{
							mark=3;
							now=it1-pressure_name.begin();
							next=it2-pressure_name.begin();
//							cout<<now<<" " <<next<<endl;
							return true;
						}
					}
				}
			}
			for(it1=volume_name.begin();it1!=volume_name.end();it1++)
			{
				if(str1==*it1)
				{
					for(it2=volume_name.begin();it2!=volume_name.end();it2++)
					{
						if(str2==*it2)
						{
							mark=4;
							now=it1-volume_name.begin();
							next=it2-volume_name.begin();
//							cout<<now<<" " <<next<<endl;
							return true;
						}
					}
				}
			}
			for(it1=velocity_name.begin();it1!=velocity_name.end();it1++)
			{
				if(str1==*it1)
				{
					for(it2=velocity_name.begin();it2!=velocity_name.end();it2++)
					{
						if(str2==*it2)
						{
							mark=5;
							now=it1-velocity_name.begin();
							next=it2-velocity_name.begin();
//							cout<<now<<" " <<next<<endl;
							return true;
						}
					}
				}
			}
			if(!mark) return false;
		}
		virtual void trans(double num)
		{
			if(now==next)
			{
				cout<<num;
				return;
			}
			vector<double>::iterator it1,it2;
			switch(mark)
			{
				case 1:it1=now+area_mul.begin();it2=next+area_mul.begin();cout<<"换算结果："<<num*(*it1)/(*it2)<<endl<<endl; break;
				case 2:it1=now+power_mul.begin();it2=next+power_mul.begin();cout<<"换算结果："<<num*(*it2)/(*it1)<<endl<<endl; break;
				case 3:it1=now+pressure_mul.begin();it2=next+pressure_mul.begin();cout<<"换算结果："<<num*(*it2)/(*it1)<<endl<<endl; break;
				case 4:it1=now+volume_mul.begin();it2=next+volume_mul.begin();cout<<"换算结果："<<num*(*it2)/(*it1)<<endl<<endl; break;
				case 5:it1=now+velocity_mul.begin();it2=next+velocity_mul.begin();cout<<"换算结果："<<num*(*it2)/(*it1)<<endl<<endl; break;
			}
		}
};

int main()
{
	bool win;
	double num;
	string origin,end;
	cout<<"请输入正确的数字与单位，所有单位用相应的英文缩写表示，单位内部不允许有空格，若需空格请用下划线连接"<<endl; 
	while(cin>>num>>origin>>end)
	{
    	Base obj1;
    	win=obj1.find(origin,end);
    	if(win)
    	obj1.trans(num);
	    else
	    {
		    Mix obj2;
		    win=obj2.find(origin,end);
		    if(!win) cout<<"Error";
		    else obj2.trans(num);
	    }
	}
	return 0;
}
