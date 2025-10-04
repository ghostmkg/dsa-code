package main

import "fmt"

func largestAltitude(gain []int) int {
	ans := 0
	sum := 0
	for _, value := range gain {
		sum += value
		ans = max(ans, sum)
	}
	return ans
}

func main() {
	gain := []int{-5, 1, 5, 0, -7}
	ans := largestAltitude(gain)
	fmt.Println("largest altitude is ", ans)

}
