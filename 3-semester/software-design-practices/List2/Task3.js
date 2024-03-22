console.log((![]+[])[+[]]+(![]+[])[+!+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]] ); // fail

console.log("\nPierwsza Grupa: ");
console.log(typeof (![] + []), ![] + []);
console.log(typeof +[], +[]);
console.log(typeof (![] + [])[+[]], (![] + [])[+[]]); // literka f

console.log("\nDruga Grupa: ");
console.log(typeof (![] + [])[+!+[]], (![] + [])[+!+[]]);
console.log(typeof (![] + []), ![] + []);
console.log(typeof +!+[], +!+[]); // literka a

console.log("\nTrzecia Grupa: ");
console.log(
  typeof ([![]] + [][[]])[+!+[] + [+[]]],
  ([![]] + [][[]])[+!+[] + [+[]]]
);
console.log(typeof [![]], [![]]);
console.log(typeof [][[]], [][[]]);
console.log(typeof ([![]] + [][[]]), [![]] + [][[]]);
console.log(typeof +!+[], +!+[]);
console.log(typeof [+[]], [+[]]);
console.log(typeof [+!+[] + [+[]]], [+!+[] + [+[]]]);

console.log("\nCzwarta Grupa: ");
console.log(typeof (![] + [])[!+[] + !+[]], (![] + [])[!+[] + !+[]]);
console.log(typeof (![] + []), ![] + []);
console.log(typeof [!+[] + !+[]], [!+[] + !+[]]);