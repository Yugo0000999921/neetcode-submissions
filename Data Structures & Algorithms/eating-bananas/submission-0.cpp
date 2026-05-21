class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            long long hours = 0; 
            for (int pile : piles) {
                // 山のバナナを食べるのにかかる時間を切り上げ計算
                // (pile / mid) の切り上げは (pile + mid - 1) / mid で計算できる
                hours += (pile + mid - 1) / mid;
            }
            
            if (hours <= h) {
                // 制限時間内に食べ切れる場合、もっと遅い速度(小さい k)でもいけるか探す
                right = mid - 1;
            } else {
                // 間に合わない場合、もっと早い速度(大きい k)にする必要がある
                left = mid + 1;
            }
        }
        
        // 最終的に left が条件を満たす最小の k になる
        return left;
    }
};