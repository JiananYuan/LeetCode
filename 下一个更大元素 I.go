func nextGreaterElement(nums1 []int, nums2 []int) []int {
	var ans []int
	for _, num := range nums1 {
		pos := 0
		for pos < len(nums2) {
			if nums2[pos] == num {
				break
			}
			pos += 1
		}
		for pos < len(nums2) {
			if nums2[pos] > num {
				ans = append(ans, nums2[pos])
				break
			}
			pos += 1
		}
		if pos == len(nums2) {
			ans = append(ans, -1)
		}
	}
	return ans
}
