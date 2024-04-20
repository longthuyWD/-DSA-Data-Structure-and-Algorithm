// [DSA] Sort Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

class CSort
{
public:
	CSort();
	~CSort();
	void SelectSort(vector<int>& vInput)
	{
		// Fix warning when run at x64 (64bit)
		int nSize = (int)vInput.size();
		for (int idx_i = 0; idx_i < nSize - 1; idx_i++)
		{
			int nTempIdx = idx_i;
			for (int idx_j = idx_i + 1; idx_j < nSize; idx_j++)
			{
				if (vInput[idx_j] < vInput[nTempIdx])
					nTempIdx = idx_j;
			}
			if (nTempIdx != idx_i)
			{	// Exchange 2 value
				Exchange(vInput[nTempIdx], vInput[idx_i]);
			}
		}
	}

	void InsertSort(vector<int>& vInput)
	{
		// Fix warning when run at x64 (64bit)
		int nSize = (int)vInput.size();
		// Assumming the first value (its position equal 0)  of vector is negative value.
		vInput.insert(vInput.begin(), -1);
		// Propose that the value at the second position is the newly added value to the vector.
		for (int idx_i = 2; idx_i <= nSize; idx_i++)
		{
			int nTemp = vInput[idx_i];
			int idx_j = idx_i - 1;
			// Select position for new value if new value is minimum.
			// New value is vInput[idx_i]
			// Comparison value is vInput[idx_j]
			while (nTemp < vInput[idx_j])
			{	// If vector has wrong position, move the wrong position value to the following position.
				// Continue array iteration until right position for new value.
				vInput[idx_j + 1] = vInput[idx_j];
				idx_j = idx_j - 1;
			}

			// Set temp value (the newly added) to the right position
			vInput[idx_j + 1] = nTemp;
		}
		// Remove negative value at first position.
		vInput.erase(vInput.begin());
	}

	void BubbleSort(vector<int>& vInput)
	{
		int nSize = (int)vInput.size();
		int nCountExc = 0;
		// Iterate through n-1 times
		for (int idx_i = 0; idx_i < nSize; idx_i++)
		{
			// Iterate from bottom to top
			for (int idx_j = nSize - 1; idx_j > idx_i; idx_j--)
			{
				// If they are wrong potion, exchange two value
				if (vInput[idx_j] < vInput[idx_j - 1])
				{
					Exchange(vInput[idx_j - 1], vInput[idx_j]);
					nCountExc++;
				}
			}
			// All value of vector are at right position
			if (nCountExc == 0)
				break;
		}
	}

	void QuickSort(vector<int>& vInput, int nStart, int nEnd)
	{
		if (nStart < nEnd)
		{
			int nKeyIdx;
			Partition(vInput, nStart, nEnd, nKeyIdx);
			this->QuickSort(vInput, nStart, nKeyIdx - 1);
			this->QuickSort(vInput, nKeyIdx + 1, nEnd);
		}
	}

	// Function devide vector input to 2 part by a key
	// Parameter: vInput is the vector which need to devide
	// nLB is the first index of vector (low bound index)
	// nUB is the last index of vector (upper bound index)
	// nKeyIdx is the true index of key
	// Assume the first value is the key to device vector input
	void Partition(vector<int>& vInput, int nLB, int nUB, int& nKeyIdx)
	{
		//vInput.push_back(9999);
		int nStartIter = nLB;
		int nEndIter = nUB;
		while (nStartIter < nEndIter)
		{
			// Find until having a value larger than key (first value)
			while (vInput[nStartIter] < vInput[nLB])
				nStartIter++;
			// Find until having a value smaller than key 
			while (vInput[nEndIter] > vInput[nLB])
				nEndIter--;
			if (nStartIter < nEndIter)
			{
				// Arrange value to right part compare to key
				Exchange(vInput[nStartIter], vInput[nEndIter]);
				nStartIter++;
				nEndIter--;
			}
		}
		Exchange(vInput[nLB], vInput[nEndIter]);
		// Save true position of key
		nKeyIdx = nEndIter;
	}

	void HeapSort(vector<int>& vInput)
	{
		int nSize = (int)vInput.size();
		for (int idx_i = (int)nSize / 2; idx_i > 0; idx_i++)
			Adjust(vInput, idx_i);
		for (int idx_i = nSize - 1; idx_i > 0; idx_i--)
		{
			//Exchange(vInput[0], vInput[])
		}
	}

	void Adjust(vector<int>& vInput, int rootIdx)
	{

	}

	void Exchange(int& nValue, int& vValueExc)
	{
		int nTemp = nValue;
		nValue = vValueExc;
		vValueExc = nTemp;
	}

	// Show vector
	void PrintVec(vector<int> vInput)
	{
		// Fix warning when run at x64 (64bit)
		int nSize = (int)vInput.size();
		for (auto nValue : vInput)
			cout << nValue << " ";
		cout << endl;
	}

	// Compare two vector input
	bool IsEqual(vector<int> vInputCur, vector<int> vInputCmp)
	{
		int nSizeCur = (int)vInputCur.size();
		int nSizeCmp = (int)vInputCmp.size();

		if (nSizeCur != nSizeCmp)
			return false;

		for (int idx_i = 0; idx_i < nSizeCur; idx_i++)
		{
			if (vInputCur[idx_i] != vInputCmp[idx_i])
				return false;
		}

		return true;
	}

	// Function test 
	// Prevent change value of input
	void Test(const vector<int> vInput)
	{
		CSort cSortAlgTest;
		cout << "Original Vector: ";
		cSortAlgTest.PrintVec(vInput);
		int nSize = (int)vInput.size();

		vector<int> vLibSort = vInput;
		sort(vLibSort.begin(), vLibSort.end());
		cout << "Liblary Sort: ";
		cSortAlgTest.PrintVec(vLibSort);


		vector<int> vInsertSort = vInput;
		cSortAlgTest.InsertSort(vInsertSort);
		cout << "Insert Sort: ";
		cSortAlgTest.PrintVec(vInsertSort);
		if (cSortAlgTest.IsEqual(vLibSort, vInsertSort))
			cout << "Insert Sort PASS" << endl;
		else
			cout << "Insert Sort FAILED" << endl;

		vector<int> vBubbleSort = vInput;
		cSortAlgTest.BubbleSort(vBubbleSort);
		cout << "Bubble Sort: ";
		cSortAlgTest.PrintVec(vBubbleSort);
		if (cSortAlgTest.IsEqual(vLibSort, vBubbleSort))
			cout << "Bubble Sort PASS" << endl;
		else
			cout << "Bubble Sort FAILED" << endl;

		vector<int> vSelectSort = vInput;
		cSortAlgTest.SelectSort(vSelectSort);
		cout << "Select Sort: ";
		cSortAlgTest.PrintVec(vSelectSort);
		if (cSortAlgTest.IsEqual(vLibSort, vSelectSort))
			cout << "Select Sort PASS" << endl;
		else
			cout << "Select Sort FAILED" << endl;

		vector<int> vQuickSort = vInput;
		cSortAlgTest.QuickSort(vQuickSort, 0, (int)vQuickSort.size() - 1);
		cout << "Quick Sort: ";
		cSortAlgTest.PrintVec(vQuickSort);
		if (cSortAlgTest.IsEqual(vLibSort, vQuickSort))
			cout << "Quick Sort PASS" << endl;
		else
			cout << "Quick Sort FAILED" << endl;
	}
private:

};

CSort::CSort()
{
}

CSort::~CSort()
{
}

int main()
{
	vector<int> vTestCase = { 42,23,74,65,58,94,36,99,87 };
	CSort cSortAlg;
	cSortAlg.Test(vTestCase);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
