const v=[];
for (let i=1;i<=64;i++)v.push(Math.min(i,32));
const cost=v.map(a=>Math.floor(64/a));
const suf=new Array(65).fill(0);
for (let i=63;i>=0;i--)suf[i]=suf[i+1]+cost[i];
console.log(cost);
console.log(suf);
const dp=new Array(65).fill(0);
for (let i=1;i<=64;i++) {
    dp[i]=suf[i]+i+i;
}
const score=new Array(65).fill(0);
for (let i=1;i<=64;i++) {
    score[i]=parseFloat((13000/(dp[i]+64+12)+10).toFixed(2));
}
console.log(score)
