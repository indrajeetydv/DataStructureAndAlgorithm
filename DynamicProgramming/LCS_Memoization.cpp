#include<bits/stdc++.h>
using namespace std;

#define MAX 10
// lookup[i][j] stores the length of LCS of substring X[0..i-1], Y[0..j-1]
int L[MAX][MAX];

// Function to return all LCS of substrings X[0..m-1], Y[0..n-1]
vector<string> LCS(string X, string Y, int m, int n)
{
	// if we have reached the end of either sequence
	if (m == 0 || n == 0)
	{
		// create a vector with 1 empty string and return
		vector<string> v(1);
		return v;
	}

	// if last character of X and Y matches
	if (X[m - 1] == Y[n - 1])
	{
		// ignore last characters of X and Y and find all LCS of substring
		// X[0..m-2], Y[0..n-2] and store it in a vector
		vector<string> lcs1 = LCS(X, Y, m - 1, n - 1);

		// append current character X[m - 1] or Y[n - 1] to all LCS of
		// substring X[0..m-2] and Y[0..n-2]
		for (string &str : lcs1)		// don't remove &
			str.push_back(X[m - 1]);

		return lcs1;
	}

	// we reach here when the last character of X and Y don't match

	// if top cell of current cell has more value than the left cell,
	// then ignore current character of string X and find all LCS of
	// substring X[0..m-2], Y[0..n-1]

	if (L[m - 1][n] > L[m][n - 1])
		return LCS(X, Y, m - 1, n);

	// if left cell of current cell has more value than the top cell,
	// then ignore current character of string Y and find all LCS of
	// substring X[0..m-1], Y[0..n-2]

	if (L[m][n - 1] > L[m - 1][n])
		return LCS(X, Y, m, n - 1);

	// if top cell has equal value to the left cell, then consider
	// both characters

	vector<string> top = LCS(X, Y, m - 1, n);
	vector<string> left = LCS(X, Y, m, n - 1);

	// merge two vectors and return
	top.insert(top.end(), left.begin(), left.end());
	// copy(left.begin(), left.end(), back_inserter(top));

	return top;
}

int LCSLength(string X,string Y,int m,int n){
	
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0)
			  L[i][j]=0;	
			else if(X[i-1]==Y[j-1])
			   L[i][j]=L[i-1][j-1]+1;
			else
			   L[i][j]=max(L[i-1][j],L[i][j-1]);
		}
	}	
	return L[m][n];
}

set<string> LCS(string X,string Y){
	int m=X.length(), n=Y.length();
	
	//fill lookup table
	cout<<"LCS Length: "<<LCSLength(X,Y,m,n)<<"\n"<<endl;
	
	//find all the longest common subsequence
	vector<string> v=LCS(X,Y,m,n);
	
	
   	 
	//convert vector to set
	set<string> lcs(make_move_iterator(v.begin()),make_move_iterator(v.end()));
	
	return lcs;
	
}

int main(){
	//string s1="stone" , s2="longest";
	
	//string s1 = "ABCBDAB", s2 = "BDCABA";
	
	 string s1 = "abaaba", s2 = "babbab";
	
   set<string> lcsSet=LCS(s1,s2);
   
   cout<<"LCS value:\n"<<endl;
   
   for(string s:lcsSet)
   	 cout<<s<<"\t"<<endl;
   	 
  return 0;
}
