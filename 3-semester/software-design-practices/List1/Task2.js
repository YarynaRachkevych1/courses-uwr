corect_numbers = []
for (let num = 0; num <= 100000; num++){
    cnt = 0
    flag = true
    j = num
    while (j > 0){
        actual_num = j % 10
        cnt += actual_num
        if (num % actual_num != 0){flag = false}
        j = Math.floor(j / 10)
    }
    if (flag && (num % cnt == 0)){
        corect_numbers.push(num)
    }
}

console.log(corect_numbers)