type MyPick<T, K extends keyof T > = {
  [k in K]: T[k]
} 

type MyPick2<T, K> = {
  [k in keyof T & K]: T[k]
}