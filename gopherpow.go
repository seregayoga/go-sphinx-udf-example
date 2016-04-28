package main

import (
	"C"
	"math"
)

//export Pow
func Pow(x, y float64) float64 {
	return math.Pow(x, y)
}

func main() {}
