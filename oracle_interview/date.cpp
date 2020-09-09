#include<bits/stdc++.h>
using namespace std;
string abc(string str,int n){
	
	vector<int> months({31,28,31,30,31,30,31,31,30,31,30,31});
	map<string,int> names({{"Jan",0},{"Feb",1},{"Mar",2},{"Apr",3},{"May",4},{"Jun",5},{"Jul",6},{"Aug",7},{"Sep",8},{"Oct",9},{"Nov",10},{"Dec",11}});
	vector<string> name({"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"});
	int date = int(str.substr(0,2));
	
	string month = str.substr(3,6);
	
	int year = int(str.substr(7));
	
	int days = n;
	int cur_month = names[month];
	int cur_date = date;
	int cur_year = year;
	while(days>0){
		if(days >= (months[cur_month]-cur_date)){
			int temp_days = months[cur_month];
			if(cur_year%4==0 && cur_month==1 && cur_year%400!=0)temp_days = 29; 
			days -= (temp_days-cur_date);
		}
		else 
			{
			cur_date += days;
			if(days>10)
			return cur_date + "-" + name[cur_month]  + "-"  + cur_year;
			else
			return "0" +  cur_date + "-" + name[cur_month]  + "-" +cur_year;
			}
			
		cur_date = 0;
		cur_month++;
		if(cur_month>11){
			cur_year++;
			cur_month = 0;
		}
		
	}
	
}
