prime_numbers =[]
for (let i = 2; i <= 100000; i++) {
    flag = true;

    for (let j = 2; j < i; j++) {
        if (i % j == 0) {
            flag = false;
            break;
        }
    }

    if (i > 1 && flag) {
        prime_numbers.push(i)
    }
}

console.log(prime_numbers)