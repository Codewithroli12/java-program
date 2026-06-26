class BIT {
public:
    vector<int> bit;
    int n;

    BIT(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        BIT ft(2 * n + 5);

        int prefix = n + 2;     // Shift to avoid negative indices
        ft.update(prefix, 1);

        long long ans = 0;

        for (int x : nums) {
            if (x == target)
                prefix++;
            else
                prefix--;

            ans += ft.query(prefix - 1);
            ft.update(prefix, 1);
        }

        return ans;
    }
};