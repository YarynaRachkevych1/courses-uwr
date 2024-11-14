function numerDniaRoku(data) {
  const parts = data.split('.');
  const day = parseInt(parts[0]);
  const month = parseInt(parts[1]);
  const year = parseInt(parts[2]);

  const dateObj = new Date(year, month - 1, day); 

  const startOfYear = new Date(year, 0, 1);

  const diffTime = Math.abs(dateObj - startOfYear); 
  const diffDays = Math.ceil(diffTime / (1000 * 60 * 60 * 24)); 

  return diffDays;
}

// Przykładowe użycie funkcji:
const data = '20.03.2008';
const numer = numerDniaRoku(data);
console.log(numer);

console.log("aaa" + "ca");