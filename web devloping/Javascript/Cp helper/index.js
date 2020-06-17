
let T;
function Type(){
   T = document.getElementById("list").value;
}
let A = new Array();
let data;
function takeinput(){
    data = document.getElementById("userinput").value;
    data += ' ';
    let tmp = ``;
    for(let i = 0;i < data.length;i++){
        if(data[i] == ' '){
            A.push(tmp);
            tmp = ``;
        }
        else tmp += data[i];
    }
    action();
    change();
}

function factorize(n){
    let res = `${n} = `;
    if(n == 1){
        res += "1";
        return res;
    }
    for(let i = 2;i <= n;i++){
        if(i * i > n) i = n;
        
        if(n % i == 0){
            let cnt = 0;
            while(n % i == 0){
                n /= i;
                cnt++;
            }
            if(n > 1){
                res += `${i} <sup>${cnt}</sup> x `;
            }
            else res += `${i} <sup>${cnt}</sup>`;
        }
    }
    return res;
}

function factorial(n){
  let res = `${n}! = `;
  let pro = 1n;
  for(let i=1;i<=n;i++){
    pro = pro * BigInt(i);
  }
  res += pro;
  return res;
}
function power(n){
  let res = ``;
  for(let i=0;i<20;i++){
    let x = Math.pow(n,i);
    res += `${n} <sup>${i}</sup> = ${x} <br>`;
  }
  return res;
}
let ans = ``;

function change(){
  
  let sel = document.querySelector("#st");
  sel.innerHTML = ans;
  ans = ``;
  A = [];
}
function clr(){
  let sel = document.querySelector("#st");
  ans = ``;
}

function actionfactorization(){
  for(let i = 0;i < A.length;i++){
    let n = Number(A[i]);
    if(n == 0) continue;
    let x = factorize(n);
    ans += x + "<br>";
  }
}

function actionfactorial(){
  for(let i = 0;i < A.length;i++){

    let n = Number(A[i]);
    if(n == 0) continue;
    let x = factorial(n);
    ans += x + "<br>";
  }
}
function actionpower(){
  for(let i=0;i<A.length;i++){
    ans += power(A[i]);
  }
}
function cmp(a , b){
  return a - b;
}
function actionsort(){

  A.sort(cmp);
  let len = A.length;
  for(let i=0;i < len;i++){
    if(A[i] == ' ') continue;
    if(i == len - 1) ans += A[i];
    else ans += A[i] + ' ';
  }
}
function actionfreqS(){
  let cnt = {};
  let S = data.split("");
  //document.write(S + "<br>");
  for(let i=0;i < S.length;i++){
    if(cnt[S[i]] == undefined) cnt[S[i]] = 0;
    cnt[S[i]]++;
  }
  for(let i in cnt){
    if(i == ' ') continue;
    ans += `${i} = ${cnt[i]} <br>`;
  }
  // for(let i = 'a' ; i <= 'z';i++){
  //   ans += `${i} = ${cnt[i]} `;
  // }
 // document.write("I am working");
 // document.write(cnt);
}


function action(){
  if(T == "pfac"){
    actionfactorization();
  }
  else if(T == "fac"){
    actionfactorial();
  }
  else if(T == "pow"){
    actionpower();
  }
  else if(T == "sort"){
    actionsort();
  }
  else if(T == "fres"){
    actionfreqS();
  }
}

























