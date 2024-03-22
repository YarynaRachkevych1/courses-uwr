function fib_rec(n){
    if (n == 0){
        return 0
    } else if (n == 1){
            return 1
        }
        else{
            return fib_rec(n-1) + fib_rec (n-2)
        }
}

console.time();
console.log("Iteracja:", fib_rec(40))
console.timeEnd();

function fib_iter(n){
    if (n == 0){
        return 0
    } else if (n == 1){
            return 1
       }
        else{
            num_n2 = 0
            num_n1 = 1
            for (let i = 2; i <= n; i++){
                num_actual = num_n1 + num_n2
                num_n2 = num_n1
                num_n1 = num_actual
            }
        }
    return num_actual
}

function memoize(fn) {
    var cache = {};
    return function(n) {
        if (n in cache) {
            return cache[n];
        } else {
            var result = fn(n);
            cache[n] = result;
            return result;
        }
    }
}

fib_rec = memoize(fib_rec)
console.time()
console.log("Pierwsze wyliczenie z rekurencija:", fib_rec(400))
console.timeEnd()
console.time()
console.log("Drugie wyliczenie z rekurencija:", fib_rec(400))
console.timeEnd()