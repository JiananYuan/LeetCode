func originalDigits(s string) string {
	numArr := []string{ "zero", "two", "six", "seven", "four", "five", "one", "three", "eight", "nine" }
	numRealArr := []int{ 0, 2, 6, 7, 4, 5, 1, 3, 8, 9 }
	countArr := make([]int, 26)
	sLen := len(s)
	// 统计字符出现的个数
	for i := 0; i < sLen; i += 1 {
		ch := s[i]
		countArr[ ch - 'a' ] += 1
	}
	// check 函数检查剩下字符是否足够拼成one, two, three
	check := func(i int) bool {
		numStr := numArr[i]
		numStrLen := len(numStr)
		ok := true
		for j := 0; j < numStrLen; j += 1 {
			ch := numStr[j]
			if countArr[ ch - 'a' ] <= 0 {
				ok = false
				break
			}
		}
		if ok {
			for j := 0; j < numStrLen; j += 1 {
				countArr[ numStr[j] - 'a' ] -= 1
			}
		}
		return ok
	}
	ansNum := []string{}
	// 持续检查, 从1～9
	for i := 0; i < 10; i += 1 {
		for {
			if check(i) {
				// 自然有序
				ansNum = append(ansNum, strconv.Itoa(numRealArr[i]))
			} else {
				break
			}
		}
	}
	sort.Strings(ansNum)
	return strings.Join(ansNum, "")
}
