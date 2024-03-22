console.log(typeof 42) // "number"
console.log(typeof "Hello Word") // "string"
console.log(typeof [1, 2, 3]) // "object"
console.log(typeof function() {}) // "function"

// typeof jest operatorem jednoargumentowym, który służy do określania typu wartości lub wyrażenia.
// Zwraca nazwe typu wartości jako string.

function Person() {}
const person = new Person();
console.log(person instanceof Person); // true

// instanceof jest operatorem dwuargumentowym, który sprawdza, czy obiekt jest instancją konkretnej klasy lub konstruktora.
// Zwraca wartość true lub false.