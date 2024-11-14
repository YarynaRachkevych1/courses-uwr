var Person = function(name, surname) {
    this.name = name;
    this.surname = surname;
    // console.log
    // usuwanie pliku
    // wysylanie czegos przez internet
   }

Person.prototype.hello = function() {
    console.log(`hello from person ${this.name} ${this.surname}`);
}

//var p = new Person('jan', 'kowalski');
var p = Object.create( Person.prototype );
p.name = 'jan';
p.surname = 'kowalski';
p.hello();

var Worker = function(name, surname, age) {
    // wywołanie bazowej funkcji konstruktorowej
    Person.call( this, name, surname );
    this.age = age;
   }
  
Worker.prototype = Object.create( Person.prototype );

Worker.prototype.foo = function() { console.log(1); }

const worker1 = new Worker("a", "28");

worker1.hello();
worker1.foo();

// console.log(Object.getPrototypeOf(worker1));

// Worker.prototype = new Person();
// const worker2 = new Worker("b", "28");

// console.log(Object.getPrototypeOf(worker2));

// Worker.prototype = Object.create(Person.prototype);
// const worker3 = new Worker("c", "28");

// console.log(Object.getPrototypeOf(worker3));