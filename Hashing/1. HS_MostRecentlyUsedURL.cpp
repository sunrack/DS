/*
Given a list of URLs entered by a user write a program to print unique and most recently used URLs. For example if user entered the following: - 
1. google.com 
2. yahoo.com 
3. wsj.com 
4. google.com 

The output should be :- 
1. google.com 
2. wsj.com 
3.yahoo.com
*/

#include <list>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

list<string> urlList;
unordered_map<string, list<string>::iterator> checkMap;

void visit(const string &url)
{
	unordered_map<string, list<string>::iterator>::iterator it = checkMap.find(url);

	if(it != checkMap.end())
	{
		urlList.erase(it->second);
	}

	checkMap[url] = urlList.insert(urlList.end(), url);
}

void printHistory()
{
	for(list<string>::reverse_iterator it = urlList.rbegin(); it != urlList.rend();++it)
	{
		cout<<*it<<endl;
	}
}

int main()
{
	visit("google.com");
	visit("yahoo.com");
	visit("wsj.com");
	visit("google.com");

	printHistory();
}