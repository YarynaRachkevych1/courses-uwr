var n = 1;
// liczba ma prototyp? - tak
console.log( typeof Object.getPrototypeOf(n), Object.getPrototypeOf(n) );

// można jej dopisać pole/funkcję?
n.foo = 'foo';
console.log(n.foo);

var m = Number(1);
m.foo = 'foo';
console.log( m.foo );

var k = Number(2);

var l = m + n;

// n.prototype.foo1 = function(){
//     return 'foo1';
// }
// Nie można do typów prostych dodawać funkcje/pola.