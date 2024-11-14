// function createFs(n) { // tworzy tablicę n funkcji
//     let fs = []; // i-ta funkcja z tablicy ma zwrócić i
//     for ( let i=0; i<n; i++ ) {
//         fs[i] = function() {
//             return i;
//         };
//     };
//     return fs;
//     }
// var myfs = createFs(10);
// console.log( myfs[0]() ); // zwraca 0
// console.log( myfs[2]() ); // zwraca 2
// console.log( myfs[7]() );

// Kiedy zastąpisz słowo kluczowe var na let, 
// to zmienne i zostaną związane z blokiem (zasięgiem blokowym), 
// co oznacza, że każda iteracja pętli będzie tworzyła nowe zmienną i z własnym zasięgiem. 
// W wyniku tego każda funkcja w tablicy fs będzie miała dostęp do własnej kopii zmiennej i, 
// a nie do tej samej zmiennej globalnej, co było problemem w pierwszym przykładzie.

function createFs2(n) {
    var fs = [];
    for (var i = 0; i < n; i++) {
        fs[i] = (function(j) {
            return function() {
                return j;
            };
        })(i);
    }
    return fs;
}

var myfs = createFs2(10);
console.log(myfs[0]()); // Wynik: 0
console.log(myfs[2]()); // Wynik: 2
console.log(myfs[7]()); // Wynik: 7
