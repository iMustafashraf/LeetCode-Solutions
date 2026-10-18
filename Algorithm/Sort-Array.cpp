class Solution {
public:
    void countSort(vector<int> &array) {
	// Find the largest element of the array
	int size = array.size(), mxValue = array[0];
	for (int i = 1; i < size; ++i){
		if (array[i] > 0 && array[i] > mxValue)
			mxValue = array[i];
		if(array[i] < 0 && -array[i] > mxValue)
			mxValue = -array[i];
	}

	// Compute Frequency
	vector<int> count_pos(mxValue + 1);	// Positives
	vector<int> count_neg(mxValue + 1);	// Negatives
	for (int i = 0; i < size; ++i){
		if(array[i] > 0)
			count_pos[array[i]] += 1;
		else if(array[i] < 0)
			count_neg[-array[i]] += 1;
        else if(array[i] == 0)
            count_neg[array[i]] += 1;
	}

	// Put the values back to the array
	int idx = 0;
	for (int i = mxValue; i >= 0; --i)
		for (int j = 0; j < count_neg[i]; ++j, ++idx)
			array[idx] = -i;

	for (int i = 0; i <= mxValue; ++i){
        for (int j = 0; j < count_pos[i]; ++j, ++idx)
			array[idx] = i;
    }	
}

    vector<int> sortArray(vector<int>& nums) {
        countSort(nums);
        return nums;
        // for (int i = 0; i < (int) v.size(); ++i) {
        //     cout << v[i] << " ";
        // }
    }
};
