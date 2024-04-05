package main

import (
  "fmt"
)

func main() {
    a:=0
    for i:=0; i<3; i++ {
      var b int
      fmt.Scan(&b)
      a+=b
    }
    fmt.Println(a)
}
