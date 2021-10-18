func findComplement(num int) int {
	var arr [35] int
	i := 1
	for num != 0 {
		bit := num % 2
		num /= 2
		arr[i] = bit
		i += 1
	}
	j := i - 1
	k := 1
	// reverse array
	for ; k < j; j, k = j - 1, k + 1 {
		arr[k], arr[j] = arr[j], arr[k]
	}
	j = 1
	for ; j < i; j += 1 {
		if arr[j] == 1 {
			arr[j] = 0
		} else {
			arr[j] = 1
		}
	}
	ans := 0
	j = 1
	for ; j < i; j += 1 {
		ans = ans *2 + arr[j]
	}
	return ans
}
