const d=[]
for(let i=1;i<=9;i++) {
    const r=[];
    for(let j=1;j<=9;j++) {
        const c=[];
        for(let k=1;k<=9;k++) {
            c.push(true);
        }
        r.push(c);
    }
    d.push(r);
}
for (let i=0;i<=8;i++){
    d[i][1][1]=false
    d[1][i][1]=false
    d[1][1][i]=false
}
console.log(d)
