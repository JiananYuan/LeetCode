func constructRectangle(area int) []int {
    w := int(math.Sqrt(float64(area)))
    arr := make([]int, 2)
    for ; w >= 1; w -= 1 {
        if (area % w) == 0 {
            arr[0] = area / w
            arr[1] = w
            break
        }
    }
    return arr
}

