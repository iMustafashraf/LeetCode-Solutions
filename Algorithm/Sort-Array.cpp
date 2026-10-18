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

// -------------------------------{ For Bigger values but difference between them is slow! }------------------------------

vector<int> CountShift(vector<int> &nums){
	if (nums.empty()) {
		return {};
	}

	int min_val = nums[0];
	int max_val = nums[0];
	for (int num : nums) {
		if (num < min_val) min_val = num;
		if (num > max_val) max_val = num;
	}

	int range_span = max_val - min_val + 1;
	std::vector<int> count(range_span, 0);

	for (int num : nums) {
		count[num - min_val]++;
	}

	std::vector<int> result;
	for (int i = 0; i < range_span; ++i) {
		while (count[i] > 0) {
			result.push_back(i + min_val);
			count[i]--;
		}
	}

	return result;
}
