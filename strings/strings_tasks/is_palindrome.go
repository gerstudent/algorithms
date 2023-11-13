package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	text, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	runes := []rune(text)
	middle_idx := len(runes) / 2
	for i := 0; i < middle_idx; i++ {
		if runes[i] != runes[len(runes)-i-1] {
			fmt.Println("Нет")
			break
		}
	}
	fmt.Println("Палиндром")
}
