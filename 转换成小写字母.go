func toLowerCase(s string) string {
    b := []byte(s)
    bLen := len(b)
    for i := 0; i < bLen; i += 1 {
        if b[i] >= 'A' && b[i] <= 'Z' {
            b[i] = b[i] + ('a' - 'A')
        }
    }
    return string(b)
}
