function isOwnProperty(obj, propName) {
    return obj.hasOwnProperty(propName);
}

var personProto = {
    say: function() {
        return this.name;
    }
}

var p = {
    name: 'jan'
};

Object.setPrototypeOf(p, personProto);

console.log(isOwnProperty(p, 'name')); // true, ponieważ 'name' jest polem obiektu
console.log(isOwnProperty(p, 'say')); // false, ponieważ metoda 'say' pochodzi z prototypu
