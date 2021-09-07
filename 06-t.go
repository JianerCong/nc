/**
 * @file 06-t.go
 * @author Jianer Cong
 * @brief test to travere the binary tree in layer order.
 */

package main

import(
	"fmt"
	"math/rand"
)

type tree struct{
	d int			//data
	l *tree			//left and right child
	r *tree
}

func (tr *tree) childNum() int{
	n := 0
	if tr.l != nil {
		n++
	}
	if tr.r != nil {
		n++
	}
	return n
}
func (tr *tree) show(){
	// traverse the tree
	if tr == nil{
		fmt.Println("Empty tree")
	}else{
		fmt.Println("Showing tree:")
		show_iter(tr, 0)
	}
}

func show_iter(tr *tree, lay int){
	// Showing tree where lay is the layer
	for i := 0; i < lay; i++{
		fmt.Print("\t")
	}
	fmt.Println("Node: ", tr.d)
	if tr.l != nil{
		show_iter(tr.l, lay+1)
	}
	if tr.r != nil{
		show_iter(tr.r, lay+1)
	}
}

type queue struct{
	d []*tree			//date is a slice of tree node
}

func (q *queue) add(tr *tree){
	q.d = append(q.d,tr)
}

func (q *queue) get() *tree{
	r := q.d[0]
	q.d = q.d[1:]
	return r
}

func (q *queue) isEmpty() bool {
	return (len(q.d) == 0)
}

func (tr *tree) lshow(){
	if tr == nil{
		fmt.Println("Empty tree")
		return
	}
	c := 1 		// how many nodes in this layer
	ct := tr	// current node
	n := 0	// how many nodes in the next layer

	// init
	var q queue
	q.add(ct)

	for ;c>0;{
		for ;c>0;c--{
			// process this layer
			ct = q.get()
			fmt.Println("Data: ",ct.d)
			// Add child if exits
			if ct.l != nil {
				q.add(ct.l)
				n++
			}
			if ct.r != nil {
				q.add(ct.r)
				n++
			}
			// when this layer is done
		}
		fmt.Print("One layer is done. ")
		fmt.Println("Next layer has ", n ," children\n")
		c = n
		n = 0
	}
	// Layer traversal. First need to remember the size of next layer
	fmt.Println("Done")
}

func main(){

	// get a queue, push a layer and count the number of node in this layer
	var ts []tree
	n := 5
	for i := 1; i <= n; i++{
		ts = append(ts,tree{d:i})
	}

	// Assign child
	for i := 1; i <= n; i++{
		if 2*i-1 < n{
			ts[i-1].l = &ts[2*i-1]
		}else{
			ts[i-1].l = nil
		}
		if 2*i < n{
			ts[i-1].r = &ts[2*i]
		}else{
			ts[i-1].r = nil
		}
	}

	ts[0].show()
	// Automatically layer traverse
	fmt.Println("Showing tree layer-wise")
	ts[0].lshow()

}

func testQueue(n int, ts []tree){
	fmt.Println("Trying the queue: ")
	var q queue
	// m is a positive int from [0,n-1], which indicates when
	// to start popping
	m := rand.Intn(n)
	fmt.Println("We start popping after ",m,"th inserts.")
	for i := 0; i<n;i++{
		fmt.Println("Add value: ", ts[i].d)
		q.add(&(ts[i]))
		if i == m {
			// pop and show until the queue is empty.
			// Should already has m elements. Therefore pop m times.
			for ;!q.isEmpty();{
				fmt.Println("The value popped: ",q.get().d)
			}
		}
	}
	fmt.Println("All stuff inserted.")
	for ;!q.isEmpty();{
		fmt.Println("The value popped: ",q.get().d)
	}
}
