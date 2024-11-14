function forEach( a, f ) {
    for (elem in a){
        f(elem);
    }
    }
function map( a, f ) {
    var new_a = [];
    for (elem in a){
        new_a.push(f(elem));
    }
    return new_a;
}
function filter( a, f ) {
    var new_a = [];
    for (elem in a){
        if (f(elem)){
            new_a.push(elem);
        }
    }
    return new_a;
}
var a = [1,2,3,4];
forEach( a, _ => { console.log( _ ); } );
// [1,2,3,4]
console.log(filter( a, _ => _ < 3 ));
// [1,2]
console.log(map( a, _ => _ * 2 ));
//[2,4,6,8]
