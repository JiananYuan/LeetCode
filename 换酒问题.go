func numWaterBottles(numBottles int, numExchange int) int {
    cnt := numBottles
    empty := numBottles
    for empty >= numExchange {
        cnt += (empty / numExchange)
        empty = empty / numExchange + empty % numExchange
    }
    return cnt
}

