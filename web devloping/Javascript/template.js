function dg(x , cnt) { for(let i = 0; i < cnt; i++) { console.log(Object.keys(x)[i] + ' : ' + Object.values(x)[i]); } }
function watch(...a) { for(let i = 0; i < a.length; i++) { console.log(a[i]); } }
/*--------------------------------  debug()      ------------------------------------------------------------*/



/* ---------------------------- New --------------------------------------*/
function dg(x) { let item = Object.keys(x); let Val = Object.values(x); for(let i = 0; i < item.length; i++) { console.log(item[i] + ' : ' + Val[i]); } }
