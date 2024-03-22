// type Concat<T extends any[], U extends any[]> = [...T, ...U] // nie dziala dla tuple
type Tuple = readonly unknown[];

type Concat<T extends Tuple, U extends Tuple> = [...T, ...U];