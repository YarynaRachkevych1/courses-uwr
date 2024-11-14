// tsc Zadanie1.ts // jednorazowa kompilajca
// tsc -watch Zadanie1.ts // tryb kompliacji "na zywo"
function fib(n) {
    if (n <= 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}
function memoize(fn) {
    var cache = {};
    return function (n) {
        if (n in cache) {
            return cache[n];
        }
        else {
            var result = fn(n);
            cache[n] = result;
            return result;
        }
    };
}
var mem_fib = memoize(fib);
console.log(mem_fib(40));
