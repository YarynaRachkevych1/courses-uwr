function fib() {
    let x0 = 0
    let x1 = 1
    return {
        next : function() {
            const value = x1;
            [x0, x1] = [x1, x1 + x0];
            return {
                value,
                done : false
                }
            }
        }
    }

function* fib_gen(n) {
    let x0 = 0;
    let x1 = 1;
    while (true) {
        const x = x1;
        [x0, x1] = [x1, x1 + x0];
        yield x;
    }
}

var n = 0;
var _it = fib();
for (var _result; (_result = _it.next()), !_result.done;) {
    console.log(_result.value);
    n += 1
    if (n > 20) { 
        break;
    }
}

n = 0;
for (var i of fib_gen()) {
    console.log(i);
    n += 1
    if (n > 20) {
      break;
    }
  }


function* take(it, top) {
    var n = 0;
    for (var _result; _result = it.next(); !_result.done) {
        n += 1
        if (n > top) {
            break;
        }
        yield _result.value;
    }
}

for (let num of take(fib(), 10)) {
    console.log(num);
}
  