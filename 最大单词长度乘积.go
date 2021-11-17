func maxProduct(words []string) int {
	wordsLen := len(words)
	bitset := make([]int, wordsLen)
	for i := 0; i < wordsLen; i += 1 {
		word := words[i]
		wordLen := len(word)
		for j := 0; j < wordLen; j += 1 {
			offset := word[j] - 'a'
			bitset[i] = bitset[i] | (1 << offset)
		}
	}
	maxProduct := 0
	for i := 0; i < wordsLen; i += 1 {
		iLen := len(words[i])
		for j := i + 1; j < wordsLen; j += 1 {
			if (bitset[i] & bitset[j]) == 0 {
				maxProduct = max(maxProduct, iLen * len(words[j]))
			}
		}
	}
	return maxProduct
}

func max(a int, b int) int {
	if a > b {
		return a 
	} else {
		return b
	}
}
