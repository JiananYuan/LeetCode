func longestSubsequence(arr []int, difference int) int {
	mark := map[int]bool{}
	len := len(arr)
	maxLength := 0
	for i := 0; i < len; i += 1 {
		if mark[ arr[i] ] == true {
			continue
		}
		mark[ arr[i] ] = true
		tmpLength := 1
		lastNum := arr[i]
		for j := i + 1; j < len; j += 1 {
			if arr[j] - lastNum	== difference {
				tmpLength += 1
				mark[ arr[j] ] = true
                		lastNum	= arr[j]
			}
		}
		maxLength = max(maxLength, tmpLength)
	}
	return maxLength
}

func max(a int, b int) int  {
	if a > b {
		return a
	} else {
		return b
	}
}
