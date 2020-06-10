
/*
 
   Code wrtiien as a solution for a hackerank problem
	This code solves the parser for a language HRML
   Author- Tarun Sharma
 
*/

#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<unistd.h>
#include<string.h>

using namespace std;

class HRML{

	string tag,attribute,value,query="";
	string tag_old;
	map<string,string>mp;
	vector<string>vc;
	public:
	
	void fun_data(string &); 
	void mp_print();
	void query_data(int);



};

void HRML :: fun_data(string &strm){
	
	// this function will separate the tag,attibute and value 
	
	strm	= strm.substr(1);
	size_t pos  = strm.find('>');
	strm = strm.substr(0,pos); 
      
	
        //separate tag, attribute and values 
	if(strm[0]!='/'){
		
		bool tag_stat = true;
		tag   =  ""; //refresh tag
		value =  ""; //refresh value;

	

		do{
		
		if(tag_stat == true){	
		pos = strm.find(" ");
		//check the o/p of position
		if(pos!=-1)
		tag = strm.substr(0,pos);
		else
			tag = strm.substr(0);
	//	cout<<"tag value is--- "<<tag<<'\n';
		
		}
		
		//attribute
		pos = strm.find(' ');
		if(pos!=-1){
		strm = strm.substr(pos+1);
		pos = strm.find(" ");
		
		attribute = strm.substr(0,pos);
		}		
		
		//value
		pos   = strm.find('"');
		if(pos!=-1){
 		strm  = strm.substr(pos+1);
		pos   = strm.find('"');
		value = strm.substr(0,pos);
		strm  = strm.substr(pos+1);
		}


			if(strm.find(' ')!= -1){
			tag_stat =  false;
		}


		//create a query and add in the map<query,value>
		if(query=="" || tag_old == ""){
			query = tag + "~" + attribute;
			mp[query] = value;
			tag_old = tag;	
		}
		else{
			if(tag_old.find(tag)!=-1){
				query = tag_old + "~" + attribute;
				mp[query] = value;

			}
				
			else{
				if(value!=""){
			query = tag_old + "." + tag + "~" + attribute;
			mp[query] = value;
				}
			
			tag_old = tag_old + "." + tag;
			}	
				
			
				
		
		}
		}while(strm.find(' ')!=-1);
		}//if(strm[0]!='/')	

	else{
	
		//remove tag from the /tag
               strm = strm.substr(1);
               pos = query.find(strm);
               if(pos!=0)
               tag_old = query.substr(0,pos-1);
				else
					tag_old = "";


	}


}

//to test the map data

void HRML:: mp_print(){

	map<string,string> :: iterator itr_mp;
	
 	
	//print the data corresponding to the vector query ; search value in the vector
	 vector<string>:: iterator itr_vc;

	 for(itr_vc = vc.begin(),itr_mp = mp.begin(); itr_vc!=vc.end(); itr_vc++ ){
			
		 while(itr_mp!=mp.end()){
			if(itr_mp->first ==*itr_vc )			 
				 break;
			itr_mp++;
	
	 }
	
	if(itr_mp==mp.end())
       		cout<<"Not Found!\n";
	else
		cout<<itr_mp->second<<'\n';	
	
	itr_mp = mp.begin();

}
}

void HRML:: query_data(int q){

	int i =0;
	string strm = "";
	//to print the value based on the query 
	for(;i<q;i++){
	
		getline(cin,strm);
		vc.push_back(strm);

		//search the data in map and see if its there in vector or not:
		
		
		
			
	}
}

int main(){

	HRML obj_;

	int q=0,n=0,i;
	string strm_data ;
	cin>>n>>q;
	
	cin.ignore();

	for(i=0;i<n;i++){
        
	getline(cin,strm_data);
	obj_.fun_data(strm_data);

	}
	//call the map print function to check the map data
	
	obj_.query_data(q);
	obj_.mp_print();

}




