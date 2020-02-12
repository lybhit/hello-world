#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector<int>> seg_set;
	cout << seg_set.size() << endl;
	vector<int> a = {1,2,3,4,5,8,9,12,15,16,17,22,23,29,30};
	int pre_pp = a[0];
	vector<int> temp;
	for(int i = 1; i < a.size(); ++i)
	{
		if(a[i] - pre_pp <= 1)
		{
			temp.push_back(a[i]);
		}
		else
		{
			if(temp.size() > 0)
			{
				seg_set.push_back(temp);
				temp.clear();
			} 
				temp.clear();
		}
			pre_pp = a[i];
        }
		cout << "ok" << seg_set[0].size() << endl;

		for(int j = 0; j < seg_set.size(); ++j)
		{
			for(int k = 0; k < seg_set[j].size(); ++k)
			{
				cout << seg_set[j][k] << ' ';
			}
			cout << endl;
		}
		return 0; 
	}
