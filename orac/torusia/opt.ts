function log(x, y) {
  return Math.log(y) / Math.log(x);
}
const v=[];
for (let i=1;i<=64;i++)v.push(i);

const exp=Math.sqrt(2);

function calc(exp) {
    const round2=a=>Math.pow(exp,Math.floor(log(exp,a+1)));
    const cost=v.map(a=>Math.floor(64/round2(a)));
    const suf=new Array(65).fill(0);
    for (let i=63;i>=0;i--)suf[i]=suf[i+1]+cost[i];
    const dp=new Array(65).fill(0);
    for (let i=1;i<=64;i++) {
        dp[i]=suf[i]+2*(i-1);
    }
    const score=new Array(65).fill(0);
    for (let i=1;i<=64;i++) {
        score[i]=(13000/(dp[i]+64+12)+10);
    }
    return Math.max(...score);
}
let best=0;
for (let exp=1.001;exp<=2;exp+=0.001) {
    console.log(exp.toFixed(3),calc(exp));
    if (calc(exp)>best){
        best=calc(exp);
        console.log(`NEW BEST: f(${exp})=${calc(exp)}`);
    }
}
console.log(best);
