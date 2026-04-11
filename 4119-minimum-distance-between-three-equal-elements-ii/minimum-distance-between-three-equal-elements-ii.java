public class Solution {
    public int minimumDistance(int[] nums) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        int min = Integer.MAX_VALUE;

        //Step 1: Record position of each value
        for (int i = 0; i < nums.length; i++) {
            map.computeIfAbsent(nums[i], x -> new ArrayList<>()).add(i);
        }

        // Step 2: For numbers with at least 3 occurrences
        for (List<Integer> search : map.values()) {
            if (search.size() < 3) continue;

            // Step 3: Check all groups of consecutive 3 indices
            for (int i = 0; i + 2 < search.size(); i++) {
                int a = search.get(i);
                int b = search.get(i + 1);
                int c = search.get(i + 2);
                int totalDist = Math.abs(a - b) + Math.abs(b - c) + Math.abs(c - a);
                min = Math.min(min, totalDist);
            }
        }

        return (min == Integer.MAX_VALUE) ? -1 : min;
    }
}