function dg(x , cnt) { for(let i = 0; i < cnt; i++) { console.log(Object.keys(x)[i] + ' : ' + Object.values(x)[i]); } }
function watch(...a) { for(let i = 0; i < a.length; i++) { console.log(a[i]); } }
/*--------------------------------  debug()      ------------------------------------------------------------*/


function Constuct(){
    for(let i = 0; i < arguments.length; i++) {
        let N = arguments[i];
        let name = Object.keys(N)[0];
        let val = Object.values(N)[0];
        this[name] = val;
    }
}

let a = {};

Constuct.call(a, {age : 23}, {roll : 33});
watch(a);
class b {

    details(){
        console.log(this.Language);
    }
};
let myclass = new b;
Constuct.call(myclass, {Language : "Bangla"}, {Contry : "Bangladesh"});
watch(myclass);
myclass.details();
