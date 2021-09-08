/**
 * @file 06-layer.go
 * @author Jianer Cong
 * @brief layer-traversal of the tree.
 */


package main
import . "nc_tools"
/*
 * type TreeNode struct {
 *   Val int
 *   Left *TreeNode
 *   Right *TreeNode
 * }
 */

type queue struct{
	d []*TreeNode			//date is a slice of TreeNode node
}

func (q *queue) add(tr *TreeNode){
	q.d = append(q.d,tr)
}

func (q *queue) get() *TreeNode{
	r := q.d[0]
	q.d = q.d[1:]
	return r
}

func (q *queue) isEmpty() bool {
	return (len(q.d) == 0)
}
/**
 *
 * @param root TreeNode类
 * @return int整型二维数组
 */
func levelOrder( root *TreeNode ) [][]int {
	// write code here
	var r [][]int

	if root == nil{
		// fmt.Println("Empty tree")
		return r
	}

	c := 1 		// how many nodes in this layer
	ct := root	// current node
	n := 0	// how many nodes in the next layer

	// init
	var q queue
	q.add(ct)

	l := 0			// layer number
	for ;c>0;l++{
		r = append(r, make([]int,0)) // add a new layer
		for ;c>0;c--{
			// process this layer
			ct = q.get()
			// fmt.Println("Data: ",ct.Val)
			r[l] = append(r[l], ct.Val)
			// Add child if exits
			if ct.Left != nil {
				q.add(ct.Left)
				n++
			}
			if ct.Right != nil {
				q.add(ct.Right)
				n++
			}
			// when this layer is done
		}
		// fmt.Print("One layer is done. ")
		// fmt.Println("Next layer has ", n ," children\n")
		c = n
		n = 0
	}

	// Layer traversal. First need to remember the size of next layer
	return r

}

