#include <iostream>
#include <cstring>
using namespace std;
int duval(char* str,int len)
{
	int a,b,i=0,j=1,k=0,n;
	n=2*len;
	while(i+k<n && j+k<n)
	{
	if(i+k>=len)
	a=str[i+k-len];
	else
	a=str[i+k];
	if(j+k>=len)
	b=str[j+k-len];
	else
	b=str[j+k];
	
	if(a==b)
	k++;
	else if(a>b)
	{
	i=i+k+1;
	if(i<=j)
	i=j+1;
	k=0;
	}
	else
	{
		j=j+k+1;
		if(j<=i)
		j=i+1;
		k=0;
	}
	
	}
	
	if(i>j)
	return j;
	else
	return i;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int len,a;
		string s;
		cin>>s;
		char txt[10001];
strcpy(txt, s.c_str());
		len=strlen(txt);
		a=duval(txt,len);
		cout<<a+1<<endl;
	}
	return 0;
}
