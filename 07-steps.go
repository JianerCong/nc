package main

import(
	"fmt"
	)

func main(){
	// jumping steps
	for i:=1;i<6;i++{
		fmt.Println("when n = ", i,": ", steps(i))
	}
	}

/**
  * @brief Calculate the number of possible ways to get on a n-step steps
  * @param n the number of jumps needed.
  */
func steps(n int) int{
	k := 1
	m := 1
	var m_next int
	for x := 1;x<n;x++{
		m_next = k+m
		k = m
		m = m_next
	}
	return m
}

/**
 * 
 * @param number int整型 
 * @return int整型
 */
func jumpFloor( number int ) int {
	// write code here
	k := 1
	m := 1
	var m_next int
	for x := 1;x<number;x++{
		m_next = k+m
		k = m
		m = m_next
	}
	return m
}
