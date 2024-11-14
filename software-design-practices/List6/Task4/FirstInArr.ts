type First<T extends any[]> = T extends [] ? never : T[0]

type First2<T extends any[]> = T[0] // można tak?