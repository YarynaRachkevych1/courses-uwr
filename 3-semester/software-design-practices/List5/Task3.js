const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const actual_n = Math.floor(Math.random() * 101);

function game(){
    rl.question("Sproboj zgadnac liczbe: ", (input) => {
        const input_n = parseInt(input);

        if (input_n > actual_n){
            console.log('Moja liczba jest mniejsza');
        } 
        else if (input_n < actual_n){
            console.log("Moja liczba jest wieksza");
        }
        else console.log("To jest wlasnie ta liczba");

        if (actual_n != input_n){
            game();
        }
    })
}

game();