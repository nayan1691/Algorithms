#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct suffix
{
	int index; //Store Index
	int rank[2]; //Rank and next rank of pair
};
int cmp(struct suffix a,struct suffix b)
{
	if(a.rank[0]==b.rank[0])
	{
	if(a.rank[1]<b.rank[1])
	return 1;
	else 
	return 0;
	}
	else if(a.rank[0]<b.rank[0])
	return 1;
	else 
	return 0;
}

int* buildsuffixArray(char text[],int n)
{
	struct suffix suffixes[n];
	
	for(int i=0;i<n;i++)
	{
		suffixes[i].index=i; //Indexing
		suffixes[i].rank[0]=text[i]-'a'; //Storing 1st rank
		if((i+1)<n)
		suffixes[i].rank[1]=text[i+1]-'a'; //Storing 2nd rank
		else
		suffixes[i].rank[1]=-1;
	}
	// Sort the suffixes using the comparison function
	sort(suffixes,suffixes+n,cmp);
	// At his point, all suffixes are sorted according to first
    // 2 characters.  Let us sort suffixes according to first 4
    // characters, then first 8 and so on
    int ind[n];  // This array is needed to get the index in suffixes[]
                 // from original index.  This mapping is needed to get
                 // next suffix.
	
	for(int k=4;k<2*n;k=2*k)
	{
		int rank=0; //Intial values
		int prev_rank=suffixes[0].rank[0];
		suffixes[0].rank[0]=rank;
		ind[suffixes[0].index]=0;
		
		for(int i=1;i<n;i++)
		{ // If first rank and next ranks are same as that of previous
            // suffix in array, assign the same new rank to this suffix
			if(suffixes[i].rank[0]==prev_rank && suffixes[i-1].rank[1]==suffixes[i].rank[1])
			{
				prev_rank=suffixes[i].rank[0];
				suffixes[i].rank[0]=rank;
			}
			else
			{
				prev_rank=suffixes[i].rank[0];
				suffixes[i].rank[0]=++rank;	
			}
			ind[suffixes[i].index]=i;
		}
		// Assign next rank to every suffix
		for(int i=0;i<n;i++)
		{
			int next_index=suffixes[i].index+k/2;
			if(next_index<n)
			// suffixes[ind[next_index]].rank[0] This tracks down old ranks
			// and sets new rank accordingly
			suffixes[i].rank[1]=suffixes[ind[next_index]].rank[0];
			else
			suffixes[i].rank[1]=-1;
		}
		sort(suffixes, suffixes+n, cmp);
	}
	int *suffixarr = new int[n];
	for(int i=0;i<n;i++){
	suffixarr[i]=suffixes[i].index;
	}
	return suffixarr;
}
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
// Driver program to test above functions
int main()
{
    char txt[] = "banana";
    int n = strlen(txt);
    int *suffixArr = buildsuffixArray(txt,  n);
    cout << "Following is suffix array for " << txt << endl;
    printArr(suffixArr, n);
    return 0;
}
