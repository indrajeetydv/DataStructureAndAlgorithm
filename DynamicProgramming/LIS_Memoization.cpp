#include <bits/stdc++.h>

using namespace std;

void findLIS(int arr[], int n)
{
	vector<int> LIS[n];

	// LIS[0] denotes longest increasing subsequence ending with arr[0]
	LIS[0].push_back(arr[0]);

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && LIS[j].size() > LIS[i].size())
				LIS[i] = LIS[j];
		}
		// include arr[i] in LIS[i]
		LIS[i].push_back(arr[i]);
	}
	
	//for testing purpose
	for (int i = 0; i < n; i++)
	{
		cout << "LIS[" << i << "] - ";
		for (int j : LIS[i])
			cout << j << " ";
		cout << endl;
	}

	// j will contain index of LIS
	cout<<"\n\n";
	int j;
	for (int i = 0; i < n; i++)     {
			
			cout << "LIS["<< i <<"i].size() " << LIS[i].size()<< "\n";
			cout << "LIS["<< j <<"j].size() " << LIS[j].size()<< "\n\n";
			if (LIS[j].size() < LIS[i].size())
				j = i;
	}

	 cout << "\nj: " << j<<" LIS[j]:"<<LIS[j].size() << "\n\n";
	// print LIS
	for (int i : LIS[j])
		cout << i << " ";
}

// main function
int main()
{
	int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
	int n = sizeof(arr)/sizeof(arr[0]);

	findLIS(arr, n);

	return 0;
}
