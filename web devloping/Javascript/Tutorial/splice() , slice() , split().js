
let p = (x) => console.log(x);

let n = ["1" , "2" , "3" , "10"];
p(n);
// splice(begining index ,number of element to be removed from begining index , element to add , ..., ...)
n.splice(0,0,5,6,7,8);
p(n);
//splice(element from index >= begin will removed , number of element to remove)
n.splice(2,0);
p(n);

//----------------------------------------

// slice(l , r) will slice element from l ro (r-1) and return a new array or string

let str = "ABCDEFGHIJKLMNOP";
let newStr = str.slice(0,5);
p(newStr);

let array = [1,2,3,4,5,6,7,8,9];
let A = array.slice(0,6);
p(A);


// split works in string only and return an array

let a1 = `1 2 3 4 5 6`;
let a2 = `1,2,3,4,5,6`;

let x = a1.split(' ');
let y = a2.split(',');
let z = a2.split(',' , 3);
p(x);p(y);p(z);
