// type MyReadonly<T, K extends keyof T > = {
//   readonly [k in K]: T[k]
// } 

type MyReadonly2<T> = {
  readonly [P in keyof T]: T[P];
};