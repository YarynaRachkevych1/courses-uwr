function Foo() {
    function Qux(n) {
        n ++;
        console.log('To jest funkcja prywatna Qux', n);
    }

    this.Bar = function() {
        var n = 1;
        console.log('To jest metoda publiczna Bar');
        Qux(n); 
    };
}


var myFoo = new Foo();
myFoo.Bar();

// myFoo.Qux() - error!