

let A = new Array();
function takeinput(){
    let data = document.getElementById("userinput").value;
    //document.write(data);
    data += ' ';
    let tmp = ``;
    for(let i = 0;i < data.length;i++){
        if(data[i] == ' '){
            A.push(tmp);
            tmp = ``;
        }
        else tmp += data[i];
    }
    factorize();
    change();
}
function cal(n){
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

let ans = ``;

function factorize(){
    for(let i = 0;i < A.length;i++){
        let n = Number(A[i]);
        let x = cal(n);
        ans += x + "<br>";
    }
}
function change(){
    
    let sel = document.querySelector("#st");
    sel.innerHTML = ans;
    ans = ``;
    A = [];
}
function clr(){
    let sel = document.querySelector("#st");
    sel.innerHTML = "ENTER NUMBERS";
    ans = ``;
}
factorize();
change();