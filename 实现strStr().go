func strStr(haystack string, needle string) int {
	len1 := len(haystack)
	len2 := len(needle)
    if len1 < len2 {
        return -1
    }
    if len2 == 0 {
        return 0
    }
	for i := 0; i <= len1 - len2; i += 1 {
		iscons := true
		for j := 0; j < len2; j += 1 {
			if haystack[i + j] != needle[j] {
				iscons = false
				break
			}
		}
		if iscons {
			return i
		}
	}
	return -1
}
