type Includes<T extends readonly any[], U> = T extends [infer L, ...infer R]
  ? [U, L] extends [L, U]
    ? true
    : Includes<R, U>
  : false