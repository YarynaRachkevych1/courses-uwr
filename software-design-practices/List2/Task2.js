const car = {
    name: 'Honda',
    model: 'Accord',
    year: 2020
}

console.log(car.name)
console.log(car['name']) //to lepej użyć gdy nazwa kluczu ma dodatkowe znaki
// Można też użyć jej, gdy nazwa właściwości jest przechowywana w zmiennej lub jest wygenerowana w trakcie działania programu

console.log(car[0]) // undefined

const car2 = {
    1: 'Honda',
    2: 'Accord',
    3: 2020
};

console.log(car2[1]) // 'Honda'
console.log(car2['1']) // 'Honda'

const key2 = {
    0 : '1'}
console.log(car2[key2[0]]) // 'Honda'

const myArray = [1, 2, 3, 4, 5]
console.log(myArray['0']) // 1
console.log(myArray['AA']) // undefined

const key = { toString: () => '1' }
console.log(myArray[key]) // To zadziała, zwróci 2, ponieważ '1' jest użyte jako klucz

myArray['indeks'] = 'weppo'
console.log(myArray) // [ 1, 2, 3, 4, 5, indeks: 'weppo' ], dodane pod podanym kluczem

myArray.length = 3 // Ustawienie length na 3
console.log(myArray) // [1, 2, 3], Nastąpi obcięcie tablicy
myArray.length = 5 // ??
console.log(myArray, myArray.length) // [ 1, 2, 3, <2 empty items>, indeks: 'weppo' ] 5
console.log(Object.keys(myArray).length)