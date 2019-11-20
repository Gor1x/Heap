#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <bitset>
#include <map>
#include <ctime>
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define int ll

const int INF = 1e9 + 7;
const int N = 300;

struct Heap
{
	void add(int x) 
	{
		size++;
		arr[size] = x;
		placeOf[arr[size]] = size;
		heapifyUp(size);
	}


	int getMin() const
	{
		return arr[1];
	}

	

	void deleteMin()
	{
		swapping(size, 1);
		size--;
		heapifyDown(1);
	}

	void erase(int x)
	{
		int pos = placeOf[x];
		swapping(pos, size);
		size--;
		heapifyUp(pos);
		heapifyDown(pos);
	}

	void print(int v = 1, int lvl = 0)
	{
		if (v > size)
			return;
		print(v * 2 + 1, lvl + 1);
		cout << string(lvl, '=') << arr[v] << endl;
		print(v * 2, lvl + 1);
		if (lvl == 0)
			cout << endl;
	}

	vector<int> getHeapSort()
	{
		int prevSize = size;
		while (size != 0)
			deleteMin();

		vector <int> ans;
		ans.reserve(prevSize + 3);
		for (int i = 1; i <= prevSize; i++)
		{
			ans.push_back(arr[i]);
		}
		return ans;
	}

private:

	void heapifyUp(int v)
	{
		while (v > 1 && arr[v] < arr[v / 2])
		{
			swapping(v, v / 2);
			v /= 2;
		}
	}

	void swapping(int a, int b)
	{
		swap(placeOf[arr[b]], placeOf[arr[a]]);
		swap(arr[a], arr[b]);
	}


	void heapifyDown(int v)
	{
		int mini = v;
		int left = v * 2;
		int right = v * 2 + 1;

		if (left <= size && arr[left] < arr[mini])
			mini = left;

		if (right <= size && arr[right] < arr[mini])
			mini = right;

		if (v != mini)
		{
			swapping(v, mini);
			heapifyDown(mini);
		}
	}

	int arr[N];
	int size = 0;
	int placeOf[N] = { 0 };
};

signed main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	Heap a;
	a.add(7);
	a.add(3);
	a.add(6);
	a.add(228);

	auto ans = a.getHeapSort();

	for (auto v : ans)
		cout << v << " ";

	return 0;
}

