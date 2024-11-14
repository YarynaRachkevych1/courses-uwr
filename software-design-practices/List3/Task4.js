function sum(...args) {
    let total = 0;
    for (let i = 0; i < args.length; i++) {
        total += args[i];
    }
    return total;
}

console.log(sum(1, 2, 3)); // Wynik: 6
console.log(sum(1, 2, 3, 4, 5)); // Wynik: 15