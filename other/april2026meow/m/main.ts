const f = Deno.readTextFileSync("masala.txt").replace(/\r/g,"").split("\n");
const ln = f.map(a => a.split(/\s+/g).map(a => parseInt(a)).toSorted());

let good=0;
for(const [a,b,c] of ln){
    if((a+b+c)%2==1)continue;
    if(c>a+b)continue;
    good++;
}
console.log(good);
